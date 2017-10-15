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

using namespace Java::Io;

#ifdef WINDOWS

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
    try {
        return !::mknod(this->path.toString(),
                        S_IFREG | S_IRWXU | S_IRWXG,
                        0);
    } catch (Exception exception) {
        throw Exception("Cannot create file !");
    }
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

boolean File::canExecute() {
    struct stat fileStatitics;

    if (!File::exists())
        return false;

    stat(this->path.toString(), &fileStatitics);

    std::cout << "\n\n==== Can execute ====\n\n"
              << (access(this->path.toString(), X_OK) == 0);

    return (access(this->path.toString(), X_OK) == 0);
}

boolean File::setExecutable(boolean executable) {
    return setExecutable(executable, true);
}

boolean File::setExecutable(boolean executable, boolean ownerOnly) {
    struct stat fileStatitics;

    if (!File::exists())
        return false;

    stat(this->path.toString(), &fileStatitics);
    StringBuffer permissionString = File::permissionStringFormat(this->path);
    int mode;

    std::cout << "\n\n==== Set execute ====\n\n"
              << permissionString.toString();

    if (executable) {
        permissionString.replace(2, 3, "x");
        permissionString.replace(5, 6, "x");

        if (!ownerOnly) {
            permissionString.replace(8, 9, "x");
        }
    } else {
        permissionString.replace(2, 3, "-");
        permissionString.replace(5, 6, "-");

        if (!ownerOnly) {
            permissionString.replace(8, 9, "-");
        }
    }

    std::cout << "\n==After\n"
              << permissionString.toString();

    mode = File::stringFormatToPermission(permissionString);

    return (boolean) !chmod(this->path.toString(),
                            mode);
}

StringBuffer File::permissionStringFormat(String path) {
    struct stat fileStatitics;
    StringBuffer result;

    if (stat(path.toString(), &fileStatitics) == 0) {
        mode_t permission = fileStatitics.st_mode;
        (permission & S_IRUSR) ? result.append('r') : result.append('-');
        (permission & S_IWUSR) ? result.append('w') : result.append('-');
        (permission & S_IXUSR) ? result.append('x') : result.append('-');
        (permission & S_IRGRP) ? result.append('r') : result.append('-');
        (permission & S_IWGRP) ? result.append('w') : result.append('-');
        (permission & S_IXGRP) ? result.append('x') : result.append('-');
        (permission & S_IROTH) ? result.append('r') : result.append('-');
        (permission & S_IWOTH) ? result.append('w') : result.append('-');
        (permission & S_IXOTH) ? result.append('x') : result.append('-');
        return result;
    } else {
        return result.append(strerror(errno));
    }
}

int File::stringFormatToPermission(StringBuffer permissionStringFormat) {
    int permission = 0;

    permission |= (permissionStringFormat.charAt(0) == 'r') ? S_IRUSR : 0;
    permission |= (permissionStringFormat.charAt(1) == 'w') ? S_IWUSR : 0;
    permission |= (permissionStringFormat.charAt(2) == 'x') ? S_IXUSR : 0;
    permission |= (permissionStringFormat.charAt(3) == 'r') ? S_IRGRP : 0;
    permission |= (permissionStringFormat.charAt(4) == 'w') ? S_IWGRP : 0;
    permission |= (permissionStringFormat.charAt(5) == 'x') ? S_IXGRP : 0;
    permission |= (permissionStringFormat.charAt(6) == 'r') ? S_IROTH : 0;
    permission |= (permissionStringFormat.charAt(7) == 'w') ? S_IWOTH : 0;
    permission |= (permissionStringFormat.charAt(8) == 'x') ? S_IXOTH : 0;

    return permission;
}

boolean File::canRead() {
    struct stat fileStatitics;

    if (!File::exists())
        return false;

    stat(this->path.toString(), &fileStatitics);

    std::cout << "\n\n==== Can execute ====\n\n"
              << (access(this->path.toString(), R_OK) == 0);

    return (access(this->path.toString(), R_OK) == 0);
}

boolean File::canWrite() {
    struct stat fileStatitics;

    if (!File::exists())
        return false;

    stat(this->path.toString(), &fileStatitics);

    std::cout << "\n\n==== Can write ====\n\n"
              << (access(this->path.toString(), W_OK) == 0);

    return (access(this->path.toString(), W_OK) == 0);
}

boolean File::setReadOnly() {
    if (!File::exists())
        return false;

    return (File::setReadable(true, false)
            && File::setWritable(false, false)
            && File::setExecutable(false, false));
}

