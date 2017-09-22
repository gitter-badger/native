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

extern "C" {
#include "../../../kernel/test.h"
}

#include "Short.hpp"
#include "../NumberFormatException/NumberFormatException.hpp"
#include "../UnsupportedOperationException/UnsupportedOperationException.hpp"
#include "../ArithmeticException/ArithmeticException.hpp"

using namespace Java::Lang;

TEST (JavaLang, ShortConstructor) {
    //Test Short::Short()
    Short shortConstructorNoneParameter;
    ASSERT_EQUAL(0, shortConstructorNoneParameter.shortValue());
    ASSERT_STR((string) "0", shortConstructorNoneParameter.toString());

    //Test Short::Short(String stringInput)
    Short shortConstructorStringParameter((String) "69");
    ASSERT_EQUAL(69, shortConstructorStringParameter.shortValue());
    ASSERT_STR((string) "69", shortConstructorNoneParameter.toString());

    //Test Short::Short(const Short &short)
    Short shortConstructorShortParameter = 69;
    ASSERT_STR(69, shortConstructorShortParameter.shortValue());
    ASSERT_STR((string) "69", shortConstructorShortParameter.toString());
}

TEST (JavaLang, ShortComparision) {
    //Give a valid number of make a comparision
    Short validNumberComparision = 10;
    Short targetNumberComparision;

    // Test validNumber is equal targetNumber
    targetNumberComparision = 10;
    ASSERT_TRUE(validNumberComparision == targetNumberComparision);

    //Test validNumber is not equal targetNumber
    targetNumberComparision = 11;
    ASSERT_TRUE(validNumberComparision != targetNumberComparision);

    //Test validNumber is less than targetNumber
    targetNumberComparision = 20;
    ASSERT_TRUE(validNumberComparision < targetNumberComparision);

    //Test validNumber is equal or less than targetNumber;
    targetNumberComparision = 21;
    ASSERT_TRUE(validNumberComparision <= targetNumberComparision);

    //Test validNumber is greater than targetNumber
    targetNumberComparision = 15;
    ASSERT_TRUE(validNumberComparision > targetNumberComparision);

    //Test validNumber is equal or greater than targetNumber
    targetNumberComparision = 13;
    ASSERT_TRUE(validNumberComparision >= targetNumberComparision);

}

TEST (JavaLang, ShortOperator) {
    //Create variable
    Short validNumberOperator = 2;
    Short targetNumberOperator = 3;
    Short expectedResult;
    Short actualResult;

    //Make a summation
    expectedResult = 5;
    actualResult = validNumberOperator + targetNumberOperator;
    ASSERT_EQUAL(expectedResult.shortValue(), actualResult.shortValue());

    expectedResult = 5;
    actualResult += validNumberOperator;
    ASSERT_EQUAL(expectedResult.shortValue(), actualResult.shortValue());

    //Make a subtraction
    expectedResult = -1;
    actualResult = validNumberOperator - targetNumberOperator;
    ASSERT_EQUAL(expectedResult.shortValue(), actualResult.shortValue());

    expectedResult = -3;
    actualResult -= validNumberOperator;
    ASSERT_EQUAL(expectedResult.shortValue(), actualResult.shortValue());

    //Make a multiplication
    expectedResult = 6;
    actualResult = validNumberOperator * targetNumberOperator;
    ASSERT_EQUAL(expectedResult.shortValue(), actualResult.shortValue());

    expectedResult = 12;
    actualResult *= validNumberOperator;
    ASSERT_EQUAL(expectedResult.shortValue(), actualResult.shortValue());

    //Make a division
    expectedResult = 0;
    actualResult = validNumberOperator / targetNumberOperator;
    ASSERT_EQUAL(expectedResult.shortValue(), actualResult.shortValue());

    try {
        actualResult = validNumberOperator / 0;
    }
    catch(ArithmeticException &e) {
        ASSERT_STR("Divide by zero", e.getMessage().toString());
    }

    expectedResult = 5;
    actualResult = 10;
    actualResult /= validNumberOperator;
    ASSERT_EQUAL(expectedResult.shortValue(), actualResult.shortValue());

    try {
        actualResult /= 0;
    }
    catch(ArithmeticException &e) {
        ASSERT_STR("Divide by zero", e.getMessage().toString());
    }

    //Make a modulo
    expectedResult = 2;
    actualResult = validNumberOperator % targetNumberOperator;
    ASSERT_EQUAL(expectedResult.shortValue(), actualResult.shortValue());

    try {
        actualResult = validNumberOperator % 0;
    }
    catch(ArithmeticException &e) {
        ASSERT_STR("Divide by zero", e.getMessage().toString());
    }

    expectedResult = 1;
    actualResult = 3;
    actualResult %= validNumberOperator;
    ASSERT_EQUAL(expectedResult.shortValue(), actualResult.shortValue());

    try {
        actualResult /= 0;
    }
    catch(ArithmeticException &e) {
        ASSERT_STR("Divide by zero", e.getMessage().toString());
    }
}

