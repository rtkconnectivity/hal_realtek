#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "zephyr/kernel.h"

#include "os_mem.h"
#include "os_msg.h"
#include "trace.h"
bool osif_test_main(void)
{

    DBG_DIRECT("OSIF TEST BEGIN");
    /* mem */
    void *p = NULL;
    p =  os_mem_alloc(RAM_TYPE_DATA_ON, 16);
    DBG_DIRECT("alloc addr:%x", p);
    os_mem_free(p);

    p =  os_mem_alloc(RAM_TYPE_BUFFER_ON, 16);
    DBG_DIRECT("alloc addr:%x", p);
    os_mem_free(p);

    /* msg */
    struct test_msg
    {
        uint8_t id;
        uint8_t data[16];
    } msg;

#define MSG_NUM  10
    void *p_handle = NULL;
    if (os_msg_queue_create(&p_handle, MSG_NUM, sizeof(struct test_msg)) == true)
    {
        DBG_DIRECT("Message queue created successfully");
    }
    else
    {
        DBG_DIRECT("Message queue failed to create.");
    }
    uint32_t msg_num;

    DBG_DIRECT("Send item to message queue");
    msg.id = 1;
    msg.data[0] = 0;
    os_msg_send(p_handle, &msg, 0);

    os_msg_queue_peek(p_handle, &msg_num);
    DBG_DIRECT("Message queue used num:%x", msg_num);

    DBG_DIRECT("Receive the message queue item");
    if (os_msg_recv(p_handle, &msg, 0) == true)
    {
        DBG_DIRECT("Message item received successfully");
    }
    else
    {
        DBG_DIRECT("Message item failed to receive");
    }

    os_msg_queue_peek(p_handle, &msg_num);
    DBG_DIRECT("Message queue used num:%x", msg_num);

    os_msg_queue_delete(p_handle);

    return true;
}