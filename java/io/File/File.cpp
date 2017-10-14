/**
 * Copyright (c) 2016 Food Tiny Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "File.hpp"

#ifdef WINDOWS

using namespace Java::Io;
using namespace Java::Lang;

File::File(String pathName) {
    this->path = File::normalize(pathName);
    this->prefixLength = File::getPrefixLength(this->path);
}

String File::normalize(String pathName) {
    int lengthPathName = pathName.length();
    char previousChar = 0;

    for (int index = 0; index < lengthPathName; index++) {
        char currentChar = pathName.charAt(index);
        if ((previousChar == '/') && (currentChar == '/'))
            return File::normalize(pathName, lengthPathName, index - 1);
        previousChar = currentChar;
    }

    if (previousChar == '/')
        return File::normalize(pathName, lengthPathName, lengthPathName - 1);

    return pathName;
}

String File::normalize(String pathName, int length, int off) {
    if (length == 0)
        return pathName;

    int lengthPathName = length;

    while ((lengthPathName > 0)
           && (pathName.charAt(lengthPathName - 1) == '/'))
        lengthPathName--;

    if (lengthPathName == 0)
        return "/";

    StringBuffer stringBuffer = StringBuffer(pathName.length());

    if (off > 0)
        stringBuffer.append(pathName.subString(0, off));

    char prevChar = 0;

    for (int index = off; index < lengthPathName; index++) {
        char currentChar = pathName.charAt(index);

        if ((prevChar == '/') && (currentChar == '/'))
            continue;

        stringBuffer.append(currentChar);
        prevChar = currentChar;
    }

    return stringBuffer.toString();
}

int File::getPrefixLength(String pathName) {
    if (pathName.length() == 0)
        return 0;

    return (pathName.charAt(0) == '/') ? 1 : 0;
}

String File::toString() {
    return getPath();
}

String File::getPath() {
    return this->path;
}

int File::compareTo(const File &pathname) const {
//    return fs.compare(this, pathname);
}

boolean File::mkdir() {
    return (boolean) !::mkdir(this->path.toString(),
                              S_IRWXU | S_IRWXG);
}

boolean File::mkdirs() {
    char holdString[PATH_MAX];
    string pointerChar = NULL;
    size_t length;

    ::snprintf(holdString,
               sizeof(holdString),
               "%s",
               this->path.toString());

    length = ::strlen(holdString);

    if (holdString[length - 1] == '/')
        holdString[length - 1] = 0;

    for (pointerChar = holdString + 1; *pointerChar; pointerChar++)
        if (*pointerChar == '/') {
            *pointerChar = 0;
            ::mkdir(holdString, S_IRWXU | S_IRWXG);
            *pointerChar = '/';
        }

    return !::mkdir(holdString, S_IRWXU | S_IRWXG);
}

boolean File::createNewFile() {
    return !::mknod(this->path.toString(),
                    S_IFREG | S_IRWXU | S_IRWXG,
                    0);
}

boolean File::isDirectory() {
    struct stat fileStatitics;

    if (!File::exists())
        return false;

    stat(this->path.toString(), &fileStatitics);

    return S_ISDIR(fileStatitics.st_mode);
}

boolean File::isFile() {
    struct stat fileStatitics;

    if (!File::exists())
        return false;

    stat(this->path.toString(), &fileStatitics);

    return S_ISREG(fileStatitics.st_mode);
}

int deleteEntry(const_string filePath,
                const struct stat *fileStatitics,
                int typeFlag,
                struct FTW *structFTW) {
    remove(filePath);

    return 0;           /* To tell nftw() to continue */
}

boolean File::deletes() {
    if (!File::exists())
        return false;

    return (boolean) !nftw(this->path.toString(),
                           deleteEntry,
                           64,
                           FTW_DEPTH | FTW_PHYS);
}

boolean File::exists() {
    struct stat fileStatitics;
    return stat(this->path.toString(), &fileStatitics) == 0;
}

//boolean File::canExecute() {
//    struct stat fileStatitics;
//
//    if (!File::exists())
//        return false;
//
//    stat(this->path.toString(), &fileStatitics);
//
//    std::cout << "\n\n==== Can execute ====\n\n"
//         << (fileStatitics.st_mode & S_IEXEC);
//
//    return (fileStatitics.st_mode & S_IEXEC);
//
////    return access(this->path.toString(), X_OK) == 0;
//}

#endif