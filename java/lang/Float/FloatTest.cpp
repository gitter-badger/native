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

#include "Float.hpp"

using namespace Java::Lang;

TEST(JavaLang, FloatConstructor) {
	// Test Float::Float()
	Float emptyFloatConstructor;
	emptyFloatConstructor = 13.02;
	ASSERT_FLOAT_NEAR(13.02, emptyFloatConstructor.floatValue());
	
	// Test Float::Float(float original)
	Float floatConstructor = 13.02;
	ASSERT_FLOAT_NEAR(13.02, floatConstructor.floatValue());
	
	floatConstructor = 13.02;
	ASSERT_FLOAT_FAR(13.33, floatConstructor.floatValue());
	
	floatConstructor = -0.0f;
	ASSERT_FLOAT_NEAR(-0.0f, floatConstructor.floatValue());
	
	// Test Float::Float(const Float &floatNumber)
	floatConstructor = 13.02;
	Float FloatConstructor(floatConstructor);
	ASSERT_FLOAT_NEAR(13.02, floatConstructor.floatValue());
}

TEST(JavaLang, FloatArithmeticOperator) {
	// Create variable to test
	Float variableArithmeticOperator1;
	Float variableArithmeticOperator2;
	Float expectedResultOperator;
	Float actualResultOperator;
	
	// Test Operator +
	variableArithmeticOperator1 = 1.1;
	variableArithmeticOperator2 = 2.2;
	expectedResultOperator = 3.3;
	actualResultOperator = variableArithmeticOperator1 + variableArithmeticOperator2;
	ASSERT_FLOAT_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
	
	// Test Operator -
	variableArithmeticOperator1 = 3.3;
	variableArithmeticOperator2 = 2.2;
	expectedResultOperator = 1.1;
	actualResultOperator = variableArithmeticOperator1 - variableArithmeticOperator2;
	ASSERT_FLOAT_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
	
	// Test Operator *
	variableArithmeticOperator1 =  2.0;
	variableArithmeticOperator2 =  13.02;
	expectedResultOperator = 26.04;
	actualResultOperator = variableArithmeticOperator1 * variableArithmeticOperator2;
	ASSERT_FLOAT_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
	
	// Test Operator /
	variableArithmeticOperator1 = 26.04;
	variableArithmeticOperator2 = 2.0;
	expectedResultOperator = 13.02;
	actualResultOperator = variableArithmeticOperator1 / variableArithmeticOperator2;
	ASSERT_FLOAT_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
	
	// Test Operator / . Float::POSITIVE_INFINITY
	variableArithmeticOperator1 = 26.04;
	variableArithmeticOperator2 = 0;
	expectedResultOperator = Float::POSITIVE_INFINITY;
	actualResultOperator = variableArithmeticOperator1 / variableArithmeticOperator2;
	ASSERT_FLOAT_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
	
	// Test Operator / . Float::NEGATIVE_INFINITY
	variableArithmeticOperator1 = -26.04;
	variableArithmeticOperator2 = 0;
	expectedResultOperator = Float::NEGATIVE_INFINITY;
	actualResultOperator = variableArithmeticOperator1 / variableArithmeticOperator2;
	ASSERT_FLOAT_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
	
	// Test Operator / . Float::NaN
	variableArithmeticOperator1 = 0;
	variableArithmeticOperator2 = 0;
	expectedResultOperator = -Float::NaN;
	actualResultOperator = variableArithmeticOperator1 / variableArithmeticOperator2;
	ASSERT_FLOAT_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
}

TEST(JavaLang, FloatRelationalOperator) {
    // Create variable to test
    Float variableRelationalOperator1;
    Float variableRelationalOperator2;
    boolean actual;

    // Test Operator ==
    variableRelationalOperator1 = 13.12;
    variableRelationalOperator2 = 13.12;
    actual = variableRelationalOperator1 == variableRelationalOperator2;
    ASSERT_TRUE(actual);

    variableRelationalOperator1 = 13.12345;
    variableRelationalOperator2 = 13.12344;
    actual = variableRelationalOperator1 == variableRelationalOperator2;
    ASSERT_FALSE(actual);

    // Test Operator !=
    variableRelationalOperator1 = 13.02;
    variableRelationalOperator2 = 99.02;
    actual = variableRelationalOperator1 != variableRelationalOperator2;
    ASSERT_TRUE(actual);

    variableRelationalOperator1 = 13.12345;
    variableRelationalOperator2 = 13.12344;
    actual = variableRelationalOperator1 != variableRelationalOperator2;
    ASSERT_TRUE(actual);

    // Test Operator >
    variableRelationalOperator1 = 13.02;
    variableRelationalOperator2 = 1.1f;
    actual = variableRelationalOperator1 > variableRelationalOperator2;
    ASSERT_TRUE(actual);

    variableRelationalOperator1 = 13.22;
    variableRelationalOperator2 = 13.99;
    actual = variableRelationalOperator1 > variableRelationalOperator2;
    ASSERT_FALSE(actual);

    // Test Operator <
    variableRelationalOperator1 = 1.11;
    variableRelationalOperator2 = 13.02;
    actual = variableRelationalOperator1 < variableRelationalOperator2;
    ASSERT_TRUE(actual);

    variableRelationalOperator1 = 13.02;
    variableRelationalOperator2 = 13.01;
    actual = variableRelationalOperator1 < variableRelationalOperator2;
    ASSERT_FALSE(actual);

    // Test Operator >=
    variableRelationalOperator1 = 15.00;
    variableRelationalOperator2 = 13.02;
    actual = variableRelationalOperator1 >= variableRelationalOperator2;
    ASSERT_TRUE(actual);

    variableRelationalOperator1 = 10.11;
    variableRelationalOperator2 = 13.02;
    actual = variableRelationalOperator1 >= variableRelationalOperator2;
    ASSERT_FALSE(actual);

    // Test Operator <=
    variableRelationalOperator1 = 1.11;
    variableRelationalOperator2 = 13.02;
    actual = variableRelationalOperator1 <= variableRelationalOperator2;
    ASSERT_TRUE(actual);

    variableRelationalOperator1 = 13.99;
    variableRelationalOperator2 = 13.11;
    actual = variableRelationalOperator1 <= variableRelationalOperator2;
    ASSERT_FALSE(actual);
}

TEST(JavaLang, FloatLogicalOperator) {
    // Create variable to test
    Float variableLogicalOperator1;
    Float variableLogicalOperator2;
    boolean expectedResultOperator;
    boolean actualResultOperator;

    // Test Operator && . Case 0   0
    variableLogicalOperator1 = 0;
    variableLogicalOperator2 = 0;
    expectedResultOperator = false;
    actualResultOperator = variableLogicalOperator1 && variableLogicalOperator2;
    ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator && . Case 0   1
    variableLogicalOperator1 = 0;
    variableLogicalOperator2 = 1;
    expectedResultOperator = false;
    actualResultOperator = variableLogicalOperator1 && variableLogicalOperator2;
    ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator && . Case 1   0
    variableLogicalOperator1 = 1;
    variableLogicalOperator2 = 0;
    expectedResultOperator = false;
    actualResultOperator = variableLogicalOperator1 && variableLogicalOperator2;
    ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator && . Case 1   1
    variableLogicalOperator1 = 1;
    variableLogicalOperator2 = 1;
    expectedResultOperator = true;
    actualResultOperator = variableLogicalOperator1 && variableLogicalOperator2;
    ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator || . Case 0   0
    variableLogicalOperator1 = 0;
    variableLogicalOperator2 = 0;
    expectedResultOperator = false;
    actualResultOperator = variableLogicalOperator1 || variableLogicalOperator2;
    ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator || . Case 0   1
    variableLogicalOperator1 = 0;
    variableLogicalOperator2 = 1;
    expectedResultOperator = true;
    actualResultOperator = variableLogicalOperator1 || variableLogicalOperator2;
    ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator || . Case 1   0
    variableLogicalOperator1 = 1;
    variableLogicalOperator2 = 0;
    expectedResultOperator = true;
    actualResultOperator = variableLogicalOperator1 || variableLogicalOperator2;
    ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator || . Case 1   1
    variableLogicalOperator1 = 1;
    variableLogicalOperator2 = 1;
    expectedResultOperator = true;
    actualResultOperator = variableLogicalOperator1 || variableLogicalOperator2;
    ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);
}

