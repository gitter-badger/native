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

#include "../../lang/String/String.hpp"
#include "../../lang/StringBuffer/StringBuffer.hpp"
#include <memory>
#include "../../../kernel/type.h"
#include "../../lang/RuntimeException/RuntimeException.hpp"

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
            static String executeCommand(String command);

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


