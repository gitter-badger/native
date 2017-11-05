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

extern "C" {
#include "../../../kernel/test.h"
}

#include "File.hpp"
#include "../../../kernel/platform.h"
#include "../../util/Date/Date.hpp"

#include <stdlib.h>     /* system */

using namespace Java::Lang;
using namespace Java::Io;

namespace FileTest {
    String pathNameNonExistent = "java/io/File/TestFolder/NonExistentFile.txt";
    String stringPathNameNonExistent = "java/io/File/TestFolder/NonExistentFile.txt";

    String pathNameExistent = "java/io/File/TestFolder/ExistentFile.txt";
    String stringPathNameExistent = "java\\io\\File\\TestFolder\\ExistentFile.txt";

    String pathUri = "file:///Users/admin/test.txt";
    String stringUriPath = "\\Users\\admin\\test.txt";

    String pathTestFolder = "java/io/File/TestFolder/";
    String stringPathTestFolder = "java/io/File/TestFolder";

    String pathSubFolder = "java/io/File/TestFolder/SubFolder";
    String stringSubFolder = "java\\io\\File\\TestFolder\\SubFolder";

    String pathNameCanonical = "C:\\java\\io\\File\\TestFolder\\";
    String pathNameNotCanonical = "java/io/File/TestFolder/";

    String pathNameHidden = "java/io/File/TestFolder/HiddenFile.txt";

    String pathNameNonExistentFolder = "java/io/File/NonExistentFolder";
}

TEST (JavaIo, FileBeforeTest) {
    ASSERT_TRUE(File(FileTest::pathTestFolder).mkdir());
    ASSERT_TRUE(File(FileTest::pathNameExistent).createNewFile());
    ASSERT_TRUE(File(FileTest::pathNameHidden).createNewFile());
    ASSERT_TRUE(File(FileTest::pathSubFolder).mkdir());
}

TEST (JavaIo, FileConstructor) {
    String expected;
    String actual;

    /* Test File(String pathName) */
    // Valid case
    File fileParamString(FileTest::pathTestFolder);
    expected = FileTest::stringPathTestFolder.toString();
    actual = fileParamString.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Make sure constructor can normalize pathName
    File anotherFileParamString("C:///TestFolder////SubFolder///");
    expected = "C:/TestFolder/SubFolder";
    actual = anotherFileParamString.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Test empty pathName
    File oneMoreFileParamString("");
    expected = "";
    actual = oneMoreFileParamString.toString();
    ASSERT_STR(expected.toString(), actual.toString());

//    /* Test File(URI uri) */
//    String filePathOfUriPath = "/Users/admin/test.txt";
//    URI uri = URI(FileTest::pathUri);
//    File fileParamURI = File(uri);
//    assertEquals(FileTest::stringUriPath.toString(), fileParamURI.toString());
//
//    /* Test File(String parent, String child) */
//    File fileParamStringString = File(FileTest::pathTestFolder, "SubFolder");
//    assertEquals(FileTest::stringSubFolder.toString(), fileParamStringString.toString());
//
//    /* Test File(File parent, String child) */
//    File fileParamFileString = File(fileParamString, "SubFolder");
//    assertEquals(FileTest::stringSubFolder.toString(), fileParamFileString.toString());
}

TEST (JavaIo, FileCanExecute) {
    // Return FALSE with non-existent file
    File fileNonExistent = File(FileTest::pathNameNonExistent);
    ASSERT_FALSE(fileNonExistent.canExecute());

    File fileTestFolder = File(FileTest::pathTestFolder);
    File fileExistent = File(FileTest::pathNameExistent);

    ASSERT_TRUE(fileExistent.setExecutable(true));
    ASSERT_TRUE(fileExistent.canExecute());

    ASSERT_TRUE(fileExistent.setExecutable(false));
    ASSERT_FALSE(fileExistent.canExecute());

    ASSERT_TRUE(fileExistent.setExecutable(true, false));
    ASSERT_TRUE(fileExistent.canExecute());

    ASSERT_TRUE(fileExistent.setExecutable(false, false));
    ASSERT_FALSE(fileExistent.canExecute());
}

