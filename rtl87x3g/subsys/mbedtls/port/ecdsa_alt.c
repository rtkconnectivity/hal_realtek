#if (CONFIG_SOC_SERIES_RTL87X3G==1)
#include "mbedtls_port.h"
#include "mbedtls_config.h"
#include "platform.h"
#include "trace.h"
#include "entropy_poll.h"
#include "threading.h"
#include "ecdsa_alt.h"
#include "hw_pke_ecc.h"
#include "ecp.h"
#include "ecdsa.h"
#include "string.h"
#include "ecc_interface.h"
#include "mbedtls/ecdsa.h"
#include "mbedtls/ecp.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/entropy.h"
#include "mbedtls/sha256.h"
#include "mbedtls/sha512.h"
#include "mbedtls/error.h"

#define CURVE_P192       0x3
#define CURVE_P224       0x4
#define CURVE_P384       0x5

#define CURVE_P192K1       0x7
#define CURVE_P224K1       0x8
#define CURVE_P256K1       0x9

#define RET_HW_FAIL             2
#define RET_BAD_INPUT           3
#define RET_FEATURE_UNAVAIL     4

#define ECDSA_ALT_DEBUG_ENABLE  0

#if (ECDSA_ALT_DEBUG_ENABLE == 1)
static void print_mbedtls_error(const char *msg, int ret)
{
    char buf[256];
    mbedtls_strerror(ret, buf, sizeof(buf));
    DBG_DIRECT("%s: ret=%d (%s)\n", msg, ret, buf);
}


static void mpi_print_hex(const char *name, const mbedtls_mpi *X, size_t bytelen)
{
    unsigned char be[80] = {0};
    if (bytelen > sizeof(be)) { bytelen = sizeof(be); }
    int ret = mbedtls_mpi_write_binary(X, be, bytelen);
    if (ret != 0)
    {
        print_mbedtls_error("mpi_write_binary", ret);
        return;
    }
    DBG_DIRECT("%s:", name);
    for (size_t i = 0; i < bytelen; i += 8)
    {
        DBG_DIRECT("%02X %02X %02X %02X %02X %02X %02X %02X", be[i], be[i + 1], be[i + 2], be[i + 3],
                   be[i + 4], be[i + 5], be[i + 6], be[i + 7]);
    }

}
#endif

static int map_group_id_to_sel(mbedtls_ecp_group_id id)
{
    switch (id)
    {
    case MBEDTLS_ECP_DP_SECP192R1: return CURVE_P192;
    case MBEDTLS_ECP_DP_SECP224R1: return CURVE_P224;
    case MBEDTLS_ECP_DP_SECP256R1: return CURVE_P256;
    case MBEDTLS_ECP_DP_SECP384R1: return CURVE_P384;
    case MBEDTLS_ECP_DP_SECP192K1: return CURVE_P192K1;
    case MBEDTLS_ECP_DP_SECP224K1: return CURVE_P224K1;
    case MBEDTLS_ECP_DP_SECP256K1: return CURVE_P256K1;
    default: return -1;
    }
}

static int sel_to_bits_and_bytes(int curve_sel, int *bits, size_t *bytes)
{
    switch (curve_sel)
    {
    case CURVE_P192:    *bits = 192; *bytes = 24; return 0;
    case CURVE_P224:    *bits = 224; *bytes = 28; return 0;
    case CURVE_P256:
    case CURVE_P256K1:  *bits = 256; *bytes = 32; return 0;
    case CURVE_P384:    *bits = 384; *bytes = 48; return 0;
    case CURVE_P192K1:  *bits = 192; *bytes = 24; return 0;
    case CURVE_P224K1:  *bits = 225; *bytes = 28; return 0;
    default: return -1;
    }
}

/* ECC Group cache to avoid repeated hardware initialization */
typedef struct
{
    int curve_sel;
    int bits;
    int valid;
    ECC_GROUP grp;
} ecc_group_cache_t;

static ecc_group_cache_t g_ecc_group_cache = {0, 0, 0, {0}};


/* Byte order conversion: be_to_le if reverse=true, le_to_be if reverse=false */
static void byte_swap(const unsigned char *src, unsigned char *dst, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        dst[i] = src[len - 1 - i];
    }
}

