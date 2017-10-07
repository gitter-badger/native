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
//extern "C" {
//#include "../../../kernel/test.h"
//}
//
//#include "File.hpp"
//#include "../../../kernel/platform.h"
//
//#include <stdlib.h>     /* system */
//
//using namespace Java::Lang;
//
//namespace FileTest {
//    String pathNameNonExistent;
//    String stringPathNameNonExistent;
//
//    String pathNameExistent;
//    String stringPathNameExistent;
//
//    String pathUri;
//    String stringUriPath;
//
//    String pathTestFolder;
//    String stringPathTestFolder;
//
//    String pathSubFolder;
//    String stringSubFolder;
//
//    String pathNameAbsolute;
//    String pathNameNotAbsolute;
//    String pathNameHidden;
//    String pathNameNonExistentFolder;
//}
//
//#ifdef WINDOWS
//
//FileTest::pathNameNonExistent = "TestFolder/NonExistentFile.txt";
//FileTest::stringPathNameNonExistent = "TestFolder\\NonExistentFile.txt";
//
//FileTest::pathNameExistent = "TestFolder/ExistentFile.txt";
//FileTest::stringPathNameExistent = "TestFolder\\ExistentFile.txt";
//
//FileTest::pathUri = "file:///Users/admin/test.txt";
//FileTest::stringUriPath = "\\Users\\admin\\test.txt";
//
//FileTest::pathTestFolder = "TestFolder/";
//FileTest::stringPathTestFolder = "TestFolder";
//
//FileTest::pathSubFolder = "TestFolder/SubFolder";
//FileTest::stringSubFolder = "TestFolder\\SubFolder";
//
//FileTest::pathNameAbsolute = "C:\\TestFolder\\NonExistentFile.txt";
//FileTest::pathNameNotAbsolute = "TestFolder/NonExistentFile.txt";
//
//FileTest::pathNameHidden = "TestFolder/HiddenFile.txt";
//
//FileTest::pathNameNonExistentFolder = "NonExistentFolder/";
//
//TEST (JavaIo, FileBeforeTesting) {
//    // Create variables for testing
//    File fileTestFolder = new File(FileTest::pathTestFolder);
//    File fileExistent = new File(FileTest::pathNameExistent);
//    File fileHidden = new File(FileTest::pathNameHidden);
//    File fileSubFolder = new File(FileTest::pathSubFolder);
//
//    fileSubFolder.mkdirs();
//    fileExistent.createNewFile();
//    fileHidden.createNewFile();
//
//    // Delete files after testing
//    fileTestFolder.deleteOnExit();
//    fileExistent.deleteOnExit();
//    fileHidden.deleteOnExit();
//    fileSubFolder.deleteOnExit();
//}
//
//TEST (JavaIo, FileConstructor) {
//    String filePathOfUriPath = "/Users/admin/test.txt";
//    URI uri = new URI(FileTest::pathUri);
//
//    /* Test File(String pathname) */
//    File fileParamString = new File(FileTest::pathTestFolder);
//    assertEquals(FileTest::stringPathTestFolder.toString(), fileParamString.toString());
//
//    /* Test File(URI uri) */
//    File fileParamURI = new File(uri);
//    assertEquals(FileTest::stringUriPath.toString(), fileParamURI.toString());
//
//    /* Test File(String parent, String child) */
//    File fileParamStringString = new File(FileTest::pathTestFolder, "SubFolder");
//    assertEquals(FileTest::stringSubFolder.toString(), fileParamStringString.toString());
//
//    /* Test File(File parent, String child) */
//    File fileParamFileString = new File(fileParamString, "SubFolder");
//    assertEquals(FileTest::stringSubFolder.toString(), fileParamFileString.toString());
//}
//
///**
// * canExecute() doesn't test for executability,
// * it tests whether the current program
// * is permitted to execute it
// * @throws IOException
// */
//TEST (JavaIo, FileCanExecute) {
//    // Return FALSE with non-existent file
//    File fileNonExistent = new File(FileTest::pathNameNonExistent);
//    assertFalse(fileNonExistent.canExecute());
//
//    // Return FASLE when can not execute
//    File fileTestFolder = new File(FileTest::pathTestFolder);
//    File fileExistent = new File(FileTest::pathNameExistent);
//    fileExistent.createNewFile();
////		assertTrue(fileExistent.setExecutable(false));  // TODO(thoangminh): research it
////		assertFalse(fileExistent.canExecute());
//
//    // Return TRUE when can execute
//    assertTrue(fileExistent.setExecutable(true));
//    assertTrue(fileExistent.canExecute());
//}
//
//TEST (JavaIo, FileCanRead) {
//    // Case FALSE
//    File fileNonExistent = new File(FileTest::pathNameNonExistent);
//    assertFalse(fileNonExistent.canRead());
//
//    // Case TRUE
//    File fileExistent = new File(FileTest::pathNameExistent);
//    assertTrue(fileExistent.canRead());
//}
//
//TEST (JavaIo, FileCanWrite) {
//    if (isLinux) {
//        // Case FALSE
//        File fileNonExistent = new File(FileTest::pathNameNonExistent);
//        assertFalse(fileNonExistent.canWrite());
//
//        // Case TRUE
//        File fileExistent = new File(FileTest::pathNameExistent);
//        assertTrue(fileExistent.canWrite());
//    }
//}
//
//TEST (JavaIo, FileCompareTo) {
//    /* Create variable to test */
//    String pathName = "aaBaa";
//
//    String pathNameLess = "aaAaa";
//    String pathNameEqual = "aaBaa";
//    String pathNameGreater = "aaCaa";
//
//    File file = new File(pathName);
//    File fileNameLess = new File(pathNameLess);
//    File fileNameEqual = new File(pathNameEqual);
//    File fileNameGreater = new File(pathNameGreater);
//
//    // Return 1 if greater than
//    assertEquals(1, file.compareTo(fileNameLess));
//
//    // Return 0 if equal
//    assertEquals(0, file.compareTo(fileNameEqual));
//
//    // Return -1 if less than
//    assertEquals(-1, file.compareTo(fileNameGreater));
//}
//
//TEST (JavaIo, FileCreateNewFile) {
//    /* Return TRUE + Create a new file
//       if the current file is NOT EXISTENT */
//    File fileNonExistent = new File(FileTest::pathNameNonExistent);
//    assertTrue(fileNonExistent.createNewFile());
//    fileNonExistent.delete ();
//
//    /* Return FALSE + Do nothing
//       if the current file is EXISTENT */
//    File fileExistent = new File(FileTest::pathNameExistent);
//    assertFalse(fileExistent.createNewFile());
//
//    File fileTestFolder = new File(FileTest::pathTestFolder);
//    assertFalse(fileTestFolder.createNewFile());
//}
//
//TEST (JavaIo, FileCreateTempFileParamStringString) {
//    File file = new File("");
//
//    if (isLinux) {
//        // Create a non-existent file
//        file = new File(FileTest::pathNameNonExistent);
//        assertFalse(file.exists());
//    }
//
//    // Make sure the file is existent after creating a temp file.
//    file = File.createTempFile("temp", ".txt");
//    assertTrue(file.exists());
//
//    // Delete file after testing
//    assertTrue(file.delete ());
//}
//
//TEST (JavaIo, FileCreateTempFileParamStringStringFile) {
//    File file = new File("");
//
//    if (isLinux) {
//        // Create a non-existent file
//        file = new File(FileTest::pathNameNonExistent);
//        assertFalse(file.exists());
//    }
//
//    // Create a temp file.
//    File fileTestFolder = new File(FileTest::pathTestFolder);
//    file = File.createTempFile("temp", ".txt", fileTestFolder);
//    String pathParentFile = file.getParentFile().toString() + "/";
//
//    // Make sure the file is existent and the directory is right
//    assertTrue(file.exists());
//    assertEquals(pathTestFolder.toString(), pathParentFile.toString());
//
//    // Delete file after testing
//    assertTrue(file.delete ());
//}
//
//TEST (JavaIo, FileDelete) {
//    // Create a non-existent file
//    File fileNonExistent = new File(FileTest::pathNameNonExistent);
//    assertFalse(fileNonExistent.exists());
//
//    // Return FALSE when trying to delete is NOT SUCCESS
//    assertFalse(fileNonExistent.delete ());
//
//    // Create a temp file.
//    File fileTemp = File.createTempFile("temp", ".txt");
//
//    // Return TRUE when trying to delete is SUCCESS
//    assertTrue(fileTemp.delete ());
//
//    // Make sure the temp file is deleted
//    assertFalse(fileTemp.exists());
//}
//
//TEST (JavaIo, FileDeleteOnExit) {
//    if (isLinux) {
//        // Create a temp file.
//        String pathTestFolder = "/home/thoangminh/TestFolder/";
//        File fileTestFolder = new File(pathTestFolder);
//        File fileTemp = File.createTempFile("temp", ".txt", fileTestFolder);
//
//        // Deletes file when the virtual machine terminate
//        fileTemp.deleteOnExit();
//    }
//}
//
//TEST (JavaIo, FileEquals) {
//    /* Create variable to test */
//    String pathName = "aaBaa";
//
//    String pathNameNotEqual = "aaAaa";
//    String pathNameEqual = "aaBaa";
//
//    File file = new File(pathName);
//    File fileNameNotEqual = new File(pathNameNotEqual);
//    File fileNameEqual = new File(pathNameEqual);
//
//    // Return FALSE if NOT EQUAL
//    assertFalse(file.equals(fileNameNotEqual));
//
//    // Return TRUE if EQUAL
//    assertTrue(file.equals(fileNameEqual));
//}
//
//TEST (JavaIo, FileExists) {
//    // Create a non-existent file
//    File file = new File(FileTest::pathNameNonExistent);
//
//    // Return FALSE when the file is NOT EXISTENT
//    assertFalse(file.exists());
//
//    // Return TRUE when the file is EXISTENT
//    file = File.createTempFile("temp", ".txt");
//    assertTrue(file.exists());
//
//    // Delete file after testing
//    assertTrue(file.delete ());
//}
//
//TEST (JavaIo, FileGetAbsoluteFile) {
//    if (FileTest::isWindows) {
//
//        // Create a non-existent file
//        File fileNonExistent = new File(FileTest::pathNameNonExistent);
//
//        // Create an existent file
//        File fileExistent = new File(FileTest::pathNameExistent);
//
//        // getAbsoluteFile() when the file is NOT EXISTENT
//        String expected = "E:\\JavaWorkspace\\TestJavaLibrary\\TestFolder\\NonExistentFile.txt";
//        String actual = fileNonExistent.getAbsoluteFile().toString();
//        assertEquals(expected.toString(), actual.toString());
//
//        // getAbsoluteFile() when the file is EXISTENT
//        expected = "E:\\JavaWorkspace\\TestJavaLibrary\\TestFolder\\ExistentFile.txt";
//        actual = fileExistent.getAbsoluteFile().toString();
//        assertEquals(expected.toString(), actual.toString());
//    }
//}
//
//TEST (JavaIo, FileGetAbsolutePath) {
//    if (FileTest::isWindows) {
//
//        // Create a non-existent file
//        File fileNonExistent = new File(FileTest::pathNameNonExistent);
//
//        // Create an existent file
//        File fileExistent = new File(FileTest::pathNameExistent);
//
//        // getAbsoluteFile() when the file is NOT EXISTENT
//        String expected = "E:\\JavaWorkspace\\TestJavaLibrary\\TestFolder\\NonExistentFile.txt";
//        String actual = fileNonExistent.getAbsolutePath().toString();
//        assertEquals(expected.toString(), actual.toString());
//
//        // getAbsoluteFile() when the file is EXISTENT
//        expected = "E:\\JavaWorkspace\\TestJavaLibrary\\TestFolder\\ExistentFile.txt";
//        actual = fileExistent.getAbsolutePath().toString();
//        assertEquals(expected.toString(), actual.toString());
//    }
//}
//
//TEST (JavaIo, FileGetCanonicalFile) {
//    if (FileTest::isWindows) {
//        // Create an existent file
//        File fileExistent = new File(FileTest::pathNameExistent);
//
//        // Get Canonical File
//        String expected = "E:\\JavaWorkspace\\TestJavaLibrary\\TestFolder\\ExistentFile.txt";
//        String actual = fileExistent.getCanonicalFile().toString();
//        assertEquals(expected.toString(), actual.toString());
//    }
//}
//
//TEST (JavaIo, FileGetCanonicalPath) {
//    if (isWindows) {
//        // Create an existent file
//        File fileExistent = new File(FileTest::pathNameExistent);
//
//        // Get Canonical File
//        String expected = "E:\\JavaWorkspace\\TestJavaLibrary\\TestFolder\\ExistentFile.txt";
//        String actual = fileExistent.getCanonicalPath();
//        assertEquals(expected.toString(), actual.toString());
//    }
//}
//
//TEST (JavaIo, FileGetFreeSpace) {
//    File fileNonExistent = new File(FileTest::pathNameNonExistent);
//
//    // Create an existent file
//    File fileExistent = new File(FileTest::pathNameExistent);
//
//    // getFreeSpace return 0 if the file is non existent
//    assertTrue(0 == fileNonExistent.getFreeSpace());
//
//    // getFreeSpace return != 0 if the file is existent
//    assertTrue(0 != fileExistent.getFreeSpace());
//}
//
//TEST (JavaIo, FileGetName) {
//    // Create a file has file name
//    File fileNonExistent = new File(FileTest::pathNameNonExistent);
//
//    // Create a directory file
//    File fileTestFolder = new File(FileTest::pathTestFolder);
//
//    // getName() return the name of the file
//    String expected = "NonExistentFile.txt";
//    String actual = fileNonExistent.getName();
//    assertEquals(expected.toString(), actual.toString());
//
//    // getName() return the name of the directory
//    expected = FileTest::stringPathTestFolder;
//    actual = fileTestFolder.getName();
//    assertEquals(expected.toString(), actual.toString());
//}
//
//TEST (JavaIo, FileGetParent) {
//    // Create a  file has the file name
//    File fileNonExistent = new File(FileTest::pathNameNonExistent);
//
//    // Create a file doesn't has a file name
//    File fileTestFolder = new File(FileTest::pathTestFolder);
//
//    // Returns the pathname string of this abstract pathname's parent
//    String expected = FileTest::stringPathTestFolder;
//    String actual = fileNonExistent.getParent();
//    assertEquals(expected.toString(), actual.toString());
//
//    // Return null if this pathname does not name a parent directory
//    actual = fileTestFolder.getParent();
//    assertNull(actual);
//}
//
//TEST (JavaIo, FileGetParentFile) {
//    // Create a  file has the file name
//    File fileNonExistent = new File(FileTest::pathNameNonExistent);
//
//    // Create a file doesn't has a file name
//    File fileTestFolder = new File(FileTest::pathTestFolder);
//
//    // Returns the file of this abstract pathname's parent
//    String expected = FileTest::stringPathTestFolder;
//    File actual = fileNonExistent.getParentFile();
//    assertEquals(expected.toString(), actual.toString());
//
//    // Return null file if this pathname does not name a parent directory
//    actual = fileTestFolder.getParentFile();
//    assertNull(actual);
//}
//
//TEST (JavaIo, FileGetPath) {
//    // Create a file has file name
//    File fileNonExistent = new File(FileTest::pathNameNonExistent);
//
//    // Create a directory file
//    File fileTestFolder = new File(FileTest::pathTestFolder);
//
//    // getPath() return the name of the file
//    String expected = FileTest::stringPathNameNonExistent;
//    String actual = fileNonExistent.getPath();
//    assertEquals(expected.toString(), actual.toString());
//
//    // getPath() return the name of the directory
//    expected = FileTest::stringPathTestFolder;
//    actual = fileTestFolder.getPath();
//    assertEquals(expected.toString(), actual.toString());
//}
//
//TEST (JavaIo, FileGetTotalSpace) {
//    // Create a non-existent file
//    File fileNonExistent = new File(FileTest::pathNameNonExistent);
//
//    // Create an existent file
//    File fileExistent = new File(FileTest::pathNameExistent);
//
//    // Return 0 if the file is non existent
//    assertTrue(0 == fileNonExistent.getTotalSpace());
//
//    // Return != 0 if the file is existent
//    assertTrue(0 != fileExistent.getTotalSpace());
//}
//
//TEST (JavaIo, FileGetUsableSpace) {
//    // Create a non-existent file
//    File fileNonExistent = new File(FileTest::pathNameNonExistent);
//
//    // Create an existent file
//    File fileExistent = new File(FileTest::pathNameExistent);
//
//    // Return 0 if the file is non existent
//    assertTrue(0 == fileNonExistent.getUsableSpace());
//
//    // Return != 0 if the file is existent
//    assertTrue(0 != fileExistent.getUsableSpace());
//}
//
//TEST (JavaIo, FileIsAbsolute) {
//    File fileNotAbsolute = new File(FileTest::pathNameNotAbsolute);
//    File fileAbsolute = new File(FileTest::pathNameAbsolute);
//
//    assertFalse(fileNotAbsolute.isAbsolute());
//    assertTrue(fileAbsolute.isAbsolute());
//}
//
//TEST (JavaIo, FileIsDirectory) {
//    // Create a file has file name
//    File fileNonExistent = new File(FileTest::pathNameNonExistent);
//
//    // Create a directory file
//    File fileTestFolder = new File(FileTest::pathTestFolder);
//
//    // return FALSE if file is not a directory
//    assertFalse(fileNonExistent.isDirectory());
//
//    // return TRUE if file is a directory
//    assertTrue(fileTestFolder.isDirectory());
//}
//
//TEST (JavaIo, FileIsFile) {
//    // Create a directory file
//    File fileTestFolder = new File(FileTest::pathTestFolder);
//
//    // Create a file from a non-existent path
//    File fileNonExistent = new File(FileTest::pathNameNonExistent);
//
//    // Create a file from a existent path
//    File fileExistent = new File(FileTest::pathNameExistent);
//
//    // return FALSE if file is a directory
//    assertFalse(fileTestFolder.isFile());
//
//    // return FALSE if file is non-existent
//    assertFalse(fileNonExistent.isFile());
//
//    // return TRUE if file is existent
//    assertTrue(fileExistent.isFile());
//}
//
//TEST (JavaIo, FileIsHidden) {
//    // Create a directory file
//    File fileTestFolder = new File(FileTest::pathTestFolder);
//
//    // Create a file from a non-existent path
//    File fileNonExistent = new File(FileTest::pathNameNonExistent);
//
//    // Create a file from an existent path
//    File fileExistent = new File(FileTest::pathNameExistent);
//
//    // Create a file from an existent hidden path
//    File fileHidden = new File(FileTest::pathNameHidden);
//
//    // return FALSE if file is a directory
//    assertFalse(fileTestFolder.isHidden());
//
//    // return FALSE if file is non-existent
//    assertFalse(fileNonExistent.isHidden());
//
//    // return FALSE if file is existent
//    assertFalse(fileExistent.isHidden());
//
//    // return TRUE if file is hidden
////		assertTrue(fileHidden.isHidden());
//}
//
//TEST (JavaIo, FileLastModified) {
//    // Create a directory file
//    File fileTestFolder = new File(FileTest::pathTestFolder);
//
//    // Create a file from a non-existent path
//    File fileNonExistent = new File(FileTest::pathNameNonExistent);
//
//    // Create a file from an existent path
//    File fileExistent = new File(FileTest::pathNameExistent);
//
//    assertTrue(0 != fileTestFolder.lastModified());
//    assertTrue(0 == fileNonExistent.lastModified());
//    assertTrue(0 != fileExistent.lastModified());
//}
//
//TEST (JavaIo, FileLength) {
//    // Create a directory file
//    File fileTestFolder = new File(FileTest::pathTestFolder);
//
//    // Create a file from a non-existent path
//    File fileNonExistent = new File(FileTest::pathNameNonExistent);
//
//    // Create a file from an existent path
//    File fileExistent = new File(FileTest::pathNameExistent);
//
//    assertEquals(0, fileTestFolder.length());
//    assertEquals(0, fileNonExistent.length());
//    assertEquals(0, fileExistent.length());
//}
//
//TEST (JavaIo, FileList) {
//    // Test a not empty directory
//    File fileTestFolder = new File(FileTest::pathTestFolder);
//    String[] expected = {"ExistentFile.txt", "HiddenFile.txt", "SubFolder"};
//    String[] actual = fileTestFolder.list();
//    assertEquals(expected[0].toString(), actual[0].toString());
//    assertEquals(expected[1].toString(), actual[1].toString());
//    assertEquals(expected[2].toString(), actual[2].toString());
//    assertEquals(3, actual.length);
//
//    // Test an empty directory
//    File fileSubFolder = new File(FileTest::pathTestFolder + "SubFolder");
//    assertTrue(fileSubFolder.exists());
//    actual = fileSubFolder.list();
//    assertEquals(0, actual.length);
//}
//
//TEST (JavaIo, FileListFiles) {
//    // Test a not empty directory
//    File fileTestFolder = new File(FileTest::pathTestFolder);
//    File fileExistent = new File(FileTest::pathNameExistent);
//    File fileHidden = new File(FileTest::pathNameHidden);
//    File fileSubFolder = new File(FileTest::pathTestFolder + "SubFolder");
//    File[] expected = {fileExistent, fileHidden, fileSubFolder};
//    File[] actual = fileTestFolder.listFiles();
//    assertEquals(expected[0].toString(), actual[0].toString());
//    assertEquals(expected[1].toString(), actual[1].toString());
//    assertEquals(expected[2].toString(), actual[2].toString());
//    assertEquals(3, actual.length);
//
//    // Test an empty directory
//    assertTrue(fileSubFolder.exists());
//    actual = fileSubFolder.listFiles();
//    assertEquals(0, actual.length);
//}
//
//TEST (JavaIo, FileListRoots) {
//
//    if (FileTest::isWindows) {
//        // Test a not empty directory
//        File fileCDrive = new File("C:\\");
//        File fileDDrive = new File("D:\\");
//        File fileEDrive = new File("E:\\");
//        File[] expected = {fileCDrive, fileDDrive, fileEDrive};
//        File[] actual = File.listRoots();
//        assertEquals(expected[0].toString(), actual[0].toString());
//        assertEquals(expected[1].toString(), actual[1].toString());
//        assertEquals(expected[2].toString(), actual[2].toString());
//        assertEquals(3, actual.length);
//    }
//}
//
//TEST (JavaIo, FileMkdir) {
//    // Create an existent directory file
//    File fileTestFolder = new File(FileTest::pathTestFolder);
//
//    // Create a non-existent directory file
//    File fileNonExistentFolder
//            = new File(FileTest::pathNameNonExistentFolder + "NonExistentFile.txt");
//
//    // Create a file from a non-existent path
//    File fileNonExistent = new File(FileTest::pathNameNonExistent);
//
//    // Create a file from a existent path
//    File fileExistent = new File(FileTest::pathNameExistent);
//
//    // return FALSE if a directory file is existent and do nothing
//    assertFalse(fileTestFolder.mkdir());
//
//    // return FALSE if file is existent and do nothing
//    assertFalse(fileExistent.mkdir());
//
//    // return FALSE if the parent directory is non-existent
//    assertFalse(fileNonExistentFolder.mkdir());
//
//    // return TRUE if file is non-existent,
//    // and creates the directory named by this abstract pathname.
//    assertTrue(fileNonExistent.mkdir());
//    assertTrue(fileNonExistent.exists());
//
//    // delete file after testing
//    fileNonExistent.delete ();
//}
//
//TEST (JavaIo, FileMkdirs) {
//    // Create an existent directory file
//    File fileTestFolder = new File(FileTest::pathTestFolder);
//
//    // Create a non-existent directory file
//    File fileNonExistentFolder
//            = new File(FileTest::pathNameNonExistentFolder);
//    File fileNonExistentFolderFile
//            = new File(FileTest::pathNameNonExistentFolder + "NonExistentFile.txt");
//
//    // Create a file from a non-existent path
//    File fileNonExistent = new File(FileTest::pathNameNonExistent);
//
//    // Create a file from a existent path
//    File fileExistent = new File(FileTest::pathNameExistent);
//
//    // return FALSE if a directory file is existent and do nothing
//    assertFalse(fileTestFolder.mkdirs());
//
//    // return FALSE if file is existent and do nothing
//    assertFalse(fileExistent.mkdirs());
//
//    // return TRUE if the parent directory is non-existent
//    // and create the file
//    assertTrue(fileNonExistentFolderFile.mkdirs());
//    assertTrue(fileNonExistentFolder.exists());
//    assertTrue(fileNonExistentFolder.exists());
//
//    // return TRUE if file is non-existent,
//    // and creates the directory named by this abstract pathname.
//    assertTrue(fileNonExistent.mkdirs());
//    assertTrue(fileNonExistent.exists());
//
//    // delete file after testing
//    fileNonExistentFolder.deleteOnExit();
//    fileNonExistentFolderFile.deleteOnExit();
//    assertTrue(fileNonExistent.delete ());
//}
//
//TEST (JavaIo, FileRenameTo) {
//    // Create a file from a non-existent file path
//    File fileNonExistentFile = new File(FileTest::pathNameNonExistent);
//
//    // Create a file form a non-existent folder path
//    File fileNonExistentFoler = new File(FileTest::pathNameNonExistentFolder);
//
//    // Create a file from an existent path
//    File fileExistent = new File(FileTest::pathNameExistent);
//
//    // Create a file from an existent folder path
//    File fileExistentFolder = new File(FileTest::pathTestFolder);
//
//    // Create a new file to test
//    File fileTest = new File("Test/");
//
//    // return FALSE if fileTest is non-existent
//    assertFalse(fileTest.renameTo(fileExistent));
//    assertFalse(fileTest.renameTo(fileNonExistentFoler));
//    assertFalse(fileTest.renameTo(fileExistentFolder));
//
//    /* Create a File object for fileTest variable */
//    // After that: renameTo() will return TRUE with the non-existent destination
//    assertTrue(fileTest.createNewFile());
//    assertTrue(fileTest.exists());
//    assertFalse(fileTest.renameTo(fileExistentFolder));
//
//    // Return FALSE with fileNonExistentFoler,
//    // and create a new file for fileNonExistentFoler
//    assertFalse(fileTest.renameTo(fileNonExistentFoler));
//    assertEquals("Test", fileTest.toString());
//
//    // Create a destination fileNewTest
//    File fileNewTest = new File("NewTest");
//
//    // Make sure the fileTest is Existent, fileNewTest is non-existent
//    assertTrue(fileTest.exists());
//    assertFalse(fileNewTest.exists());
//
//    // Return TRUE. The fileTest was moved into fileNewTest
//    assertTrue(fileTest.renameTo(fileNewTest));
//    assertFalse(fileTest.exists());
//    assertTrue(fileNewTest.exists());
//
//    // Delete file after testing
//    fileNewTest.deleteOnExit();
//    fileNonExistentFoler.delete ();
//}
//
//TEST (JavaIo, FileToString) {
//    File fileTestFolder = new File(FileTest::pathTestFolder);
//    assertEquals(FileTest::stringPathTestFolder.toString(), fileTestFolder.toString());
//}
//
//TEST (JavaIo, FileToUri) {
//    URI uri = new URI(FileTest::pathUri);
//    File fileUri = new File(uri);
//    assertEquals(FileTest::stringUriPath.toString(), fileUri.toString());
//    assertEquals("file:/E:/Users/admin/test.txt", fileUri.toURI().toString());
//}
//
//TEST (JavaIo, FileToUrl) {
//    URI uri = new URI(FileTest::pathUri);
//    File fileUri = new File(uri);
//    assertEquals(FileTest::stringUriPath.toString(), fileUri.toString());
//    assertEquals("file:/E:/Users/admin/test.txt", fileUri.toURL().toString());
//}
//
//TEST (JavaIo, FileSystem) {
//    String command = "mkdir ";
//    String testFolder = "testFolder";
//    String actual = command + testFolder;
//    system(actual.toString());
//}
//
//#endif