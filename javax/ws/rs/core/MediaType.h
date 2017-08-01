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

#ifndef NATIVE_MEDIATYPE_H
#define NATIVE_MEDIATYPE_H

#include "../../../../java/Lang.hpp"
#include "../../../../java/util/Map/Map.hpp"

namespace Javax {
    namespace Ws {
        class MediaType : public virtual Java::Lang::Object {
        public:
            static String APPLICATION_ATOM_XML          = "application/atom+xml";
            static String APPLICATION_FORM_URLENCODED   = "application/x-www-form-urlencoded";
            static String APPLICATION_JSON              = "application/json";
            static String APPLICATION_OCTET_STREAM      = "application/octet-stream";
            static String APPLICATION_SVG_XML           = "application/svg+xml";
            static String APPLICATION_XHTML_XML         = "application/xhtml+xml";
            static String APPLICATION_XML               = "application/xml";
            static String MEDIA_TYPE_WILDCARD           = "*";
            static String MULTIPART_FORM_DATA           = "multipart/form-data";
            static String TEXT_HTML                     = "text/html";
            static String TEXT_PLAIN                    = "text/plain";
            static String TEXT_XML                      = "text/xml";
            static String WILDCARD                      = "*/*";

            /**
             * Creates a new instance of MediaType, both type and subtype are wildcards.
             */
            MediaType();

            /**
             * Creates a new instance of MediaType with the supplied type and subtype.
             *
             * @param type
             * @param subtype
             */
            MediaType(String type, String subtype);

            /**
             *   Creates a new instance of MediaType with the supplied type, subtype and parameters.
             *
             * @param type
             * @param subtype
             * @param parameters
             */
            MediaType(String type, String subtype, Map<String, String> parameters);

            /**
             * Remove media type instance
             */
            ~MediaType();

            /**
             *  Getter for a read-only parameter map.
             *
             * @return
             */
            const Map<String, String> &getParameters() const;

            /**
             * Getter for subtype.
             *
             * @return
             */
            const String &getSubtype() const;

            /**
             * Getter for primary type.
             *
             * @return
             */
            const String &getType() const;

            /**
             * Check if this media type is compatible with another media type.
             *
             * @param other
             * @return
             */
            Boolean isCompatible(MediaType other);

            /**
             * Checks if the subtype is a wildcard
             *
             * @return
             */
            Boolean isWildcardSubtype();

            /**
             * Checks if the primary type is a wildcard.
             *
             * @return
             */
            Boolean isWildcardType();

        private:
            String type;
            String subtype;
            Map<String, String> parameters;
        };
    }
}

#endif //NATIVE_MEDIATYPE_H
