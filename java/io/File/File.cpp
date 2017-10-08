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
//    return result;
//}
//
//boolean File::mkdir() {
//    int exitCode = 0;
//    String command = "mkdir " + this->path;
//
//    try {
//        File::executeCommand(command, exitCode);
//    } catch (RuntimeException &exception) {
//        if (exitCode == 127) {
//            String message = (String) "cannot create directory '"
//                             + this->path
//                             + (String) "': File exists";
//            throw RuntimeException(message);
//        } else {
//            throw RuntimeException(exception.toString());
//        }
//    }
//
//    return !exitCode;
//}
//
//boolean File::mkdirs() {
//    try {
//        return File::mkdir();
//    } catch (RuntimeException &exception) {
//        throw RuntimeException(exception.toString());
//    }
//}
//
//boolean File::createNewFile() {
////    SecurityManager security = System.getSecurityManager();
////    if (security != null)
////        security.checkWrite(path);
////    if (isInvalid()) {
////        throw new IOException("Invalid file path");
////    }
////    return fs.createFileExclusively(path);
//
//    // type NUL > EmptyFile.txt
//}
//
//#endif