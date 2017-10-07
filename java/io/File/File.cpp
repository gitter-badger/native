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
//using namespace Java::Io;
//using namespace Java::Lang;
//
//File::File(String pathName) {
////    if (pathName == null) {
////        throw new NullPointerException();
////    }
//    this->path = File::normalize(pathName);
//    this->prefixLength = File::getPrefixLength(this->path);
//}
//
//String File::normalize(String pathName) {
//    int lengthPathName = pathName.length();
//    char prevChar = 0;
//    for (int index = 0; index < lengthPathName; index++) {
//        char currentChar = pathName.charAt(index);
//        if ((prevChar == '/') && (currentChar == '/'))
//            return normalize(pathName, lengthPathName, index - 1);
//        prevChar = currentChar;
//    }
//    if (prevChar == '/')
//        return normalize(pathName, lengthPathName, lengthPathName - 1);
//    return pathName;
//}
//
//String File::normalize(String pathName, int len, int off) {
//    if (len == 0)
//        return pathName;
//    int lengthPathName = len;
//    while ((lengthPathName > 0) && (pathName.charAt(lengthPathName - 1) == '/'))
//        lengthPathName--;
//    if (lengthPathName == 0)
//        return "/";
//    StringBuffer stringBuffer = StringBuffer(pathName.length());
//    if (off > 0)
//        stringBuffer.append(pathName.subString(0, off));
//    char prevChar = 0;
//    for (int index = off; index < lengthPathName; index++) {
//        char currentChar = pathName.charAt(index);
//        if ((prevChar == '/') && (currentChar == '/'))
//            continue;
//        stringBuffer.append(currentChar);
//        prevChar = currentChar;
//    }
//    return stringBuffer.toString();
//}
//
//int File::getPrefixLength(String pathName) {
//    if (pathName.length() == 0)
//        return 0;
//    return (pathName.charAt(0) == '/') ? 1 : 0;
//}