TEST(JavaLang, FloatAssignmentOperator) {
	// Create variable to test
	Float variableAssignmentOperator1;
	Float variableAssignmentOperator2;
	Float expectedResultOperator;
	Float actualResultOperator;
	
	// Test Operator =
	variableAssignmentOperator1 = 0.0;
	variableAssignmentOperator2 = 1.1;
	expectedResultOperator = 1.1;
	actualResultOperator = (variableAssignmentOperator1 = variableAssignmentOperator2);
	ASSERT_FLOAT_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
	
	// Test Operator +=
	variableAssignmentOperator1 = 1.1;
	variableAssignmentOperator2 = 2.2;
	expectedResultOperator = 3.3;
	actualResultOperator = (variableAssignmentOperator1 += variableAssignmentOperator2);
	ASSERT_FLOAT_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
	
	
	// Test Operator -=
	variableAssignmentOperator1 =   3.3;
	variableAssignmentOperator2 =  1.1;
	expectedResultOperator = 2.2;
	actualResultOperator = (variableAssignmentOperator1 -= variableAssignmentOperator2);
	ASSERT_FLOAT_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
	
	// Test Operator *=
	variableAssignmentOperator1 = 13.02;
	variableAssignmentOperator2 = 2.0;
	expectedResultOperator = 26.04;
	actualResultOperator = (variableAssignmentOperator1 *= variableAssignmentOperator2);
	ASSERT_FLOAT_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
	
	// Test Operator /=
	variableAssignmentOperator1 = 26.04;
	variableAssignmentOperator2 = 2.0;
	expectedResultOperator = 13.02;
	actualResultOperator = (variableAssignmentOperator1 /= variableAssignmentOperator2);
	ASSERT_FLOAT_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
}

TEST(JavaLang, FloatCharValue) {
	// Create variable to test
	Float variableTestCharValue;
	char expectedResultCharValue;
	char actualResultCharValue;
	
	// Test Float::POSITIVE_INFINITY
	variableTestCharValue = Float::POSITIVE_INFINITY;
	expectedResultCharValue = 'i';
	actualResultCharValue = variableTestCharValue.charValue();
	ASSERT_EQUAL(expectedResultCharValue, actualResultCharValue);
	
	// Test Float::NEGATIVE_INFINITY
	variableTestCharValue = Float::NEGATIVE_INFINITY;
	expectedResultCharValue = '-';
	actualResultCharValue = variableTestCharValue.charValue();
	ASSERT_EQUAL(expectedResultCharValue, actualResultCharValue);

//    // Test Float::NaN
//    variableTestCharValue = Float::NaN;
//    expectedResultCharValue = 45;  // 110 in MacOS
//    actualResultCharValue = variableTestCharValue.charValue();
//    ASSERT_EQUAL(expectedResultCharValue, actualResultCharValue);
	
	// Test Float::MAX_VALUE
	variableTestCharValue = Float::MAX_VALUE;
	expectedResultCharValue = '3';
	actualResultCharValue = variableTestCharValue.charValue();
	ASSERT_EQUAL(expectedResultCharValue, actualResultCharValue);
	
	// Test Float::MIN_NORMAL
	variableTestCharValue = Float::MIN_NORMAL;
	expectedResultCharValue = '1';
	actualResultCharValue = variableTestCharValue.charValue();
	ASSERT_EQUAL(expectedResultCharValue, actualResultCharValue);
	
	// Test Float::MIN_VALUE
	variableTestCharValue = Float::MIN_VALUE;
	expectedResultCharValue = '1';
	actualResultCharValue = variableTestCharValue.charValue();
	ASSERT_EQUAL(expectedResultCharValue, actualResultCharValue);
	
	// Test valid case
	variableTestCharValue = 13.02;
	expectedResultCharValue = '1';
	actualResultCharValue = variableTestCharValue.charValue();
	ASSERT_EQUAL(expectedResultCharValue, actualResultCharValue);
	
	// Test invalid case
	variableTestCharValue = 13.02;
	expectedResultCharValue = '5';
	actualResultCharValue = variableTestCharValue.charValue();
	ASSERT_NOT_EQUAL(expectedResultCharValue, actualResultCharValue);
}

TEST(JavaLang, FloatStringValue) {
    // Create variable to test
    Float variableTestStringValue;
    string expectedResultStringValue;
    string actualResultStringValue;

    // Test Float::POSITIVE_INFINITY
    variableTestStringValue = Float::POSITIVE_INFINITY;
    expectedResultStringValue = (string) "inf";
    actualResultStringValue = variableTestStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue, actualResultStringValue);

    // Test Float::NEGATIVE_INFINITY
    variableTestStringValue = Float::NEGATIVE_INFINITY;
    expectedResultStringValue = (string) "-inf";
    actualResultStringValue = variableTestStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue, actualResultStringValue);

    // Test Float::NaN
    variableTestStringValue = Float::NaN;
    expectedResultStringValue = (string) "nan";
    actualResultStringValue = variableTestStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue, actualResultStringValue);

    // Test Float::MAX_VALUE
    variableTestStringValue = Float::MAX_VALUE;
    expectedResultStringValue = (string) "3.40282e+38";
    actualResultStringValue = variableTestStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue, actualResultStringValue);

    // Test Float::MIN_NORMAL
    variableTestStringValue = Float::MIN_NORMAL;
    expectedResultStringValue = (string) "1.4013e-45";
    actualResultStringValue = variableTestStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue, actualResultStringValue);

    // Test Float::MIN_VALUE
    variableTestStringValue = Float::MIN_VALUE;
    expectedResultStringValue = (string) "1.17549e-38";
    actualResultStringValue = variableTestStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue, actualResultStringValue);
}

