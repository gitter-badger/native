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

#ifdef WINDOWS

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

TEST (JavaIo, FileBeforeTesting) {
    // Create variables for testing
    File fileTestFolder = File(FileTest::pathTestFolder);
    File fileExistent = File(FileTest::pathNameExistent);
    File fileHidden = File(FileTest::pathNameHidden);
    File fileSubFolder = File(FileTest::pathSubFolder);

//    ASSERT_TRUE(fileTestFolder.mkdir());
    ASSERT_TRUE(fileSubFolder.mkdirs());
    ASSERT_TRUE(fileTestFolder.isDirectory());
    ASSERT_TRUE(fileExistent.createNewFile());
    ASSERT_TRUE(fileHidden.createNewFile());
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

//TEST (JavaIo, FileCreateTempFileParamStringString) {
//    File tempFile("");
//    File fileTestFolder = File(FileTest::pathTestFolder);
//
//    // Make sure the file is existent after creating a temp file.
//    tempFile = File::createTempFile("temp", ".txt");
//    ASSERT_TRUE(tempFile.exists());
//
//    // Delete file after testing
//    ASSERT_TRUE(tempFile.deletes());
//
//    tempFile = File::createTempFile("temp", ".txt", fileTestFolder);
//    ASSERT_TRUE(tempFile.exists());
//
//    // Delete file after testing
//    ASSERT_TRUE(tempFile.deletes());
//}
//////
//////TEST (JavaIo, FileCreateTempFileParamStringStringFile) {
//////    File file = File("");
//////
//////    if (isLinux) {
//////        // Create a non-existent file
//////        file = File(FileTest::pathNameNonExistent);
//////        ASSERT_FALSE(file.exists());
//////    }
//////
//////    // Create a temp file.
//////    File fileTestFolder = File(FileTest::pathTestFolder);
//////    file = File.createTempFile("temp", ".txt", fileTestFolder);
//////    String pathParentFile = file.getParentFile().toString() + "/";
//////
//////    // Make sure the file is existent and the directory is right
//////    ASSERT_TRUE(file.exists());
//////    assertEquals(pathTestFolder.toString(), pathParentFile.toString());
//////
//////    // Delete file after testing
//////    ASSERT_TRUE(file.delete ());
//////}
//////
//////
//////TEST (JavaIo, FileDeleteOnExit) {
//////    if (isLinux) {
//////        // Create a temp file.
//////        String pathTestFolder = "/home/thoangminh/java/io/File/TestFolder/";
//////        File fileTestFolder = File(pathTestFolder);
//////        File fileTemp = File.createTempFile("temp", ".txt", fileTestFolder);
//////
//////        // Deletes file when the virtual machine terminate
//////        fileTemp.deleteOnExit();
//////    }
//////}

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
//////
//////TEST (JavaIo, FileGetFreeSpace) {
//////    File fileNonExistent = File(FileTest::pathNameNonExistent);
//////
//////    // Create an existent file
//////    File fileExistent = File(FileTest::pathNameExistent);
//////
//////    // getFreeSpace return 0 if the file is non existent
//////    ASSERT_TRUE(0 == fileNonExistent.getFreeSpace());
//////
//////    // getFreeSpace return != 0 if the file is existent
//////    ASSERT_TRUE(0 != fileExistent.getFreeSpace());
//////}
//////
//////TEST (JavaIo, FileGetName) {
//////    // Create a file has file name
//////    File fileNonExistent = File(FileTest::pathNameNonExistent);
//////
//////    // Create a directory file
//////    File fileTestFolder = File(FileTest::pathTestFolder);
//////
//////    // getName() return the name of the file
//////    String expected = "NonExistentFile.txt";
//////    String actual = fileNonExistent.getName();
//////    assertEquals(expected.toString(), actual.toString());
//////
//////    // getName() return the name of the directory
//////    expected = FileTest::stringPathTestFolder;
//////    actual = fileTestFolder.getName();
//////    assertEquals(expected.toString(), actual.toString());
//////}
//////
//////TEST (JavaIo, FileGetParent) {
//////    // Create a  file has the file name
//////    File fileNonExistent = File(FileTest::pathNameNonExistent);
//////
//////    // Create a file doesn't has a file name
//////    File fileTestFolder = File(FileTest::pathTestFolder);
//////
//////    // Returns the pathName string of this abstract pathName's parent
//////    String expected = FileTest::stringPathTestFolder;
//////    String actual = fileNonExistent.getParent();
//////    assertEquals(expected.toString(), actual.toString());
//////
//////    // Return null if this pathName does not name a parent directory
//////    actual = fileTestFolder.getParent();
//////    assertNull(actual);
//////}
//////
//////TEST (JavaIo, FileGetParentFile) {
//////    // Create a  file has the file name
//////    File fileNonExistent = File(FileTest::pathNameNonExistent);
//////
//////    // Create a file doesn't has a file name
//////    File fileTestFolder = File(FileTest::pathTestFolder);
//////
//////    // Returns the file of this abstract pathName's parent
//////    String expected = FileTest::stringPathTestFolder;
//////    File actual = fileNonExistent.getParentFile();
//////    assertEquals(expected.toString(), actual.toString());
//////
//////    // Return null file if this pathName does not name a parent directory
//////    actual = fileTestFolder.getParentFile();
//////    assertNull(actual);
//////}
//////
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

//////TEST (JavaIo, FileGetTotalSpace) {
//////    // Create a non-existent file
//////    File fileNonExistent = File(FileTest::pathNameNonExistent);
//////
//////    // Create an existent file
//////    File fileExistent = File(FileTest::pathNameExistent);
//////
//////    // Return 0 if the file is non existent
//////    ASSERT_TRUE(0 == fileNonExistent.getTotalSpace());
//////
//////    // Return != 0 if the file is existent
//////    ASSERT_TRUE(0 != fileExistent.getTotalSpace());
//////}
//////
//////TEST (JavaIo, FileGetUsableSpace) {
//////    // Create a non-existent file
//////    File fileNonExistent = File(FileTest::pathNameNonExistent);
//////
//////    // Create an existent file
//////    File fileExistent = File(FileTest::pathNameExistent);
//////
//////    // Return 0 if the file is non existent
//////    ASSERT_TRUE(0 == fileNonExistent.getUsableSpace());
//////
//////    // Return != 0 if the file is existent
//////    ASSERT_TRUE(0 != fileExistent.getUsableSpace());
//////}
//////
//TEST (JavaIo, FileIsAbsolute) {
//    File fileNotAbsolute = File(FileTest::pathNameNotAbsolute);
//    File fileAbsolute = File(FileTest::pathNameAbsolute);
//
//    ASSERT_FALSE(fileNotAbsolute.isAbsolute());
//    ASSERT_TRUE(fileAbsolute.isAbsolute());
//}

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

//////TEST (JavaIo, FileIsHidden) {
//////    // Create a directory file
//////    File fileTestFolder = File(FileTest::pathTestFolder);
//////
//////    // Create a file from a non-existent path
//////    File fileNonExistent = File(FileTest::pathNameNonExistent);
//////
//////    // Create a file from an existent path
//////    File fileExistent = File(FileTest::pathNameExistent);
//////
//////    // Create a file from an existent hidden path
//////    File fileHidden = File(FileTest::pathNameHidden);
//////
//////    // return FALSE if file is a directory
//////    ASSERT_FALSE(fileTestFolder.isHidden());
//////
//////    // return FALSE if file is non-existent
//////    ASSERT_FALSE(fileNonExistent.isHidden());
//////
//////    // return FALSE if file is existent
//////    ASSERT_FALSE(fileExistent.isHidden());
//////
//////    // return TRUE if file is hidden
////////		ASSERT_TRUE(fileHidden.isHidden());
//////}
//////
TEST (JavaIo, FileLastModified) {
    // Create a directory file
    File fileTestFolder = File(FileTest::pathTestFolder);
    fileTestFolder.setLastModified(1302l);
    long expected = 1302l;
    long actual = fileTestFolder.lastModified();
    ASSERT_EQUAL(expected, actual);

    // Time < 0
    try {
        fileTestFolder.setLastModified(-1);
    } catch(IllegalArgumentException exception) {
        ASSERT_STR("Negative time", exception.toString());
    }

    // Create a file from an existent path
    File fileExistent = File(FileTest::pathNameExistent);
    fileExistent.setLastModified(1302l);
    expected = 1302l;
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

    myFile = fopen("java\\io\\File\\TestFolder\\ExistentFile.txt", "a");
    fputs("abcd", myFile);
    fclose(myFile);

    ASSERT_EQUAL(0, fileNonExistent.length());
    ASSERT_EQUAL(4, fileExistent.length());
}

//////TEST (JavaIo, FileListFiles) {
//////    // Test a not empty directory
//////    File fileTestFolder = File(FileTest::pathTestFolder);
//////    File fileExistent = File(FileTest::pathNameExistent);
//////    File fileHidden = File(FileTest::pathNameHidden);
//////    File fileSubFolder = File(FileTest::pathTestFolder + "SubFolder");
//////    File[] expected = {fileExistent, fileHidden, fileSubFolder};
//////    File[] actual = fileTestFolder.listFiles();
//////    assertEquals(expected[0].toString(), actual[0].toString());
//////    assertEquals(expected[1].toString(), actual[1].toString());
//////    assertEquals(expected[2].toString(), actual[2].toString());
//////    assertEquals(3, actual.length);
//////
//////    // Test an empty directory
//////    ASSERT_TRUE(fileSubFolder.exists());
//////    actual = fileSubFolder.listFiles();
//////    assertEquals(0, actual.length);
//////}
//////
//////TEST (JavaIo, FileListRoots) {
//////
//////    if (FileTest::isWindows) {
//////        // Test a not empty directory
//////        File fileCDrive = File("C:\\");
//////        File fileDDrive = File("D:\\");
//////        File fileEDrive = File("E:\\");
//////        File[] expected = {fileCDrive, fileDDrive, fileEDrive};
//////        File[] actual = File.listRoots();
//////        assertEquals(expected[0].toString(), actual[0].toString());
//////        assertEquals(expected[1].toString(), actual[1].toString());
//////        assertEquals(expected[2].toString(), actual[2].toString());
//////        assertEquals(3, actual.length);
//////    }
//////}
//////
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
//////
//////TEST (JavaIo, FileToUri) {
//////    URI uri = URI(FileTest::pathUri);
//////    File fileUri = File(uri);
//////    assertEquals(FileTest::stringUriPath.toString(), fileUri.toString());
//////    assertEquals("file:/E:/Users/admin/test.txt", fileUri.toURI().toString());
//////}
//////
//////TEST (JavaIo, FileToUrl) {
//////    URI uri = URI(FileTest::pathUri);
//////    File fileUri = File(uri);
//////    assertEquals(FileTest::stringUriPath.toString(), fileUri.toString());
//////    assertEquals("file:/E:/Users/admin/test.txt", fileUri.toURL().toString());
//////}
//////

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
    Array<String> expected = {"ExistentFile.txt", "HiddenFile.txt", "SubFolder"};
    Array<String> actual = fileTestFolder.list();
    ASSERT_STR(expected[0].toString(), actual[0].toString());
    ASSERT_STR(expected[1].toString(), actual[1].toString());
    ASSERT_STR(expected[2].toString(), actual[2].toString());
    ASSERT_EQUAL(3, actual.getLength());

    // Test an empty directory
    File fileSubFolder = File(FileTest::pathTestFolder + (string) "SubFolder");
    ASSERT_TRUE(fileSubFolder.exists());
    actual = fileSubFolder.list();
    ASSERT_EQUAL(0, actual.length);
}