boolean File::setReadable(boolean readable, boolean ownerOnly) {
    struct stat fileStatitics;

    if (!File::exists())
        return false;

    stat(this->path.toString(), &fileStatitics);
    StringBuffer permissionString = File::permissionStringFormat(this->path);
    int mode;

    std::cout << "\n\n==== Set readable ====\n\n"
              << permissionString.toString();

    if (readable) {
        permissionString.replace(0, 1, "r");
        permissionString.replace(3, 4, "r");

        if (!ownerOnly) {
            permissionString.replace(6, 7, "r");
        }
    } else {
        permissionString.replace(0, 1, "-");
        permissionString.replace(3, 4, "-");

        if (!ownerOnly) {
            permissionString.replace(6, 7, "-");
        }
    }

    std::cout << "\n==After\n"
              << permissionString.toString();

    mode = File::stringFormatToPermission(permissionString);

    return (boolean) !chmod(this->path.toString(),
                            mode);
}

boolean File::setReadable(boolean readable) {
    return File::setReadable(readable, true);
}

boolean File::setWritable(boolean writable) {
    return setWritable(writable, true);
}


boolean File::setWritable(boolean writable, boolean ownerOnly) {
    struct stat fileStatitics;

    if (!File::exists())
        return false;

    stat(this->path.toString(), &fileStatitics);
    StringBuffer permissionString = File::permissionStringFormat(this->path);
    int mode;

    std::cout << "\n\n==== Set writable ====\n\n"
              << permissionString.toString();

    if (writable) {
        permissionString.replace(1, 2, "w");
        permissionString.replace(4, 4, "w");

        if (!ownerOnly) {
            permissionString.replace(7, 8, "w");
        }
    } else {
        permissionString.replace(1, 2, "-");
        permissionString.replace(4, 5, "-");

        if (!ownerOnly) {
            permissionString.replace(7, 8, "-");
        }
    }

    std::cout << "\n==After\n"
              << permissionString.toString();

    mode = File::stringFormatToPermission(permissionString);

    return (boolean) !chmod(this->path.toString(),
                            mode);
}

int File::compareTo(const File &pathname) const {
    return ((this->path > pathname.path) ? 1
                                         : (this->path == pathname.path) ? 0 : -1);
}

File File::createTempFile(String prefix, String suffix) {
    return createTempFile(prefix, suffix, (String) "");
}

// TODO(thoangminh): check it
File File::createTempFile(String prefix,
                          String suffix,
                          File directory) {
    if (prefix.length() < 3)
        throw IllegalArgumentException("Prefix string too short");
    if (suffix.isEmpty())
        suffix = ".tmp";

    String directoryStringFormat
            = (directory.toString() == "")
              ? getenv("TEMP")
              : directory.toString();

    FILE *temporaryFile = std::tmpfile();
    String nameTempFile = std::to_string(fileno(temporaryFile));

    String oldName = directoryStringFormat + (string) "/" + nameTempFile;
    String newTempName = directoryStringFormat
                         + (string) "/"
                         + prefix
                         + nameTempFile
                         + suffix;

    std::cout << "\n\ndirectoryStringFormat: " << directoryStringFormat.toString();
    std::cout << "\n\ndirectory: " << directory.toString().toString();
    std::cout << "\n\noldName: " << oldName.toString();
    std::cout << "\n\nnewTempName: " << newTempName.toString();

    File result = File(newTempName);
    if (!result.createNewFile())
        throw Exception("Cannot create temp file !");

    return result;
}

boolean File::equals(File inputFile) {
    return this->path == inputFile.path;
}

String File::getCanonicalPath() {
    string holdResult = realpath(this->path.toString(), NULL);
    String result = holdResult;
    free(holdResult);

    return result;
}

File File::getCanonicalFile() {
    return File(File::getCanonicalPath());
}

long File::lastModified() {
    struct stat fileStatitics;

    if (!File::exists())
        return 0;

    stat(this->path.toString(), &fileStatitics);

    return fileStatitics.st_mtim.tv_sec;
}

long File::length() {
    if (!File::exists())
        return 0;

    using namespace std;

    streampos begin;
    streampos end;

    ifstream myFile(this->path.toString(), ios::binary);

    begin = myFile.tellg();
    myFile.seekg(0, ios::end);
    end = myFile.tellg();

    myFile.close();

    cout << "size is: " << (end - begin) << " bytes.\n";
    return (long) (end - begin);
}

//ArrayList<String> File::list() {
//    glob_t glob_result;
//
//    glob(this->path.toString(), GLOB_TILDE, NULL, &glob_result);
//
//    for (unsigned int i = 0; i < glob_result.gl_pathc; ++i) {
//        std::cout << "aaaa" << glob_result.gl_pathv[i] << "\n\n";
//    }
//}


//boolean File::renameTo(File destinationFile) {
//    if (!destinationFile.canWrite()
//        || destinationFile.path.isEmpty()
//        || destinationFile.exists()
//        || !File::exists())
//        return false;

//    return rename(this->getCanonicalPath().toString(),
//                  destinationFile.getCanonicalPath().toString()) == 0;

//    return rename("java\\io\\\\File\\TestFolder\\HiddenFile.txt",
//                  "java\\io\\\\File\\TestFolder\\a.txt") == 0;
//}

#endif