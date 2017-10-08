///**
// * Copyright (c) 2016 Food Tiny Project. All rights reserved.
// *
// * Redistribution and use in source and binary forms, with or without
// * modification, are permitted provided that the following conditions are met:
// *
// * Redistributions of source code must retain the above copyright
// * notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above
// * copyright notice, this list of conditions and the following disclaimer
// * in the documentation and/or other materials provided with the
// * distribution.
// *
// * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// */
//
//#include "File.hpp"
//
//#ifdef WINDOWS
//
//using namespace Java::Io;
//using namespace Java::Lang;
//
//File::File(String pathName) {
////    if (pathName == null) {
////        throw NullPointerException();
////    }
//    this->path = File::normalize(pathName);
//    this->prefixLength = File::getPrefixLength(this->path);
//}
//
//String File::normalize(String pathName) {
//    int lengthPathName = pathName.length();
//    char prevChar = 0;
//
//    for (int index = 0; index < lengthPathName; index++) {
//        char currentChar = pathName.charAt(index);
//        if ((prevChar == '/') && (currentChar == '/'))
//            return normalize(pathName, lengthPathName, index - 1);
//        prevChar = currentChar;
//    }
//
//    if (prevChar == '/')
//        return normalize(pathName, lengthPathName, lengthPathName - 1);
//
//    return pathName;
//}
//
//String File::normalize(String pathName, int length, int off) {
//    if (length == 0)
//        return pathName;
//
//    int lengthPathName = length;
//
//    while ((lengthPathName > 0)
//           && (pathName.charAt(lengthPathName - 1) == '/'))
//        lengthPathName--;
//
//    if (lengthPathName == 0)
//        return "/";
//
//    StringBuffer stringBuffer = StringBuffer(pathName.length());
//
//    if (off > 0)
//        stringBuffer.append(pathName.subString(0, off));
//
//    char prevChar = 0;
//
//    for (int index = off; index < lengthPathName; index++) {
//        char currentChar = pathName.charAt(index);
//
//        if ((prevChar == '/') && (currentChar == '/'))
//            continue;
//
//        stringBuffer.append(currentChar);
//        prevChar = currentChar;
//    }
//
//    return stringBuffer.toString();
//}
//
//int File::getPrefixLength(String pathName) {
//    if (pathName.length() == 0)
//        return 0;
//
//    return (pathName.charAt(0) == '/') ? 1 : 0;
//}
//
//String File::toString() {
//    return getPath();
//}
//
//String File::getPath() {
//    return this->path;
//}
//
//int File::compareTo(const File &pathname) const {
////    return fs.compare(this, pathname);
//}
//
//String File::executeCommand(String command, int &exitCode) {
//    char buffer[128];
//    std::string result = "";
//    FILE *pipe = popen(command.toString(), "r");
//
//    while (!feof(pipe)) {
//        if (fgets(buffer, 128, pipe) != NULL)
//            result += buffer;
//    }
//
//    exitCode = WEXITSTATUS(pclose(pipe));
//
//    if (exitCode) {
//        String message = ": can not run command";
//        throw RuntimeException(command + message);
//    }
//
//    exitCode = !exitCode;
//
//    return result;
//}
//
//String File::executeCommand(String command) {
//    char buffer[128];
//    std::string result = "";
//    FILE *pipe = popen(command.toString(), "r");
//
//    while (!feof(pipe)) {
//        if (fgets(buffer, 128, pipe) != NULL)
//            result += buffer;
//    }
//
//    int exitCode = WEXITSTATUS(pclose(pipe));
//
//    if (exitCode) {
//        String message = ": can not run command";
//        throw RuntimeException(command + message);
//    }
//
//    return result;
//}
//
//boolean File::mkdirFile() {
//    return !mkdir(this->path.toString(), S_IRWXU | S_IRWXG);
//}
//
//boolean File::mkdirs() {
//    char holdString[256];
//    string p = NULL;
//    size_t len;
//
//    snprintf(holdString, sizeof(holdString),"%s", this->path.toString());
//    len = strlen(holdString);
//
//    if(holdString[len - 1] == '/')
//        holdString[len - 1] = 0;
//
//    for(p = holdString + 1; *p; p++)
//        if(*p == '/') {
//            *p = 0;
//            mkdir(holdString, S_IRWXU);
//            *p = '/';
//        }
//
//    return !mkdir(holdString, S_IRWXU);
//
////    if (!dir) {
////        errno = EINVAL;
////        return 1;
////    }
////
////    if (strlen(dir) == 1 && dir[0] == '/')
////        return 0;
////
////    mkpath(dirname(strdupa(dir)), mode);
////
////    return mkdir(dir, mode);
//
////#include <string.h>
////#include <sys/stat.h>
////#include <unistd.h>
////#include <limits.h>
//
////    static void mkdirRecursive(const char *path, mode_t mode) {
////        char opath[PATH_MAX];
////        char *p;
////        size_t len;
////
////        strncpy(opath, path, sizeof(opath));
////        opath[sizeof(opath) - 1] = '\0';
////        len = strlen(opath);
////        if (len == 0)
////            return;
////        else if (opath[len - 1] == '/')
////            opath[len - 1] = '\0';
////        for(p = opath; *p; p++)
////            if (*p == '/') {
////                *p = '\0';
////                if (access(opath, F_OK))
////                    mkdir(opath, mode);
////                *p = '/';
////            }
////        if (access(opath, F_OK))         /* if path is not terminated with / */
////            mkdir(opath, mode);
////    }
//}
//
//boolean File::createNewFile() {
//    return !mknod(this->path.toString(),
//                  S_IFREG | S_IRWXU | S_IRWXG,
//                  0);
//}
//
//boolean File::isDirectory() {
////    String command = (String) "ls -l " + this->path;
////    String resultExecuteCommand = File::executeCommand(command);
////
////    return resultExecuteCommand.charAt(0) != '-';
//    struct stat fileStatus;
//
//    if (stat(this->path.toString(), &fileStatus) != -1) {
//        if (S_ISDIR(fileStatus.st_mode) != 0) {
//            printf("%s is a directory", this->path.toString());
//            return true;
//        } else {
//            printf("%s is not a directory", this->path.toString());
//            return false;
//        }
//    }
//}
//
//boolean File::isFile() {
////    String command = (String) "ls -l " + this->path;
////    String resultExecuteCommand = File::executeCommand(command);
////
////    return resultExecuteCommand.charAt(0) == '-';
//
//    struct stat fileStatus;
//
//    if (stat(this->path.toString(), &fileStatus) != -1) {
//        if (S_ISREG(fileStatus.st_mode) != 0) {
//            printf("%s is a file", this->path.toString());
//        } else {
//            printf("%s is not a file", this->path.toString());
//        }
//    }
//}
//
//boolean File::deletes() {
////#define _XOPEN_SOURCE 500
////#include <stdio.h>
////#include <ftw.h>
////#include <unistd.h>
////
////    int unlink_cb(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf)
////    {
////        int rv = remove(fpath);
////
////        if (rv)
////            perror(fpath);
////
////        return rv;
////    }
////
////    int rmrf(char *path)
////    {
////        return nftw(path, unlink_cb, 64, FTW_DEPTH | FTW_PHYS);
////    }
//}
//
//#endif