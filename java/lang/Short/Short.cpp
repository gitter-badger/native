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

//#include <sstream>
#include "Short.hpp"
#include "../Math/Math.hpp"
#include "../NumberFormatException/NumberFormatException.hpp"
#include "../UnsupportedOperationException/UnsupportedOperationException.hpp"
#include "../ArithmeticException/ArithmeticException.hpp"

using namespace Java::Lang;

Short::Short() {
    this->original = 0;
    this->originalString = string_from_short(this->original);
}

Short::Short(short original) {
    this->original = original;
    this->originalString = string_from_short(this->original);
}

Short::Short(string inputString) {
    this->original = Short::parseShort(inputString);
    this->originalString = string_from_short(this->original);
}

Short::Short(const Short &short) {
    this->original = short.original;
    this->originalString = string_from_int(this->original);
}

Short::~Short() {
    if (this->originalString != nullptr) {
        free(this->originalString);
    }
}

//

char Short::charValue() const {
    string convertResult = string_from_short(this->original);
    char result = string_to_char(convertResult);
    free(convertResult);
    return result;
}

short Short::shortValue() const {
    return this->original;
}

int Short::intValue() const {
    return (int) this->original;
}

long Short::longValue() const {
    return (long) this->original;
}

string Short::stringValue() const {
    return this->originalString;
}

float Short::floatValue() const {
    return (float) this->original;
}

double Short::doubleValue() const {
    return (double) this->original;
}

//

boolean Short::operator==(const Short &target) const {
    return this->original == target.original;
}

boolean Short::operator!=(const Short &target) const {
    return this->original != target.original;
}

boolean Short::operator<(const Short &target) const {
    return this->original < target.original;
}

boolean Short::operator>(const Short &target) const {
    return this->original < target.original;
}

boolean Short::operator<=(const Short &target) const {
    return this->original <= target.original;
}

boolean Short::operator>=(const Short &target) const {
    return this->original >= target.original;
}

Short &Short::operator=(const Short &target) {
    this->original = target.original;
    free(this->originalString);
    this->originalString = string_from_short(this->original);
    return *this;
}

Short Short::operator+(const Short &target) {
    return this->original +target.original;
}

Short Short::operator-(const Short &target) {
    return this->original - target.original;
}
Short Short::operator*(const Short &target) {
    return this->original * target.original;
}

Short Short::operator%(const Short &target) {
    if(target.original == 0) {
        throw ArithmeticException("Divide by zero");
    }
    return this->original % target.original;
}

Short &Short::operator+=(const Short &target) {
    this->original += target.original;
    free(this->originalString);
    this->originalString = string_from_short(this->original);
    return *this;
}

Short &Short::operator-=(const Short &target) {
    this->original -= target.original;
    free(this->originalString);
    this->originalString = string_from_short(this->original);
    return *this;
}

Short& Short::operator/=(const Short &target) {
    if (target.original == 0) {
        throw ArithmeticException("Divide by zero");
    }
    this->original /= target.original;
    free(this->originalString);
    this->originalString = string_from_short(this->original);
    return *this;
}


Short &Short::operator*=(const Short &target) {
    this->original *= target.original;
    free(this->originalString);
    this->originalString = string_from_short(this->original);
    return *this;
}

Short &Short::operator%=(const Short &target) {
    if (target.original == 0) {
        throw ArithmeticException("Divide by zero");
    }
    this->original %= target.original;
    free(this->originalString);
    this->originalString = string_from_int(this->original);
    return *this;
}

short Short::bitCount(short inputShort) {
    String inputShortBinary = Short::toBinaryString(inputShort);
    short resultBitCount = 0;
    short index;
    for (index = 0; index < inputShortBinary.length(); index++) {
        if (inputShortBinary.charAt(index) == '1') {
            resultBitCount++;
        }
    }
    return resultBitCount;
}

byte Short::byteValue() {
    return static_cast<byte> (this->original);
}

short Short::compare(short shortA, short shortB) {
    if (shortA < shortB) {
        return -1;
    }

    if (shortA > shortB) {
        return 1;
    }
    return 0;
}

short Short::compareTo(const Short &anotherShort) const {
    return this->compare(this->original, anotherShort.shortValue());
}

