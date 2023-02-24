#include "../unity/unity.h"

// get 3 grades and return the average rounded to the nearest 5
// return the grade as a character: 'F', 'D', 'C', 'B', 'A'
// if the average is less than 60, return 'F'
// if the average is between 60 and 69, return 'D'
// if the average is between 70 and 79, return 'C'
// if the average is between 80 and 89, return 'B'
// if the average is between 90 and 100, return 'A'
int get_grade(int grade1, int grade2, int grade3)
{
    int average = (grade1 + grade2 + grade3) / 3;
    if (average < 60)
        return 'F';
    else if (average < 70)
        return 'D';
    else if (average < 80)
        return 'C';
    else if (average < 90)
        return 'B';
    else
        return 'A';
}

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

void test_function_should_assignGrades(void)
{
    TEST_ASSERT_EQUAL_INT_MESSAGE('A', get_grade(95, 90, 93), "95, 90, 93 should return 'A'");
    TEST_ASSERT_EQUAL_INT_MESSAGE('A', get_grade(92, 93, 94), "92, 93, 94 should return 'A'");
    TEST_ASSERT_EQUAL_INT_MESSAGE('A', get_grade(100, 85, 96), "100, 85, 96 should return 'A'");
    TEST_ASSERT_EQUAL_INT_MESSAGE('B', get_grade(70, 70, 100), "70, 70, 100 should return 'B'");
    TEST_ASSERT_EQUAL_INT_MESSAGE('B', get_grade(82, 85, 87), "82, 85, 87 should return 'B'");
    TEST_ASSERT_EQUAL_INT_MESSAGE('B', get_grade(84, 79, 85), "84, 79, 85 should return 'B'");
    TEST_ASSERT_EQUAL_INT_MESSAGE('C', get_grade(70, 70, 70), "70, 70, 70 should return 'C'");
    TEST_ASSERT_EQUAL_INT_MESSAGE('C', get_grade(60, 82, 76), "60, 82, 76 should return 'C'");
    TEST_ASSERT_EQUAL_INT_MESSAGE('C', get_grade(75, 70, 79), "75, 70, 79 should return 'C'");
    TEST_ASSERT_EQUAL_INT_MESSAGE('D', get_grade(60, 60, 60), "60, 60, 60 should return 'D'");
    TEST_ASSERT_EQUAL_INT_MESSAGE('F', get_grade(30, 30, 30), "30, 30, 30 should return 'F'");
    TEST_ASSERT_EQUAL_INT_MESSAGE('F', get_grade(48, 55, 52), "48, 55, 52 should return 'F'");
}

// test the above get_grade function using unity
int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_function_should_assignGrades);
    return UNITY_END();
}