TEST (JavaIo, FileCanRead) {
    // Return FALSE with non-existent file
    File fileNonExistent = File(FileTest::pathNameNonExistent);
    ASSERT_FALSE(fileNonExistent.canRead());

    File fileTestFolder = File(FileTest::pathTestFolder);
    File fileExistent = File(FileTest::pathNameExistent);

    ASSERT_TRUE(fileExistent.setReadable(true));
    ASSERT_TRUE(fileExistent.canRead());

    ASSERT_TRUE(fileExistent.setReadable(false));
    ASSERT_FALSE(fileExistent.canRead());

    ASSERT_TRUE(fileExistent.setReadable(true, false));
    ASSERT_TRUE(fileExistent.canRead());

    ASSERT_TRUE(fileExistent.setReadable(false, false));
    ASSERT_FALSE(fileExistent.canRead());
}

TEST (JavaIo, FileCanWrite) {
    // Return FALSE with non-existent file
    File fileNonExistent = File(FileTest::pathNameNonExistent);
    ASSERT_FALSE(fileNonExistent.canWrite());

    File fileTestFolder = File(FileTest::pathTestFolder);
    File fileExistent = File(FileTest::pathNameExistent);

    ASSERT_TRUE(fileExistent.setWritable(true));
    ASSERT_TRUE(fileExistent.canWrite());

    ASSERT_TRUE(fileExistent.setWritable(false));
    ASSERT_FALSE(fileExistent.canWrite());
    ASSERT_TRUE(fileExistent.setWritable(true, false));
    ASSERT_TRUE(fileExistent.canWrite());

    ASSERT_TRUE(fileExistent.setWritable(false, false));
    ASSERT_FALSE(fileExistent.canWrite());
}

TEST (JavaIo, FileSetReadOnly) {
    // Return FALSE with non-existent file
    File fileNonExistent = File(FileTest::pathNameNonExistent);
    ASSERT_FALSE(fileNonExistent.setReadOnly());

    File fileTestFolder = File(FileTest::pathTestFolder);
    File fileExistent = File(FileTest::pathNameExistent);

    // Make sure the file can read, can write and can execute before testing
    ASSERT_TRUE(fileExistent.setReadable(true, false));
    ASSERT_TRUE(fileExistent.canRead());

    ASSERT_TRUE(fileExistent.setWritable(true, false));
    ASSERT_TRUE(fileExistent.canWrite());

    ASSERT_TRUE(fileExistent.setExecutable(true, false));
    ASSERT_TRUE(fileExistent.canExecute());

    // Make sure the file is read only after setReadOnly
    ASSERT_TRUE(fileExistent.setReadOnly());
    ASSERT_TRUE(fileExistent.canRead());
    ASSERT_FALSE(fileExistent.canWrite());
    ASSERT_FALSE(fileExistent.canExecute());
}

TEST (JavaIo, FileCompareTo) {
    /* Create variable to test */
    String pathName = "aaBaa";

    String pathNameLess = "aaAaa";
    String pathNameEqual = "aaBaa";
    String pathNameGreater = "aaCaa";

    File file = File(pathName);
    File fileNameLess = File(pathNameLess);
    File fileNameEqual = File(pathNameEqual);
    File fileNameGreater = File(pathNameGreater);

    // Return 1 if greater than
    ASSERT_EQUAL(1, file.compareTo(fileNameLess));

    // Return 0 if equal
    ASSERT_EQUAL(0, file.compareTo(fileNameEqual));

    // Return -1 if less than
    ASSERT_EQUAL(-1, file.compareTo(fileNameGreater));
}

TEST (JavaIo, FileCreateNewFile) {
    /* Return TRUE + Create a file
       if the current file is NOT EXISTENT */
    File fileNonExistent = File(FileTest::pathNameNonExistent);
    ASSERT_TRUE(fileNonExistent.createNewFile());
    fileNonExistent.deletes();

    /* Return FALSE + Do nothing
       if the current file is EXISTENT */
    File fileExistent = File(FileTest::pathNameExistent);
    ASSERT_FALSE(fileExistent.createNewFile());

    File fileTestFolder = File(FileTest::pathTestFolder);
    ASSERT_FALSE(fileTestFolder.createNewFile());
}

