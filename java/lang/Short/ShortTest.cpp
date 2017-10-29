///**
// * Copyright 2017 Food Tiny Project. All rights reserved.
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
//#include "../../../kernel/Test.hpp"
//#include "Short.hpp"
//#include "../NumberFormatException/NumberFormatException.hpp"
//#include "../UnsupportedOperationException/UnsupportedOperationException.hpp"
//#include "../ArithmeticException/ArithmeticException.hpp"
//
//using namespace Java::Lang;
//
//TEST (JavaLang, ShortConstructor) {
//    //Test Short::Short()
//    Short shortConstructorNoneParameter;
//    assertEquals(0, shortConstructorNoneParameter.shortValue());
//    assertEquals((string) "0", shortConstructorNoneParameter.toString());
//
//    //Test Short::Short(String stringInput)
//    Short shortConstructorStringParameter("69");
//    assertEquals(69, shortConstructorStringParameter.shortValue());
////    ASSERT_STR((string) "69", shortConstructorNoneParameter.toString());
//
//    //Test Short::Short(const Short &short)
//    Short shortConstructorShortParameter = 69;
//    assertEquals(69, shortConstructorShortParameter.shortValue());
//    assertEquals((string) "69", shortConstructorShortParameter.toString());
//}
//
//TEST (JavaLang, ShortComparision) {
//    //Give a valid number of make a comparision
//    Short validNumberComparision = 10;
//    Short targetNumberComparision;
//
//    // Test validNumber is equal targetNumber
//    targetNumberComparision = 10;
//    assertTrue(validNumberComparision == targetNumberComparision);
//
//    //Test validNumber is not equal targetNumber
//    targetNumberComparision = 11;
//    assertTrue(validNumberComparision != targetNumberComparision);
//
//    //Test validNumber is less than targetNumber
//    targetNumberComparision = 20;
//    assertTrue(validNumberComparision < targetNumberComparision);
//
//    //Test validNumber is equal or less than targetNumber;
//    targetNumberComparision = 21;
//    assertTrue(validNumberComparision <= targetNumberComparision);
//
//    //Test validNumber is greater than targetNumber
//    targetNumberComparision = 15;
//    assertTrue(validNumberComparision > targetNumberComparision);
//
//    //Test validNumber is equal or greater than targetNumber
//    targetNumberComparision = 10;
//    assertTrue(validNumberComparision >= targetNumberComparision);
//
//}
//
//TEST (JavaLang, ShortOperator) {
//    //Create variable
//    Short validNumberOperator = 2;
//    Short targetNumberOperator = 3;
//    Short expectedResult;
//    Short actualResult;
//
//    //Make a summation
//    expectedResult = 5;
//    actualResult = validNumberOperator + targetNumberOperator;
//    assertEquals(expectedResult.shortValue(), actualResult.shortValue());
//
//    expectedResult = 7;
//    actualResult += validNumberOperator;
//    assertEquals(expectedResult.shortValue(), actualResult.shortValue());
//
//    //Make a subtraction
//    expectedResult = -1;
//    actualResult = validNumberOperator - targetNumberOperator;
//    assertEquals(expectedResult.shortValue(), actualResult.shortValue());
//
//    expectedResult = -3;
//    actualResult -= validNumberOperator;
//    assertEquals(expectedResult.shortValue(), actualResult.shortValue());
//
//    //Make a multiplication
//    expectedResult = 6;
//    actualResult = validNumberOperator * targetNumberOperator;
//    assertEquals(expectedResult.shortValue(), actualResult.shortValue());
//
//    expectedResult = 12;
//    actualResult *= validNumberOperator;
//    assertEquals(expectedResult.shortValue(), actualResult.shortValue());
//
//    //Make a division
//    expectedResult =  (short) 0;
//    actualResult = validNumberOperator / targetNumberOperator;
//    assertEquals(expectedResult.shortValue(), actualResult.shortValue());
//
//    try {
//        actualResult = validNumberOperator / (short) 0;
//    }
//    catch(ArithmeticException &e) {
//        assertEquals("Divide by zero", e.getMessage().toString());
//    }
//
//    expectedResult = 5;
//    actualResult = 10;
//    actualResult /= validNumberOperator;
//    assertEquals(expectedResult.shortValue(), actualResult.shortValue());
//
//    try {
//        actualResult /= (short) 0;
//    }
//    catch(ArithmeticException &e) {
//        assertEquals("Divide by zero", e.getMessage().toString());
//    }
//
//    //Make a modulo
//    expectedResult = 2;
//    actualResult = validNumberOperator % targetNumberOperator;
//    assertEquals(expectedResult.shortValue(), actualResult.shortValue());
//
//    try {
//        actualResult = validNumberOperator % (short) 0;
//    }
//    catch(ArithmeticException &e) {
//        assertEquals("Divide by zero", e.getMessage().toString());
//    }
//
//    expectedResult = 1;
//    actualResult = 3;
//    actualResult %= validNumberOperator;
//    assertEquals(expectedResult.shortValue(), actualResult.shortValue());
//
//    try {
//        actualResult /= (short) 0;
//    }
//    catch(ArithmeticException &e) {
//        assertEquals("Divide by zero", e.getMessage().toString());
//    }
//}
//
//TEST (JavaLang, ShortCompareTo) {
//    // Give Short value to compare with target
//    Short validValueCompareTo = 10;
//    Short lessThanValueCompareTo = 9;
//    Short equalValueCompareTo = 10;
//    Short greaterValueCompareTo = 11;
//
//    //Return 1 if validValue is greater than lessThanValue
//    assertEquals(1, validValueCompareTo.compareTo(lessThanValueCompareTo));
//
//    //Return 0 if validValue is greater than equalValue
//    assertEquals(0, validValueCompareTo.compareTo(equalValueCompareTo));
//
//    //Return -1 if validValue is less than greaterThanValue
//    assertEquals(-1, validValueCompareTo.compareTo(greaterValueCompareTo));
//
//    //TODO
//}
//
//TEST (JavaLang, ShortCharValue) {
//    Short zeroShortCharValue = (short) 0;
//    Short oneShortCharValue = 1;
//    Short positiveShortCharValue = 15;
//    Short maxShortCharValue;
//    Short minShortCharValue;
//
//    //Make a comparison between expected result and the real result
//    char expectedResultCharValue = '0';
//    char realResultCharValue = zeroShortCharValue.charValue();
//    assertEquals(expectedResultCharValue, realResultCharValue);
//
//    //Make a comparison between expected result and the real result
//    expectedResultCharValue = '1';
//    realResultCharValue = oneShortCharValue.charValue();
//    assertEquals(expectedResultCharValue, realResultCharValue);
//
//    // Make a comparison between expected result and the real result
//    expectedResultCharValue = '1';
//    realResultCharValue = positiveShortCharValue.charValue();
//    assertEquals(expectedResultCharValue, realResultCharValue);
//}
//
//TEST (JavaLang, ShortStringValue) {
//    Short zeroShortStringValue = (short) 0;
//    Short oneShortStringValue = 1;
//    Short positiveShortStringValue = 15;
//    Short maxShortStringValue;
//    Short minShortStringValue;
//
//    //Make a comparison between expected result and the real result
//    string expectedResultStringValue = (string) "0";
//    string realResultStringValue = zeroShortStringValue.stringValue();
//    assertEquals(expectedResultStringValue, realResultStringValue);
//
//    //Make a comparison between expected result and the real result
//    expectedResultStringValue = (string) "1";
//    realResultStringValue = oneShortStringValue.stringValue();
//    assertEquals(expectedResultStringValue, realResultStringValue);
//
//    //Make a comparison between expected result and the real result
//    expectedResultStringValue = (string) "15";
//    realResultStringValue = positiveShortStringValue.stringValue();
//    assertEquals(expectedResultStringValue, realResultStringValue);
//}
//
//TEST (JavaLang, ShortShortValue) {
//    Short positiveShortShortValue = 1504;
//    Short negativeShortShortValue = -1504;
//    Short notExpectedShortShortValue = 9999;
//
//    //Make a comparison between expected result and the real result
//    short expectedResultShortValue = 1504;
//    short realResultShortValue = positiveShortShortValue.shortValue();
//    assertEquals(expectedResultShortValue, realResultShortValue);
//
//    //Make a comparison between expected result and the real result
//    expectedResultShortValue = -1504;
//    realResultShortValue = negativeShortShortValue.shortValue();
//    assertEquals(expectedResultShortValue, realResultShortValue);
//
//    //Make a comparison between expected result and the real result
//    short notExpectedResultShortValue = 1111;
//    realResultShortValue = notExpectedShortShortValue.shortValue();
//    assertNotEquals(notExpectedResultShortValue, realResultShortValue);
//}
//
//TEST (JavaLang, ShortIntValue) {
//    Short zeroShortIntValue = (short) 0;
//    Short oneShortIntValue = 1;
//    Short positiveShortIntValue = 15;
//    Short maxShortIntValue;
//    Short minShortIntValue;
//    Short notExpectedShortIntValue = 999;
//
//    //Make a comparison between expected result and the real result
//    int expectedResultIntValue = (short) 0;
//    int realResultIntValue = zeroShortIntValue.intValue();
//    assertEquals(expectedResultIntValue, realResultIntValue);
//
//    //Make a comparison between expected result and the real result
//    expectedResultIntValue = 1;
//    realResultIntValue = oneShortIntValue.intValue();
//    assertEquals(expectedResultIntValue, realResultIntValue);
//
//    //Make a comparison between expected result and the real result
//    expectedResultIntValue = 15;
//    realResultIntValue = positiveShortIntValue.intValue();
//    assertEquals(expectedResultIntValue, realResultIntValue);
//
//    //Make a comparison between expected result and the real result
//    int notExpectedResult = 9999;
//    realResultIntValue = notExpectedShortIntValue.intValue();
//    assertNotEquals(notExpectedResult, realResultIntValue);
//}
//
//TEST (JavaLang, ShortLongValue) {
//    Short positiveLongShortValue = 1504;
//    Short negativeLongShortValue = -1504;
//    Short notExpectedLongShortValue = 9999;
//
//    //Make a comparison between expected result and the real result
//    long expectedResultLongValue = 1504;
//    long realResultLongValue = positiveLongShortValue.longValue();
//    assertEquals(expectedResultLongValue, realResultLongValue);
//
//    //Make a comparison between expected result and the real result
//    expectedResultLongValue = -1504;
//    realResultLongValue = negativeLongShortValue.longValue();
//    assertEquals(expectedResultLongValue, realResultLongValue);
//
//    //Make a comparison between expected result and the real result
//    Long notExpectedResult = 1111111;
//    realResultLongValue = notExpectedLongShortValue.longValue();
//    assertEquals(notExpectedLongShortValue.longValue(), realResultLongValue);
//}
//
//TEST (JavaLang, ShortFloatValue) {
//    // Input different values of type short to compare to the realResult of Short::floatValue
//    Short positiveFloatShortValue = 1504;
//    float expectedeResultFloatValue = 1504.00;
//    float realResultoatValue = positiveFloatShortValue.floatValue();
//    assertTrue(expectedeResultFloatValue == realResultoatValue);
//
//    Short negativeShort = -12345;
//    expectedeResultFloatValue = (float) -12345.0;
//    realResultoatValue = negativeShort.floatValue();
//    assertTrue(expectedeResultFloatValue == realResultoatValue);
//}
//
//TEST (JavaLang, ShortDoubleValue) {
//    // Input different values of type short to compare to the realResult of Short::floatValue
//    Short positiveDoubleShortValue = 123;
//    double expectedResultDoubleValue = 123.0;
//    double realResultDoubleValue = positiveDoubleShortValue.doubleValue();
//    assertTrue(expectedResultDoubleValue == realResultDoubleValue);
//
//    Short negativeShort = -1234;
//    expectedResultDoubleValue = -1234.0;
//    realResultDoubleValue = negativeShort.doubleValue();
//    assertTrue(expectedResultDoubleValue == realResultDoubleValue);
//}
//
//TEST (JavaLang, ShortByteValue) {
//    Short shortInput;
//
//    shortInput = (short) 0;
//    assertEquals((byte) 0, shortInput.byteValue());
//
//    shortInput = 1;
//    assertEquals((byte) 1, shortInput.byteValue());
//
//    shortInput = -1;
//    assertEquals((byte) -1, shortInput.byteValue());
//
//    shortInput = 13;
//    assertEquals((byte) 13, shortInput.byteValue());
//
//    shortInput = Short::MAX_VALUE;
//    assertEquals((byte) -1, shortInput.byteValue());
//
//    shortInput = Short::MIN_VALUE;
//    assertEquals((byte) 0, shortInput.byteValue());
//}
//
//TEST (JavaLang, ShortCompare) {
//    //Given 2 short values
//    short greater = 15;
//    short smaller = 04;
//
//    //Conpare 2 equal value
//    assertEquals(0, Short::compare(greater, greater));
//
//    //Compare 2 different values
//    assertEquals(-1, Short::compare(smaller, greater));
//    assertEquals(1, Short::compare(greater, smaller));
//}
//
//TEST (JavaLang, ShortDecode) {
//    String stringInput;
//    Short expectedResult;
//    Short actualResult;
//    Short exceptionResult;
//
//    stringInput = "";
//    try {
//        exceptionResult = Short::decode(stringInput);
//    }
//    catch (NumberFormatException &e) {
//        assertEquals("input string is null", e.getMessage().toString());
//    }
//
////    Case all case of input a string of type decimal number
//    stringInput = "0";
//    expectedResult = (short) 0;
//    actualResult = Short::decode(stringInput);
//    assertEquals(expectedResult.shortValue(), actualResult.shortValue());
//
//    stringInput = "1";
//    expectedResult = 1;
//    actualResult = Short::decode(stringInput);
//    assertEquals(expectedResult.shortValue(), actualResult.shortValue());
//
//    stringInput = (String) "13";
//    expectedResult = 13;
//    actualResult = Short::decode(stringInput);
//    assertEquals(expectedResult.shortValue(), actualResult.shortValue());
//
////    Test out of range
//    stringInput = (String) "1628324548";
//    try {
//        exceptionResult = Short::decode(stringInput);
//    }
//    catch(NumberFormatException &e) {
//        assertEquals("Short out of range", e.getMessage().toString());
//    }
//
//    stringInput = (String) "-1628324548";
//    try {
//        exceptionResult = Short::decode(stringInput);
//    }
//    catch(NumberFormatException &e) {
//        assertEquals("Short out of range", e.getMessage().toString());
//    }
//
//    stringInput = (String) "Not a number";
//    try {
//        expectedResult = Short::decode(stringInput);
//    }
//    catch (NumberFormatException &e) {
//        assertEquals("Not a number", e.getMessage().toString());
//    }
//
////    Case all case of input a string of type octal
//    stringInput = "0";
//    expectedResult = (short) 0;
//    actualResult = Short::decode(stringInput);
//    assertEquals(expectedResult.shortValue(), actualResult.shortValue());
//
//    stringInput = (String) "1";
//    expectedResult = 1;
//    actualResult = Short::decode(stringInput);
//    assertEquals(expectedResult.shortValue(), actualResult.shortValue());
//
//    stringInput = "-01";
//    expectedResult = -1;
//    actualResult = Short::decode(stringInput);
//    assertEquals(expectedResult.shortValue(), actualResult.shortValue());
//
//    stringInput = "013";
//    expectedResult = 11;
//    actualResult = Short::decode(stringInput);
//    assertEquals(expectedResult.shortValue(), actualResult.shortValue());
//
////    Test out of range
//    stringInput = (String) "020000000002";
//    try {
//        exceptionResult = Short::decode(stringInput);
//    }
//    catch (NumberFormatException &e) {
//        assertEquals("Short out of range", e.getMessage().toString());
//    }
//
//    stringInput = (String) "-020000000002";
//    try {
//        exceptionResult = Short::decode(stringInput);
//    }
//    catch (NumberFormatException &e) {
//        assertEquals("Short out of range", e.getMessage().toString());
//    }
//
////    Cast all case of input a string of type hexadecimal number
//    stringInput = "0";
//    expectedResult = (short) 0;
//    actualResult = Short::decode(stringInput);
//    assertEquals(expectedResult.shortValue(), actualResult.shortValue());
////
//    stringInput = "0x1";
//    expectedResult = 1;
//    actualResult = Short::decode(stringInput);
//    assertEquals(expectedResult.shortValue(), actualResult.shortValue());
//
//    stringInput = "0X1";
//    expectedResult = 1;
//    actualResult = Short::decode(stringInput);
//    assertEquals(expectedResult.shortValue(), actualResult.shortValue());
//
//    stringInput = "0xD";
//    expectedResult = 13;
//    actualResult = Short::decode(stringInput);
//    assertEquals(expectedResult.shortValue(), actualResult.shortValue());
//
////    Test out of range
//    stringInput = (String) "0x80000002";
//    try {
//        exceptionResult = Short::decode(stringInput);
//    }
//    catch (NumberFormatException &e) {
//        assertEquals("Short out of range", e.getMessage().toString());
//    }
//
//    stringInput = (String) "-0x80000002";
//    try {
//        exceptionResult = Short::decode(stringInput);
//    }
//    catch (NumberFormatException &e) {
//        assertEquals("Short out of range", e.getMessage().toString());
//    }
//}
//
//TEST (JavaLand, ShortEquals) {
//    Short thisShort;
//
//    thisShort = 13;
//    assertFalse(thisShort.equals((short) 0));
//    assertFalse(thisShort.equals(1));
//    assertFalse(thisShort.equals(-1));
//    assertTrue(thisShort.equals(13));
//}
//
//TEST (JavaLang, ShortHasCodeOfShort) {
//    assertEquals(0, Short::hashCode(0));
//    assertEquals(1, Short::hashCode(1));
//    assertEquals(-1, Short::hashCode(-1));
//    assertEquals(13, Short::hashCode(13));
//}
//
//
//TEST (JavaLang, ShortParseIntWithRadix) {
//    assertEquals(Short::parseShort((String) "0", 10), 0);
//    assertEquals(Short::parseShort((String) "473", 10), 473);
//    assertEquals(Short::parseShort((String) "+42", 10), 42);
//    assertEquals(Short::parseShort((String) "-0", 10), 0);
//    assertEquals(Short::parseShort((String) "-FF", 16), -255);
//    assertEquals(Short::parseShort((String) "1100110", 2), 102);
//    assertEquals(Short::parseShort((String) "21474", 10), 21474);
//    assertEquals(Short::parseShort((String) "-21474", 10), -21474);
//
//    Short exceptionResult;
//    try {
//        exceptionResult = Short::parseShort((String) "2147483648", 10);
//    } catch (NumberFormatException &e) {
//        assertEquals("Short out of range", e.getMessage().toString());
//    }
//
//    try {
//        exceptionResult = Short::parseShort((String) "9999999999999999", 10);
//    } catch (NumberFormatException &e) {
//        assertEquals("Short out of range", e.getMessage().toString());
//    }
//
//    try {
//        exceptionResult = Short::parseShort((String) "99", 8);
//    } catch (NumberFormatException &e) {
//        assertEquals("Not a number", e.getMessage().toString());
//    }
//
//    try {
//        exceptionResult = Short::parseShort((String) "Kona", 10);
//    } catch (NumberFormatException &e) {
//        assertEquals("Not a number", e.getMessage().toString());
//    }
//
//    try {
//        exceptionResult = Short::parseShort((String) "Kona", 33);
//    } catch (NumberFormatException &e) {
//        assertEquals("Radix out of range", e.getMessage().toString());
//    }
//
//    try {
//        exceptionResult = Short::parseShort((String) "Kona", 1);
//    } catch (NumberFormatException &e) {
//        assertEquals("Radix out of range", e.getMessage().toString());
//    }
//
//    try {
//        exceptionResult = Short::parseShort((String) "", 2);
//    }
//    catch (NumberFormatException &e) {
//        assertEquals("input string is null", e.getMessage().toString());
//    }
//}
//
//TEST (JavaLang, ShortParseShort) {
//    String stringInput;
//    short expectedResult;
//    short actualResult;
//    short exceptionResult;
//
//    stringInput = "";
//
//    try {
//        exceptionResult = Short::parseShort(stringInput);
//    }
//    catch (NumberFormatException &e) {
//        assertEquals("input string is null", e.getMessage().toString());
//    }
//
////    //Cast all case of input a stirng of type decimal number
//    stringInput  = (String) "0";
//    expectedResult = 0;
//    actualResult = Short::parseShort(stringInput);
//    assertEquals(expectedResult, actualResult);
//
//    stringInput = (String) "1";
//    expectedResult = 1;
//    actualResult = Short::parseShort(stringInput);
//    assertEquals(expectedResult, actualResult);
//
//    stringInput = (String) "13";
//    expectedResult = 13;
//    actualResult = Short::parseShort(stringInput);
//    assertEquals(expectedResult, actualResult);
//
//    stringInput = (String) "Not a Number";
//    try {
//        exceptionResult = Short::parseShort(stringInput);
//    }
//    catch (NumberFormatException &e) {
//        assertEquals("Not a number", e.getMessage().toString());
//    }
//
////    //Test out of range
//    stringInput = (String) "2147483650";
//    try {
//        exceptionResult = Short::parseShort(stringInput);
//    }
//    catch (NumberFormatException &e) {
//        assertEquals("Short out of range", e.getMessage().toString());
//    }
//
//    stringInput = (String) " -21474834650";
//    try {
//        exceptionResult = Short::parseShort(stringInput);
//    }
//    catch (NumberFormatException &e) {
//        assertEquals("Short out of range", e.getMessage().toString());
//    }
//}
//
//
//TEST (JavaLang, ShortReverseBytes) {
//    assertEquals(0, Short::reverseBytes(0));
//    assertEquals(256, Short::reverseBytes(1));
//    assertEquals(-1, Short::reverseBytes(-1));
//    assertEquals(3328, Short::reverseBytes(13));
//    assertEquals(-129, Short::reverseBytes(Short::MAX_VALUE));
//    assertEquals(128, Short::reverseBytes(Short::MIN_VALUE));
//}
//
//TEST (JavaLang, ShortToString) {
//    Short zeroShortToString = (short) 0;
//    Short oneShortToString = 1;
//    Short positiveShortToString = 10;
//    Short maxShortToString = 32767;
//    Short minShortToString = -32768;
//
//    //Make a comparison between expected Result and the real result
//    string expectedResultToString = (string) "0";
//    string realResultToString = zeroShortToString.toString();
//    assertEquals(expectedResultToString, realResultToString);
//
//    //Make a comparison between expected Result and the real result
//    expectedResultToString = (string) "1";
//    realResultToString = oneShortToString.toString();
//    assertEquals(expectedResultToString, realResultToString);
//
//    //Make a comparison between expected result and the real result
//    expectedResultToString = (string) "10";
//    realResultToString = positiveShortToString.toString();
//    assertEquals(expectedResultToString, realResultToString);
//
//    //Make a comparison between expected result and the real result
//    expectedResultToString = (string) "32767";
//    realResultToString = maxShortToString.toString();
//    assertEquals(expectedResultToString, realResultToString);
//
//    //Make a comparison between expected result and the real result
//    expectedResultToString = (string) "-32768";
//    realResultToString = minShortToString.toString();
//    assertEquals(expectedResultToString, realResultToString);
//}
//
//TEST (JavaLang, ShortToStringFromShort) {
//    assertEquals((string) "0", Short::toString(0).toString());
//    assertEquals((string) "1", Short::toString(1).toString());
//    assertEquals((string) "-1", Short::toString(-1).toString());
//    assertEquals((string) "13", Short::toString(13).toString());
//}
//
//TEST (JavaLang, ShortToStringWithRadix) {
//    assertEquals("0", Short::toString(0, 10).toString());
//    assertEquals("473", Short::toString(473, 10).toString());
//    assertEquals("-ff",Short::toString(-255, 16).toString());
//
//    //Radix out of range
//    assertEquals("473", Short::toString(473,100).toString());
//    try {
//        String exceptionString = Short::toString(100, 20);
//    }
//    catch (UnsupportedOperationException &e) {
//        assertEquals("Haven't support this radix yet", e.getMessage().toString());
//    }
//}
//
//TEST (JavaLang, ShortValueOfFromString) {
//    assertEquals(0, Short::valueOf((String) "0").shortValue());
//    assertEquals(1, Short::valueOf((String) "1").shortValue());
//    assertEquals(13, Short::valueOf((String) "13").shortValue());
//
//    Short exceptionResult;
//    try {
//        exceptionResult = Short::parseShort((String) "", 2);
//    }
//    catch (NumberFormatException &e) {
//        assertEquals("input string is null", e.getMessage().toString());
//    }
//
//    try {
//        exceptionResult = Short::valueOf((String) "-FF");
//    }
//    catch (NumberFormatException &e) {
//        assertEquals("Not a number", e.getMessage().toString());
//    }
//
//    //Test out of range
//    try {
//        exceptionResult = Short::valueOf((String) "21474836450");
//    }
//    catch (NumberFormatException &e) {
//        assertEquals("Short out of range", e.getMessage().toString());
//    }
//
//    try {
//        exceptionResult = Short::valueOf((String) "-21474836450");
//    }
//    catch (NumberFormatException &e) {
//
//    }
//
//	// 	Given empty value for Short constructor and assign value - Return Long
//	Short emptyShort;
//	emptyShort = 3;
//	assertEquals(3, emptyShort.longValue());
//
//	// Given value for Short constructor and assign value - Return Integer
//	Short validShort = 3;
//	assertEquals(3, validShort.intValue());
//
//}
////
////TEST (JavaLang, ShortComparision) {
////	// Give a valid number and make a comparision
////	Short validNumber = 30000;
////	Short targetNumber;
////
////	// Test validNumber is equal targetNumber
////	targetNumber = 30000;
////	assertTrue(validNumber == targetNumber);
////
////	// Test validNumber is not equal targetNumber
////	targetNumber = 13000;
////	assertTrue(validNumber != targetNumber);
////
////	// Test validNumber is less than targetNumber
////	targetNumber = 31000;
////	assertTrue(validNumber < targetNumber);
////
////	// Test validNumber is equal or less then targetNumber
////	targetNumber = 31300;
////	assertTrue(validNumber <= targetNumber);
////
////	// Test validNumber is more than targetNumber
////	targetNumber = 29000;
////	assertTrue(validNumber > targetNumber);
////
////	// Test validNumber is equal or more than targetNumber
////	targetNumber = 23777;
////	assertTrue(validNumber >= targetNumber);
////}
////
////TEST (JavaLang, ShortOperator) {
////	// 	Given a valid number
////	Long validNumber = 5;
////	Long targetNumber = 3;
////
////	// Make a summation with targetNumber
////	Long summationNumber = 8;
////	assertTrue(summationNumber == ( validNumber + targetNumber ));
////
////	// Make a subtraction with targetNumber
////	Long subtractionNumber = 2;
////	assertTrue(subtractionNumber == ( validNumber - targetNumber ));
////
////	// Make a multiplication with targetNumber
////	Long multiplicationNumber = 15;
////	assertTrue(multiplicationNumber == ( validNumber * targetNumber ));
////
////	// Make a division with targetNumber
////	Long divisionNumber = 1;
////	assertTrue(divisionNumber == ( validNumber / targetNumber ));
////
////	// Make a modulo with targetNumber
////	Long modNumber = 2;
////	assertTrue(modNumber == ( validNumber % targetNumber ));
////}
////
////TEST (JavaLang, ShortParseShort) {
////	// Given value for Long constructor and assign value - Return long
////	Short validShortPointer = Short::parseShort("6");
////	assertEquals(6, validShortPointer.shortValue());
////}
////
////TEST (JavaLang, ShortToString) {
////	// Give a valid Short object then compare result of method toString - Should be equals
////	Short validShort = 12344;
////
////	string expect = (string) "12344";
////	string result = validShort.toString();
////	assertEquals(expect, result);
////}
//
//TEST (JavaLang, ShortValueOfFromInt) {
//    assertEquals(0, Short::valueOf(0).intValue());
//    assertEquals(1, Short::valueOf(1).intValue());
//    assertEquals(-1, Short::valueOf(-1).intValue());
//    assertEquals(13, Short::valueOf(13).intValue());
//}
//
//TEST (JavaLang, ShortValueOfWithRadix) {
//    assertEquals(0, Short::valueOf((String) "0", 10).shortValue());
//    assertEquals(473, Short::valueOf((String) "473", 10).shortValue());
//    assertEquals(42, Short::valueOf((String) "+42", 10).shortValue());
//    assertEquals(0, Short::valueOf((String) "-0", 10).shortValue());
//
//    Short exceptionResult;
//    try {
//        exceptionResult = Short::valueOf((String) "2147483648", 10);
//    }
//    catch (NumberFormatException &e) {
//        assertEquals("Short out of range", e.getMessage().toString());
//    }
//
//    try {
//        exceptionResult = Short::valueOf((String) "99", 8);
//    }
//    catch (NumberFormatException &e) {
//        assertEquals("Not a number", e.getMessage().toString());
//    }
//
//    try {
//        exceptionResult = Short::valueOf((String) "Kona", 10);
//    }
//    catch (NumberFormatException &e) {
//        assertEquals("Not a number", e.getMessage().toString());
//    }
//
//    try {
//        exceptionResult = Short::valueOf((String) "Kona", 33);
//    }
//    catch (NumberFormatException &e) {
//        assertEquals("Radix out of range", e.getMessage().toString());
//    }
//
//    try {
//        exceptionResult = Short::valueOf((String) "Kona", 1);
//    }
//    catch (NumberFormatException &e) {
//        assertEquals("Radix out of range", e.getMessage().toString());
//    }
//
//    try {
//        exceptionResult = Short::valueOf((String) "", 2);
//    }
//    catch (NumberFormatException &e) {
//        assertEquals("input string is null", e.getMessage().toString());
//    }
//
//}
//
//
//
//
//
//