TEST(JavaLang, FloatShortValue) {
	// Create variable to test
	Float variableTestShortValue;
	short expectedResultShortValue;
	short actualResultShortValue;
	
	// Test Float::POSITIVE_INFINITY
	variableTestShortValue = Float::POSITIVE_INFINITY;
	expectedResultShortValue = 0;
	actualResultShortValue = variableTestShortValue.shortValue();
	ASSERT_EQUAL(expectedResultShortValue, actualResultShortValue);
	
	// Test Float::NEGATIVE_INFINITY
	variableTestShortValue = Float::NEGATIVE_INFINITY;
	expectedResultShortValue = 0;
	actualResultShortValue = variableTestShortValue.shortValue();
	ASSERT_EQUAL(expectedResultShortValue, actualResultShortValue);
	
	// Test Float::NaN
	variableTestShortValue = Float::NaN;
	expectedResultShortValue = 0;
	actualResultShortValue = variableTestShortValue.shortValue();
	ASSERT_EQUAL(expectedResultShortValue, actualResultShortValue);
	
	// Test Float::MAX_VALUE
	variableTestShortValue = Float::MAX_VALUE;
	expectedResultShortValue = 0;
	actualResultShortValue = variableTestShortValue.shortValue();
	ASSERT_EQUAL(expectedResultShortValue, actualResultShortValue);
	
	// Test Float::MIN_NORMAL
	variableTestShortValue = Float::MIN_NORMAL;
	expectedResultShortValue = 0;
	actualResultShortValue = variableTestShortValue.shortValue();
	ASSERT_EQUAL(expectedResultShortValue, actualResultShortValue);
	
	// Test Float::MIN_VALUE
	variableTestShortValue = Float::MIN_VALUE;
	expectedResultShortValue = 0;
	actualResultShortValue = variableTestShortValue.shortValue();
	ASSERT_EQUAL(expectedResultShortValue, actualResultShortValue);
	
	// Test valid case
	variableTestShortValue = 5.9;
	expectedResultShortValue = 5;
	actualResultShortValue = variableTestShortValue.shortValue();
	ASSERT_EQUAL(expectedResultShortValue, actualResultShortValue);

	// Test invalid case
	variableTestShortValue = 6;
	expectedResultShortValue = 5;
	actualResultShortValue = variableTestShortValue.shortValue();
	ASSERT_NOT_EQUAL(expectedResultShortValue, actualResultShortValue);
}

TEST(JavaLang, FloatIntValue) {
    // Create variable to test
    Float variableTestIntValue;
    int expectedResultIntValue;
    int actualResultIntValue;

    // Test Float::POSITIVE_INFINITY
    variableTestIntValue = Float::POSITIVE_INFINITY;
    expectedResultIntValue = -2147483648;
    actualResultIntValue = variableTestIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue, actualResultIntValue);

    // Test Float::NEGATIVE_INFINITY
    variableTestIntValue = Float::NEGATIVE_INFINITY;
    expectedResultIntValue = -2147483648;
    actualResultIntValue = variableTestIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue, actualResultIntValue);

    // Test Float::NaN
    variableTestIntValue = Float::NaN;
    expectedResultIntValue = -2147483648;
    actualResultIntValue = variableTestIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue, actualResultIntValue);

    // Test Float::MAX_VALUE
    variableTestIntValue = Float::MAX_VALUE;
    expectedResultIntValue = -2147483648;
    actualResultIntValue = variableTestIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue, actualResultIntValue);

    // Test Float::MIN_NORMAL
    variableTestIntValue = Float::MIN_NORMAL;
    expectedResultIntValue = 0;
    actualResultIntValue = variableTestIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue, actualResultIntValue);

    // Test Float::MIN_VALUE
    variableTestIntValue = Float::MIN_VALUE;
    expectedResultIntValue = 0;
    actualResultIntValue = variableTestIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue, actualResultIntValue);

    // Test valid case
    variableTestIntValue = 5.9;
    expectedResultIntValue = 5;
    actualResultIntValue = variableTestIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue, actualResultIntValue);

    // Test invalid case
    variableTestIntValue = 6;
    expectedResultIntValue = 5;
    actualResultIntValue = variableTestIntValue.intValue();
    ASSERT_NOT_EQUAL(expectedResultIntValue, actualResultIntValue);
}

TEST(JavaLang, FloatLongValue) {
    // Create variable to test
    Float variableTestLongValue;
    long expectedResultLongValue;
    long actualResultLongValue;

    // Test Float::POSITIVE_INFINITY
    variableTestLongValue = Float::POSITIVE_INFINITY;
    expectedResultLongValue = -9223372036854775808u;
    actualResultLongValue = variableTestLongValue.longValue();
    ASSERT_EQUAL(expectedResultLongValue, actualResultLongValue);

    // Test Float::NEGATIVE_INFINITY
    variableTestLongValue = Float::NEGATIVE_INFINITY;
    expectedResultLongValue = -9223372036854775808u;
    actualResultLongValue = variableTestLongValue.longValue();
    ASSERT_EQUAL(expectedResultLongValue, actualResultLongValue);

    // Test Float::NaN
    variableTestLongValue = Float::NaN;
    expectedResultLongValue = -9223372036854775808u;
    actualResultLongValue = variableTestLongValue.longValue();
    ASSERT_EQUAL(expectedResultLongValue, actualResultLongValue);

    // Test Float::MAX_VALUE
    variableTestLongValue = Float::MAX_VALUE;
    expectedResultLongValue = -9223372036854775808u;
    actualResultLongValue = variableTestLongValue.longValue();
    ASSERT_EQUAL(expectedResultLongValue, actualResultLongValue);

    // Test Float::MIN_NORMAL
    variableTestLongValue = Float::MIN_NORMAL;
    expectedResultLongValue = 0;
    actualResultLongValue = variableTestLongValue.longValue();
    ASSERT_EQUAL(expectedResultLongValue, actualResultLongValue);

    // Test Float::MIN_VALUE
    variableTestLongValue = Float::MIN_VALUE;
    expectedResultLongValue = 0;
    actualResultLongValue = variableTestLongValue.longValue();
    ASSERT_EQUAL(expectedResultLongValue, actualResultLongValue);

    // Test valid case
    variableTestLongValue = 5.9;
    expectedResultLongValue = 5;
    actualResultLongValue = variableTestLongValue.longValue();
    ASSERT_EQUAL(expectedResultLongValue, actualResultLongValue);

    // Test invalid case
    variableTestLongValue = 6;
    expectedResultLongValue = 5;
    actualResultLongValue = variableTestLongValue.longValue();
    ASSERT_NOT_EQUAL(expectedResultLongValue, actualResultLongValue);
}

TEST(JavaLang, FloatDoubleValue) {
    Float variableTest;

    variableTest = 0.0;
    ASSERT_DBL_NEAR(0.0, variableTest.doubleValue());

    variableTest = Float::NaN;
    ASSERT_DBL_NEAR(Float::NaN, variableTest.doubleValue());

    variableTest = Float::POSITIVE_INFINITY;
    ASSERT_DBL_NEAR(Float::POSITIVE_INFINITY, variableTest.doubleValue());

    variableTest = Float::NEGATIVE_INFINITY;
    ASSERT_DBL_NEAR(Float::NEGATIVE_INFINITY, variableTest.doubleValue());

    variableTest = Float::MIN_NORMAL;
    ASSERT_DBL_NEAR(Float::MIN_NORMAL, variableTest.doubleValue());

    variableTest = Float::MIN_VALUE;
    ASSERT_DBL_NEAR(Float::MIN_VALUE, variableTest.doubleValue());

    variableTest = Float::MAX_VALUE;
    ASSERT_DBL_NEAR(Float::MAX_VALUE, variableTest.doubleValue());
}