TEST (JavaLang, ShortCompareTo) {
    // Give Short value to compare with target
    Short validValueCompareTo = 10;
    Short lessThanValueCompareTo = 9;
    Short equalValueCompareTo = 10;
    Short greaterValueCompareTo = 11;

    //Return 1 if validValue is greater than lessThanValue
    ASSERT_EQUAL(1, validValueCompareTo.compareTo(lessThanValueCompareTo));

    //Return 0 if validValue is greater than equalValue
    ASSERT_EQUAL(0, validValueCompareTo.compareTo(equalValueCompareTo));

    //Return -1 if validValue is less than greaterThanValue
    ASSERT_EQUAL(-1, validValueCompareTo.compareTo(greaterValueCompareTo));

    //TODO
}

TEST (JavaLang, ShortCharValue) {
    Short zeroShortCharValue = 0;
    Short oneShortCharValue = 1;
    Short positiveShortCharValue = 15;
    Short maxShortCharValue;
    Short minShortCharValue;

    //Make a comparison between expected result and the real result
    char expectedResultCharValue = '0';
    char realResultCharValue = zeroShortCharValue.charValue();
    ASSERT_EQUAL(expectedResultCharValue, realResultCharValue);

    //Make a comparison between expected result and the real result
    expectedResultCharValue = '1';
    realResultCharValue = oneShortCharValue.charValue();
    ASSERT_EQUAL(expectedResultCharValue, realResultCharValue);

    // Make a comparison between expected result and the real result
    expectedResultCharValue = '1';
    realResultCharValue = positiveShortCharValue.charValue();
    ASSERT_EQUAL(expectedResultCharValue, realResultCharValue);
}

TEST (JavaLang, ShortStringValue) {
    Short zeroShortStringValue = 0;
    Short oneShortStringValue = 1;
    Short positiveShortStringValue = 15;
    Short maxShortStringValue;
    Short minShortStringValue;

    //Make a comparison between expected result and the real result
    string expectedResultStringValue = (string) "0";
    string realResultStringValue = zeroShortStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue, realResultStringValue);

    //Make a comparison between expected result and the real result
    expectedResultStringValue = (string) "1";
    realResultStringValue = oneShortStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue, realResultStringValue);

    //Make a comparison between expected result and the real result
    expectedResultStringValue = (string) "15";
    realResultStringValue = positiveShortStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue, realResultStringValue);
}

TEST (JavaLang, ShortShortValue) {
    Short positiveShortShortValue = 1504;
    Short negativeShortShortValue = -1504;
    Short notExpectedShortShortValue = 9999;

    //Make a comparison between expected result and the real result
    short expectedResultShortValue = 1504;
    short realResultShortValue = positiveShortShortValue.shortValue();
    ASSERT_EQUAL(expectedResultShortValue, realResultShortValue);

    //Make a comparison between expected result and the real result
    expectedResultShortValue = -1504;
    realResultShortValue = negativeShortShortValue.shortValue();
    ASSERT_EQUAL(expectedResultShortValue, realResultShortValue);

    //Make a comparison between expected result and the real result
    short notExpectedResultShortValue = 1111;
    realResultShortValue = notExpectedShortShortValue.shortValue();
    ASSERT_NOT_EQUAL(notExpectedResultShortValue, notExpectedShortShortValue);
}

TEST (JavaLang, ShortIntValue) {
    Short zeroShortIntValue = 0;
    Short oneShortIntValue = 1;
    Short positiveShortIntValue = 15;
    Short maxShortIntValue;
    Short minShortIntValue;
    Short notExpectedShortIntValue = 999;

    //Make a comparison between expected result and the real result
    int expectedResultIntValue = 0;
    int realResultIntValue = zeroShortIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue, realResultIntValue);

    //Make a comparison between expected result and the real result
    expectedResultIntValue = 1;
    realResultIntValue = oneShortIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue, realResultIntValue);

    //Make a comparison between expected result and the real result
    expectedResultIntValue = 15;
    realResultIntValue = positiveShortIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue, realResultIntValue);

    //Make a comparison between expected result and the real result
    int notExpectedResult = 9999;
    realResultIntValue = notExpectedShortIntValue.intValue();
    ASSERT_NOT_EQUAL(notExpectedResult, notExpectedShortIntValue);
}