TEST (JavaIo, FileRenameTo) {
    // Create a file from a non-existent file path
    File fileNonExistentFile = File(FileTest::pathNameNonExistent);

    // Create a file form a non-existent folder path
    File fileNonExistentFoler = File(FileTest::pathNameNonExistentFolder);

    // Create a file from an existent path
    File fileExistent = File(FileTest::pathNameExistent);

    // Create a file from an existent folder path
    File fileExistentFolder = File(FileTest::pathTestFolder);

    // Create a file to test
    File fileTest = File("Test/");

    // return FALSE if fileTest is non-existent
    ASSERT_FALSE(fileTest.renameTo(fileExistent));
//    ASSERT_FALSE(fileTest.renameTo(fileNonExistentFoler));
//    ASSERT_FALSE(fileTest.renameTo(fileExistentFolder));

//    /* Create a File object for fileTest variable */
//    // After that: renameTo() will return TRUE with the non-existent destination
//    ASSERT_TRUE(fileTest.createNewFile());
//    ASSERT_TRUE(fileTest.exists());
//    ASSERT_FALSE(fileTest.renameTo(fileExistentFolder));
//
//    // Return FALSE with fileNonExistentFoler,
//    // and create a file for fileNonExistentFoler
//    ASSERT_FALSE(fileTest.renameTo(fileNonExistentFoler));
//    ASSERT_STR("Test", fileTest.toString().toString());
//
//    // Create a destination fileNewTest
//    File fileNewTest = File("NewTest");
//
//    // Make sure the fileTest is Existent, fileNewTest is non-existent
//    ASSERT_TRUE(fileTest.exists());
//    ASSERT_FALSE(fileNewTest.exists());
//
//    // Return TRUE. The fileTest was moved into fileNewTest
//    ASSERT_TRUE(fileTest.renameTo(fileNewTest));
//    ASSERT_FALSE(fileTest.exists());
//    ASSERT_TRUE(fileNewTest.exists());
//
//    // Delete file after testing
//    fileNewTest.deletes();
    fileNonExistentFoler.deletes();
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

#endif