TEST(JavaLang, FloatToString) {
    // Create variable to test
    Float variableTestToString;
    string expectedResultToString;
    string actualResultToString;

    // Test Float::POSITIVE_INFINITY
    variableTestToString = Float::POSITIVE_INFINITY;
    expectedResultToString = (string) "inf";
    actualResultToString = variableTestToString.toString();
    ASSERT_STR(expectedResultToString, actualResultToString);

    // Test Float::NEGATIVE_INFINITY
    variableTestToString = Float::NEGATIVE_INFINITY;
    expectedResultToString = (string) "-inf";
    actualResultToString = variableTestToString.toString();
    ASSERT_STR(expectedResultToString, actualResultToString);

    // Test Float::NaN
    variableTestToString = Float::NaN;
    expectedResultToString = (string) "nan";
    actualResultToString = variableTestToString.toString();
    ASSERT_STR(expectedResultToString, actualResultToString);

    // Test Float::MAX_VALUE
    variableTestToString = Float::MAX_VALUE;
    expectedResultToString = (string) "3.40282e+38";
    actualResultToString = variableTestToString.toString();
    ASSERT_STR(expectedResultToString, actualResultToString);

    // Test Float::MIN_NORMAL
    variableTestToString = Float::MIN_NORMAL;
    expectedResultToString = (string) "1.4013e-45";
    actualResultToString = variableTestToString.toString();
    ASSERT_STR(expectedResultToString, actualResultToString);

    // Test Float::MIN_VALUE
    variableTestToString = Float::MIN_VALUE;
    expectedResultToString = (string) "1.17549e-38";
    actualResultToString = variableTestToString.toString();
    ASSERT_STR(expectedResultToString, actualResultToString);
}

TEST(JavaLang, FloatParseFloat) {
    // Test Float::POSITIVE_INFINITY
    ASSERT_FLOAT_NEAR(Float::POSITIVE_INFINITY, Float::parseFloat((String) "inf").floatValue());

    // Test Float::NEGATIVE_INFINITY
    ASSERT_FLOAT_NEAR(Float::NEGATIVE_INFINITY, Float::parseFloat((String) "-inf").floatValue());

    // Test Float::NaN
    ASSERT_FLOAT_NEAR(Float::NaN, Float::parseFloat((String) "nan").floatValue());

    // Test Float::MAX_VALUE
    ASSERT_FLOAT_NEAR(Float::MAX_VALUE,
                      Float::parseFloat((String) "340282346638528859811704183484516925440.0").floatValue());

    // Test Float::MIN_NORMAL
    ASSERT_FLOAT_NEAR(Float::MIN_NORMAL, Float::parseFloat((String) "1.4013e-45").floatValue());

    // Test Float::MIN_VALUE
    ASSERT_FLOAT_NEAR(Float::MIN_VALUE, Float::parseFloat((String) "1.17549e-38").floatValue());
}

TEST(JavaLang, FloatValueOfParamString) {
    // Test Float::POSITIVE_INFINITY
    ASSERT_FLOAT_NEAR(Float::POSITIVE_INFINITY, Float::valueOf((String) "inf").floatValue());

    // Test Float::NEGATIVE_INFINITY
    ASSERT_FLOAT_NEAR(Float::NEGATIVE_INFINITY, Float::valueOf((String) "-inf").floatValue());

    // Test Float::NaN
    ASSERT_FLOAT_NEAR(Float::NaN, Float::valueOf((String) "nan").floatValue());

    // Test Float::MAX_VALUE
    ASSERT_FLOAT_NEAR(Float::MAX_VALUE,
                      Float::valueOf((String) "340282346638528859811704183484516925440.0").floatValue());

    // Test Float::MIN_NORMAL
    ASSERT_FLOAT_NEAR(Float::MIN_NORMAL, Float::valueOf((String) "1.4013e-45").floatValue());

    // Test Float::MIN_VALUE
    ASSERT_FLOAT_NEAR(Float::MIN_VALUE, Float::valueOf((String) "1.17549e-38").floatValue());
}

TEST(JavaLang, FloatValueOfParamFloat) {
    // Test Float::POSITIVE_INFINITY
    ASSERT_FLOAT_NEAR(Float::POSITIVE_INFINITY, Float::valueOf(Float::POSITIVE_INFINITY).floatValue());

    // Test Float::NEGATIVE_INFINITY
    ASSERT_FLOAT_NEAR(Float::NEGATIVE_INFINITY, Float::valueOf(Float::NEGATIVE_INFINITY).floatValue());

    // Test Float::NaN
    ASSERT_FLOAT_NEAR(-Float::NaN, Float::valueOf(-Float::NaN).floatValue());

    // Test Float::MAX_VALUE
    ASSERT_FLOAT_NEAR(Float::MAX_VALUE,
                      Float::valueOf(340282346638528859811704183484516925440.0f).floatValue());

    // Test Float::MIN_NORMAL
    ASSERT_FLOAT_NEAR(Float::MIN_NORMAL, Float::valueOf(1.4013e-45).floatValue());

    // Test Float::MIN_VALUE
    ASSERT_FLOAT_NEAR(Float::MIN_VALUE, Float::valueOf(1.17549e-38).floatValue());
}

TEST(JavaLang, FloatToRawIntBits) {
    // Create variable to test
    float input;
    int expectedResult;
    int actualResult;

    // Input 0.0
    input = 0.0;
    expectedResult = 0;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input Float::POSITIVE_INFINITY
    input = Float::POSITIVE_INFINITY;
    expectedResult = 2139095040;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input Float::NEGATIVE_INFINITY
    input = Float::NEGATIVE_INFINITY;
    expectedResult = -2139095040;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input Float::NaN
    input = Float::NaN;
    expectedResult = 2147483647;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -0.7
    input = -0.7f;
    expectedResult = -1060320051;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 12.375
    input = 12.375;
    expectedResult = 1095106560;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 1.0
    input = 1.0;
    expectedResult = 1065353216;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 0.375
    input = 0.375;
    expectedResult = 1052770304;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -2
    input = -2.0f;
    expectedResult = -1073741824;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 83
    input = 83.0;
    expectedResult = 1118175232;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -2625
    input = -2625.0f;
    expectedResult = -1159991296;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 0.5
    input = 0.5;
    expectedResult = 1056964608;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -1302.12345678
    input = -1302.12345678f;
    expectedResult = -1151517683;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);
}

TEST(JavaLang, FloatToIntBits) {
    // Create variable to test
    float input;
    int expectedResult;
    int actualResult;

    // Input 0.0
    input = 0.0;
    expectedResult = 0;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input Float::POSITIVE_INFINITY
    input = Float::POSITIVE_INFINITY;
    expectedResult = 2139095040;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input Float::NEGATIVE_INFINITY
    input = Float::NEGATIVE_INFINITY;
    expectedResult = -2139095040;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input Float::NaN
    input = Float::NaN;
    expectedResult = 2147483647;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -0.7
    input = -0.7f;
    expectedResult = -1060320051;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 12.375
    input = 12.375;
    expectedResult = 1095106560;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 1.0
    input = 1.0;
    expectedResult = 1065353216;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 0.375
    input = 0.375;
    expectedResult = 1052770304;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -2
    input = -2.0f;
    expectedResult = -1073741824;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 83
    input = 83.0;
    expectedResult = 1118175232;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -2625
    input = -2625.0f;
    expectedResult = -1159991296;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 0.5
    input = 0.5;
    expectedResult = 1056964608;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -1302.12345678
    input = -1302.12345678f;
    expectedResult = -1151517683;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);
}

TEST(JavaLang, FloatIsNaNNoneParam) {
    Float variableIsInfinite2;

    variableIsInfinite2 = Float::NaN;
    ASSERT_TRUE(variableIsInfinite2.isNaN());

    variableIsInfinite2 = Float::NEGATIVE_INFINITY;
    ASSERT_FALSE(variableIsInfinite2.isNaN());

    variableIsInfinite2 = 13.02;
    ASSERT_FALSE(variableIsInfinite2.isNaN());
}