TEST (JavaLang, ShortLongValue) {
    Short positiveLongShortValue = 1504;
    Short negativeLongShortValue = -1504;
    Short notExpectedLongShortValue = 9999;

    //Make a comparison between expected result and the real result
    long expectedResultLongValue = 1504;
    long realResultLongValue = positiveLongShortValue.longValue();
    ASSERT_EQUAL(expectedResultLongValue, realResultLongValue);

    //Make a comparison between expected result and the real result
    expectedResultLongValue = -1504;
    realResultLongValue = negativeLongShortValue.longValue();
    ASSERT_EQUAL(expectedResultLongValue, realResultLongValue);

    //Make a comparison between expected result and the real result
    long notExpectedResult = 1111;
    realResultLongValue = notExpectedLongShortValue.longValue();
    ASSERT_EQUAL(notExpectedLongShortValue, realResultLongValue);
}

TEST (JavaLang, ShortFloatValue) {
    // Input different values of type short to compare to the realResult of Short::floatValue
    Short positiveFloatShortValue = 1504;
    float expectedeResultFloatValue = 1504.00;
    float realResultoatValue = positiveFloatShortValue.floatValue();
    ASSERT_TRUE(expectedeResultFloatValue == realResultoatValue);

    Short negativeShort = -12345;
    expectedeResultFloatValue = (float) -12345.0;
    realResultoatValue = negativeShort.floatValue();
    ASSERT_TRUE(expectedeResultFloatValue == realResultoatValue);
}

TEST (JavaLang, ShortDoubleValue) {
    // Input different values of type short to compare to the realResult of Short::floatValue
    Short positiveDoubleShortValue = 123;
    double expectedResultDoubleValue = 123.0;
    double realResultDoubleValue = positiveDoubleShortValue.doubleValue();
    ASSERT_TRUE(expectedResultDoubleValue == realResultDoubleValue);

    Short negativeShort = -1234;
    expectedResultDoubleValue = -1234.0;
    realResultDoubleValue = negativeShort.doubleValue();
    ASSERT_TRUE(expectedResultDoubleValue == realResultDoubleValue);
}

TEST (JavaLang, ShortBitCount) {
    short inputShort;
    short expectedResult;
    short actualResult;

    inputShort = 0;
    expectedResult = 0;
    actualResult = Short::bitCount(inputShort);
    ASSERT_EQUAL(expectedResult, actualResult);

    inputShort = -1;
    expectedResult = 1;
    actualResult = Short::bitCount(inputShort);
    ASSERT_EQUAL(expectedResult, actualResult);

    inputShort = -1;
    expectedResult = 32;
    actualResult = Short::bitCount(inputShort);
    ASSERT_EQUAL(expectedResult, actualResult);

    inputShort = 13;
    expectedResult = 3;
    actualResult = Short::bitCount(inputShort);
    ASSERT_EQUAL(expectedResult, actualResult);

    inputShort = Short::MAX_VALUE;
    expectedResult = 31;
    actualResult Short::bitCount(inputShort);
    ASSERT_EQUAL(expectedResult, actualResult);

    inputShort = Short::MIN_VALUE;
    expectedResult = 1;
    actualResult = Short::bitCOunt(inputShort);
    ASSERT_EQUAL(expectedResult, actualResult);
}

TEST (JavaLang, ShortByteValue) {
    Short shortInput;

    shortInput = 0;
    ASSERT_EQUAL((byte) 0, shortInput.byteValue());

    shortInput = 1;
    ASSERT_EQUAL((byte) 1, shortInput.byteValue());

    shortInput = -1;
    ASSERT_EQUAL((byte) -1, shortInput.byteValue());

    shortInput = 13;
    ASSERT_EQUAL((byte) 13, shortInput.byteValue());

    shortInput = Short::MAX_VALUE;
    ASSERT_EQUAL((byte) -1, shortInput.byteValue());

    shortInput = Short::MIN_VALUE;
    ASSERT_EQUAL((byte) 0, shortInput.byteValue());
}

