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

// isHidden
#ifdef WINDOWS
#define boolean SOMETHING_ELSE
#include <windows.h>
#undef boolean
#endif

using namespace Java::Io;

File::File(String pathName) {
    this->path = File::normalize(pathName);
    this->prefixLength = File::getPrefixLength(this->path);
    File::updateFileStatitics();
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

String File::normalize(String pathName, int length, int offset) {
    if (length == 0)
        return pathName;

    int lengthPathName = length;

    while ((lengthPathName > 0)
           && (pathName.charAt(lengthPathName - 1) == '/'))
        lengthPathName--;

    if (lengthPathName == 0)
        return "/";

    StringBuffer stringBuffer = StringBuffer(pathName.length());

    if (offset > 0)
        stringBuffer.append(pathName.subString(0, offset));

    char prevChar = 0;

    for (int index = offset; index < lengthPathName; index++) {
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
    return (::mkdir(this->path.toString(),
                    S_IRWXU | S_IRWXG) == 0);
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
    if (!File::exists())
        return false;

    return S_ISDIR(this->fileStatitics.st_mode);
}

boolean File::isFile() {
    if (!File::exists())
        return false;

    return S_ISREG(this->fileStatitics.st_mode);
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

    return (nftw(this->path.toString(),
                 deleteEntry,
                 64,
                 FTW_DEPTH | FTW_PHYS) == 0);
}

boolean File::exists() {
    return stat(this->path.toString(), &this->fileStatitics) == 0;
}

boolean File::setExecutable(boolean executable) {
    return setExecutable(executable, true);
}

boolean File::setExecutable(boolean executable, boolean ownerOnly) {
    if (!File::exists())
        return false;

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

    return (chmod(this->path.toString(), mode) == 0);
}

StringBuffer File::permissionStringFormat(String path) {
    StringBuffer result;

    if (this->canGetStatitics) {
        mode_t permission = this->fileStatitics.st_mode;
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

boolean File::setReadOnly() {
    if (!File::exists())
        return false;

    return (File::setReadable(true, false)
            && File::setWritable(false, false)
            && File::setExecutable(false, false));
}

boolean File::setReadable(boolean readable, boolean ownerOnly) {
    if (!File::exists())
        return false;

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

    return (chmod(this->path.toString(), mode) == 0);
}

boolean File::setReadable(boolean readable) {
    return File::setReadable(readable, true);
}

boolean File::setWritable(boolean writable) {
    return setWritable(writable, true);
}

boolean File::setWritable(boolean writable, boolean ownerOnly) {
    if (!File::exists())
        return false;

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

    return (chmod(this->path.toString(), mode) == 0);
}

int File::compareTo(const File &pathname) const {
    return ((this->path > pathname.path) ? 1
                                         : (this->path == pathname.path) ? 0 : -1);
}

boolean File::equals(File inputFile) {
    return this->path == inputFile.path;
}

String File::getCanonicalPath() {
    string holdResult = realpath(this->path.toString(), NULL);
    String result = holdResult;

#ifdef WINDOWS
    result = result.replace('/', '\\');
#endif

    free(holdResult);
    return result;
}

File File::getCanonicalFile() {
    return File(File::getCanonicalPath());
}

long File::lastModified() {
    if (!File::exists())
        return 0;
    return this->lastModifiedTime;
}

long File::length() {
    if (!File::exists())
        return 0;

    using namespace std;

    streampos start;
    streampos end;

    ifstream myFile(this->path.toString(), ios::binary);

    start = myFile.tellg();
    myFile.seekg(0, ios::end);
    end = myFile.tellg();

    myFile.close();

    std::cout << "size is: " << (end - start) << " bytes.\n";
    return (long) (end - start);
}

String File::getAbsolutePath() {
    string holdResult = realpath(this->path.toString(), NULL);
    String result = holdResult;
    free(holdResult);
    return result;
}

File File::getAbsoluteFile() {
    return File(File::getAbsolutePath());
}

Array<String> File::list() {
    if (!File::isDirectory()
        || !File::exists()) {
        throw Exception("file is not a directory or not exist");
    }

    ArrayList<String> result;
    String holdString;

    DIR *directory;
    struct dirent *directoryEntity;

    if ((directory = opendir(File::getAbsolutePath().toString())) != NULL) {

        /* Get the files and directories name */
        while ((directoryEntity = readdir(directory)) != NULL) {
            String name = directoryEntity->d_name;

            if (name != "." &&  name != "..")
            result.add(name);
        }

        closedir(directory);
    } else {
        throw Exception("could not open directory");
    }

    return result.toArray();
}

void File::updateFileStatitics() {
    this->canGetStatitics
            = (stat(this->path.toString(), &this->fileStatitics) == 0);
    this->lastModifiedTime = this->fileStatitics.st_mtim.tv_sec;
}

boolean File::canRead() {
    if (!File::exists())
        return false;

    StringBuffer permissionString = File::permissionStringFormat(this->path);

    String currentUser = File::getCurrentUser();
    String currentGroup = File::getCurrentGroup();

    std::cout << "\n\n==== permissionString ====\n\n"
              << permissionString.toString();

    std::cout << "\n\n==== Get owner ====\n\n"
              << currentUser.toString()
              << "  "
              << File::getUser().toString();

    std::cout << "\n\n==== Get group ====\n\n"
              << currentGroup.toString()
              << "  "
              << File::getGroup().toString();

    // Owner permission
    if (File::getUser() == currentUser
        && permissionString.charAt(0) == 'r')
        return true;

    // Group permission
    if (File::getGroup() == currentGroup
        && permissionString.charAt(3) == 'r')
        return true;

    // Other permission
    if (permissionString.charAt(6) == 'r')
        return true;

    return false;
}

boolean File::canWrite() {
    if (!File::exists())
        return false;

    StringBuffer permissionString = File::permissionStringFormat(this->path);

    String currentUser = File::getCurrentUser();
    String currentGroup = File::getCurrentGroup();

    std::cout << "\n\n==== permissionString ====\n\n"
              << permissionString.toString();

    std::cout << "\n\n==== Get owner ====\n\n"
              << currentUser.toString()
              << "  "
              << File::getUser().toString();

    std::cout << "\n\n==== Get group ====\n\n"
              << currentGroup.toString()
              << "  "
              << File::getGroup().toString();

    // Owner permission
    if (File::getUser() == currentUser
        && permissionString.charAt(1) == 'w')
        return true;

    // Group permission
    if (File::getGroup() == currentGroup
        && permissionString.charAt(4) == 'w')
        return true;

    // Other permission
    if (permissionString.charAt(7) == 'w')
        return true;

    return false;
}

boolean File::canExecute() {
    if (!File::exists())
        return false;

    StringBuffer permissionString = File::permissionStringFormat(this->path);

    String currentUser = File::getCurrentUser();
    String currentGroup = File::getCurrentGroup();

    std::cout << "\n\n==== permissionString ====\n\n"
              << permissionString.toString();

    std::cout << "\n\n==== Get owner ====\n\n"
              << currentUser.toString()
              << "  "
              << File::getUser().toString();

    std::cout << "\n\n==== Get group ====\n\n"
              << currentGroup.toString()
              << "  "
              << File::getGroup().toString();

    // Owner permission
    if (File::getUser() == currentUser
        && permissionString.charAt(2) == 'x')
        return true;

    // Group permission
    if (File::getGroup() == currentGroup
        && permissionString.charAt(5) == 'x')
        return true;

    // Other permission
    if (permissionString.charAt(8) == 'x')
        return true;

    return false;
}

String File::getUser() {
    struct passwd *userLoginInfo = getpwuid(this->fileStatitics.st_uid);
    return userLoginInfo->pw_name;
}

String File::getGroup() {
    struct group *groupInfo = getgrgid(this->fileStatitics.st_gid);
    return groupInfo->gr_name;
}

String File::getCurrentUser() {
    struct passwd *userInfo = getpwuid(getuid());
    return userInfo->pw_name;
}

String File::getCurrentGroup() {
    struct passwd *userInfo = getpwuid(getuid());
    struct group *groupInfo = getgrgid(userInfo->pw_gid);
    return groupInfo->gr_name;
}

boolean File::setLastModified(long time) {
    if (time < 0)
        throw IllegalArgumentException("Negative time");

//    if (isInvalid()) {
//        return false;
//    }

    this->lastModifiedTime = time;

    return (this->lastModifiedTime == time);
}

long File::getFreeSpace() {
//    if (isInvalid()) {
//        return 0L;
//    }

    struct statvfs systemStatitics;
    boolean canGetSystemStatitics
            = (statvfs(this->path.toString(), &systemStatitics) == 0);
    if (!File::exists() || !canGetSystemStatitics)
        return 0L;

    return systemStatitics.f_bsize * systemStatitics.f_bfree;
}

String File::getName() {
    int index = this->path.lastIndexOf(this->separatorChar);
    if (index < this->prefixLength)
        return this->path.subString(this->prefixLength);
    return this->path.subString(index + 1);
}

String File::getParent() {
    int index = this->path.lastIndexOf(this->separatorChar);
    if (index < this->prefixLength) {
        if ((this->prefixLength > 0)
            && (this->path.length() > this->prefixLength))
            return this->path.subString(0, this->prefixLength);
        return "";
    }
    return this->path.subString(0, index);
}

File File::getParentFile() {
    String path = File::getParent();
    if (path == "")
        return File("");
    return File(path);
}

long File::getTotalSpace() {
//    if (isInvalid()) {
//        return 0L;
//    }

    struct statvfs systemStatitics;
    boolean canGetSystemStatitics
            = (statvfs(this->path.toString(), &systemStatitics) == 0);
    if (!File::exists() || !canGetSystemStatitics)
        return 0L;

    return systemStatitics.f_bsize * systemStatitics.f_blocks;
}

long File::getUsableSpace() {
//    if (isInvalid()) {
//        return 0L;
//    }

    struct statvfs systemStatitics;
    boolean canGetSystemStatitics
            = (statvfs(this->path.toString(), &systemStatitics) == 0);
    if (!File::exists() || !canGetSystemStatitics)
        return 0L;

    return systemStatitics.f_bsize * systemStatitics.f_bavail;
}

boolean File::isAbsolute() {
    String path = this->path;
    int length = path.length();
#ifdef WINDOWS
    char charAt0 = (length > 0) ? path.charAt(0) : '-';
    char charAt1 = (length > 1) ? path.charAt(1) : '-';
    char charAt2 = (length > 2) ? path.charAt(2) : '-';

    if (charAt0 == '\\\\'       // case \\ ;
        || charAt0 == '\\'      // case \  ;
        || charAt1 == ':'       // case c:
        || charAt2 == '\\')     // case c:\ ;
        return true;
#else
    if (path.charAt(0) == '/')  // case /home
        return true;
#endif
    return false;
}

Array<File> File::listFiles() {
    Array<String> arrayString;

    try {
        arrayString = File::list();
    } catch (Exception exception) {
        throw Exception(exception);
    }

    Array<File> arrayFile;

    if (arrayString.length == 0) {
        return arrayFile;
    }

    int arrayStringLength = arrayString.length;

    for (int index = 0; index < arrayStringLength; index++) {
        File file = File(this->path + (string) "/" + arrayString.get(index));
        arrayFile.push(file);
    }

    return arrayFile;
}

Array<String> File::listRootString() {
    ArrayList<String> result;
    long int index = 0;

    std::ifstream streamMountInfo("/proc/mounts");
    std::string holdStream;

    while (!streamMountInfo.eof()) {
        streamMountInfo >> holdStream;

        index++;
        if (index % 6 == 1) {
            String holdString = String(holdStream);
            result.add(holdString);
        }
    }

    return result.toArray();
}

Array<File> File::listRoots() {
    ArrayList<File> arrayFile;
    ArrayList<String> arrayString = File::listRootString();

    for (int index = 0; index < arrayString.size(); index++) {
        std::cout << arrayString[index].toString()<< "\n";
    }

    for (int index = 0; index < arrayString.size(); index++) {
        File file = File(arrayString[index]);
        arrayFile.add(file);
    }

    return arrayFile.toArray();
}

ArrayList<String> arrayPath;
void deleteThisFile() {

    std::cout<< "\n\ndeleteThisFile: arrayPathSize:  "
             << arrayPath.size()  <<"\n\n";

    struct stat fileStatitics;
    for(String thisPath : arrayPath) {
        nftw(thisPath.toString(),
             deleteEntry,
             64,
             FTW_DEPTH | FTW_PHYS);
    }
}

void File::deleteOnExit() {
//    if (isInvalid()) {
//        return;
//    }
    arrayPath.add(File::getPath());
    std::atexit(deleteThisFile);
}

boolean File::isHidden() {
//    if (isInvalid()) {
//        return false;
//    }

    if (!File::exists())
        return false;
#ifdef WINDOWS
    DWORD attributes = GetFileAttributes(this->path.toString());
    if (attributes & FILE_ATTRIBUTE_HIDDEN)
        return true;
#else
    std::cout << "\n\n this->path " << this->path.toString() << "\n\n";
    if (this->getName().charAt(0) == '.') {
        std::cout << "\n\n this->path.charAt(0) == '.' \n\n";
        return true;
    }
#endif
    return false;
}

boolean File::renameTo(File destinationFile) {
//    if (security != null) {
//        security.checkWrite(path);
//        security.checkWrite(dest.path);
//    }

    if (destinationFile.toString().isEmpty()) {
        return false;
    }

//    if (File::isInvalid() || dest.isInvalid()) {
//        return false;
//    }

    std::cout << "\n\n renameTo: \n\n";
    std::cout << "original: " << File::getPath().toString() << "\n";
    std::cout << "destination: " << destinationFile.getPath().toString() << "\n";

    boolean result = rename(this->getPath().toString(),
           destinationFile.getPath().toString()) == 0;

    if (!result)
    {
        String errorName = "renaming error: ";
        String error = strerror(errno);
        throw Exception(errorName + error);
    }

    this->path = destinationFile.getPath();
    return  result;
}

File File::createTempFile(String prefix, String suffix) {
    return createTempFile(prefix, suffix, (String) "");
}

File File::createTempFile(String prefix,
                          String suffix,
                          File directory) {
    if (prefix.length() < 3)
        throw IllegalArgumentException("Prefix string too short");
    if (suffix.isEmpty())
        suffix = ".tmp";

    String directoryName;

#ifdef WINDOWS
    directoryName = (directory.toString() == "")
                      ? getenv("TEMP")
                      : directory.toString();
#else
    directoryName = (directory.toString() == "")
                    ? "/tmp"
                    : directory.toString();
#endif

    // Get temp name
    String tempName = tmpnam(NULL);
    tempName = tempName.subString(tempName.lastIndexOf('/') + 1,
                                  tempName.lastIndexOf('.'));
    String fullTempName = directoryName
                     + (string) "/"
                     + prefix
                     + tempName
                     + suffix;
    std::cout << "\n\ndirectoryName: " << directoryName.toString();
    std::cout << "\n\ndirectory: " << directory.toString().toString();
    std::cout << "\n\ntempName: " << tempName.toString();
    std::cout << "\n\nfullTempName: " << fullTempName.toString();

    File fileTemporary = File(fullTempName);
    fileTemporary.createNewFile();
    fileTemporary.deleteOnExit();

    return fileTemporary;
}

boolean File::isInvalid() {
    return this->path.indexOf('\u0000') < 0;
}