TEST(JavaLang, FloatIsNaNParamFloat) {
    ASSERT_TRUE(Float::isNaN(Float::NaN));
    ASSERT_FALSE(Float::isNaN(Float::NEGATIVE_INFINITY));
    ASSERT_FALSE(Float::isNaN(13.02));
    ASSERT_FALSE(Float::isNaN(130.2));
}

TEST(JavaLang, FloatFloatValue) {
    // Create variable to test
    Float variableTestFloatValue;
    float expectedResultFloatValue;
    float actualResultFloatValue;

    // Test Float::POSITIVE_INFINITY
    variableTestFloatValue = Float::POSITIVE_INFINITY;
    expectedResultFloatValue = Float::POSITIVE_INFINITY;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_FLOAT_NEAR(expectedResultFloatValue, actualResultFloatValue);

    // Test Float::NEGATIVE_INFINITY
    variableTestFloatValue = Float::NEGATIVE_INFINITY;
    expectedResultFloatValue = Float::NEGATIVE_INFINITY;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_FLOAT_NEAR(expectedResultFloatValue, actualResultFloatValue);

    // Test Float::NaN
    variableTestFloatValue = Float::NaN;
    expectedResultFloatValue = Float::NaN;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_FLOAT_NEAR(expectedResultFloatValue, actualResultFloatValue);

    // Test Float::MAX_VALUE
    variableTestFloatValue = Float::MAX_VALUE;
    expectedResultFloatValue = Float::MAX_VALUE;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_FLOAT_NEAR(expectedResultFloatValue, actualResultFloatValue);

    // Test Float::MIN_NORMAL
    variableTestFloatValue = Float::MIN_NORMAL;
    expectedResultFloatValue = Float::MIN_NORMAL;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_FLOAT_NEAR(expectedResultFloatValue, actualResultFloatValue);

    // Test Float::MIN_VALUE
    variableTestFloatValue = Float::MIN_VALUE;
    expectedResultFloatValue = Float::MIN_VALUE;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_FLOAT_NEAR(expectedResultFloatValue, actualResultFloatValue);

    // Test valid case
    variableTestFloatValue = 13.02;
    expectedResultFloatValue = 13.02;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_FLOAT_NEAR(expectedResultFloatValue, actualResultFloatValue);

    // Test invalid case
    variableTestFloatValue = 130.2;
    expectedResultFloatValue = 130.0;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_FLOAT_FAR(expectedResultFloatValue, actualResultFloatValue);
}

// TODO(thoangminh): Need to pass all test cases in comment block
TEST(JavaLang, FloatCompare) {
    // Test Float::NaN
    ASSERT_EQUAL(0, Float::compare(Float::NaN, Float::NaN));
    ASSERT_EQUAL(1, Float::compare(Float::NaN, Float::POSITIVE_INFINITY));
//    ASSERT_EQUAL(1, Float::compare(Float::NaN, Float::MAX_VALUE));
    ASSERT_EQUAL(1, Float::compare(Float::NaN, 1.2));
    ASSERT_EQUAL(1, Float::compare(Float::NaN, 0.0));
    ASSERT_EQUAL(1, Float::compare(Float::NaN, -0.0f));
    ASSERT_EQUAL(1, Float::compare(Float::NaN, -1.2f));
    ASSERT_EQUAL(1, Float::compare(Float::NaN, Float::MIN_VALUE));
    ASSERT_EQUAL(1, Float::compare(Float::NaN, Float::NEGATIVE_INFINITY));

    // Test Float::POSITIVE_INFINITY
    ASSERT_EQUAL(-1, Float::compare(Float::POSITIVE_INFINITY, Float::NaN));
    ASSERT_EQUAL(0, Float::compare(Float::POSITIVE_INFINITY, Float::POSITIVE_INFINITY));
//    ASSERT_EQUAL(-1, Float::compare(Float::POSITIVE_INFINITY, Float::MAX_VALUE), -9999);
    ASSERT_EQUAL(1, Float::compare(Float::POSITIVE_INFINITY, 1.2));
    ASSERT_EQUAL(1, Float::compare(Float::POSITIVE_INFINITY, 0.0));
    ASSERT_EQUAL(1, Float::compare(Float::POSITIVE_INFINITY, -0.0f));
    ASSERT_EQUAL(1, Float::compare(Float::POSITIVE_INFINITY, -1.2f));
    ASSERT_EQUAL(1, Float::compare(Float::POSITIVE_INFINITY, Float::MIN_VALUE));
    ASSERT_EQUAL(1, Float::compare(Float::POSITIVE_INFINITY, Float::NEGATIVE_INFINITY));

    // Test Float::NEGATIVE_INFINITY
    ASSERT_EQUAL(-1, Float::compare(Float::NEGATIVE_INFINITY, Float::NaN));
    ASSERT_EQUAL(-1, Float::compare(Float::NEGATIVE_INFINITY, Float::POSITIVE_INFINITY));
//    ASSERT_EQUAL(-1, Float::compare(Float::NEGATIVE_INFINITY, Float::MAX_VALUE), -9999);
    ASSERT_EQUAL(-1, Float::compare(Float::NEGATIVE_INFINITY, 1.2));
    ASSERT_EQUAL(-1, Float::compare(Float::NEGATIVE_INFINITY, 0.0));
    ASSERT_EQUAL(-1, Float::compare(Float::NEGATIVE_INFINITY, -0.0f));
    ASSERT_EQUAL(-1, Float::compare(Float::NEGATIVE_INFINITY, -1.2f));
    ASSERT_EQUAL(-1, Float::compare(Float::NEGATIVE_INFINITY, Float::MIN_VALUE));
    ASSERT_EQUAL(0, Float::compare(Float::NEGATIVE_INFINITY, Float::NEGATIVE_INFINITY));

//    // Test Float::MAX_VALUE
//    ASSERT_EQUAL(Float::compare(Float::MAX_VALUE, Float::NaN), -9999);
//    ASSERT_EQUAL(Float::compare(Float::MAX_VALUE, Float::POSITIVE_INFINITY), -9999);
//    ASSERT_EQUAL(Float::compare(Float::MAX_VALUE, Float::MAX_VALUE));
//    ASSERT_EQUAL(Float::compare(Float::MAX_VALUE, 1.2));
//    ASSERT_EQUAL(Float::compare(Float::MAX_VALUE, 0.0));
//    ASSERT_EQUAL(Float::compare(Float::MAX_VALUE, -0.0f));
//    ASSERT_EQUAL(Float::compare(Float::MAX_VALUE, -1.2f));
//    ASSERT_EQUAL(Float::compare(Float::MAX_VALUE, Float::MIN_VALUE));
//    ASSERT_EQUAL(Float::compare(Float::MAX_VALUE, Float::NEGATIVE_INFINITY), -9999);

    // Test Float::MIN_VALUE
    ASSERT_EQUAL(-1, Float::compare(Float::MIN_VALUE, Float::NaN));
    ASSERT_EQUAL(-1, Float::compare(Float::MIN_VALUE, Float::POSITIVE_INFINITY));
//    ASSERT_EQUAL(Float::compare(Float::MIN_VALUE, Float::MAX_VALUE));
    ASSERT_EQUAL(-1, Float::compare(Float::MIN_VALUE, 1.2));
    ASSERT_EQUAL(1, Float::compare(Float::MIN_VALUE, 0.0));
    ASSERT_EQUAL(1, Float::compare(Float::MIN_VALUE, -0.0f));
    ASSERT_EQUAL(1, Float::compare(Float::MIN_VALUE, -1.2f));
    ASSERT_EQUAL(0, Float::compare(Float::MIN_VALUE, Float::MIN_VALUE));
    ASSERT_EQUAL(1, Float::compare(Float::MIN_VALUE, Float::NEGATIVE_INFINITY));

    // Test value 1.2
    ASSERT_EQUAL(-1, Float::compare(1.2, Float::NaN));
    ASSERT_EQUAL(-1, Float::compare(1.2, Float::POSITIVE_INFINITY));
//    ASSERT_EQUAL(-1, Float::compare(1.2, Float::MAX_VALUE));
    ASSERT_EQUAL(0, Float::compare(1.2, 1.2));
    ASSERT_EQUAL(1, Float::compare(1.2, 0.0));
    ASSERT_EQUAL(1, Float::compare(1.2, -0.0f));
    ASSERT_EQUAL(1, Float::compare(1.2, -1.2f));
    ASSERT_EQUAL(1, Float::compare(1.2, Float::MIN_VALUE));
    ASSERT_EQUAL(1, Float::compare(1.2, Float::NEGATIVE_INFINITY));

    // Test value 0.0
    ASSERT_EQUAL(-1, Float::compare(0.0, Float::NaN));
    ASSERT_EQUAL(-1, Float::compare(0.0, Float::POSITIVE_INFINITY));
//    ASSERT_EQUAL(Float::compare(0.0, Float::MAX_VALUE));
    ASSERT_EQUAL(-1, Float::compare(0.0, 1.2));
    ASSERT_EQUAL(0, Float::compare(0.0, 0.0));
    ASSERT_EQUAL(0, Float::compare(0.0, -0.0f));  // error in OSX
    ASSERT_EQUAL(1, Float::compare(0.0, -1.2f));
    ASSERT_EQUAL(-1, Float::compare(0.0, Float::MIN_VALUE));
    ASSERT_EQUAL(1, Float::compare(0.0, Float::NEGATIVE_INFINITY));

    // Test value -0.0f
    ASSERT_EQUAL(-1, Float::compare(-0.0f, Float::NaN));
    ASSERT_EQUAL(-1, Float::compare(-0.0f, Float::POSITIVE_INFINITY));
//    ASSERT_EQUAL(Float::compare(-0.0f, Float::MAX_VALUE));
    ASSERT_EQUAL(-1, Float::compare(-0.0f, 1.2));
    ASSERT_EQUAL(0, Float::compare(-0.0f, 0.0));  // error in OSX
    ASSERT_EQUAL(0, Float::compare(-0.0f, -0.0f));   // error in OSX
    ASSERT_EQUAL(1, Float::compare(-0.0f, -1.2f));
    ASSERT_EQUAL(-1, Float::compare(-0.0f, Float::MIN_VALUE));
    ASSERT_EQUAL(1, Float::compare(-0.0f, Float::NEGATIVE_INFINITY));

    // Test value -1.2f
    ASSERT_EQUAL(-1, Float::compare(-1.2f, Float::NaN));
    ASSERT_EQUAL(-1, Float::compare(-1.2f, Float::POSITIVE_INFINITY));
//    ASSERT_EQUAL(Float::compare(-1.2f, Float::MAX_VALUE));
    ASSERT_EQUAL(-1, Float::compare(-1.2f, 1.2));
    ASSERT_EQUAL(-1, Float::compare(-1.2f, 0.0));
    ASSERT_EQUAL(-1, Float::compare(-1.2f, -0.0f));
    ASSERT_EQUAL(0, Float::compare(-1.2f, -1.2f));
    ASSERT_EQUAL(-1, Float::compare(-1.2f, Float::MIN_VALUE));
    ASSERT_EQUAL(1, Float::compare(-1.2f, Float::NEGATIVE_INFINITY));
}

