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

extern "C" {
#include "../unit_test.h"
}
#include "../generic.h"
#include <iostream>

TEST(Generic, Len) {
    std::string target_string = std::string("Hello world");
    ASSERT_EQUAL(11, len(target_string));

    char *target_pointer_char = (char*) "Hello world";
    ASSERT_EQUAL(11, len(target_pointer_char));

    short target_short = 10;
    ASSERT_EQUAL(2, len(target_short));

    int target_int = 100000;
    ASSERT_EQUAL(6, len(target_int));

    int target_long = 100000000;
    ASSERT_EQUAL(9, len(target_long));

    // TODO - @anhkhoa will fix
    int target_float = 1.23;
    //ASSERT_EQUAL(4, len(target_float));

    // TODO - @anhkhoa will fix
    int target_double = 1234444444.112;
    //ASSERT_EQUAL(14, len(target_double));
}