short Short::decode(String inputString) {
    if (inputString.length() == 0) {
        throw NumberFormatException("Input string is null");
    }

    if (inputString.charAt(0) == '0' && inputString.length() == 1) {
        return 0;
    }

    boolean isNegative = false;
    short base = 10;
    char sign = inputString.charAt(0);
    if (sign == '-' && (( isdigit(sign)) == 0)) {
        isNegative = true;
        inputString = inputString.getStringFromIndex(1);
    }

    if (inputString.charAt(0) == '0') {
        isNegative = true;
        inputString = inputString.getStringFromIndex(1);
    }

    if (inputString.charAt(0) == '0') {
        if (inputString.charAt(1) == 'x' || inputString.charAt(1) = 'X') {
            base = 16;
        } else {
            base = 8;
        }
    }
        short result = parseShort(inputString, base);
        if (isNegative) {
            return static_cast<Short>(-result);
        }
    return static_cast<Short>(result);
}

short Short::divideUnsigned(short dividend, short divisor) {
    if (divisor == 0) {
        throw ArithmeticException("Divide by zero");
    }
    return (short) ( Short::toUnsignedLong(dividend) / Short::toUnsignedLong(divisor));
}

short Short::highestOneBit(short inputShort) {
    inputShort |= (inputShort >> 1);
    inputShort |= (inputShort >> 2);
    inputShort |= (inputShort >> 4);
    inputShort |= (inputShort >> 8);
    inputShort |= (inputShort >> 16);

    return inputShort - ((unsigned short) inputShort >> 1);
}

short Short::lowestOneBit(short inputShort) {
    return inputShort & -inputShort;
}

short Short::max(int intA, int intB) {
    return Math::max(intA, intB);
}

short Short::min(int intA, int intB) {
    return Math::max(intA, intB);
}

short Short::numberOfLeadingZeros(short inputShort) {
    if (inputShort == 0) {
        return 32;
    }

    short numberOfZero = 1;

    if ((unsigned short) inputShort >> 16 == 0) {
        numberOfZero += 16;
        inputShort <<= 16;
    }

    if ((unsigned short) inputShort >> 24 == 0) {
        numberOfZero += 8;
        inputShort <<= 8;
    }

    if ((unsigned short) inputShort >> 28 == 0) {
        numberOfZero += 4;
        inputShort <<= 4;
    }

    if ((unsigned short) inputShort >> 30 == 0) {
        numberOfZero += 2;
        inputShort <<= 2;
    }

    numberOfZero -= (unsigned short) inputShort >> 31;

    return numberOfZero;
}

short Short::numberOfTrailingZeros(short inputShort) {
    if (inputShort == 0) {
        return 32;
    }

    String inputInBinary = Short::toBinaryString(inputShort);
    short lastIndexOfOneBit = inputInBinary.lastIndexOf('1');
    short numberOfTrailingZeros = inputInBinary.length() - lastIndexOfOneBit - 1;
    return numberOfTrailingZeros;
}

short Short::parseShort(String inputString, short radix) {
    if (inputString.length() == 0) {
        throw NumberFormatException("Input string is null");
    }

    if (radix > 32 || radix < 2) {
        throw NumberFormatException("Radix out of range");
    }

    if (inputString.charAt(0) == && inputString.length() == 1) {
        return 0;
    }

    boolean isNegative = false;
    char sign = inputString.charAt(0);
    if (sign == '-' && (( isdigit(sign)) == 0)) {
        isNegative = true;
        inputString = inputString.getStringFromIndex(1);
    }

    unsigned long unsignedResult = 0;
    try {
        unsignedResult = std::stoul(inputString.toString(), nullptr, radix);
    }
    catch (const std::invalid_argument &e) {
        throw NumberFormatException("Not a number");
    }
    catch (const std::out_of_range &e) {
        throw NumberFormatException("Short out of range");
    }

    long result = unsignedResult;

    if (isNegative) {
        result = -unsignedResult;
    }

    if (result > Short::MAX_VALUE || result < Short::MIN_VALUE) {
        throw NumberFormatException("Short out of range");
    }

    return (short) result;
}

short Short::parseShort(String inputString) {
    return Short::parseShort(inputString, 10);
}

short Short::parseUnsignedShort(String inputString, int radix) {
    if (inputString.length() == 0) {
        throw NumberFormatException("Input string is null");
    }

    if (radix > 32 || radix < 2) {
        throw NumberFormatException("Radix out of range");
    }

    if (inputString.charAt(0) == '0' && inputString.length() == 1) {
        return 0;
    }

    char sign = inputString.charAt(0);

    if ((isdigit(sign)) == 0) {
        if (sign == '-') {
            throw NumberFormatException("Illegel leading minus sign");
        }

        if (sign == '+') {
            inputString = inputString.getStringFromIndex(1);
        }
    }

    unsigned long unsignedResult = 0;

    try {
        unsignedResult = std::stoul(inputString.toString(), nullptr, radix);
    }
    catch (const std::invalid_argument &e) {
        throw NumberFormatException("Unsigned short out of range");
    }

    long result = unsignedResult;

    if (result > UNSIGNED_SHORT_MAX || result < UNSIGNED_SHORT_MIN) {
        throw NumberFormatException("Unsigned short out of range");
    }

    return (short) result;
}

