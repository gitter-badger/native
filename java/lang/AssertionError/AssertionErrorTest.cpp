/**
 * Copyright (c) 2017 Food Tiny Project. All rights reserved.
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
#include "AssertionError.hpp"

using namespace Java::Lang;

TEST (JavaLang, AssertionErrorConstructor) {
	// Constructs a new AssertionError with null as its detail message.
	AssertionError assertionErrorWithNullMessage;
	assertEquals("", assertionErrorWithNullMessage.getMessage().toString());
	
	// Constructs a new AssertionError with double
	AssertionError assertionErrorWithDouble = AssertionError(10000.0);
	assertEquals("10000.000000000000000", assertionErrorWithDouble.getMessage().toString());
	
	// Constructs a new AssertionError with float
	AssertionError assertionErrorWithFloat = AssertionError(10000.0f);
	assertEquals("10000", assertionErrorWithFloat.getMessage().toString());
	
	// Constructs a new AssertionError with long
	AssertionError assertionErrorWithLong = AssertionError(100000000000);
	assertEquals("100000000000", assertionErrorWithLong.getMessage().toString());
	
	// Constructs a new AssertionError with int
	AssertionError assertionErrorWithInt = AssertionError(10000);
	assertEquals("10000", assertionErrorWithInt.getMessage().toString());
	
	// Constructs a new AssertionError with char
	AssertionError assertionErrorWithChar = AssertionError('A');
	assertEquals("A", assertionErrorWithChar.getMessage().toString());
	
	// Constructs a new AssertionError with bool true
	AssertionError assertionErrorWithBoolTrue = AssertionError(true);
	assertEquals("true", assertionErrorWithBoolTrue.getMessage().toString());
	
	// Constructs a new AssertionError with bool false
	AssertionError assertionErrorWithBoolFalse = AssertionError(false);
	assertEquals("false", assertionErrorWithBoolFalse.getMessage().toString());
	
	// Constructs a new AssertionError with the specified detail message and cause.
	AssertionError assertionErrorWithMessageAndCause = AssertionError("AssertionError with the specified message and cause", &assertionErrorWithDouble);
	assertEquals("AssertionError with the specified message and cause", assertionErrorWithMessageAndCause.getMessage().toString());
	assertEquals("10000.000000000000000", assertionErrorWithMessageAndCause.getCause()->getMessage().toString());
}

TEST (JavaLang, AssertionErrorTryCatch) {
	try {
		throw AssertionError(10000);
	} catch (AssertionError &e) {
		assertEquals("10000", e.getMessage().toString());
	}
}

