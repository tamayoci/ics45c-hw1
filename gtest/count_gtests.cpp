// ------------------------- Tests File - stack_test.cpp -------------------- //
// This file is for writing your own user tests. Be sure to include your *.hpp
// files to be able to access the functions that you wrote for unit testing.
// An example has been provided, but more documentation is available here:
// https://github.com/google/googletest/blob/main/docs/primer.md
// -------------------------------------------------------------------------- //

#include <gtest/gtest.h>
#include <string>

#include <iostream>
using namespace std;
// Include all of your *.h files you want to unit test:
#include "letter_count.hpp"

namespace {

TEST(Count, SimpleString) {
  // Push 'c' on the stack, and make sure we get 'c' back.
  std::string ts = "ABCDEF";
  int char_counts[26] = { 0 };
  count(ts, char_counts);
  for (int i = 0; i < 6; ++i) {
    EXPECT_EQ(1, char_counts[i]);
  }
}

// ADD YOUR TESTS HERE:
TEST(ConvertKnots, Three) {
    EXPECT_NEAR(0.057539, knots_to_miles_per_minute(3), 0.01);
}

TEST(CharToIndex, LowercaseLettersMapLikeUppercase)
{
    EXPECT_EQ(char_to_index('A'), char_to_index('a'));
    EXPECT_EQ(char_to_index('M'), char_to_index('m'));
    EXPECT_EQ(char_to_index('Z'), char_to_index('z'));
}

TEST(CharToIndex, MiddleLettersBothCases)
{
    EXPECT_EQ(7, char_to_index('H'));
    EXPECT_EQ(7, char_to_index('h'));

    EXPECT_EQ(12, char_to_index('M'));
    EXPECT_EQ(12, char_to_index('m'));

    EXPECT_EQ(18, char_to_index('S'));
    EXPECT_EQ(18, char_to_index('s'));
}

} // anonymous namespace