TEST (JavaIo, FileEquals) {
    /* Create variable to test */
    String pathName = "aaBaa";

    String pathNameNotEqual = "aaAaa";
    String pathNameEqual = "aaBaa";

    File file = File(pathName);
    File fileNameNotEqual = File(pathNameNotEqual);
    File fileNameEqual = File(pathNameEqual);

    // Return FALSE if NOT EQUAL
    ASSERT_FALSE(file.equals(fileNameNotEqual));

    // Return TRUE if EQUAL
    ASSERT_TRUE(file.equals(fileNameEqual));
}

TEST (JavaIo, FileExists) {
    // Test an existent directory file
    File fileTestFolder = File(FileTest::pathTestFolder);
    ASSERT_TRUE(fileTestFolder.exists());

    // Test a file from a existent path
    File fileExistent = File(FileTest::pathNameExistent);
    ASSERT_TRUE(fileExistent.exists());

    // Test a file from a non-existent path
    File fileNonExistent = File(FileTest::pathNameNonExistentFolder
                                + (string) "/NonExistentFile.txt");
    ASSERT_FALSE(fileNonExistent.exists());

    // Test a non-existent directory file
    File fileNonExistentFolder
            = File(FileTest::pathNameNonExistentFolder);
    ASSERT_FALSE(fileNonExistentFolder.exists());
}

TEST (JavaIo, FileGetPath) {
    // Create a file has file name
    File fileNonExistent = File(FileTest::pathNameNonExistent);

    // Create a directory file
    File fileTestFolder = File(FileTest::pathTestFolder);

    // getPath() return the name of the file
    String expected = FileTest::stringPathNameNonExistent;
    String actual = fileNonExistent.getPath();
    ASSERT_STR(expected.toString(), actual.toString());

    // getPath() return the name of the directory
    expected = FileTest::stringPathTestFolder;
    actual = fileTestFolder.getPath();
    ASSERT_STR(expected.toString(), actual.toString());
}

TEST (JavaIo, FileGetCanonicalPath) {
    File fileRoot("java/io/File");
    String pathRoot = fileRoot.getCanonicalPath();
    File fileTest = File(FileTest::pathNameNotCanonical);

    String expected = pathRoot
                      + (string) "/TestFolder";
#ifdef WINDOWS
    expected = expected.replace('/', '\\');
#endif

    String actual = fileTest.getCanonicalPath();
    ASSERT_STR(expected.toString(), actual.toString());
}

TEST (JavaIo, FileGetCanonicalFile) {
    File fileRoot("java/io/File");
    String pathRoot = fileRoot.getCanonicalPath();

    File fileTest = File(FileTest::pathNameNotCanonical);

    String expected = pathRoot
                      + (string) "/TestFolder";
#ifdef WINDOWS
    expected = expected.replace('/', '\\');
#endif

    String actual = fileTest.getCanonicalFile().toString();
    ASSERT_STR(expected.toString(), actual.toString());
}

TEST (JavaIo, FileIsDirectory) {
    // Create a file has file name
    File fileNonExistent = File(FileTest::pathNameNonExistent);

    // Create an existent directory file
    File fileTestFolder = File(FileTest::pathTestFolder);

    // Create a non-existent directory file
    File fileNonExistentFolder = File(FileTest::pathNameNonExistentFolder);

    // return FALSE if file is not a directory
    ASSERT_FALSE(fileNonExistent.isDirectory());

    // return TRUE if file is an existent directory
    ASSERT_TRUE(fileTestFolder.isDirectory());

    // return FALSE if file is a non-existent directory
    ASSERT_FALSE(fileNonExistentFolder.isDirectory());
}