#define be_to_le(be, le, len)  byte_swap((be), (le), (len))
#define le_to_be(le, be, len)  byte_swap((le), (be), (len))


static int mpi_to_le_fixed(const mbedtls_mpi *X, unsigned char *le, size_t len)
{
    unsigned char be_buf[64];
    if (len > sizeof(be_buf))
    {
        return RET_BAD_INPUT;
    }

    memset(be_buf, 0, sizeof(be_buf));
    int ret = mbedtls_mpi_write_binary(X, be_buf + (sizeof(be_buf) - len), len);
    if (ret != 0)
    {
        return ret;
    }
    be_to_le(be_buf + (sizeof(be_buf) - len), le, len);
    return 0;
}


static int le_fixed_to_mpi(mbedtls_mpi *X, const unsigned char *le, size_t len)
{
    unsigned char be_buf[64];
    if (len > sizeof(be_buf))
    {
        return RET_BAD_INPUT;
    }
    le_to_be(le, be_buf, len);
    return mbedtls_mpi_read_binary(X, be_buf, len);
}


static int ecp_point_to_le(const mbedtls_ecp_point *P, unsigned char *x_le, unsigned char *y_le,
                           size_t len)
{
    int ret = mpi_to_le_fixed(&P->MBEDTLS_PRIVATE(X), x_le, len);
    if (ret != 0)
    {
        return ret;
    }
    ret = mpi_to_le_fixed(&P->MBEDTLS_PRIVATE(Y), y_le, len);
    return ret;
}


static int le_to_ecp_point(mbedtls_ecp_point *P, const unsigned char *x_le,
                           const unsigned char *y_le, size_t len)
{
    int ret = le_fixed_to_mpi(&P->MBEDTLS_PRIVATE(X), x_le, len);
    if (ret != 0)
    {
        return ret;
    }
    ret = le_fixed_to_mpi(&P->MBEDTLS_PRIVATE(Y), y_le, len);
    if (ret != 0)
    {
        return ret;
    }
    return mbedtls_mpi_lset(&P->MBEDTLS_PRIVATE(Z), 1);
}


static int hw_curve_init(ECC_GROUP *grp, int curve_sel, int bits)
{
    /* Use cached ECC group if available */
    if (g_ecc_group_cache.valid && g_ecc_group_cache.curve_sel == curve_sel)
    {
        memcpy(grp, &g_ecc_group_cache.grp, sizeof(ECC_GROUP));
        return 0;
    }

    /* Initialize and cache the ECC group */
    memset(&g_ecc_group_cache, 0, sizeof(g_ecc_group_cache));
    hw_pke_ecc_curve_init(&g_ecc_group_cache.grp, curve_sel);
    g_ecc_group_cache.curve_sel = curve_sel;
    g_ecc_group_cache.bits = bits;
    g_ecc_group_cache.valid = 1;

    memcpy(grp, &g_ecc_group_cache.grp, sizeof(ECC_GROUP));
    return 0;
}


