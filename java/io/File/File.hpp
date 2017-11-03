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

#ifndef JAVA_IO_FILE_FILE_HPP_
#define JAVA_IO_FILE_FILE_HPP_

#include <stdlib.h>
#include <memory>
#include <sys/types.h>
#include <sys/stat.h> // mkdir
#include <limits.h>

#include <stdio.h>
#include <ftw.h> // deletes
#include <unistd.h> // access()

// obtaining file size
#include <iostream>

// Get file list
#include <glob.h>
#include <dirent.h>
#include<fstream>

// Get owner
#include <pwd.h>

// Get group
#include <grp.h>

// Get free space
#include <sys/statvfs.h>

// strmode: convert numeric file mode to string representation
#include <string.h>

// WEXITSTATUS
#include <sys/wait.h>

// isHidden
//#include <windows.h>

//#undef boolean

//#define boolean aaa_boolean
//#include "../../lang/Object/Object.hpp"
//#undef  boolean
//#define boolean bbb_boolean
//#include <windows.h>
//#undef  boolean
//#define boolean ambiguous use aaa_boolean or bbb_boolean

//#define boolean abcdef
//#include <windows.h>
//#undef boolean
//
//#undef boolean

#include "../../lang/String/String.hpp"
#include "../../lang/StringBuffer/StringBuffer.hpp"
#include "../../../kernel/type.h"
#include "../../lang/RuntimeException/RuntimeException.hpp"
#include "../../lang/SecurityException/SecurityException.hpp"
#include "../../lang/Exception/Exception.hpp"
#include "../../lang/IllegalArgumentException/IllegalArgumentException.hpp"
#include "../../util/Arrays/Arrays.hpp"

using namespace Java::Lang;

