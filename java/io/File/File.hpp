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

#include "../../lang/String/String.hpp"
#include "../../lang/StringBuffer/StringBuffer.hpp"
#include "../../../kernel/type.h"
#include "../../lang/RuntimeException/RuntimeException.hpp"
#include "../../lang/SecurityException/SecurityException.hpp"

using namespace Java::Lang;

namespace Java {
    namespace Io {
        class File:
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
        };
    }  // namespace Io
} // namspace Java

#endif // JAVA_IO_FILE_FILE_HPP_


