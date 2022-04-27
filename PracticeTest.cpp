/**
 * Unit Tests for Practice class
**/

#include <gtest/gtest.h>
#include "Practice.h"

class PracticeTest : public ::testing::Test {
protected:
    PracticeTest() {} //constructor runs before each test
    virtual ~PracticeTest() {} //destructor cleans up after tests
    virtual void SetUp() {} //sets up before each test (after constructor)
    virtual void TearDown() {} //clean up after each test, (before destructor)
    void sortDescending(int &first, int &second, int &third);

    bool isPalindrome(string input);

    int count_starting_repeats(string word);

    int *allnighter(int sleep[7]);
};

TEST(PracticeTest, SmokeTestAssertTrue)
{
ASSERT_TRUE(true);
}

TEST(PracticeTest, SmokeTestMath)
{

ASSERT_TRUE(2 > 1);
}

TEST(PracticeTest, StartingRepeatsCase) {
Practice testObj;
ASSERT_EQ(testObj.count_starting_repeats("zzzZzzzzz"), 3);
}

TEST(PracticeTest, StartingRepeatsOnlyRepeat) {
Practice testObj;
ASSERT_EQ(testObj.count_starting_repeats("ppppppppppp"), 11);
}

TEST(PracticeTest, StartingRepeatsNoRepeat) {
Practice testObj;
ASSERT_EQ(testObj.count_starting_repeats(""), 0);
}

TEST(PracticeTest, StartingRepeatsFourSpace) {
Practice testObj;
ASSERT_EQ(testObj.count_starting_repeats("    "), 4);
}

TEST(PracticeTest, StartingRepeatsEvenNullTerminator) {
Practice testObj;
ASSERT_EQ(testObj.count_starting_repeats("\0\0"), 0);
}

TEST(PracticeTest, StartingRepeatsOddNullTerminator) {
Practice testObj;
ASSERT_EQ(testObj.count_starting_repeats("\0"), 0);
}

TEST(PracticeTest, PalindromeRaceCar) {
Practice testObj;
ASSERT_TRUE(testObj.isPalindrome("racecar"));
}

TEST(PracticeTest, PalindromeNotPalindrome) {
Practice testObj;
ASSERT_TRUE(!testObj.isPalindrome("ab"));
}

TEST(PracticeTest, PalindromeNotPalindromeLong) {
Practice testObj;
ASSERT_TRUE(!testObj.isPalindrome("abcdabcd"));
}

TEST(PracticeTest, PalindromeChaos) {
Practice testObj;
ASSERT_TRUE(testObj.isPalindrome("\0\n.abcd1234🥴4321dcba.\n\0"));
}

TEST(PracticeTest, PalindromeEven) {
Practice testObj;
ASSERT_TRUE(testObj.isPalindrome("0000"));
}

TEST(PracticeTest, PalindromeOdd) {
Practice testObj;
ASSERT_TRUE(testObj.isPalindrome("000"));
}

TEST(PracticeTest, SortDescendingNegative) {
Practice testObj;
int a = -1, b = -2, c = -3;
testObj.sortDescending(a, b, c);
ASSERT_TRUE(a >= b && b >= c);
}

TEST(PracticeTest, SortDescendingAscending) {
Practice testObj;
int a = 3, b = 2, c = 1;
testObj.sortDescending(a, b, c);
ASSERT_TRUE(a >= b && b >= c);
}

TEST(PracticeTest, SortDescendingRandom) {
Practice testObj;
int a = 2, b = 3, c = 1;
testObj.sortDescending(a, b, c);
ASSERT_TRUE(a >= b && b >= c);
}

TEST(PracticeTest, SortDescendingPresortedV1) {
Practice testObj;
int a = 1, b = 2, c = 3;
testObj.sortDescending(a, b, c);
ASSERT_TRUE(a >= b && b >= c);
}

TEST(PracticeTest, SortDescendingZeros) {
Practice testObj;
int a = 0, b = 0, c = 0;
testObj.sortDescending(a, b, c);
ASSERT_TRUE(a == b && b == c);
}

TEST(PracticeTest, SortDescendingPresortedV2) {
Practice testObj;
int a = -10, b = -100, c = -1000;
testObj.sortDescending(a, b, c);
ASSERT_TRUE(a >= b && b >= c);
}


TEST(PracticeTest, AllNighterNormal) {
Practice testObj;
int nights[7] = {7, 7, 7, 0, 7, 7, 7};
int *k = testObj.allnighter(nights);

ASSERT_TRUE(*k
== nights[3]);
}

TEST(PracticeTest, AllNighterNullTerminator) {
Practice testObj;
int nights[7] = {7, -7, 7, 0, 7, (int)'\0', 7};
int *k = testObj.allnighter(nights);

ASSERT_TRUE(*k == nights[3]);
}

TEST(PracticeTest, AllNighterOver24Hours) {
Practice testObj;
int nights[7] = {9999, 7, 0, 99, 0, 7, 99};
int *k = testObj.allnighter(nights);

ASSERT_TRUE(*k
== nights[2]);
}

TEST(PracticeTest, AllNighterOversizedArray) {
Practice testObj;
int nights[8] = {1, 7, 2, 4, 0, 7, 0, 9};
int *k = testObj.allnighter(nights);

ASSERT_TRUE(*k
== nights[4]);
}

TEST(PracticeTest, AllNighterUndersizedArray) {
Practice testObj;
int nights[6] = {1, 7, 2, 4, 3, 9};
int *k = testObj.allnighter(nights);

ASSERT_TRUE(k == nullptr);
}

TEST(PracticeTest, AllNighterEmpty) {
Practice testObj;
int nights[0] = {};
int *k = testObj.allnighter(nights);
ASSERT_TRUE(*k == 0);
}