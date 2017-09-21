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

#ifndef JAVA_LANG_SHORT_SHORT_HPP_
#define JAVA_LANG_SHORT_SHORT_HPP_

#include "../Number/Number.hpp"
#include "../String/String.hpp"
#include "../Comparable/Comparable.hpp"
#include <iostream>
#include <bitset>

using namespace Java::Lang;

namespace Java {
    namespace Lang {
        class Short;

        class Short: public Number, public virtual Comparable<Short> {
        private:
            short original;
            string originalString;

        private:
            /**
             * Max value of unsigned short
             */
            static constexpr unsigned short UNSIGNED_SHORT_MAX = 0xffffffff;

            /**
             * Min value of unsigned short
             */
            static constexpr unsigned short UNSIGNED_SHORT_MIN = 0;

        public:
            /**
             * The number of bits used to represent an short value in two's complement binary form.
             */
            static const short SIZE = 32;

            /**
             * The number of bytes used to represent an short value in two's complement binary form.
             */
            static const short BYTE = SIZE / 8;

            /**
             * A constant holding the maximum value of short type.
             */

            static constexpr short MAX_VALUE = std::numeric_limits<short>::max();

            /**
             * A constant holding the minimum value of short type.
             */
            static constexpr short MIN_VALUE = std::numeric_limits<short>::min();

        public:
            /**
             * Short initialization
             *
             */
            Short();

            /**
             * Short initialization with specific original value
             *
             * @param original
             */
            Short(short original);

            /**
             * Short initialization with specifix original value from string
             *
             * @param inputString
             */
            Short(string inputString);

            /**
             * Copy Constructor
             *
             * @param Short @target
             */
            Short(const Short &target);

            /**
             * Short Destructor
             */
            ~Short();

        public:
            char charValue() const;
            short shortValue() const;
            int intValue() const;
            long longValue() const;
//            float floatValue() const;
//            double doubleValue() const;
            string stringValue() const;
//            string toString() override const;


        public:

            boolean operator==(const Short &target) const;
            boolean operator!=(const Short &target) const;
            boolean operator<(const Short &target) const;
            boolean operator>(const Short &target) const;
            boolean operator<=(const Short &target) const;
            boolean operator>=(const Short &target) const;
        };
    }
}
#endif  // JAVA_LANG_SHORT_SHORT_HPP