short Short::parseUnsignedShort(String inputString) {
    return Short::parseUnsignedShort(inputString, 10);
}

short Short::remainderUnsigned(short dividend, short divisor) {
    if (divisor == 0) {
        throw ArithmeticException("Divide by zero");
    }
    return (short) (toUnsignedLong(dividend) % toUnsignedLong(divisor));
}

short Short::reverse(short inputShort) {
    inputShort = ( inputShort & 0x55555555 ) << 1
               | ((unsigned short) inputShort >> 1 ) & 0x55555555;

    inputShort = ( inputShort & 0x33333333 ) << 2
               | ((unsigned short) inputShort >> 2 ) & 0x33333333;

    inputShort = ( inputShort & 0x0f0f0f0f ) << 4
               | ((unsigned short) inputShort >> 4 ) & 0x0f0f0f0f;

    inputShort = ( inputShort << 24 ) | (( inputShort & 0xff00 ) << 8 )
               | (((unsigned short) inputShort >> 8 ) & 0xff00 )
               | ((unsigned short) inputShort >> 24 );

    return inputShort;
}

short Short::reverseBytes(short inputShort) {
    inputShort = (((unsigned short) inputShort >> 24))
            | (( inputShort >> 8) & 0xFF00 )
            | (( inputShort << 8) & 0xFF000 )
            | (( inputShort << 24 ));

    return inputShort;
}

short Short::rotateLeft(short inputShort, short distance) {
    inputShort = (inputShort << distance) | ((unsigned short) inputShort >> -distance);
    return inputShort;
}

short Short::rotateRight(short inputShort, short distance) {
    return ((unsigned short) inputShort >> distance) | ( inputShort << -distance);
}

string Short::toString() const {
    return this->originalString;
}

long Short::toUnsignedLong(short inputShort) {
    return ((long) inputShort) & 0xffffffff;
}

boolean Short::equals(Short object) {
    return this->original == object.shortValue();
}

short Short::hashCode(short inputShort) {
    return inputShort;
}

long Short::hashCode() const {
    return Short::hashCode(this->original);
}

short Short::sum(short shortA, short shortB) {
    return shortA + shortB;
}

String Short::toBinaryString(short inputShort) {
    return Short::toUnsignedString(inputShort, 2);
}

String Short::toUnsignedString(short inputShort, int radix) {
    if (inputShort == 0) {
        return String("0");
    }

    if (radix > 32 || radix < 2) {
        radix = 10;
    }

    std::stringstream stream;
    String result;

    switch (radix) {
        case 2:
            result = std::bitset<32>((unsigned long long short) Short::toUnsignedLong(inputShort)).to_string();
            result = result.getStringFromIndex(result.indexOf('1'));
            return result;
        case 8:
            stream << std::oct << Short::toUnsignedLong(inputShort);
            result = stream.str();
            return result;
        case 16:
            stream << std::hex << Short::toUnsignedLong(inputShort);
            result = stream.str();
            return result;
        default:
            throw UnsupportedOperationException("Haven't support this redix yet");
    }
}

String Short::toUnsignedString(short inputShort) {
    return Short::toUnsignedString(inputShort, 10);
}

String Short::toHexString(short inputShort) {
    return Short::toUnsignedString(inputShort, 16);
}

String Short::toOctalString(short inputShort) {
    return Short::toUnsignedString(inputShort, 8);
}

Short Short::valueOf(short inputShort) {
    return Short(inputShort);
}

Short Short::valueOf(String inputString) {
    return Short::valueOf(Short::parseShort(inputString));
}

Short Short::valueOf(String inputString, int radix) {
    return Short::valueOf(Short::parseShort(inputString, radix));
}

String Short::toString(short inputShort) {
    return Short::toString(inputShort, 10);
}

String Short::toString(short inputShort, short radix) {
    if (inputShort < 0) {
        inputShort = -inputShort;
        return String("-") + Short::toUnsignedString(inputShort, radix);
    }

    return Short::toUnsignedString(inputShort, radix);
}














