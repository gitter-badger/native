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

#include "../../../kernel/Test.hpp"
#include "Boolean.hpp"

TEST (JavaLangBoolean, Constructor) {
	// Give a object Boolean with value true - Should be true
	Boolean objectBoolean1(true);
	assertTrue(objectBoolean1.booleanValue());
	
	// Give a object Boolean with value false - Should be false
	Boolean objectBoolean2(false);
	assertFalse(objectBoolean2.booleanValue());
	
	// Give a object Boolean with String - Should be true
	Boolean objectBoolean3("True");
	assertTrue(objectBoolean3.booleanValue());
	
	// Give a object Boolean with String - Should be false
	Boolean objectBoolean4("False");
	assertFalse(objectBoolean4.booleanValue());
}

TEST (JavaLangBoolean, Destructor) {
	// Create new object Boolean, then delete - Should not leak memory
	Boolean *newBoolean = new Boolean(true);
	boolean result = newBoolean->booleanValue();
	assertTrue(result);
	delete newBoolean;
}

TEST (JavaLangBoolean, Compare) {
	boolean booleanTrue = true;
	boolean booleanFalse = false;
	
	// Give two boolean (true - true) to compare - Should be equal
	int expect = 0;
	int result = Boolean::compare(booleanTrue, booleanTrue);
	assertEquals(expect, result);
	
	// Give two boolean (true - false) to compare - Should equal
	expect = 1;
	result = Boolean::compare(booleanTrue, booleanFalse);
	assertEquals(expect, result);
	
	// Give two boolean (false - true) to compare - Should equal
	expect = -1;
	result = Boolean::compare(booleanFalse, booleanTrue);
	assertEquals(expect, result);
}

TEST (JavaLangBoolean, CompareTo) {
	Boolean objectBooleanTrue(true);
	Boolean objectBooleanFalse(false);
	
	// Give two object Boolean (true - true) to compare - Should be equal
	int expect = 0;
	int result = objectBooleanTrue.compareTo(objectBooleanTrue);
	assertEquals(expect, result);
	
	// Give two object Boolean (true - false) to compare - Should equal
	expect = 1;
	result = objectBooleanTrue.compareTo(objectBooleanFalse);
	assertEquals(expect, result);
	
	// Give two object Boolean (false - true) to compare - Should equal
	expect = -1;
	result = objectBooleanFalse.compareTo(objectBooleanTrue);
	assertEquals(expect, result);
}

TEST (JavaLangBoolean, GetBoolean) {
	// Give two value boolean (true - true) - Should equal
	boolean expect = true;
	boolean result = Boolean::getBoolean("True");
	assertEquals(expect, result);
	
	// Give two value boolean (false - false) - Should equal
	expect = false;
	result = Boolean::getBoolean("False");
	assertEquals(expect, result);
}

TEST (JavaLang, BooleanHashCode) {
	//Giving an expected result and a boolean value
	long expectedResult;
	Boolean booleanTrueValue(true);
	Boolean booleanFalseValue(false);
	long result;

	//Test expectedResult and true-hashcode-booleanValue are equal
	expectedResult = 1231;
	result = booleanTrueValue.hashCode();
	assertEquals(expectedResult, result);

	//Test expectedResult and false-hashcode-booleanValue are equal
	expectedResult = 1237;
	booleanFalseValue = false;
	result = booleanFalseValue.hashCode();
	assertEquals(expectedResult, result);
}

TEST (JavaLangBoolean, ParseBoolean) {
	// Give two value boolean (true - true) - Should equal
	boolean expect = true;
	boolean result = Boolean::parseBoolean("True");
	assertEquals(expect, result);
	
	// Give two value boolean (false - false) - Should equal
	expect = false;
	result = Boolean::parseBoolean("False");
	assertEquals(expect, result);
}

TEST (JavaLangBoolean, ToString) {
	// Give two string - Should equal
	Boolean objectBooleanTrue(true);
	string expect = (string) "true";
	String result = objectBooleanTrue.toString();
	assertEquals(expect, result);
	
	// Give two string - Should equal
	Boolean objectBooleanFalse(false);
	expect = (string) "false";
	result = objectBooleanFalse.toString();
	assertEquals(expect, result);
	
	// Give two string - Should equal
	expect = (string) "true";
	result = Boolean::toString(true);
	assertEquals(expect, result);
}

TEST (JavaLangBoolean, StaticValueOf) {
	// Give two value boolean (true - true) - Should equal
	boolean expect = true;
	boolean result = Boolean::valueOf("True");
	assertEquals(expect, result);
	
	// Give two value boolean (false - false) - Should equal
	expect = false;
	result = Boolean::valueOf("False");
	assertEquals(expect, result);
}

TEST (JavaLangBoolean, ValueOf) {
	// Give two boolean - Should equal
	boolean expect = true;
	boolean result = Boolean::valueOf(expect).booleanValue();
	assertEquals(expect, result);
	
	// Give two boolean - Should equal
	expect = false;
	result = Boolean::valueOf(expect).booleanValue();
	assertEquals(expect, result);
}

TEST (JavaLang, BooleanOperator) {
	//Giving expected - target and actual boolean value
	boolean expectedResult = true;
	boolean targetResult;
	boolean actualResult;

	//Test two boolean values are equal - true
	targetResult = true;
	actualResult = targetResult;
	assertEquals(expectedResult, actualResult);

	//Test two boolean values are equals - false
	targetResult = false;
	actualResult = targetResult;
	assertEquals(expectedResult, actualResult);
}