TEST (JavaIo, FileIsFile) {
    // Create a directory file
    File fileTestFolder = File(FileTest::pathTestFolder);

    // Create a file from a non-existent path
    File fileNonExistent = File(FileTest::pathNameNonExistent);

    // Create a file from a existent path
    File fileExistent = File(FileTest::pathNameExistent);

    // return FALSE if file is a directory
    ASSERT_FALSE(fileTestFolder.isFile());

    // return FALSE if file is non-existent
    ASSERT_FALSE(fileNonExistent.isFile());

    // return TRUE if file is existent
    ASSERT_TRUE(fileExistent.isFile());
}

TEST (JavaIo, FileLastModified) {
    // Create a directory file
    File fileTestFolder = File(FileTest::pathTestFolder);
    fileTestFolder.setLastModified(1302L);
    long expected = 1302L;
    long actual = fileTestFolder.lastModified();
    ASSERT_EQUAL(expected, actual);

    // Time < 0
    try {
        fileTestFolder.setLastModified(-1);
    } catch (IllegalArgumentException exception) {
        ASSERT_STR("Negative time", exception.toString());
    }

    // Create a file from an existent path
    File fileExistent = File(FileTest::pathNameExistent);
    fileExistent.setLastModified(1302L);
    expected = 1302L;
    actual = fileTestFolder.lastModified();
    ASSERT_EQUAL(expected, actual);

    // Create a file from a non-existent path
    File fileNonExistent = File(FileTest::pathNameNonExistent);
    ASSERT_EQUAL(0, fileNonExistent.lastModified());
}

TEST (JavaIo, FileLength) {
    // Create a file from a non-existent path
    File fileNonExistent = File(FileTest::pathNameNonExistent);

    // Create a file from an existent path
    File fileExistent = File(FileTest::pathNameExistent);
    ASSERT_TRUE(fileExistent.setWritable(true));

    // Write string "abc" to fileExistent
    FILE *myFile;

#ifdef WINDOWS
    FileTest::pathNameExistent.replace('/', '\\');
    myFile = fopen(FileTest::pathNameExistent.toString(), "a");
#else
    myFile = fopen(FileTest::pathNameExistent.toString(), "a");
#endif
    fputs("abcd", myFile);
    fclose(myFile);

    ASSERT_EQUAL(0, fileNonExistent.length());
    ASSERT_EQUAL(4, fileExistent.length());
}

TEST (JavaIo, FileMkdir) {
    // Create an existent directory file
    File fileTestFolder = File(FileTest::pathTestFolder);

    // Create a file from a existent path
    File fileExistent = File(FileTest::pathNameExistent);

    // Create a file from a non-existent path
    File fileNonExistent = File(FileTest::pathNameNonExistentFolder
                                + (string) "/NonExistentFile.txt");

    // Create a non-existent directory file
    File fileNonExistentFolder
            = File(FileTest::pathNameNonExistentFolder);

    // return FALSE if a directory file is existent and do nothing
    ASSERT_FALSE(fileTestFolder.mkdir());

    // return FALSE if file is existent and do nothing
    ASSERT_FALSE(fileExistent.mkdir());

    // return FALSE if the parent directory is non-existent and do nothing
    ASSERT_FALSE(fileNonExistent.mkdir());

    // return TRUE if directory is non-existent and the parent directory
    // is existent. Creates the directory named by this abstract pathName.
    ASSERT_TRUE(fileNonExistentFolder.mkdir());

    // delete file after testing
    ASSERT_TRUE(fileNonExistentFolder.deletes());
}

TEST (JavaIo, FileMkdirs) {
    // Create an existent directory file
    File fileTestFolder = File(FileTest::pathTestFolder);

    // Create a file from a existent path
    File fileExistent = File(FileTest::pathNameExistent);

    // Create a file from a non-existent path
    File fileNonExistent = File(FileTest::pathNameNonExistentFolder
                                + (string) "/NonExistentFile.txt");

    // Create a non-existent directory file
    File fileNonExistentFolder
            = File(FileTest::pathNameNonExistentFolder);

    // return FALSE if a directory file is existent and do nothing
    ASSERT_FALSE(fileTestFolder.mkdirs());

    // return FALSE if file is existent and do nothing
    ASSERT_FALSE(fileExistent.mkdirs());

    // return TRUE if the parent directory is non-existent
    // Creates the directory named by this abstract pathName.
    ASSERT_TRUE(fileNonExistent.mkdirs());

    // delete file after testing
    ASSERT_TRUE(fileNonExistentFolder.deletes());
}