// TODO(thoangminh): Need to pass all test cases in comment block
TEST(JavaLang, FloatEquals) {
    // Create variable to test
    Float variableFloatEquals;
    Float FLOAT_NaN = Float::NaN;
    Float FLOAT_POSITIVE_INFINITY = Float::POSITIVE_INFINITY;
    Float FLOAT_NEGATIVE_INFINITY = Float::NEGATIVE_INFINITY;
    Float FLOAT_MAX_VALUE = Float::MAX_VALUE;
    Float FLOAT_MIN_VALUE = Float::MIN_VALUE;

    // Test Float::NaN
    variableFloatEquals = Float::NaN;
    ASSERT_EQUAL(1, variableFloatEquals.equals(FLOAT_NaN));
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MAX_VALUE));
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)1.2));
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)0.0));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)-0.0));
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)-1.2));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MIN_VALUE));
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_NEGATIVE_INFINITY));

    // Test FLOAT_POSITIVE_INFINITY
    variableFloatEquals = FLOAT_POSITIVE_INFINITY;
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_NaN));
    ASSERT_EQUAL(1, variableFloatEquals.equals(FLOAT_POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableFloatEquals.equals( FLOAT_MAX_VALUE), -9999);
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)1.2));
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)0.0));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)-0.0), -9999);
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)-1.2));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MIN_VALUE), -9999);
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_NEGATIVE_INFINITY));

//    // Test FLOAT_MAX_VALUE
//    variableFloatEquals = FLOAT_MAX_VALUE;
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_NaN));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MAX_VALUE));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)1.2));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)0.0));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)-0.0));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)-1.2));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MIN_VALUE));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_NEGATIVE_INFINITY));
//
//    // Test FLOAT_MIN_VALUE
//    variableFloatEquals = FLOAT_MIN_VALUE;
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_NaN), -9999);
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_POSITIVE_INFINITY), -9999);
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MAX_VALUE));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)1.2));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)0.0));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)-0.0));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)-1.2));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MIN_VALUE));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_NEGATIVE_INFINITY));

    // Test FLOAT_NEGATIVE_INFINITY
    variableFloatEquals = FLOAT_NEGATIVE_INFINITY;
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_NaN));
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MAX_VALUE), -9999);
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)1.2));
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)0.0));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)-0.0), -9999);
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)-1.2));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MIN_VALUE), -9999);
    ASSERT_EQUAL(1, variableFloatEquals.equals(FLOAT_NEGATIVE_INFINITY));

    // Test value (Float)1.2
    variableFloatEquals = (Float)1.2;
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_NaN));
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MAX_VALUE));
    ASSERT_EQUAL(1, variableFloatEquals.equals((Float)1.2));
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)0.0));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)-0.0));
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)-1.2));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MIN_VALUE));
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_NEGATIVE_INFINITY));

    // Test value (Float)0.0
    variableFloatEquals = (Float)0.0;
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_NaN));
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MAX_VALUE));
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)1.2));
    ASSERT_EQUAL(1, variableFloatEquals.equals((Float)0.0));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)-0.0));
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)-1.2));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MIN_VALUE));
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_NEGATIVE_INFINITY));

    // Test value (Float)-0.0