namespace Java {
    namespace Io {
        class File :
                virtual public Serializable,
                virtual public Comparable<File> {

        public:
            /**
             * Creates a new File instance by converting the given
             * pathname string into an abstract pathname.  If the given string is
             * the empty string, then the result is the empty abstract pathname.
             *
             * @param   pathname  A pathname string
             * @throws  NullPointerException
             *          If the pathname argument is null
             */
            File(String pathname);

            /**
             * The system-dependent default name-separator character.  This field is
             * initialized to contain the first character of the value of the system
             * property <code>file.separator</code>.  On UNIX systems the value of this
             * field is <code>'/'</code>; on Microsoft Windows systems it is <code>'\\'</code>.
             *
             * @see     java.lang.System#getProperty(java.lang.String)
             */
            static const char separatorChar = '/';

        public:
            /**
             * Compares two abstract pathnames lexicographically.  The ordering
             * defined by this method depends upon the underlying system.  On UNIX
             * systems, alphabetic case is significant in comparing pathnames;
             * on Microsoft Windows systems it is not.
             *
             * @param   pathname  The abstract pathname to be compared to this abstract
             *                    pathname
             *
             * @return  Zero if the argument is equal to this abstract pathname, a
             *          value less than zero if this abstract pathname is
             *          lexicographically less than the argument, or a value greater
             *          than zero if this abstract pathname is lexicographically
             *          greater than the argument
             */
            int compareTo(const File &pathname) const override;

            /**
             * Returns the pathname string of this abstract pathname.
             * This is just the string returned by the getPath method.
             *
             * @return  The string form of this abstract pathname
             */
            String toString();

            /**
             * Converts this abstract pathname into a pathname string.  The resulting
             * string uses the separator default name-separator character} to
             * separate the names in the name sequence.
             *
             * @return  The string form of this abstract pathname
             */
            String getPath();

            /**
             * Execute command
             *
             * @param command
             * @return a String contains result of command
             */
            static String executeCommand(String command, int &exitCode);


            static String executeCommand(String command);

            /**
             * Creates the directory named by this abstract pathname.
             *
             * @return  true if and only if the directory was
             *          created; false otherwise
             *
             * @throws  SecurityException
             *          If a security manager exists and its
             *          method does not permit the named directory to be created
             */
            boolean mkdir();

            /**
             * Creates the directory named by this abstract pathname, including any
             * necessary but nonexistent parent directories.  Note that if this
             * operation fails it may have succeeded in creating some of the necessary
             * parent directories.
             *
             * @return  true if and only if the directory was created,
             *          along with all necessary parent directories; false
             *          otherwise
             *
             * @throws  SecurityException
             *          If a security manager exists and its
             *          method does not permit verification of the existence of the
             *          named directory and all necessary parent directories; or if
             *          the method does not permit the named directory
             *          and all necessary parent directories to be created
             */
            boolean mkdirs();

            /**
             * Atomically creates a new, empty file named by this abstract pathname if
             * and only if a file with this name does not yet exist.  The check for the
             * existence of the file and the creation of the file if it does not exist
             * are a single operation that is atomic with respect to all other
             * filesystem activities that might affect the file.
             *
             * Note: this method should not be used for file-locking, as
             * the resulting protocol cannot be made to work reliably.
             * The facility should be used instead.
             *
             * @return  true if the named file does not exist and was
             *          successfully created; false if the named file
             *          already exists
             *
             * @throws  IOException
             *          If an I/O error occurred
             *
             * @throws  SecurityException
             *          If a security manager exists and its
             *          method denies write access to the file
             */
            boolean createNewFile();

            /**
             * Tests whether the file denoted by this abstract pathname is a
             * directory.
             *
             * Where it is required to distinguish an I/O exception from the case
             * that the file is not a directory, or where several attributes of the
             * same file are required at the same time, then the
             * method may be used.
             *
             * @return true if and only if the file denoted by this
             *          abstract pathname exists and is a directory;
             *          false otherwise
             *
             * @throws  SecurityException
             *          If a security manager exists and its
             *          method denies read access to the file
             */
            boolean isDirectory();

            /**
             * Tests whether the file denoted by this abstract pathname is a normal
             * file.  A file is normal if it is not a directory and, in
             * addition, satisfies other system-dependent criteria.  Any non-directory
             * file created by a Java application is guaranteed to be a normal file.
             *
             * Where it is required to distinguish an I/O exception from the case
             * that the file is not a normal file, or where several attributes of the
             * same file are required at the same time, then the
             * java.nio.file.Files#readAttributes(Path,Class,LinkOption[])
             * Files.readAttributes method may be used.
             *
             * @return  true if and only if the file denoted by this
             *          abstract pathname exists and is a normal file;
             *          false otherwise
             *
             * @throws  SecurityException
             *          If a security manager exists and its
             *          java.lang.SecurityManager#checkRead(java.lang.String)
             *          method denies read access to the file
             */
            boolean isFile();

            /**
             * Deletes the file or directory denoted by this abstract pathname.  If
             * this pathname denotes a directory, then the directory must be empty in
             * order to be deleted.
             *
             * Note that the java.nio.file.Files class defines the
             * java.nio.file.Files#delete(Path) delete method to throw an IOException
             * when a file cannot be deleted. This is useful for error reporting and to
             * diagnose why a file cannot be deleted.
             *
             * @return  true if and only if the file or directory is
             *          successfully deleted; false otherwise
             *
             * @throws  SecurityException
             *          If a security manager exists and its
             *          java.lang.SecurityManager#checkDelete method denies
             *          delete access to the file
             */
            boolean deletes();

            /**
             * Tests whether the file or directory denoted by this abstract pathname
             * exists.
             *
             * @return  true if and only if the file or directory denoted
             *          by this abstract pathname exists; false otherwise
             *
             * @throws  SecurityException
             *          If a security manager exists and its
             *          method denies read access to the file or directory
             */
            boolean exists();

            /**
            * Tests whether the application can execute the file denoted by this
            * abstract pathname. On some platforms it may be possible to start the
            * Java virtual machine with special privileges that allow it to execute
            * files that are not marked executable. Consequently this method may return
            * {@code true} even though the file does not have execute permissions.
            *
            * @return  <code>true</code> if and only if the abstract pathname exists
            *          <em>and</em> the application is allowed to execute the file
            *
            * @throws  SecurityException
            *          If a security manager exists and its <code>{@link
            *          java.lang.SecurityManager#checkExec(java.lang.String)}</code>
            *          method denies execute access to the file
            *
            * @since 1.6
            */
            boolean canExecute();

            /**
             * A convenience method to set the owner's execute permission for this
             * abstract pathname. On some platforms it may be possible to start the Java
             * virtual machine with special privileges that allow it to execute files
             * that are not marked executable.
             *
             * <p>An invocation of this method of the form <tt>file.setExcutable(arg)</tt>
             * behaves in exactly the same way as the invocation
             *
             * <pre>
             *     file.setExecutable(arg, true) </pre>
             *
             * @param   executable
             *          If <code>true</code>, sets the access permission to allow execute
             *          operations; if <code>false</code> to disallow execute operations
             *
             * @return   <code>true</code> if and only if the operation succeeded.  The
             *           operation will fail if the user does not have permission to
             *           change the access permissions of this abstract pathname.  If
             *           <code>executable</code> is <code>false</code> and the underlying
             *           file system does not implement an execute permission, then the
             *           operation will fail.
             *
             * @throws  SecurityException
             *          If a security manager exists and its <code>{@link
             *          java.lang.SecurityManager#checkWrite(java.lang.String)}</code>
             *          method denies write access to the file
             *
             * @since 1.6
             */
            boolean setExecutable(boolean executable);

            /**
             * Sets the owner's or everybody's execute permission for this abstract
             * pathname. On some platforms it may be possible to start the Java virtual
             * machine with special privileges that allow it to execute files that are
             * not marked executable.
             *
             * <p> The {@link java.nio.file.Files} class defines methods that operate on
             * file attributes including file permissions. This may be used when finer
             * manipulation of file permissions is required.
             *
             * @param   executable
             *          If <code>true</code>, sets the access permission to allow execute
             *          operations; if <code>false</code> to disallow execute operations
             *
             * @param   ownerOnly
             *          If <code>true</code>, the execute permission applies only to the
             *          owner's execute permission; otherwise, it applies to everybody.
             *          If the underlying file system can not distinguish the owner's
             *          execute permission from that of others, then the permission will
             *          apply to everybody, regardless of this value.
             *
             * @return  <code>true</code> if and only if the operation succeeded.  The
             *          operation will fail if the user does not have permission to
             *          change the access permissions of this abstract pathname.  If
             *          <code>executable</code> is <code>false</code> and the underlying
             *          file system does not implement an execute permission, then the
             *          operation will fail.
             *
             * @throws  SecurityException
             *          If a security manager exists and its <code>{@link
             *          java.lang.SecurityManager#checkWrite(java.lang.String)}</code>
             *          method denies write access to the file
             *
             * @since 1.6
             */
            boolean setExecutable(boolean executable, boolean ownerOnly);

            /**
             * Tests whether the application can read the file denoted by this
             * abstract pathname. On some platforms it may be possible to start the
             * Java virtual machine with special privileges that allow it to read
             * files that are marked as unreadable. Consequently this method may return
             * {@code true} even though the file does not have read permissions.
             *
             * @return  <code>true</code> if and only if the file specified by this
             *          abstract pathname exists <em>and</em> can be read by the
             *          application; <code>false</code> otherwise
             *
             * @throws  SecurityException
             *          If a security manager exists and its <code>{@link
             *          java.lang.SecurityManager#checkRead(java.lang.String)}</code>
             *          method denies read access to the file
             */
              boolean canRead();

            /**
             * Tests whether the application can modify the file denoted by this
             * abstract pathname. On some platforms it may be possible to start the
             * Java virtual machine with special privileges that allow it to modify
             * files that are marked read-only. Consequently this method may return
             * {@code true} even though the file is marked read-only.
             *
             * @return  <code>true</code> if and only if the file system actually
             *          contains a file denoted by this abstract pathname <em>and</em>
             *          the application is allowed to write to the file;
             *          <code>false</code> otherwise.
             *
             * @throws  SecurityException
             *          If a security manager exists and its <code>{@link
             *          java.lang.SecurityManager#checkWrite(java.lang.String)}</code>
             *          method denies write access to the file
             */
              boolean canWrite();

            /**
             * Marks the file or directory named by this abstract pathname so that
             * only read operations are allowed. After invoking this method the file
             * or directory will not change until it is either deleted or marked
             * to allow write access. On some platforms it may be possible to start the
             * Java virtual machine with special privileges that allow it to modify
             * files that are marked read-only. Whether or not a read-only file or
             * directory may be deleted depends upon the underlying system.
             *
             * @return <code>true</code> if and only if the operation succeeded;
             *          <code>false</code> otherwise
             *
             * @throws  SecurityException
             *          If a security manager exists and its <code>{@link
             *          java.lang.SecurityManager#checkWrite(java.lang.String)}</code>
             *          method denies write access to the named file
             *
             * @since 1.2
             */
            boolean setReadOnly();

            /**
             * Sets the owner's or everybody's read permission for this abstract
             * pathname. On some platforms it may be possible to start the Java virtual
             * machine with special privileges that allow it to read files that are
             * marked as unreadable.
             *
             * <p> The {@link java.nio.file.Files} class defines methods that operate on
             * file attributes including file permissions. This may be used when finer
             * manipulation of file permissions is required.
             *
             * @param   readable
             *          If <code>true</code>, sets the access permission to allow read
             *          operations; if <code>false</code> to disallow read operations
             *
             * @param   ownerOnly
             *          If <code>true</code>, the read permission applies only to the
             *          owner's read permission; otherwise, it applies to everybody.  If
             *          the underlying file system can not distinguish the owner's read
             *          permission from that of others, then the permission will apply to
             *          everybody, regardless of this value.
             *
             * @return  <code>true</code> if and only if the operation succeeded.  The
             *          operation will fail if the user does not have permission to
             *          change the access permissions of this abstract pathname.  If
             *          <code>readable</code> is <code>false</code> and the underlying
             *          file system does not implement a read permission, then the
             *          operation will fail.
             *
             * @throws  SecurityException
             *          If a security manager exists and its <code>{@link
             *          java.lang.SecurityManager#checkWrite(java.lang.String)}</code>
             *          method denies write access to the file
             *
             * @since 1.6
             */
            boolean setReadable(boolean readable, boolean ownerOnly);

            /**
             * A convenience method to set the owner's read permission for this abstract
             * pathname. On some platforms it may be possible to start the Java virtual
             * machine with special privileges that allow it to read files that that are
             * marked as unreadable.
             *
             * <p>An invocation of this method of the form <tt>file.setReadable(arg)</tt>
             * behaves in exactly the same way as the invocation
             *
             * <pre>
             *     file.setReadable(arg, true) </pre>
             *
             * @param  readable
             *          If <code>true</code>, sets the access permission to allow read
             *          operations; if <code>false</code> to disallow read operations
             *
             * @return  <code>true</code> if and only if the operation succeeded.  The
             *          operation will fail if the user does not have permission to
             *          change the access permissions of this abstract pathname.  If
             *          <code>readable</code> is <code>false</code> and the underlying
             *          file system does not implement a read permission, then the
             *          operation will fail.
             *
             * @throws  SecurityException
             *          If a security manager exists and its <code>{@link
             *          java.lang.SecurityManager#checkWrite(java.lang.String)}</code>
             *          method denies write access to the file
             *
             * @since 1.6
             */
            boolean setReadable(boolean readable);

            /**
             * A convenience method to set the owner's write permission for this abstract
             * pathname. On some platforms it may be possible to start the Java virtual
             * machine with special privileges that allow it to modify files that
             * disallow write operations.
             *
             * <p> An invocation of this method of the form <tt>file.setWritable(arg)</tt>
             * behaves in exactly the same way as the invocation
             *
             * <pre>
             *     file.setWritable(arg, true) </pre>
             *
             * @param   writable
             *          If <code>true</code>, sets the access permission to allow write
             *          operations; if <code>false</code> to disallow write operations
             *
             * @return  <code>true</code> if and only if the operation succeeded.  The
             *          operation will fail if the user does not have permission to
             *          change the access permissions of this abstract pathname.
             *
             * @throws  SecurityException
             *          If a security manager exists and its <code>{@link
             *          java.lang.SecurityManager#checkWrite(java.lang.String)}</code>
             *          method denies write access to the file
             *
             * @since 1.6
             */
            boolean setWritable(boolean writable);

            /**
            * Sets the owner's or everybody's write permission for this abstract
            * pathname. On some platforms it may be possible to start the Java virtual
            * machine with special privileges that allow it to modify files that
            * disallow write operations.
            *
            * <p> The {@link java.nio.file.Files} class defines methods that operate on
            * file attributes including file permissions. This may be used when finer
            * manipulation of file permissions is required.
            *
            * @param   writable
            *          If <code>true</code>, sets the access permission to allow write
            *          operations; if <code>false</code> to disallow write operations
            *
            * @param   ownerOnly
            *          If <code>true</code>, the write permission applies only to the
            *          owner's write permission; otherwise, it applies to everybody.  If
            *          the underlying file system can not distinguish the owner's write
            *          permission from that of others, then the permission will apply to
            *          everybody, regardless of this value.
            *
            * @return  <code>true</code> if and only if the operation succeeded. The
            *          operation will fail if the user does not have permission to change
            *          the access permissions of this abstract pathname.
            *
            * @throws  SecurityException
            *          If a security manager exists and its <code>{@link
            *          java.lang.SecurityManager#checkWrite(java.lang.String)}</code>
            *          method denies write access to the named file
            *
            * @since 1.6
            */
            boolean setWritable(boolean writable, boolean ownerOnly);

            /**
             * Creates an empty file in the default temporary-file directory, using
             * the given prefix and suffix to generate its name. Invoking this method
             * is equivalent to invoking <code>{@link #createTempFile(java.lang.String,
             * java.lang.String, java.io.File)
             * createTempFile(prefix,&nbsp;suffix,&nbsp;null)}</code>.
             *
             * <p> The {@link
             * java.nio.file.Files#createTempFile(String,String,java.nio.file.attribute.FileAttribute[])
             * Files.createTempFile} method provides an alternative method to create an
             * empty file in the temporary-file directory. Files created by that method
             * may have more restrictive access permissions to files created by this
             * method and so may be more suited to security-sensitive applications.
             *
             * @param  prefix     The prefix string to be used in generating the file's
             *                    name; must be at least three characters long
             *
             * @param  suffix     The suffix string to be used in generating the file's
             *                    name; may be <code>null</code>, in which case the
             *                    suffix <code>".tmp"</code> will be used
             *
             * @return  An abstract pathname denoting a newly-created empty file
             *
             * @throws  IllegalArgumentException
             *          If the <code>prefix</code> argument contains fewer than three
             *          characters
             *
             * @throws  IOException  If a file could not be created
             *
             * @throws  SecurityException
             *          If a security manager exists and its <code>{@link
             *          java.lang.SecurityManager#checkWrite(java.lang.String)}</code>
             *          method does not allow a file to be created
             *
             * @since 1.2
             * @see java.nio.file.Files#createTempDirectory(String,FileAttribute[])
             */
            static File createTempFile(String prefix, String suffix);

            /**
             * <p> Creates a new empty file in the specified directory, using the
             * given prefix and suffix strings to generate its name.  If this method
             * returns successfully then it is guaranteed that:
             *
             * <ol>
             * <li> The file denoted by the returned abstract pathname did not exist
             *      before this method was invoked, and
             * <li> Neither this method nor any of its variants will return the same
             *      abstract pathname again in the current invocation of the virtual
             *      machine.
             * </ol>
             *
             * This method provides only part of a temporary-file facility.  To arrange
             * for a file created by this method to be deleted automatically, use the
             * <code>{@link #deleteOnExit}</code> method.
             *
             * <p> The <code>prefix</code> argument must be at least three characters
             * long.  It is recommended that the prefix be a short, meaningful string
             * such as <code>"hjb"</code> or <code>"mail"</code>.  The
             * <code>suffix</code> argument may be <code>null</code>, in which case the
             * suffix <code>".tmp"</code> will be used.
             *
             * <p> To create the new file, the prefix and the suffix may first be
             * adjusted to fit the limitations of the underlying platform.  If the
             * prefix is too long then it will be truncated, but its first three
             * characters will always be preserved.  If the suffix is too long then it
             * too will be truncated, but if it begins with a period character
             * (<code>'.'</code>) then the period and the first three characters
             * following it will always be preserved.  Once these adjustments have been
             * made the name of the new file will be generated by concatenating the
             * prefix, five or more internally-generated characters, and the suffix.
             *
             * <p> If the <code>directory</code> argument is <code>null</code> then the
             * system-dependent default temporary-file directory will be used.  The
             * default temporary-file directory is specified by the system property
             * <code>java.io.tmpdir</code>.  On UNIX systems the default value of this
             * property is typically <code>"/tmp"</code> or <code>"/var/tmp"</code>; on
             * Microsoft Windows systems it is typically <code>"C:\\WINNT\\TEMP"</code>.  A different
             * value may be given to this system property when the Java virtual machine
             * is invoked, but programmatic changes to this property are not guaranteed
             * to have any effect upon the temporary directory used by this method.
             *
             * @param  prefix     The prefix string to be used in generating the file's
             *                    name; must be at least three characters long
             *
             * @param  suffix     The suffix string to be used in generating the file's
             *                    name; may be <code>null</code>, in which case the
             *                    suffix <code>".tmp"</code> will be used
             *
             * @param  directory  The directory in which the file is to be created, or
             *                    <code>null</code> if the default temporary-file
             *                    directory is to be used
             *
             * @return  An abstract pathname denoting a newly-created empty file
             *
             * @throws  IllegalArgumentException
             *          If the <code>prefix</code> argument contains fewer than three
             *          characters
             *
             * @throws  IOException  If a file could not be created
             *
             * @throws  SecurityException
             *          If a security manager exists and its <code>{@link
             *          java.lang.SecurityManager#checkWrite(java.lang.String)}</code>
             *          method does not allow a file to be created
             *
             * @since 1.2
             */
            static File createTempFile(String prefix,
                                       String suffix,
                                       File directory);

            /**
             * Tests this abstract pathname for equality with the given file.
             * Returns <code>true</code> if and only if the argument is not
             * <code>null</code> and is an abstract pathname that denotes the same file
             * or directory as this abstract pathname.  Whether or not two abstract
             * pathnames are equal depends upon the underlying system.  On UNIX
             * systems, alphabetic case is significant in comparing pathnames; on Microsoft Windows
             * systems it is not.
             *
             * @param   inputFile   The file to be compared with this abstract pathname
             *
             * @return  <code>true</code> if and only if the files are the same;
             *          <code>false</code> otherwise
             */
            boolean equals(File inputFile);

            /**
             * Returns the absolute pathname string of this abstract pathname.
             *
             * <p> If this abstract pathname is already absolute, then the pathname
             * string is simply returned as if by the <code>{@link #getPath}</code>
             * method.  If this abstract pathname is the empty abstract pathname then
             * the pathname string of the current user directory, which is named by the
             * system property <code>user.dir</code>, is returned.  Otherwise this
             * pathname is resolved in a system-dependent way.  On UNIX systems, a
             * relative pathname is made absolute by resolving it against the current
             * user directory.  On Microsoft Windows systems, a relative pathname is made absolute
             * by resolving it against the current directory of the drive named by the
             * pathname, if any; if not, it is resolved against the current user
             * directory.
             *
             * @return  The absolute pathname string denoting the same file or
             *          directory as this abstract pathname
             *
             * @throws  SecurityException
             *          If a required system property value cannot be accessed.
             *
             * @see     java.io.File#isAbsolute()
             */
            String getAbsolutePath();

            /**
            * Returns the absolute form of this abstract pathname.  Equivalent to
            * <code>new&nbsp;File(this.{@link #getAbsolutePath})</code>.
            *
            * @return  The absolute abstract pathname denoting the same file or
            *          directory as this abstract pathname
            *
            * @throws  SecurityException
            *          If a required system property value cannot be accessed.
            *
            * @since 1.2
            */
            File getAbsoluteFile();

            /**
             * Returns the canonical pathname string of this abstract pathname.
             *
             * <p> A canonical pathname is both absolute and unique.  The precise
             * definition of canonical form is system-dependent.  This method first
             * converts this pathname to absolute form if necessary, as if by invoking the
             * {@link #getAbsolutePath} method, and then maps it to its unique form in a
             * system-dependent way.  This typically involves removing redundant names
             * such as <tt>"."</tt> and <tt>".."</tt> from the pathname, resolving
             * symbolic links (on UNIX platforms), and converting drive letters to a
             * standard case (on Microsoft Windows platforms).
             *
             * <p> Every pathname that denotes an existing file or directory has a
             * unique canonical form.  Every pathname that denotes a nonexistent file
             * or directory also has a unique canonical form.  The canonical form of
             * the pathname of a nonexistent file or directory may be different from
             * the canonical form of the same pathname after the file or directory is
             * created.  Similarly, the canonical form of the pathname of an existing
             * file or directory may be different from the canonical form of the same
             * pathname after the file or directory is deleted.
             *
             * @return  The canonical pathname string denoting the same file or
             *          directory as this abstract pathname
             *
             * @throws  IOException
             *          If an I/O error occurs, which is possible because the
             *          construction of the canonical pathname may require
             *          filesystem queries
             *
             * @throws  SecurityException
             *          If a required system property value cannot be accessed, or
             *          if a security manager exists and its <code>{@link
             *          java.lang.SecurityManager#checkRead}</code> method denies
             *          read access to the file
             *
             * @since   JDK1.1
             * @see     Path#toRealPath
             */
            String getCanonicalPath();

            /**
             * Returns the canonical form of this abstract pathname.  Equivalent to
             * <code>new&nbsp;File(this.{@link #getCanonicalPath})</code>.
             *
             * @return  The canonical pathname string denoting the same file or
             *          directory as this abstract pathname
             *
             * @throws  IOException
             *          If an I/O error occurs, which is possible because the
             *          construction of the canonical pathname may require
             *          filesystem queries
             *
             * @throws  SecurityException
             *          If a required system property value cannot be accessed, or
             *          if a security manager exists and its <code>{@link
             *          java.lang.SecurityManager#checkRead}</code> method denies
             *          read access to the file
             *
             * @since 1.2
             * @see     Path#toRealPath
             */
            File getCanonicalFile();

            /**
             * Renames the file denoted by this abstract pathname.
             *
             * <p> Many aspects of the behavior of this method are inherently
             * platform-dependent: The rename operation might not be able to move a
             * file from one filesystem to another, it might not be atomic, and it
             * might not succeed if a file with the destination abstract pathname
             * already exists.  The return value should always be checked to make sure
             * that the rename operation was successful.
             *
             * <p> Note that the {@link java.nio.file.Files} class defines the {@link
             * java.nio.file.Files#move move} method to move or rename a file in a
             * platform independent manner.
             *
             * @param  destinationFile  The new abstract pathname for the named file
             *
             * @return  <code>true</code> if and only if the renaming succeeded;
             *          <code>false</code> otherwise
             *
             * @throws  SecurityException
             *          If a security manager exists and its <code>{@link
             *          java.lang.SecurityManager#checkWrite(java.lang.String)}</code>
             *          method denies write access to either the old or new pathnames
             *
             * @throws  NullPointerException
             *          If parameter <code>dest</code> is <code>null</code>
             */
            boolean renameTo(File destinationFile);

            /**
             * Returns the time that the file denoted by this abstract pathname was
             * last modified.
             *
             * <p> Where it is required to distinguish an I/O exception from the case
             * where {@code 0L} is returned, or where several attributes of the
             * same file are required at the same time, or where the time of last
             * access or the creation time are required, then the {@link
             * java.nio.file.Files#readAttributes(Path,Class,LinkOption[])
             * Files.readAttributes} method may be used.
             *
             * @return  A <code>long</code> value representing the time the file was
             *          last modified, measured in milliseconds since the epoch
             *          (00:00:00 GMT, January 1, 1970), or <code>0L</code> if the
             *          file does not exist or if an I/O error occurs
             *
             * @throws  SecurityException
             *          If a security manager exists and its <code>{@link
             *          java.lang.SecurityManager#checkRead(java.lang.String)}</code>
             *          method denies read access to the file
             */
            long lastModified();

            /**
             * Returns the length of the file denoted by this abstract pathname.
             * The return value is unspecified if this pathname denotes a directory.
             *
             * <p> Where it is required to distinguish an I/O exception from the case
             * that {@code 0L} is returned, or where several attributes of the same file
             * are required at the same time, then the {@link
             * java.nio.file.Files#readAttributes(Path,Class,LinkOption[])
             * Files.readAttributes} method may be used.
             *
             * @return  The length, in bytes, of the file denoted by this abstract
             *          pathname, or <code>0L</code> if the file does not exist.  Some
             *          operating systems may return <code>0L</code> for pathnames
             *          denoting system-dependent entities such as devices or pipes.
             *
             * @throws  SecurityException
             *          If a security manager exists and its <code>{@link
             *          java.lang.SecurityManager#checkRead(java.lang.String)}</code>
             *          method denies read access to the file
             */
            long length();

            /**
             * Returns an array of strings naming the files and directories in the
             * directory denoted by this abstract pathname.
             *
             * <p> If this abstract pathname does not denote a directory, then this
             * method returns {@code null}.  Otherwise an array of strings is
             * returned, one for each file or directory in the directory.  Names
             * denoting the directory itself and the directory's parent directory are
             * not included in the result.  Each string is a file name rather than a
             * complete path.
             *
             * <p> There is no guarantee that the name strings in the resulting array
             * will appear in any specific order; they are not, in particular,
             * guaranteed to appear in alphabetical order.
             *
             * <p> Note that the {@link java.nio.file.Files} class defines the {@link
             * java.nio.file.Files#newDirectoryStream(Path) newDirectoryStream} method to
             * open a directory and iterate over the names of the files in the directory.
             * This may use less resources when working with very large directories, and
             * may be more responsive when working with remote directories.
             *
             * @return  An array of strings naming the files and directories in the
             *          directory denoted by this abstract pathname.  The array will be
             *          empty if the directory is empty.  Returns {@code null} if
             *          this abstract pathname does not denote a directory, or if an
             *          I/O error occurs.
             *
             * @throws  SecurityException
             *          If a security manager exists and its {@link
             *          SecurityManager#checkRead(String)} method denies read access to
             *          the directory
             */
            Array<String> list();

            /**
             * Sets the last-modified time of the file or directory named by this
             * abstract pathname.
             *
             * <p> All platforms support file-modification times to the nearest second,
             * but some provide more precision.  The argument will be truncated to fit
             * the supported precision.  If the operation succeeds and no intervening
             * operations on the file take place, then the next invocation of the
             * <code>{@link #lastModified}</code> method will return the (possibly
             * truncated) <code>time</code> argument that was passed to this method.
             *
             * @param  time  The new last-modified time, measured in milliseconds since
             *               the epoch (00:00:00 GMT, January 1, 1970)
             *
             * @return <code>true</code> if and only if the operation succeeded;
             *          <code>false</code> otherwise
             *
             * @throws  IllegalArgumentException  If the argument is negative
             *
             * @throws  SecurityException
             *          If a security manager exists and its <code>{@link
             *          java.lang.SecurityManager#checkWrite(java.lang.String)}</code>
             *          method denies write access to the named file
             *
             * @since 1.2
             */
             boolean setLastModified(long time);

            /**
             * Returns the number of unallocated bytes in the partition <a
             * href="#partName">named</a> by this abstract path name.
             *
             * <p> The returned number of unallocated bytes is a hint, but not
             * a guarantee, that it is possible to use most or any of these
             * bytes.  The number of unallocated bytes is most likely to be
             * accurate immediately after this call.  It is likely to be made
             * inaccurate by any external I/O operations including those made
             * on the system outside of this virtual machine.  This method
             * makes no guarantee that write operations to this file system
             * will succeed.
             *
             * @return  The number of unallocated bytes on the partition or <tt>0L</tt>
             *          if the abstract pathname does not name a partition.  This
             *          value will be less than or equal to the total file system size
             *          returned by {@link #getTotalSpace}.
             *
             * @throws  SecurityException
             *          If a security manager has been installed and it denies
             *          {@link RuntimePermission}<tt>("getFileSystemAttributes")</tt>
             *          or its {@link SecurityManager#checkRead(String)} method denies
             *          read access to the file named by this abstract pathname
             *
             * @since  1.6
             */
             long getFreeSpace();

            /**
             * Returns the name of the file or directory denoted by this abstract
             * pathname.  This is just the last name in the pathname's name
             * sequence.  If the pathname's name sequence is empty, then the empty
             * string is returned.
             *
             * @return  The name of the file or directory denoted by this abstract
             *          pathname, or the empty string if this pathname's name sequence
             *          is empty
             */
             String getName();

            /**
             * Returns the pathname string of this abstract pathname's parent, or
             * <code>null</code> if this pathname does not name a parent directory.
             *
             * <p> The <em>parent</em> of an abstract pathname consists of the
             * pathname's prefix, if any, and each name in the pathname's name
             * sequence except for the last.  If the name sequence is empty then
             * the pathname does not name a parent directory.
             *
             * @return  The pathname string of the parent directory named by this
             *          abstract pathname, or <code>null</code> if this pathname
             *          does not name a parent
             */
             String getParent();

            /**
             * Returns the abstract pathname of this abstract pathname's parent,
             * or <code>null</code> if this pathname does not name a parent
             * directory.
             *
             * <p> The <em>parent</em> of an abstract pathname consists of the
             * pathname's prefix, if any, and each name in the pathname's name
             * sequence except for the last.  If the name sequence is empty then
             * the pathname does not name a parent directory.
             *
             * @return  The abstract pathname of the parent directory named by this
             *          abstract pathname, or <code>null</code> if this pathname
             *          does not name a parent
             *
             * @since 1.2
             */
             File getParentFile();

            /**
             * Returns the size of the partition <a href="#partName">named</a> by this
             * abstract pathname.
             *
             * @return  The size, in bytes, of the partition or <tt>0L</tt> if this
             *          abstract pathname does not name a partition
             *
             * @throws  SecurityException
             *          If a security manager has been installed and it denies
             *          {@link RuntimePermission}<tt>("getFileSystemAttributes")</tt>
             *          or its {@link SecurityManager#checkRead(String)} method denies
             *          read access to the file named by this abstract pathname
             *
             * @since  1.6
             */
             long getTotalSpace();

            /**
             * Returns the number of bytes available to this virtual machine on the
             * partition <a href="#partName">named</a> by this abstract pathname.  When
             * possible, this method checks for write permissions and other operating
             * system restrictions and will therefore usually provide a more accurate
             * estimate of how much new data can actually be written than {@link
             * #getFreeSpace}.
             *
             * <p> The returned number of available bytes is a hint, but not a
             * guarantee, that it is possible to use most or any of these bytes.  The
             * number of unallocated bytes is most likely to be accurate immediately
             * after this call.  It is likely to be made inaccurate by any external
             * I/O operations including those made on the system outside of this
             * virtual machine.  This method makes no guarantee that write operations
             * to this file system will succeed.
             *
             * @return  The number of available bytes on the partition or <tt>0L</tt>
             *          if the abstract pathname does not name a partition.  On
             *          systems where this information is not available, this method
             *          will be equivalent to a call to {@link #getFreeSpace}.
             *
             * @throws  SecurityException
             *          If a security manager has been installed and it denies
             *          {@link RuntimePermission}<tt>("getFileSystemAttributes")</tt>
             *          or its {@link SecurityManager#checkRead(String)} method denies
             *          read access to the file named by this abstract pathname
             *
             * @since  1.6
             */
             long getUsableSpace();

            /**
             * Tests whether this abstract pathname is absolute.  The definition of
             * absolute pathname is system dependent.  On UNIX systems, a pathname is
             * absolute if its prefix is <code>"/"</code>.  On Microsoft Windows systems, a
             * pathname is absolute if its prefix is a drive specifier followed by
             * <code>"\\"</code>, or if its prefix is <code>"\\\\"</code>.
             *
             * @return  <code>true</code> if this abstract pathname is absolute,
             *          <code>false</code> otherwise
             */
            boolean isAbsolute();

            /**
             * Tests whether the file named by this abstract pathname is a hidden
             * file.  The exact definition of <em>hidden</em> is system-dependent.  On
             * UNIX systems, a file is considered to be hidden if its name begins with
             * a period character (<code>'.'</code>).  On Microsoft Windows systems, a file is
             * considered to be hidden if it has been marked as such in the filesystem.
             *
             * @return  <code>true</code> if and only if the file denoted by this
             *          abstract pathname is hidden according to the conventions of the
             *          underlying platform
             *
             * @throws  SecurityException
             *          If a security manager exists and its <code>{@link
             *          java.lang.SecurityManager#checkRead(java.lang.String)}</code>
             *          method denies read access to the file
             *
             * @since 1.2
             */
             boolean isHidden();

            // TODO(thoangminh): we will support it later
            /**
             * Computes a hash code for this abstract pathname.  Because equality of
             * abstract pathnames is inherently system-dependent, so is the computation
             * of their hash codes.  On UNIX systems, the hash code of an abstract
             * pathname is equal to the exclusive <em>or</em> of the hash code
             * of its pathname string and the decimal value
             * <code>1234321</code>.  On Microsoft Windows systems, the hash
             * code is equal to the exclusive <em>or</em> of the hash code of
             * its pathname string converted to lower case and the decimal
             * value <code>1234321</code>.  Locale is not taken into account on
             * lowercasing the pathname string.
             *
             * @return  A hash code for this abstract pathname
             */
//             int hashCode();

            /**
             * Returns an array of abstract pathnames denoting the files in the
             * directory denoted by this abstract pathname.
             *
             * <p> If this abstract pathname does not denote a directory, then this
             * method returns {@code null}.  Otherwise an array of {@code File} objects
             * is returned, one for each file or directory in the directory.  Pathnames
             * denoting the directory itself and the directory's parent directory are
             * not included in the result.  Each resulting abstract pathname is
             * constructed from this abstract pathname using the {@link #File(File,
             * String) File(File,&nbsp;String)} constructor.  Therefore if this
             * pathname is absolute then each resulting pathname is absolute; if this
             * pathname is relative then each resulting pathname will be relative to
             * the same directory.
             *
             * <p> There is no guarantee that the name strings in the resulting array
             * will appear in any specific order; they are not, in particular,
             * guaranteed to appear in alphabetical order.
             *
             * <p> Note that the {@link java.nio.file.Files} class defines the {@link
             * java.nio.file.Files#newDirectoryStream(Path) newDirectoryStream} method
             * to open a directory and iterate over the names of the files in the
             * directory. This may use less resources when working with very large
             * directories.
             *
             * @return  An array of abstract pathnames denoting the files and
             *          directories in the directory denoted by this abstract pathname.
             *          The array will be empty if the directory is empty.  Returns
             *          {@code null} if this abstract pathname does not denote a
             *          directory, or if an I/O error occurs.
             *
             * @throws  SecurityException
             *          If a security manager exists and its {@link
             *          SecurityManager#checkRead(String)} method denies read access to
             *          the directory
             *
             * @since  1.2
             */
            Array<File> listFiles();

            /**
             * List the available filesystem roots.
             *
             * <p> A particular Java platform may support zero or more
             * hierarchically-organized file systems.  Each file system has a
             * {@code root} directory from which all other files in that file system
             * can be reached.  Windows platforms, for example, have a root directory
             * for each active drive; UNIX platforms have a single root directory,
             * namely {@code "/"}.  The set of available filesystem roots is affected
             * by various system-level operations such as the insertion or ejection of
             * removable media and the disconnecting or unmounting of physical or
             * virtual disk drives.
             *
             * <p> This method returns an array of {@code File} objects that denote the
             * root directories of the available filesystem roots.  It is guaranteed
             * that the canonical pathname of any file physically present on the local
             * machine will begin with one of the roots returned by this method.
             *
             * <p> The canonical pathname of a file that resides on some other machine
             * and is accessed via a remote-filesystem protocol such as SMB or NFS may
             * or may not begin with one of the roots returned by this method.  If the
             * pathname of a remote file is syntactically indistinguishable from the
             * pathname of a local file then it will begin with one of the roots
             * returned by this method.  Thus, for example, {@code File} objects
             * denoting the root directories of the mapped network drives of a Windows
             * platform will be returned by this method, while {@code File} objects
             * containing UNC pathnames will not be returned by this method.
             *
             * <p> Unlike most methods in this class, this method does not throw
             * security exceptions.  If a security manager exists and its {@link
             * SecurityManager#checkRead(String)} method denies read access to a
             * particular root directory, then that directory will not appear in the
             * result.
             *
             * @return  An array of {@code File} objects denoting the available
             *          filesystem roots, or {@code null} if the set of roots could not
             *          be determined.  The array will be empty if there are no
             *          filesystem roots.
             *
             * @since  1.2
             * @see java.nio.file.FileStore
             */
            static Array<File> listRoots();

            /**
             * Requests that the file or directory denoted by this abstract
             * pathname be deleted when the virtual machine terminates.
             * Files (or directories) are deleted in the reverse order that
             * they are registered. Invoking this method to delete a file or
             * directory that is already registered for deletion has no effect.
             * Deletion will be attempted only for normal termination of the
             * virtual machine, as defined by the Java Language Specification.
             *
             * <p> Once deletion has been requested, it is not possible to cancel the
             * request.  This method should therefore be used with care.
             *
             * <P>
             * Note: this method should <i>not</i> be used for file-locking, as
             * the resulting protocol cannot be made to work reliably. The
             * {@link java.nio.channels.FileLock FileLock}
             * facility should be used instead.
             *
             * @throws  SecurityException
             *          If a security manager exists and its <code>{@link
             *          java.lang.SecurityManager#checkDelete}</code> method denies
             *          delete access to the file
             *
             * @see #delete
             *
             * @since 1.2
             */
            void deleteOnExit();

        private:
            /**
             * This abstract pathname's normalized pathname string.
             * A normalized pathname string uses the default
             * name-separator character and does not
             * contain any duplicate or redundant separators.
             */
            String path;

            /**
             * The length of this abstract pathname's prefix,
             * or zero if it has no prefix.
             */
            int prefixLength; // transient

            /**
             * The statitics of this File.
             */
            struct stat fileStatitics;

            /**
             * Tests whether the application can get statitics of this File
             */
            boolean canGetStatitics;

            /**
             * The last modified time of this file
             */
            long lastModifiedTime;

        private:
            /**
             * Check that the given pathname is normal.
             * If not, invoke the real normalizer on the part
             * of the pathname that requires normalization.
             * This way we iterate through the whole pathname
             * string only once.
             */
            String normalize(String pathName);

            /**
             * A normal Unix pathName contains no duplicate
             * slashes and does not end
             * with a slash.  It may be the empty string.
             *
             * Normalize the given pathName, whose length is len,
             * starting at the given offset; everything before
             * this offset is already normal.
             */
            String normalize(String pathName, int len, int off);

            /**
             * Return Prefix Length
             *
             * @param pathName
             * @return
             */
            int getPrefixLength(String pathName);

            /**
             * Return file permission in String format
             *
             * @param path
             * @return
             */
            StringBuffer permissionStringFormat(String path);

            /**
             * Return file permission in int format from String format
             *
             * @param permissionStringFormat
             * @return
             */
            int stringFormatToPermission(StringBuffer permissionStringFormat);

            /**
             * Update the statitics of this file
             */
            void updateFileStatitics();

            /**
             * Get owner of file
             * @return String
             */
            String getUser();

            /**
             * Get group of file
             * @return String
             */
            String getGroup();

            /**
             * Get current owner
             * @return String
             */
            static String getCurrentUser();

            /**
             * Get group of file
             * @return String
             */
            static String getCurrentGroup();

            /**
             * Return an array of String
             * contain a list of file system
             * @return Array<String>
             */
            static Array<String> listRootString();
        };
    }  // namespace Io
} // namspace Java

#endif // JAVA_IO_FILE_FILE_HPP_