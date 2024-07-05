#!/usr/bin/env python3

# Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.

import sys
import xml.dom.minidom
import subprocess
import os
import copy
from pathlib import Path

cppcheck = os.environ.get("CPPCHECK_PATH") or r'./cppcheck/build/bin/cppcheck'


def git(*args, cwd=None, ignore_non_zero=False):
    # Helper for running a Git command. Returns the rstrip()ed stdout output.
    # Called like git("diff"). Exits with SystemError (raised by sys.exit()) on
    # errors if 'ignore_non_zero' is set to False (default: False). 'cwd' is the
    # working directory to use (default: current directory).

    git_cmd = ("git",) + args
    try:
        cp = subprocess.run(git_cmd, capture_output=True, cwd=cwd)
    except OSError as e:
        print(f"failed to run '{git_cmd}': {e}")

    if not ignore_non_zero and (cp.returncode or cp.stderr):
        print(f"'{git_cmd}' exited with status {cp.returncode} and/or "
            f"wrote to stderr.\n"
            f"==stdout==\n"
            f"{cp.stdout.decode('utf-8')}\n"
            f"==stderr==\n"
            f"{cp.stderr.decode('utf-8')}\n")

    return cp.stdout.decode("utf-8").rstrip()

class CICheck():
    def __init__(self, subgit_repo_path, **kwargs):
        self.subgit_repo_path = subgit_repo_path

    def do_commit_check(self):
        check_commit_message_res, check_commit_message_msg = self.check_commit_message(self.subgit_repo_path)
        if not check_commit_message_res:
            return check_commit_message_res, r'[Commit Check Error]' + " " + check_commit_message_msg

        return check_commit_message_res, check_commit_message_msg

    def check_commit_message(self, repo):
        # Commit string is capsulated in '', strip it
        commit_title = git('log', '-1', 'HEAD', "--pretty='%s'", cwd=repo).strip('\'')
        commit_body = git('log', '-1', 'HEAD', "--pretty='%b'", cwd=repo).strip('\'')
        commit_message = git('log', '-1', 'HEAD', "--pretty='%B'", cwd=repo).strip('\'')
        commit_id = git('log', '-1', 'HEAD', "--pretty='%H'", cwd=repo).strip("'")
        print(r'{}: {}'.format(commit_id, commit_title))

        # Check rule1: Separate subject from body with a blank line
        if commit_title != commit_message.split('\n', maxsplit=1)[0]:
            return False, 'no blank line between title and body'
        
        # Check rule2: Limit the subject line to 72 characters
        if len(commit_title) > 72 or len(commit_title) == 0:
            return False, 'invalid subject line len {} exceeds max 72 characters'.format(len(commit_title))

        # Check rule3: Capitalize first word of the subject line
        if commit_title.lstrip(' ')[0].islower():
            return False, 'first word \'{}\' of subject line not capitalized'.format(commit_title.split(maxsplit=1)[0])

        # Check rule4: Do not end the subject line with a period
        if commit_title.endswith('.'):
            return False, 'subject line should not end with a period'

        # Check rule5: Use the imperative mood in the subject line (!!!not checked)

        # Check rule6: Wrap the body at 72 characters
        for l in commit_body.split('\n'):
            if len(l) > 72:
                return False, 'body line \'{}\' len {} not wrapped at 72 characters'.format(l, len(l))
        return True, ""

    def check_file_encodeing(self, changed_file_list, file_dir=None):
        for f in changed_file_list:
            if f.endswith(('.c', '.h', '.s', '.txt', '.html', '.md')):
                f = os.path.join(file_dir, f) if file_dir else f
                with open(f, 'rb') as fd:
                    for i, line in enumerate(fd, 1):
                        try:
                            line.decode('utf-8')
                            line.decode('gbk')
                            line.decode('cp950')
                        except UnicodeDecodeError as e:
                            return False, 'file {} encoding error {}, line {}, column {}'.format(
                                f, e.reason, i, e.start + 1)
        print("Check file encoding pass")
        return True, ""
    

    def GetAstyleVerstion(self):
        try:
            version_astyle = subprocess.check_output([r'astyle', r'--version'],
                                                    universal_newlines=True, stderr=subprocess.STDOUT)
        except subprocess.CalledProcessError as e:
            return False, 'astyle version error: ->\n {}'.format(e.output)
        print('GetAstyleVerstion -> {}'.format(version_astyle))
        return True, version_astyle
    

    def RunAStyle(self, file_list):
        file_list = list(filter(lambda x: x.endswith(('.c', '.h')), file_list))
        for i in range(0, len(file_list), 50):
            cmd_astyle = [r'astyle',
                            r'-A1', r'-z2', r'-xC100', r'-xL', r'-j',
                            r'-O', r'-o', r'-s4', r'-K', r'-m0',
                            r'-M80', r'-w', r'-c', r'-H', r'-U',
                            r'-p', r'-Z', r'-n', r'-k3', r'--dry-run'] + file_list[i:i+50]
            print('check commit files: astyle command {}'.format(cmd_astyle), flush=True)
            try:
                output_astyle = subprocess.check_output(cmd_astyle, universal_newlines=True)
            except subprocess.CalledProcessError as e:
                return False, 'astyle output error', 'ERROR: ->\n {}'.format(e)
            except Exception as e:
                return False, 'astyle output error', 'ERROR: ->\n {}'.format(e)
            if 'Formatted ' in output_astyle:
                return False, 'astyle output error(Formatted files), ERROR: ->\n {}'.format(output_astyle)
            print('RunAStyle: astyle output pass ->\n{}'.format(output_astyle), flush=True)

        return True, ""


    def GetCppCheckerVersion(self):
        try:
            version_cppcheck = subprocess.check_output([cppcheck, r'--version'],
                                                    universal_newlines=True, stderr=subprocess.STDOUT)
        except subprocess.CalledProcessError as e:
            return False, 'cppcheck version error: ->\n {}'.format(e.output)
        print('GetCppCheckerVersion -> {}'.format(version_cppcheck))
        return True, version_cppcheck


    def RunCppCheck(self, file_list):
        print("RunCppCheck file_list -> ", file_list)
        c_files = list(filter(lambda x: x.endswith('.c') or x.endswith('.cpp'), file_list))
        # Split c files or raise FileNotFoundError: [WinError 206] The filename or extension is too long
        for i in range(0, len(c_files), 50):
            cmd_cppcheck = [cppcheck,
                            r'--error-exitcode=1',
                            r'--force',
                            r'--inline-suppr',
                            r'--enable=warning,performance,portability',
                            r'--xml']

            print(".cppcheck_suppressions: ", os.path.exists(r'.cppcheck_suppressions'))
            if os.path.exists(r'.cppcheck_suppressions'):
                cmd_cppcheck.append("--suppressions-list=.cppcheck_suppressions")

            cmd_cppcheck += c_files[i:i+50]
            print('RunCppCheck: cppcheck command {}'.format(cmd_cppcheck), flush=True)
            try:
                output_cppcheck = subprocess.check_output(cmd_cppcheck, universal_newlines=True, stderr=subprocess.STDOUT)
            except subprocess.CalledProcessError as e:
                output_xml = e.output
                DOMTree = xml.dom.minidom.parseString(output_xml)
                collection = DOMTree.documentElement
                errors = collection.getElementsByTagName("error")
                outputstr = ""
                for error in errors:
                    print(error.toxml())
                for error in errors:
                    outputstr += "\n"
                    error_id = error.getAttribute("id")
                    outputstr += "[id]{}".format(error_id)
                    error_seveity = error.getAttribute("severity")
                    outputstr += "\n[severity]{}".format(error_seveity)
                    error_msg = error.getAttribute("msg")
                    outputstr += "\n[msg]{}".format(error_msg)
                    error_verbose = error.getAttribute("verbose")
                    outputstr += "\n[detail]{}".format(error_verbose)
                    error_file_path = error.getAttribute("file0")
                    if error_file_path:
                        outputstr += "\n[src file]{}".format(error_file_path)
                    locations = error.getElementsByTagName('location')
                    symbols = error.getElementsByTagName('symbol')
                    symbols_str = ""
                    if symbols:
                        for symbol in symbols:
                            symbols_str += symbol.firstChild.nodeValue
                    if symbols_str:
                        outputstr += "\n[symbols]{}".format(symbols_str)
                    detail = list()

                    for location in locations:
                        location_info = "[" + location.getAttribute("file").replace("\\","/") + "][line]" + location.getAttribute("line") + "[column]" + location.getAttribute("column")
                        if location.getAttribute("info"):
                            location_info += "[info]" + location.getAttribute("info")
                        detail.append(location_info)
                    outputstr += "\n" + "\n".join(detail) + "\n"

                return False, 'cppcheck output error: ->\n {}'.format(outputstr)
            print('RunCppCheck: cppcheck output pass ->\n{}'.format(output_cppcheck))
        return True, ""


    def get_check_files_exclude_ignore(self, all_files_changed_exclude_delete, ignore_list, des=""):
        if ignore_list is None:
            return  copy.deepcopy(all_files_changed_exclude_delete)
        res = list()
        for f in all_files_changed_exclude_delete:
            if any(f.startswith(ignore_file) for ignore_file in ignore_list):
                print("Skip {} for file check {}".format(f, des))
                continue
            res.append(f)
        return res
    

    def check_commit_files(self):
        try:
            from ignore_check_file import ignore_file_encoding as ignore_file_encoding_ins
        except Exception as e:
            ignore_file_encoding_ins = None
        try:
            from ignore_check_file import ignore_file_cpp_astyle_check as ignore_file_cpp_astyle_check_ins
        except Exception as e:
            ignore_file_cpp_astyle_check_ins = None

        all_files_need_to_check_encoding = self.get_check_files_exclude_ignore(change_files, ignore_file_encoding_ins, "encoding")
        check_file_encodeing_res, check_file_encodeing_msg = self.check_file_encodeing(all_files_need_to_check_encoding)
        if not check_file_encodeing_res:
            return check_file_encodeing_res, check_file_encodeing_msg

        all_files_need_to_check_cpp_astyle = self.get_check_files_exclude_ignore(change_files, ignore_file_cpp_astyle_check_ins, "cpp astyle")
        cppCheckerVersion_res, cppCheckerVersion_msg = self.GetCppCheckerVersion()
        if not cppCheckerVersion_res:
            return cppCheckerVersion_res, cppCheckerVersion_msg

        runCppCheck_res, runCppCheck_msg = self.RunCppCheck(all_files_need_to_check_cpp_astyle)
        if not runCppCheck_res:
            return runCppCheck_res, runCppCheck_msg
        getAstyleVerstion_res, getAstyleVerstion_msg = self.GetAstyleVerstion()
        if not getAstyleVerstion_res:
            return getAstyleVerstion_res, getAstyleVerstion_msg

        runAStyle_res, runAStyle_msg = self.RunAStyle(all_files_need_to_check_cpp_astyle)
        if not runAStyle_res:
            return runAStyle_res, runAStyle_msg

        return True, ""


if __name__ == "__main__":
    global REPO_BASE
    REPO_BASE = os.environ.get('REPO_BASE')
    if not REPO_BASE:
        REPO_BASE = str(Path(__file__).resolve().parents[2])
        os.environ['REPO_BASE'] = REPO_BASE
    change_files = os.environ.get("ALL_CHANGED_FILES", "").split(" ")
    ci_check = CICheck(subgit_repo_path=REPO_BASE)
    #1.0 Check commit message
    commit_check_res, commit_check_message = ci_check.do_commit_check()
    #commit_check_res, commit_check_message = True, ""
    if commit_check_res:
        print("check commit message pass")
    else:
        print(commit_check_message)
        sys.exit('check commit message failed')
    #2.0 check_commit_files
    check_commit_files_result, check_commit_files_message = ci_check.check_commit_files()
    if not check_commit_files_result:
        file_check_message = "[Static Check Error] " + check_commit_files_message
        sys.exit('check commit files failed\n{}'.format(file_check_message))
    else:
        print("check commit file pass")