int mbedtls_ecdsa_genkey(mbedtls_ecdsa_context *ctx,
                         mbedtls_ecp_group_id gid,
                         int (*f_rng)(void *, unsigned char *, size_t),
                         void *p_rng)
{
    (void) f_rng;
    (void) p_rng;

    int curve_sel = map_group_id_to_sel(gid);
    if (curve_sel < 0) { return RET_FEATURE_UNAVAIL; }

    int bits = 0;
    size_t bytelen = 0;
    if (sel_to_bits_and_bytes(curve_sel, &bits, &bytelen) != 0)
    {
        return RET_FEATURE_UNAVAIL;
    }

    int ret = mbedtls_ecp_group_load(&ctx->MBEDTLS_PRIVATE(grp), gid);
    if (ret != 0) { return ret; }

    ECC_GROUP grp_hw;
    if (hw_curve_init(&grp_hw, curve_sel, bits) != 0)
    {
        return RET_HW_FAIL;
    }

    ECC_OPERAND d_hw;
    memset(&d_hw, 0, sizeof(d_hw));
    d_hw.bit_len = (uint32_t)((ECC_GROUP *)&grp_hw)->nbits;

    ECC_POINT Q_hw;
    memset(&Q_hw, 0, sizeof(Q_hw));

    if (!hw_ecc_gen_keypair(&grp_hw, &d_hw, &Q_hw))
    {
        return RET_HW_FAIL;
    }
#if (ECDSA_ALT_DEBUG_ENABLE== 1)
    APP_PRINT_ERROR1(" mbedtls_ecdsa_genkey  d %b", TRACE_BINARY(bytelen, d_hw.input));
    APP_PRINT_ERROR1(" mbedtls_ecdsa_genkey  Qx %b", TRACE_BINARY(bytelen, Q_hw.x));
    APP_PRINT_ERROR1(" mbedtls_ecdsa_genkey  Qy %b", TRACE_BINARY(bytelen, Q_hw.y));
#endif

    //  big eddien to little eddien
    ret = le_fixed_to_mpi(&ctx->MBEDTLS_PRIVATE(d), d_hw.input, bytelen);

    if (ret != 0)
    {
        return ret;
    }
    ret = le_to_ecp_point(&ctx->MBEDTLS_PRIVATE(Q),
                          Q_hw.x, Q_hw.y, bytelen);

    if (ret != 0)
    {
        return ret;
    }

    ret = mbedtls_mpi_lset(&ctx->MBEDTLS_PRIVATE(Q).MBEDTLS_PRIVATE(Z), 1);
    if (ret != 0)
    {
        return ret;
    }

    if (mbedtls_mpi_cmp_int(&ctx->MBEDTLS_PRIVATE(Q).MBEDTLS_PRIVATE(X), 0) < 0 ||
        mbedtls_mpi_cmp_int(&ctx->MBEDTLS_PRIVATE(Q).MBEDTLS_PRIVATE(Y), 0) < 0 ||
        mbedtls_mpi_cmp_mpi(&ctx->MBEDTLS_PRIVATE(Q).MBEDTLS_PRIVATE(X),
                            &ctx->MBEDTLS_PRIVATE(grp).P) >= 0 ||
        mbedtls_mpi_cmp_mpi(&ctx->MBEDTLS_PRIVATE(Q).MBEDTLS_PRIVATE(Y),
                            &ctx->MBEDTLS_PRIVATE(grp).P) >= 0)
    {
        return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
    }


    ret = mbedtls_ecp_check_pubkey(&ctx->MBEDTLS_PRIVATE(grp),
                                   &ctx->MBEDTLS_PRIVATE(Q));

    return 0;
}


int mbedtls_ecdsa_sign(mbedtls_ecp_group *grp, mbedtls_mpi *r, mbedtls_mpi *s,
                       const mbedtls_mpi *d, const unsigned char *buf, size_t blen,
                       mbedtls_f_rng_t *f_rng, void *p_rng)
{
    (void) f_rng;
    (void) p_rng;

    if (!grp || !r || !s || !d || !buf)
    {
        return RET_BAD_INPUT;
    }

    int curve_sel = map_group_id_to_sel(grp->id);
    if (curve_sel < 0)
    {
        return RET_FEATURE_UNAVAIL;
    }

    int bits = 0;
    size_t bytelen = 0;
    if (sel_to_bits_and_bytes(curve_sel, &bits, &bytelen) != 0)
    {
        return RET_FEATURE_UNAVAIL;
    }

    ECC_GROUP grp_hw;
    if (hw_curve_init(&grp_hw, curve_sel, bits) != 0)
    {
        return RET_HW_FAIL;
    }

    ECC_OPERAND d_hw;
    memset(&d_hw, 0, sizeof(d_hw));
    d_hw.bit_len = (uint32_t)bits;
    int ret = mpi_to_le_fixed(d, d_hw.input, bytelen);
    if (ret != 0)
    {
        return ret;
    }

    ECC_OPERAND hash_hw;
    memset(&hash_hw, 0, sizeof(hash_hw));
    hash_hw.bit_len = (uint32_t)(blen * 8);

    memcpy(hash_hw.input, (void *)buf, blen);

    ECDSA_SIGNATURE sig_hw;
    memset(&sig_hw, 0, sizeof(sig_hw));

#if (ECDSA_ALT_DEBUG_ENABLE== 1)
    APP_PRINT_ERROR1(" mbedtls_ecdsa_sign1  hash %b", TRACE_BINARY(bytelen, hash_hw.input));
    APP_PRINT_ERROR1(" mbedtls_ecdsa_sign1  d_hw %b", TRACE_BINARY(bytelen, d_hw.input));
#endif

    if (!hw_ecdsa_sign(&grp_hw, &d_hw, &sig_hw, &hash_hw))
    {
        return RET_HW_FAIL;
    }

#if (ECDSA_ALT_DEBUG_ENABLE== 1)
    APP_PRINT_ERROR1(" mbedtls_ecdsa_sign1  r %b", TRACE_BINARY(bytelen, sig_hw.r));
    APP_PRINT_ERROR1(" mbedtls_ecdsa_sign1  s %b", TRACE_BINARY(bytelen, sig_hw.s));
#endif

    ret = le_fixed_to_mpi(r, sig_hw.r, bytelen);
    if (ret != 0)
    {
        return ret;
    }

    ret = le_fixed_to_mpi(s, sig_hw.s, bytelen);

    if (ret != 0)
    {
        return ret;
    }

    return 0;
}