TEST (JavaIo, FileToString) {
    File fileTestFolder = File(FileTest::pathTestFolder);
    ASSERT_STR(FileTest::stringPathTestFolder.toString(),
               fileTestFolder.toString().toString());
}

TEST (JavaIo, FileGetAbsolutePath) {
    File fileRoot("java/io/File");
    String pathRoot = fileRoot.getAbsolutePath();
    File fileTest = File(FileTest::pathNameNotCanonical);

    String expected = pathRoot
                      + (string) "/TestFolder";
    String actual = fileTest.getAbsolutePath();
    ASSERT_STR(expected.toString(), actual.toString());
}

TEST (JavaIo, FileGetAbsoluteFile) {
    File fileRoot("java/io/File");
    String pathRoot = fileRoot.getAbsolutePath();

    File fileTest = File(FileTest::pathNameNotCanonical);

    String expected = pathRoot
                      + (string) "/TestFolder";
    String actual = fileTest.getAbsoluteFile().toString();
    ASSERT_STR(expected.toString(), actual.toString());
}

TEST (JavaIo, FileList) {
    // Test a not empty directory
    File fileTestFolder = File(FileTest::pathTestFolder);
    Array<String> expected = {"ExistentFile.txt", "HiddenFile.txt",
                              "SubFolder"};
    Array<String> actual = fileTestFolder.list();
    boolean isSame;

    for (String elementExpected : expected) {
        isSame = false;

        for (String elementActual: actual) {
            if (elementExpected == elementActual) {
                isSame = true;
            }

            std::cout << "\n\n"
                      << elementExpected.toString()
                      << "  " << elementActual.toString()
                      << "\n\n";
        }

        ASSERT_TRUE(isSame);
    }

    ASSERT_EQUAL(expected.getLength(), actual.getLength());

    // Test an empty directory
    File fileSubFolder = File(FileTest::pathTestFolder + (string) "SubFolder");
    ASSERT_TRUE(fileSubFolder.exists());
    actual = fileSubFolder.list();
    ASSERT_EQUAL(0, actual.length);

    // Test non-exist file
    try {
        File fileNonExistent = File("NonExistentFile");
        fileNonExistent.list();
    } catch (Exception exception) {
        ASSERT_STR("file is not a directory or not exist",
                   exception.toString());
    }

    // Test not directory file
    try {
        File fileNotDirectory = File("NotDirectoryFile.txt");
        fileNotDirectory.list();
    } catch (Exception exception) {
        ASSERT_STR("file is not a directory or not exist",
                   exception.toString());
    }
}

TEST (JavaIo, FileGetFreeSpace) {
    // Check a non-existent file
    File fileNonExistent = File(FileTest::pathNameNonExistent);
    long expected = 0;
    long actual = fileNonExistent.getFreeSpace();
    ASSERT_EQUAL(expected, actual);

    // Check an existent file
    File fileExistent = File(FileTest::pathNameExistent);
    struct statvfs systemStatitics;
    statvfs(fileExistent.getPath().toString(), &systemStatitics);
    expected = systemStatitics.f_bsize * systemStatitics.f_bfree;
    actual = fileExistent.getFreeSpace();
    ASSERT_EQUAL(expected, actual);
}

TEST (JavaIo, FileGetName) {
    // Create a file has file name
    File fileNonExistent = File(FileTest::pathNameNonExistent);

    // Create a directory file
    File fileTestFolder = File(FileTest::pathTestFolder);

    // getName() return the name of the file
    String expected = "NonExistentFile.txt";
    String actual = fileNonExistent.getName();
    ASSERT_STR(expected.toString(), actual.toString());

    // getName() return the name of the directory
    expected = "TestFolder";
    actual = fileTestFolder.getName();
    ASSERT_STR(expected.toString(), actual.toString());
}