//    variableFloatEquals = (Float)-0.0;
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_NaN));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MAX_VALUE));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)1.2));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)0.0));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)-0.0));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)-1.2));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MIN_VALUE));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_NEGATIVE_INFINITY));

    // Test value (Float)-1.2
    variableFloatEquals = (Float)-1.2;
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_NaN));
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MAX_VALUE));
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)1.2));
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)0.0));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)-0.0));
    ASSERT_EQUAL(1, variableFloatEquals.equals((Float)-1.2));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MIN_VALUE));
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_NEGATIVE_INFINITY));
}

TEST(JavaLang, FloatIsFinite) {
    ASSERT_TRUE(Float::isFinite(13.02));
    ASSERT_TRUE(Float::isFinite(130.2));
    ASSERT_FALSE(Float::isFinite(Float::POSITIVE_INFINITY));
    ASSERT_FALSE(Float::isFinite(Float::NEGATIVE_INFINITY));
}

TEST(JavaLang, FloatIsInfinite) {
    ASSERT_TRUE(Float::isInfinite(Float::POSITIVE_INFINITY));
    ASSERT_TRUE(Float::isInfinite(Float::NEGATIVE_INFINITY));
    ASSERT_FALSE(Float::isInfinite(13.02));
    ASSERT_FALSE(Float::isInfinite(130.2));
}

TEST(JavaLang, FloatIsInfinite2) {
    Float variableIsInfinite2;

    variableIsInfinite2 = Float::POSITIVE_INFINITY;
    ASSERT_TRUE(variableIsInfinite2.isInfinite());

    variableIsInfinite2 = Float::NEGATIVE_INFINITY;
    ASSERT_TRUE(variableIsInfinite2.isInfinite());

    variableIsInfinite2 = 13.02;
    ASSERT_FALSE(variableIsInfinite2.isInfinite());
}

TEST(JavaLang, FloatHashCodeNoneParam) {
    // Create variable to test
    Float input;
    int expectedResult;
    int actualResult;

    // Input 0.0
    input = 0.0;
    expectedResult = 0;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input Float::POSITIVE_INFINITY
    input = Float::POSITIVE_INFINITY;
    expectedResult = 2139095040;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input Float::NEGATIVE_INFINITY
    input = Float::NEGATIVE_INFINITY;
    expectedResult = -2139095040;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input Float::NaN
    input = Float::NaN;
    expectedResult = 2147483647;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -0.7
    input = -0.7f;
    expectedResult =  -1060320051;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 12.375
    input = 12.375;
    expectedResult = 1095106560;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 1.0
    input = 1.0;
    expectedResult = 1065353216;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 0.375
    input = 0.375;
    expectedResult = 1052770304;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -2
    input = -2.0f;
    expectedResult = -1073741824;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 83
    input = 83.0;
    expectedResult = 1118175232;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -2625
    input = -2625.0f;
    expectedResult = -1159991296;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 0.5
    input = 0.5;
    expectedResult = 1056964608;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -1302.12345678
    input = -1302.12345678f;
    expectedResult = -1151517683;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);
}

TEST(JavaLang, FloatHashCodeParamFloat) {
    // Create variable to test
    float input;
    int expectedResult;
    int actualResult;

    // Input 0.0
    input = 0.0;
    expectedResult = 0;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input Float::POSITIVE_INFINITY
    input = Float::POSITIVE_INFINITY;
    expectedResult = 2139095040;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input Float::NEGATIVE_INFINITY
    input = Float::NEGATIVE_INFINITY;
    expectedResult = -2139095040;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input Float::NaN
    input = Float::NaN;
    expectedResult = 2147483647;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -0.7
    input = -0.7f;
    expectedResult = -1060320051;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 12.375
    input = 12.375;
    expectedResult = 1095106560;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 1.0
    input = 1.0;
    expectedResult = 1065353216;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 0.375
    input = 0.375;
    expectedResult = 1052770304;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -2
    input = -2.0f;
    expectedResult = -1073741824;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 83
    input = 83.0;
    expectedResult = 1118175232;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -2625
    input = -2625.0f;
    expectedResult = -1159991296;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 0.5
    input = 0.5;
    expectedResult = 1056964608;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -1302.12345678
    input = -1302.12345678f;
    expectedResult = -1151517683;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);
}

TEST(JavaLang, FloatMin) {
    float variableFloatMin1;
    float variableFloatMin2;
    float expectedResultFloatMin;
    float actualResultFloatMin;

    variableFloatMin1 = 13.02;
    variableFloatMin2 = 1.302;
    expectedResultFloatMin = 1.302;
    actualResultFloatMin = Float::min(variableFloatMin1, variableFloatMin2);
    ASSERT_FLOAT_NEAR(expectedResultFloatMin, actualResultFloatMin);

    variableFloatMin1 = 13.02;
    variableFloatMin2 = 1.302;
    expectedResultFloatMin = 13.02;
    actualResultFloatMin = Float::min(variableFloatMin1, variableFloatMin2);
    ASSERT_FLOAT_FAR(expectedResultFloatMin, actualResultFloatMin);
}