int mbedtls_ecdsa_verify(mbedtls_ecp_group *grp,
                         const unsigned char *hash, size_t hlen,
                         const mbedtls_ecp_point *Q,
                         const mbedtls_mpi *r, const mbedtls_mpi *s)
{
    if (grp == NULL || hash == NULL || Q == NULL || r == NULL || s == NULL)
    {
        return MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
    }

    int curve_sel = map_group_id_to_sel(grp->id);
    if (curve_sel < 0)
    {
        return MBEDTLS_ERR_ECP_FEATURE_UNAVAILABLE;
    }

    int bits = 0;
    size_t bytelen = 0;
    if (sel_to_bits_and_bytes(curve_sel, &bits, &bytelen) != 0)
    {
        return MBEDTLS_ERR_ECP_FEATURE_UNAVAILABLE;
    }

    ECC_GROUP grp_hw;
    if (hw_curve_init(&grp_hw, curve_sel, bits) != 0)
    {
        return MBEDTLS_ERR_ECP_FEATURE_UNAVAILABLE;
    }

    ECC_POINT Q_hw;
    memset(&Q_hw, 0, sizeof(Q_hw));
    int ret = ecp_point_to_le(Q, Q_hw.x, Q_hw.y, bytelen);
    if (ret != 0)
    {
        return ret;
    }

    ECDSA_SIGNATURE sig_hw;
    memset(&sig_hw, 0, sizeof(sig_hw));
    ret = mpi_to_le_fixed(r, sig_hw.r, bytelen);
    if (ret != 0) { return ret; }
    ret = mpi_to_le_fixed(s, sig_hw.s, bytelen);
    if (ret != 0) { return ret; }


    ECC_OPERAND hash_hw;
    memset(&hash_hw, 0, sizeof(hash_hw));
    hash_hw.bit_len = (uint32_t)(hlen * 8);

//    hw: pke The message hash with big endian
//    be_to_le(hash, hash_hw.input, hlen);
    memcpy(hash_hw.input, (void *)hash, hlen);

#if (ECDSA_ALT_DEBUG_ENABLE== 1)
    APP_PRINT_ERROR1(" mbedtls_ecdsa_verify1  hash %b", TRACE_BINARY(bytelen, hash_hw.input));
    APP_PRINT_ERROR1(" mbedtls_ecdsa_verify1  Qx %b", TRACE_BINARY(bytelen, Q_hw.x));
    APP_PRINT_ERROR1(" mbedtls_ecdsa_verify1  Qy %b", TRACE_BINARY(bytelen, Q_hw.y));
    APP_PRINT_ERROR1(" mbedtls_ecdsa_verify1  r %b", TRACE_BINARY(bytelen, sig_hw.r));
    APP_PRINT_ERROR1(" mbedtls_ecdsa_verify1  s %b", TRACE_BINARY(bytelen, sig_hw.s));
#endif

    if (!hw_ecdsa_verify(&grp_hw, &Q_hw, &sig_hw, &hash_hw))
    {
        return MBEDTLS_ERR_ECP_VERIFY_FAILED;
    }

    return 0;
}

#endif /* CONFIG_SOC_SERIES_RTL87X3G */