TEST (JavaIo, FileGetParent) {
    // Create a  file has the file name
    File fileNonExistent = File(FileTest::pathNameNonExistent);

    // Create a file doesn't has a file name
    File fileTestFolder = File(FileTest::pathTestFolder);

    // Returns the pathName string of this abstract pathName's parent
    String expected = FileTest::stringPathTestFolder;
    String actual = fileNonExistent.getParent();
    ASSERT_STR(expected.toString(), actual.toString());

    // Return null if this pathName does not name a parent directory
    actual = File("Test").getParent();
    ASSERT_STR("", actual.toString());
}

TEST (JavaIo, FileGetParentFile) {
    // Create a file has the file name
    File fileNonExistent = File(FileTest::pathNameNonExistent);

    // Create a file doesn't has a file name
    File fileTestFolder = File(FileTest::pathTestFolder);

    // Returns the pathName string of this abstract pathName's parent
    String expected = FileTest::stringPathTestFolder;
    String actual = fileNonExistent.getParentFile().getPath();
    ASSERT_STR(expected.toString(), actual.toString());

    // Return null if this pathName does not name a parent directory
    actual = File("Test").getParentFile().getPath();
    ASSERT_STR("", actual.toString());
}

TEST (JavaIo, FileGetTotalSpace) {
    // Check a non-existent file
    File fileNonExistent = File(FileTest::pathNameNonExistent);
    long expected = 0;
    long actual = fileNonExistent.getTotalSpace();
    ASSERT_EQUAL(expected, actual);

    // Check an existent file
    File fileExistent = File(FileTest::pathNameExistent);
    struct statvfs systemStatitics;
    statvfs(fileExistent.getPath().toString(), &systemStatitics);
    expected = systemStatitics.f_bsize * systemStatitics.f_blocks;
    actual = fileExistent.getTotalSpace();
    ASSERT_EQUAL(expected, actual);
}

TEST (JavaIo, FileGetUsableSpace) {
    // Check a non-existent file
    File fileNonExistent = File(FileTest::pathNameNonExistent);
    long expected = 0;
    long actual = fileNonExistent.getUsableSpace();
    ASSERT_EQUAL(expected, actual);

    // Check an existent file
    File fileExistent = File(FileTest::pathNameExistent);
    struct statvfs systemStatitics;
    statvfs(fileExistent.getPath().toString(), &systemStatitics);
    expected = systemStatitics.f_bsize * systemStatitics.f_bavail;
    actual = fileExistent.getUsableSpace();
    ASSERT_EQUAL(expected, actual);
}

TEST (JavaIo, FileIsAbsolute) {
    ASSERT_FALSE(File("TestFolder").isAbsolute());
#ifdef WINDOWS
    ASSERT_TRUE(File("\\TestFolder").isAbsolute());
    ASSERT_TRUE(File("\\\\TestFolder").isAbsolute());
    ASSERT_TRUE(File("C:").isAbsolute());
    ASSERT_TRUE(File("C:\\TestFolder").isAbsolute());
    ASSERT_FALSE(File("TestFolder").isAbsolute());
#else
    ASSERT_TRUE(File("/TestFolder").isAbsolute());
    ASSERT_FALSE(File("TestFolder").isAbsolute());
#endif
}