TEST (JavaLang, ShortCompare) {
    //Given 2 short values
    short greater = 15;
    short smaller = 04;

    //Conpare 2 equal value
    ASSERT_EQUAL(0, Short::compare(greater, greater));

    //Compare 2 different values
    ASSERT_EQUAL(-1; Short::compare(smaller, greater);
    ASSERT_EQUAL(1, Short::compare(greater, smaller));
}

TEST (JavaLang, ShortCompareUnsigned) {
    //Given 3 short values
    short greater = 15;
    short smaller = 04;
    short negative = -98;

    //Compare 2 equal values
    ASSERT_EQUAL(0, Short::compareUnsigned(greater, greater));
    ASSERT_EQUAL(0, Short::compareUnsigned(negative, negative));

    //Compare 2 different values
    ASSERT_EQUAL(-1, Short::compareUnsigned(smaller, greater));
    ASSERT_EQUAL(1, Short::compareUnsigned(greater,smaller));

    //Compare negative value
    ASSERT_EQUAL(-1, Short::compareUnsigned(greater, negative);
    ASSERT_EQUAL(1, Short::compareUnsigned(negative, greater));
}

TEST (JavaLang, ShortDecode) {
    String stringInput;
    Short expectedResult;
    Short actualResult;
    Short exceptionResult;

    stirngInput = "";
    try {
        exceptionResult = Short::decode(stringInput);
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("input string is null", e.getMessage().toString());
    }

    //Case all case of input a string of type decimal number
    stringInput = "0";
    expectedResult = 0;
    actualResult = Short::decode(stringInput);
    ASSERT_EQUAL(exceptionResult.shortValue(), actualResult.shortValue());

    stringInput = "1";
    expectedResult = 1;
    actualResult = Short::decode(stringInput);
    ASSERT_EQUAL(exceptionResult.shortValue(), actualResult.shortValue());

    stringInput = (String) "-1";
    expectedResult = 1;
    actualResult = Short::decode(stringInput);
    ASSERT_EQUAL(exceptionResult.shortValue(), actualResult.shortValue());

    stringInput = (String) "13";
    exceptionResult = 13;
    actualResult = Short::decode(stringInput);
    ASSERT_EQUAL(exceptionResult.shortValue(), actualResult.shortValue());

    //Test out of range
    stringInput = (String) "1628324548";
    try {
        exceptionResult = Short::decode(stringInput);
    }
    catch(NumberFormatException &e) {
        ASSERT_STR("Short out of range", e.getMessage().toString());
    }

    stringInput = (String) "-1628324548";
    try {
        exceptionResult = Short::decode(stringInput);
    }
    catch(NumberFormatException &e) {
        ASSERT_STR("Short out of range", e.getMessage().toString());
    }

    stringInput = (String) "Not a number";
    try {
        expectedResult = Short::decode(stringInput);
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("Not a number", e.getMessage().toString());
    }

    //Case all case of input a string of type octal
    stringInput = "0";
    expectedResult = 0;
    actualResult = Short::decode(stringInput);
    ASSERT_EQUAL(exceptionResult.shortValue(), actualResult.shortValue());

    stringInput = (String) "01";
    exceptionResult = 1;
    actualResult = Short::decode(stringInput);
    ASSERT_EQUAL(exceptionResult.shortValue(), actualResult.shortValue());

    stringInput = "-01";
    exceptionResult = -1;
    actualResult = Short::decode(stringInput);
    ASSERT_EQUAL(exceptionResult.shortValue(), actualResult.shortValue());

    stringInput = "013";
    expectedResult = 13;
    actualResult = Short::decode(stringInput);
    ASSERT_EQUAL(exceptionResult.shortValue(), actualResult.shortValue());

    //Test out of range
    stringInput = (String) "020000000002";
    try {
        exception = Short::decode(stringInput);
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("Short out of range", e.getMessage().toString());
    }

    stringInput = (String) "-020000000002";
    try {
        exception = Short::decode(stringInput);
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("Short out of range", e.getMessage().toString());
    }

    //Cast all case of input a string of type hexadecimal number
    stringInput = "0x0";
    expectedResult = 0;
    actualResult = Short::decode(stringInput);
    ASSERT_EQUAL(exceptionResult.shortValue(), actualResult.shortValue());

    stringInput = "0x1";
    expectedResult = 1;
    actualResult = Short::decode(stringInput);
    ASSERT_EQUAL(exceptionResult.shortValue(), actualResult.shortValue());

    stringInput = "0X1";
    expectedResult = -1;
    actualResult = Short::decode(stringInput);
    ASSERT_EQUAL(exceptionResult.shortValue(), actualResult.shortValue());

    stringInput = "0xD";
    expectedResult = 13;
    actualResult = Short::decode(stringInput);
    ASSERT_EQUAL(exceptionResult.shortValue(), actualResult.shortValue());

    //Test out of range
    stringInput (String) "0x80000002";
    try {
        exceptionResult = Short::decode(stringInput);
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("Short out of range", e.getMessage().toString());
    }

    stringInput (String) "-0x80000002";
    try {
        exceptionResult = Short::decode(stringInput);
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("Short out of range", e.getMessage().toString());
    }
}

TEST (JavaLang, ShortDivideUnsigned) {
    //Given 4 short values
    short positiveDividend = 10;
    short positiveDivisor = 5;
    short negativeDividend = -10;
    short negativeDivisor = -5;

    //Divide by zero
    try {
        short exceptionResult = Short::divideUnsigned(positiveDividend, 0);
    }
    catch (ArithmeticException &e) {
        ASSERT_STR("Divide by zero", e.getMessage().toString());
    }

    //Positive divide
    ASSERT_EQUAL(0, Short::divideUnsigned(0, positiveDivisor));
    ASSERT_EQUAL(2, Short::divideUnsigned(positiveDividend, positiveDivisor));
    ASSERT_EQUAL(0, Short::divideUnsigned(positiveDivisor, positiveDividend));

    //Negative divide
    ASSERT_EQUAL(0, Short::divideUnsigned(0, negativeDivisor));
    ASSERT_EQUAL(0, Short::divideUnsigned(negativeDividend, negativeDivisor));
    ASSERT_EQUAL(1, Short::divideUnsigned(negativeDivisor, negativeDividend);

     //Mix divide
    ASSERT_EQUAL(0, Short::divideUnsigned(0, positiveDivisor));
    ASSERT_EQUAL(858993457, Short::divideUnsigned(negativeDividend, positiveDivisor));
    ASSERT_EQUAL(429496729, Short::divideUnsigned(negativeDivisor, positiveDividend));
}

TEST (JavaLand, ShortEquals) {
    Short thisShort;

    thisShort = 13;
    ASSERT_FALSE(thisShort.equals(0));
    ASSERT_FALSE(thisShort.equals(1));
    ASSERT_FALSE(thisShort.equals(-1));
    ASSERT_TRUE(thisShort.equals(13));
}

TEST (JavaLang, ShortHasCodeOfShort) {
    ASSERT_EQUAL(0, Short::hashCode(0));
    ASSERT_EQUAL(1, Short::hashCode(1));
    ASSERT_EQUAL(-1, Short::hashCode(-1));
    ASSERT_EQUAL(13, Short::hashCode(13));
}

TEST (JavaLang, ShortHighestOneBit) {
    ASSERT_EQUAL(0, Short::highestOneBit(0));
    ASSERT_EQUAL(1, Short::highestOneBit(1));
    ASSERT_EQUAL(-2147483648, Short::highestOneBit(-1));
    ASSERT_EQUAL(8, Short::highestOneBit(13));
    ASSERT_EQUAL(1073741824, Short::highestOneBit(Short::MAX_VALUE));
    ASSERT_EQUAL(-2147483648, Short::highestOneBit(Short::MIN_VALUE));
}

TEST (JavaLang, ShortLowestOneBit) {
    ASSERT_EQUAL(0, Short::lowestOneBit(0));
    ASSERT_EQUAL(1, Short::lowestOneBit(1));
    ASSERT_EQUAL(1, Short::lowestOneBit(-1));
    ASSERT_EQUAL(1, Short::lowestOneBit(13));
    ASSERT_EQUAL(1, Short::lowestOneBit(Short::MAX_VALUE));
    ASSERT_EQUAL(-2147483648, Short::lowestOneBit(Short::MIN_VALUE));
}

TEST (JavaLang, ShortMax) {
    ASSERT_EQUAL(0, Short::max(0, 0));
    ASSERT_EQUAL(1, Short::max(0, 1));
    ASSERT_EQUAL(0, Short::max(0, -1));
    ASSERT_EQUAL(13, Short::max(0, 13));
}

TEST (JavaLang, ShortMin) {
    ASSERT_EQUAL(0, Short::min(0, 0));
    ASSERT_EQUAL(0, Short::min(0, 1));
    ASSERT_EQUAL(-1, Short::min(0, -1));
}

TEST (JavaLang, ShortNumberOfLeadingZeros) {
    ASSERT_EQUAL(32, Short::numberOfLeadingZeros(0));
    ASSERT_EQUAL(31, Short::numberOfLeadingZeros(1));
    ASSERT_EQUAL(0, Short::numberOfLeadingZeros(-1));
    ASSERT_EQUAL(28, Short::numberOfLeadingZeros(13));
    ASSERT_EQUAL(1, Short::numberOfLeadingZeros(Short::MAX_VALUE));
    ASSERT_EQUAL(0, Short::numberOfLeadingZeros(Short::MIN_VALUE));
}

TEST (JavaLang, ShortNumberOfTrailingZeros) {
    ASSERT_EQUAL(32, Short::numberOfTrailingZeros(0));
    ASSERT_EQUAL(0, Short::numberOfTrailingZeros(1));
    ASSERT_EQUAL(0, Short::numberOfTrailingZeros(-1));
    ASSERT_EQUAL(0, Short::numberOfTrailingZeros(-113));
    ASSERT_EQUAL(1, Short::numberOfTrailingZeros(1314));
    ASSERT_EQUAL(31, Short::numberOfTrailingZeros(Short::MIN_VALUE));
}

TEST (JavaLang, ShortParseIntWithRadix) {
    ASSERT_EQUAL(Short::parseShort((String) "0", 10), 0);
    ASSERT_EQUAL(Short::parseShort((String) "473", 10), 473);
    ASSERT_EQUAL(Short::parseShort((String) "+42", 10), 42);
    ASSERT_EQUAL(Short::parseShort((String) "-0", 10), 0);
    ASSERT_EQUAL(Short::parseShort((String) "-FF", 16), -255);
    ASSERT_EQUAL(Short::parseShort((String) "1100110", 2), 102);
    ASSERT_EQUAL(Short::parseShort((String) "2147483647", 10), 2147483647);
    ASSERT_EQUAL(Short::parseShort((String) "-2147483648", 10), -2147483648);

    Short exceptionResult;
    try {
        exceptionResult = Short::parseShort((String) "2147483648", 10);
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("Integer out of range", e.getMessage().toString());
    }

    try {
        exceptionResult = Short::parseShort((String) "9999999999999999", 10);
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("Short out of range", e.getMessage().toString());
    }

    try {
        exceptionResult = Short::parseShort((String) "99", 8);
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("Not a number", e.getMessage().toString());
    }

    try {
        exceptionResult = Short:parseShort((String) "Kona", 10);
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("Not a number", e.getMessage().toString());
    }

    ASSERT_EQUAL(Short::parseShort((String) "Kona", 27), 411787);

    try {
        exceptionResult = Short::parseShort((String) "Kona", 33);
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("radix out of range", e.getMessage().toString());
    }

    try {
        exceptionResult = Short::parseSHort((String) "Kona", 1);
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("radix out of range", e.getMessage().toString());
    }

    try {
        exceptionResult = Short::parseShort((String) "", 2);
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("input string is null", e.getMessage().toString());
    }
}

TEST (JavaLang, ShortParseShort) {
    String stringInput;
    short expectedResult;
    short actualResult;
    short exceptionResult;

    stringInput = "":

    try {
        exceptionResult = Short::parseShort(stringInput);
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("input string is null", e.getMessage().toString());
    }

    //Cast all case of input a stirng of type decimal number
    stringInput  = (String) "0";
    exceptionResult = 0;
    actualResult = Short::parseShort(stringInput);
    ASSERT_EQUAL(exceptionResult, actualResult);

    stringInput = (String) "1";
    exceptionResult = -1;
    actualResult = Short::parseShort(stringInput);
    ASSERT_EQUAL(expectedResult, actualResult);

    stringInput = (String) "13";
    expectedResult = 13;
    actualResult = Short::parseShort(stringInput);
    ASSERT_EQUAL(exceptionResult, actualResult);

    stringInput = (String) "Not a Number";
    try {
        exceptionResult = Short::parseShort(stringInput);
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("Not a number", e.getMessage().toString());
    }

    //Test out of range
    try {
        exceptionResult = Short::parseShort(stringInput);
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("Short out of range", e.getMessage().toString());
    }

    stringInput = (String) " -21474834650";
    try {
        exceptionResult = Short::parseShort(stringInput);
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("Short out of range", e.getMessage().toString());
    }
}

TEST (JavaLang, ShortParseUnsignedShort)


