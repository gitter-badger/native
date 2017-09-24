/**
 * Copyright 2017 Food Tiny Project. All rights reserved.
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

#ifndef JAVA_SECURITY_MESSAGEDIGEST_HPP_
#define JAVA_SECURITY_MESSAGEDIGEST_HPP_

#include "../../../kernel/type.h"
#include "../../Lang.hpp"
#include "MessageDigestSpi.hpp"

using namespace Java::Lang;

namespace Java {
    namespace Security {
        class MessageDigest : public MessageDigestSpi {
        public:
            static MessageDigest* getInstance(String algorithm);

            ~MessageDigest();

            String getAlgorithm();

            int getDigestLength();

            int digest(byte buf[], int offset, int len);

            Array<byte> digest();

            void reset();

            void update(const byte input[], int offset, int len);

        private:
            MessageDigestSpi* spi;
            String algorithm;

            MessageDigest(MessageDigestSpi* spi);

            int engineDigest(byte buffer[], int offset, int len) override;

            int engineGetDigestLength() override;

            void engineReset() override;

            void engineUpdate(const byte input[], int offset, int len) override;

        };
    } // namespace Security
} // namespace Java

#endif //JAVA_SECURITY_MESSAGEDIGEST_HPP_