TEST (JavaIo, FileListFiles) {

    {
        // Test a not empty directory
        File fileTestFolder = File("java/io/File/TestFolder");
        fileTestFolder.listFiles();

        ArrayList<File> actualArray = fileTestFolder.listFiles();
        ArrayList<File> expectedArray
                = {File(fileTestFolder.getPath() + (string)"/ExistentFile.txt"),
                   File(fileTestFolder.getPath() + (string)"/HiddenFile.txt"),
                   File(fileTestFolder.getPath() + (string)"/SubFolder")};

        boolean isSame;

        for (File elementExpected : expectedArray) {
            isSame = false;

            for (File elementActual: actualArray) {
                if (elementExpected.equals(elementActual)) {
                    isSame = true;
                }

                std::cout << "\n\n"
                          << elementExpected.toString()
                          << "  " << elementActual.toString()
                          << "\n\n";
            }

            ASSERT_TRUE(isSame);
        }

        ASSERT_EQUAL(expectedArray.size(), actualArray.size());
    }

    {
        // Test an empty directory
        File fileSubFolder = File("java/io/File/TestFolder/SubFolder");
        ASSERT_TRUE(fileSubFolder.exists());
        Array<File> actual = fileSubFolder.listFiles();
        ASSERT_EQUAL(0, actual.length);
    }

    // Test non-exist file
    try {
        File fileNonExistent = File("NonExistentFile");
        fileNonExistent.listFiles();
    } catch (Exception exception) {
        ASSERT_STR("file is not a directory or not exist",
                   exception.toString());
    }

    // Test not directory file
    try {
        File fileNotDirectory = File("NotDirectoryFile.txt");
        fileNotDirectory.listFiles();
    } catch (Exception exception) {
        ASSERT_STR("file is not a directory or not exist",
                   exception.toString());
    }
}

TEST (JavaIo, FileListRoots) {
    ArrayList<File> expected;
    long int index = 0;

    std::ifstream streamMountInfo("/proc/mounts");
    std::string holdStream;

    long int countFileSystem = 0;
    while (!streamMountInfo.eof()) {
        streamMountInfo >> holdStream;

        index++;
        if (index % 6 == 1) {
            expected.add(File(holdStream));
            countFileSystem++;
        }
    }
    ArrayList<File> actual = File::listRoots();

    ASSERT_EQUAL(countFileSystem, actual.size());
    for (int index = 0; index < expected.size(); index++) {
        ASSERT_STR(expected[index].toString().toString(),
                   actual[index].toString().toString());
    }
}

struct stat fileStatitics;

void checkExist() {
    ASSERT_FALSE(
            stat("java/io/File/FileDeleteOnExit.txt", &fileStatitics) == 0);
}

TEST (JavaIo, FileDeleteOnExit) {
    // Make sure the file will be deleted after the program termination
    std::atexit(checkExist);
    File fileDeleteOnExit = File("java/io/File/FileDeleteOnExit.txt");
    File fileDeleteOnExit1 = File("java/io/File/FileDeleteOnExit1.txt");

    ASSERT_TRUE(fileDeleteOnExit.createNewFile());
    ASSERT_TRUE(fileDeleteOnExit1.createNewFile());

    fileDeleteOnExit.deleteOnExit();
    fileDeleteOnExit1.deleteOnExit();

    ASSERT_TRUE(fileDeleteOnExit.exists());
    ASSERT_TRUE(fileDeleteOnExit1.exists());
}

TEST (JavaIo, FileIsHidden) {
    File testFile = File("java/io/File/FileIsHidden.txt");
    ASSERT_TRUE(testFile.createNewFile());
    ASSERT_FALSE(testFile.isHidden());

    // Set hidden
#ifdef WINDOWS
    String command = "attrib +H " + testFile.getPath();
    string buffer;
    StringBuffer result;

    FILE *pipe = popen(command.toString(), "r");

    if (!pipe)
        throw Exception("popen() failed!");

    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != NULL)
            result.append(buffer);
    }
    ASSERT_TRUE(WEXITSTATUS(pclose(pipe)) == 0);
#else
    ASSERT_TRUE(testFile.renameTo(File("java/io/File/.FileIsHidden.txt")));
#endif
    ASSERT_TRUE(testFile.isHidden());
    ASSERT_TRUE(testFile.deletes());
}

