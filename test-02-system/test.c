#include "../unity/unity.h"
#include "curl.c"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void setUp(void) {}

void tearDown(void) {}

void curl_should_returnUserIp(void) {
  // invoke curl() function; it should return a string
  // store result in a variable
  // check if the variable is not NULL
  // check if the variable is a valid ip address
  // check if the variable has 4 parts
  // check if the variable has 3 digits in each part
  // check if the variable has a dot in each part
  char *result = curl("ifconfig.me");
  TEST_ASSERT_NOT_NULL_MESSAGE(result, "ip should not be null\n");
  int i = 0;
  // check if there is a dot in each part
  char *token = strtok(result, ".");
  while (token != NULL) {
    // cast string to int
    int part = atoi(token);
    int digits[3];
    // trick to get digits of a number
    digits[0] = part / 100;
    digits[1] = (part / 10) % 10;
    digits[2] = part % 10;
    for (int i = 0; i < 3; i++) {
      // check if digit is a number, append '0' to get ascii value
      TEST_ASSERT_TRUE_MESSAGE(isdigit(digits[i] + '0'),
                               "ip should be a number\n");
    }
    // check if there is a dot in each part
    token = strtok(NULL, ".");
    // keep track of how many parts there are
    i++;
  }
  TEST_ASSERT_EQUAL_INT_MESSAGE(4, i, "ip should have 4 parts\n");
  // should have null at the end
  TEST_ASSERT_NOT_NULL_MESSAGE(strchr(result, '\0'),
                               "Ip is not null-terminated");
}

void curl_should_returnSetAndSettingsVol9(void) {
  char *result = curl("https://itunes.apple.com/lookup?id=1658237994");
  TEST_ASSERT_NOT_NULL_MESSAGE(result, "result should not be null\n");
  TEST_ASSERT_NOT_NULL_MESSAGE(strchr(result, '\0'),
                               "result is not null-terminated");
  // check if there is a string "Set and Settings, Vol. 9"
  // check if there is a string "Neosb"
  TEST_ASSERT_NOT_NULL_MESSAGE(
      strstr(result, "Set and Settings, Vol. 9"),
      "result should contain 'Set and Settings, Vol. 9'\n");
  TEST_ASSERT_NOT_NULL_MESSAGE(strstr(result, "Neosb"),
                               "result should contain 'Neosb'\n");
  // check if there is a string "1658237994"
  TEST_ASSERT_NOT_NULL_MESSAGE(strstr(result, "1658237994"),
                               "result should contain '1658237994'\n");
  // check if last character is a null terminator
  TEST_ASSERT_NOT_NULL_MESSAGE(strchr(result, '\0'),
                               "result is not null-terminated");
  TEST_ASSERT_EQUAL_CHAR_MESSAGE('\n', result[strlen(result) - 1],
                                 "result should end with a null terminator\n");
  // check if second last character is a new line

  TEST_ASSERT_EQUAL_CHAR_MESSAGE('\n', result[strlen(result) - 2],
                                 "result should end with a new line\n");
  // check if third last character is a new line
  TEST_ASSERT_EQUAL_CHAR_MESSAGE('\n', result[strlen(result) - 3],
                                 "result should end with a new line\n");
  // check if fourth last character is a curly bracket
  TEST_ASSERT_EQUAL_CHAR_MESSAGE('}', result[strlen(result) - 4],
                                 "result should end with a curly bracket\n");
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(curl_should_returnUserIp);
  RUN_TEST(curl_should_returnSetAndSettingsVol9);
  return UNITY_END();
}
