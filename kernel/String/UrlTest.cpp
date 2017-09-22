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

#include <stdlib.h>
#include "../Test.hpp"
#include "../String.hpp"

TEST (KernelString, UrlEncode) {
	char *target = "Quán ăn";
	char *result = urlEncode(target);
	char *expect = "Qu%c3%a1n+%c4%83n";
	ASSERT_STR(expect, result);
	free(result);
}

TEST (KernelString, UrlDecode) {
	char *target = "Qu%c3%a1n+%c4%83n";
	char *result = urlDecode(target);
	char *expect = "Quán ăn";
	ASSERT_STR(expect, result);
	free(result);
}

TEST (KernelString, UrlFindParam) {
	char *params = "username=loint&password=1234&firstName=Loi AbC&lastName=Nguyen";
	
	char *result = findParam("username", params);
	ASSERT_STR("loint", result);
	free(result);
	
	result = findParam("firstName", params);
	ASSERT_STR("Loi AbC", result);
	free(result);
	
	result = findParam("password", params);
	ASSERT_STR("1234", result);
	free(result);
	
	char *params2 = "username=&password=&firstName=Loi&&lastName=Nguyen";
	
	result = findParam("username", params2);
	ASSERT_STR("", result);
	free(result);
	
	result = findParam("firstName", params2);
	ASSERT_STR("Loi", result);
	free(result);
	
	result = findParam("password", params2);
	ASSERT_STR("", result);
	free(result);
	
	result = findParam("lastName", params2);
	ASSERT_STR("Nguyen", result);
	free(result);
	
	char *params3 = "";
	result = findParam("username", params3);
	ASSERT_STR("", result);
	free(result);
	
	result = findParam("firstName", params3);
	ASSERT_STR("", result);
	free(result);
	
	result = findParam("password", params3);
	ASSERT_STR("", result);
	free(result);
	
	result = findParam("lastName", params3);
	ASSERT_STR("", result);
	free(result);
}

TEST (KernelString, UrlFindParamFromUrl) {
	char *result; // result that store value after findParamFromUrl, should be freed after use
	
	char *url = "/abcd?username=loint&password=1234&firstName=Loi AbC&lastName=Nguyen";
	result = findParamFromUrl("username", url);
	ASSERT_STR("loint", result);
	free(result);
	
	result = findParamFromUrl("password", url);
	ASSERT_STR("1234", result);
	free(result);
	
	result = findParamFromUrl("firstName", url);
	ASSERT_STR("Loi AbC", result);
	free(result);
	
	result = findParamFromUrl("lastName", url);
	ASSERT_STR("Nguyen", result);
	free(result);
	
	char *url2 = "/abcd/?username=&password=&firstName=Loi&&lastName=Nguyen";
	result = findParamFromUrl("username", url2);
	ASSERT_STR("", result);
	free(result);
	
	result = findParamFromUrl("password", url2);
	ASSERT_STR("", result);
	free(result);
	
	result = findParamFromUrl("firstName", url2);
	ASSERT_STR("Loi", result);
	free(result);
	
	result = findParamFromUrl("lastName", url2);
	ASSERT_STR("Nguyen", result);
	free(result);
	
	char *url3 = "/abcd/";
	result = findParamFromUrl("username", url3);
	ASSERT_STR("", result);
	free(result);
	
	result = findParamFromUrl("firstName", url3);
	ASSERT_STR("", result);
	free(result);
	
	result = findParamFromUrl("password", url3);
	ASSERT_STR("", result);
	free(result);
	
	result = findParamFromUrl("lastName", url3);
	ASSERT_STR("", result);
	free(result);
	
	char *url4 = "/abcd/??";
	result = findParamFromUrl("username", url4);
	ASSERT_STR("", result);
	free(result);
	
	result = findParamFromUrl("firstName", url4);
	ASSERT_STR("", result);
	free(result);
	
	result = findParamFromUrl("password", url4);
	ASSERT_STR("", result);
	free(result);
	
	result = findParamFromUrl("lastName", url4);
	ASSERT_STR("", result);
	free(result);
}