TEST (JavaIo, FileRenameTo) {
    {
        // Valid case
        File fileOrigin = File("java/io/File/origin.txt");
        File fileDestination = File("java/io/File/TestFolder/destination.txt");

        ASSERT_TRUE(fileOrigin.createNewFile());
        ASSERT_FALSE(fileDestination.exists());

        ASSERT_TRUE(fileOrigin.renameTo(fileDestination));
        ASSERT_TRUE(fileDestination.exists());

        ASSERT_TRUE(fileDestination.deletes());
    }

    {
        // Destination path must not be empty
        File fileOrigin = File("java/io/File/origin.txt");
        File fileDestination = File("");

        ASSERT_TRUE(fileOrigin.createNewFile());
        ASSERT_FALSE(fileDestination.exists());

        ASSERT_FALSE(fileOrigin.renameTo(fileDestination));
        ASSERT_FALSE(fileDestination.exists());

        ASSERT_TRUE(fileOrigin.deletes());
    }

    {
        // Can not move file to another file system
        try {
            File fileOrigin = File("java/io/File/origin.txt");

            ASSERT_TRUE(fileOrigin.createNewFile());

            String originCannonicalPath = fileOrigin.getCanonicalPath();

            ArrayList<File> arrayRootFile = File::listRoots();
            long int indexRoot = -1;
            for (File file : arrayRootFile) {
                long int findResult = originCannonicalPath.indexOf(
                        file.toString());
                if (findResult != -1)
                    indexRoot = findResult;
            }

            String originRoot;
            if (indexRoot != -1)
                originRoot = originCannonicalPath.subString(0, indexRoot);
            else
                originRoot = arrayRootFile[0].toString();

            std::cout << "\n\nRenameTo: originRoot  "
                      << originRoot.toString()
                      << "\n\n";

            fileOrigin.deleteOnExit();

            File fileDestination = File(
                    originRoot + (string) "/destination.txt");
            ASSERT_FALSE(fileDestination.exists());

            fileOrigin.renameTo(fileDestination);
        } catch (Exception exception) {
            String stringException = exception.toString();
            ASSERT_TRUE(stringException.indexOf("renaming error") != -1);
        }
    }
}

TEST (JavaIo, FileCreateTempFile) {
    File tempFile("");
    File fileTestFolder = File(FileTest::pathTestFolder);

    try {
        tempFile = File::createTempFile("temp", ".txt");
    } catch (Exception exception) {
        ASSERT_TRUE(exception != Exception());
    }
    ASSERT_TRUE(tempFile.exists());
    ASSERT_TRUE(tempFile.getPath().indexOf("temp") != -1);
    ASSERT_TRUE(tempFile.getPath().indexOf(".txt") != -1);

    try {
        tempFile = File::createTempFile("temp", ".txt", fileTestFolder);
    } catch (Exception exception) {
        ASSERT_TRUE(exception != Exception());
    }
    ASSERT_TRUE(tempFile.exists());
    ASSERT_TRUE(tempFile.getPath().indexOf("temp") != -1);
    ASSERT_TRUE(tempFile.getPath().indexOf(".txt") != -1);

    ArrayList<File> listTestFoler = fileTestFolder.listFiles();
    boolean findResult = false;

    for (File file : listTestFoler) {
        if (file.getAbsolutePath() == tempFile.getAbsolutePath())
            findResult = true;
    }

    ASSERT_TRUE(findResult);
}

TEST (JavaIo, FileIsInvalid) {
    File file = File("TestFolder");
    ASSERT_TRUE(file.isInvalid());
}

TEST (JavaIo, FileDeletes) {
    // Variables for testing
    File fileTestFolder = File(FileTest::pathTestFolder);
    File fileExistent = File(FileTest::pathNameExistent);
    File fileHidden = File(FileTest::pathNameHidden);
    File fileSubFolder = File(FileTest::pathSubFolder);

    // Check these file above is existent
    ASSERT_TRUE(fileTestFolder.exists());
    ASSERT_TRUE(fileExistent.exists());
    ASSERT_TRUE(fileHidden.exists());
    ASSERT_TRUE(fileSubFolder.exists());

    // Return TRUE and Deletes all file, subFolder in an existent directory
    ASSERT_TRUE(fileTestFolder.deletes());

    // Make sure all files has been deleted
    ASSERT_FALSE(fileTestFolder.exists());
    ASSERT_FALSE(fileExistent.exists());
    ASSERT_FALSE(fileHidden.exists());
    ASSERT_FALSE(fileSubFolder.exists());

    // Return FALSE and do nothing when trying to delete a non-existent file
    ASSERT_FALSE(fileTestFolder.deletes());
}