TEST(JavaLang, FloatIntBitsToFloat) {
    // Create variable to test
    int intBitsInput;
    float expectedResult;
    float actualResult;

    // Input 0.0
    intBitsInput = 0;
    expectedResult = 0.0;
    actualResult = Float::intBitsToFloat(intBitsInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    // Input Float::POSITIVE_INFINITY
    intBitsInput = 2139095040;
    expectedResult = Float::POSITIVE_INFINITY;
    actualResult = Float::intBitsToFloat(intBitsInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    // Input Float::NEGATIVE_INFINITY
    intBitsInput = -2139095040;
    expectedResult = Float::NEGATIVE_INFINITY;
    actualResult = Float::intBitsToFloat(intBitsInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    // Input -0.7
    intBitsInput = -1060320051;
    expectedResult = -0.7f;
    actualResult = Float::intBitsToFloat(intBitsInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    // Input 12.375
    intBitsInput = 1095106560;
    expectedResult = 12.375;
    actualResult = Float::intBitsToFloat(intBitsInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    // Input 1.0
    intBitsInput = 1065353216;
    expectedResult = 1.0;
    actualResult = Float::intBitsToFloat(intBitsInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    // Input 0.375
    intBitsInput = 1052770304;
    expectedResult = 0.375;
    actualResult = Float::intBitsToFloat(intBitsInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    // Input -2
    intBitsInput = -1073741824;
    expectedResult = -2.0f;
    actualResult = Float::intBitsToFloat(intBitsInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    // Input 83
    intBitsInput = 1118175232;
    expectedResult = 83.0;
    actualResult = Float::intBitsToFloat(intBitsInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    // Input -2625
    intBitsInput = -1159991296;
    expectedResult = -2625.0f;
    actualResult = Float::intBitsToFloat(intBitsInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    // Input 0.5
    intBitsInput = 1056964608;
    expectedResult = 0.5;
    actualResult = Float::intBitsToFloat(intBitsInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    // Input -1302.12345678
    intBitsInput = -1151517683;
    expectedResult = -1302.12345678f;
    actualResult = Float::intBitsToFloat(intBitsInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);
}

TEST(JavaLang, FloatCompareTo) {
    Float variableCompareTo;

    // Test Float::NaN
    variableCompareTo = Float::NaN;
    ASSERT_EQUAL(0, variableCompareTo.compareTo(Float::NaN));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(Float::POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableCompareTo.compareTo(Float::MAX_VALUE), -9999);
    ASSERT_EQUAL(1, variableCompareTo.compareTo(1.2));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(0.0));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(-0.0f));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(-1.2f));
//    ASSERT_EQUAL(variableCompareTo.compareTo(Float::MIN_VALUE), -9999);
    ASSERT_EQUAL(1, variableCompareTo.compareTo(Float::NEGATIVE_INFINITY));

    // Test Float::POSITIVE_INFINITY
    variableCompareTo = Float::POSITIVE_INFINITY;
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(Float::NaN));
    ASSERT_EQUAL(0, variableCompareTo.compareTo(Float::POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableCompareTo.compareTo( Float::MAX_VALUE), -9999);
    ASSERT_EQUAL(1, variableCompareTo.compareTo(1.2));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(0.0));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(-0.0f));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(-1.2f));
//    ASSERT_EQUAL(variableCompareTo.compareTo(Float::MIN_VALUE), -9999);
    ASSERT_EQUAL(1, variableCompareTo.compareTo(Float::NEGATIVE_INFINITY));

    // Test Float::NEGATIVE_INFINITY
    variableCompareTo = Float::NEGATIVE_INFINITY;
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(Float::NaN));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(Float::POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableCompareTo.compareTo(Float::MAX_VALUE), -9999);
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(1.2));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(0.0));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(-0.0f));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(-1.2f));
//    ASSERT_EQUAL(variableCompareTo.compareTo(Float::MIN_VALUE), -9999);
    ASSERT_EQUAL(0, variableCompareTo.compareTo(Float::NEGATIVE_INFINITY));

    // Test Float::MAX_VALUE
//    variableCompareTo = Float::MAX_VALUE;
//    ASSERT_EQUAL(variableCompareTo.compareTo(Float::NaN), -9999);
//    ASSERT_EQUAL(variableCompareTo.compareTo(Float::POSITIVE_INFINITY), -9999);
//    ASSERT_EQUAL(variableCompareTo.compareTo(Float::MAX_VALUE));
//    ASSERT_EQUAL(variableCompareTo.compareTo(1.2));
//    ASSERT_EQUAL(variableCompareTo.compareTo(0.0));
//    ASSERT_EQUAL(variableCompareTo.compareTo(-0.0));
//    ASSERT_EQUAL(variableCompareTo.compareTo(-1.2));
//    ASSERT_EQUAL(variableCompareTo.compareTo(Float::MIN_VALUE));
//    ASSERT_EQUAL(variableCompareTo.compareTo(Float::NEGATIVE_INFINITY), -9999);

    // Test Float::MIN_VALUE
    variableCompareTo = Float::MIN_VALUE;
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(Float::NaN));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(Float::POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableCompareTo.compareTo(Float::MAX_VALUE));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(1.2));
//    ASSERT_EQUAL(variableCompareTo.compareTo(0.0));
//    ASSERT_EQUAL(variableCompareTo.compareTo(-0.0));
//    ASSERT_EQUAL(variableCompareTo.compareTo(-1.2));
    ASSERT_EQUAL(0, variableCompareTo.compareTo(Float::MIN_VALUE));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(Float::NEGATIVE_INFINITY));

    // Test value 1.2
    variableCompareTo = 1.2;
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(Float::NaN));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(Float::POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableCompareTo.compareTo(Float::MAX_VALUE));
    ASSERT_EQUAL(0, variableCompareTo.compareTo(1.2));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(0.0));
//    ASSERT_EQUAL(variableCompareTo.compareTo(-0.0));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(-1.2f));
//    ASSERT_EQUAL(variableCompareTo.compareTo(Float::MIN_VALUE));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(Float::NEGATIVE_INFINITY));

    // Test value 0.0
    variableCompareTo = 0.0;
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(Float::NaN));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(Float::POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableCompareTo.compareTo(Float::MAX_VALUE));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(1.2));
    ASSERT_EQUAL(0, variableCompareTo.compareTo(0.0));
//    ASSERT_EQUAL(variableCompareTo.compareTo(-0.0)); // error in OSX
    ASSERT_EQUAL(1, variableCompareTo.compareTo(-1.2f));
//    ASSERT_EQUAL(variableCompareTo.compareTo(Float::MIN_VALUE));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(Float::NEGATIVE_INFINITY));

    // Test value -0.0
    variableCompareTo = -0.0;
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(Float::NaN));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(Float::POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableCompareTo.compareTo(Float::MAX_VALUE));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(1.2));
    ASSERT_EQUAL(0, variableCompareTo.compareTo(0.0));  // error in OSX
    ASSERT_EQUAL(0, variableCompareTo.compareTo(-0.0f));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(-1.2f));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(Float::MIN_VALUE));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(Float::NEGATIVE_INFINITY));

    // Test value -1.2
    variableCompareTo = -1.2;
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(Float::NaN));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(Float::POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableCompareTo.compareTo(Float::MAX_VALUE));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(1.2));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(0.0));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(-0.0));
    ASSERT_EQUAL(0, variableCompareTo.compareTo(-1.2f));
//    ASSERT_EQUAL(variableCompareTo.compareTo(Float::MIN_VALUE));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(Float::NEGATIVE_INFINITY));
}

TEST(JavaLang, FloatByteValue) {
    // Create variable to test
    Float variableTestByteValue;
    byte expectedResultByteValue;
    byte actualResultByteValue;

    // Test Float::POSITIVE_INFINITY
    variableTestByteValue = Float::POSITIVE_INFINITY;
    expectedResultByteValue = 0;
    actualResultByteValue = variableTestByteValue.byteValue();
    ASSERT_EQUAL(expectedResultByteValue, actualResultByteValue);

    // Test Float::NEGATIVE_INFINITY
    variableTestByteValue = Float::NEGATIVE_INFINITY;
    expectedResultByteValue = 0;
    actualResultByteValue = variableTestByteValue.byteValue();
    ASSERT_EQUAL(expectedResultByteValue, actualResultByteValue);

    // Test Float::NaN
    variableTestByteValue = Float::NaN;
    expectedResultByteValue = 0;
    actualResultByteValue = variableTestByteValue.byteValue();
    ASSERT_EQUAL(expectedResultByteValue, actualResultByteValue);

    // Test Float::MAX_VALUE
    variableTestByteValue = Float::MAX_VALUE;
    expectedResultByteValue = 0;
    actualResultByteValue = variableTestByteValue.byteValue();
    ASSERT_EQUAL(expectedResultByteValue, actualResultByteValue);

    // Test Float::MIN_NORMAL
    variableTestByteValue = Float::MIN_NORMAL;
    expectedResultByteValue = 0;
    actualResultByteValue = variableTestByteValue.byteValue();
    ASSERT_EQUAL(expectedResultByteValue, actualResultByteValue);

    // Test Float::MIN_VALUE
    variableTestByteValue = Float::MIN_VALUE;
    expectedResultByteValue = 0;
    actualResultByteValue = variableTestByteValue.byteValue();
    ASSERT_EQUAL(expectedResultByteValue, actualResultByteValue);

    // Test valid case
    variableTestByteValue = 13.02;
    expectedResultByteValue = 13;
    actualResultByteValue = variableTestByteValue.byteValue();
    ASSERT_EQUAL(expectedResultByteValue, actualResultByteValue);

    // Test invalid case
    variableTestByteValue = 13.02;
    expectedResultByteValue = 5;
    actualResultByteValue = variableTestByteValue.byteValue();
    ASSERT_NOT_EQUAL(expectedResultByteValue, actualResultByteValue);
}