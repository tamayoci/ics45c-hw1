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

#include "stack.hpp"

namespace {

TEST(Stack, PushPopEQ) {
  Stack st;
  st.push('c');
  EXPECT_EQ('c', st.pop());
}

TEST(Stack, PushPopNE) {
  Stack st;
  st.push('c');
  EXPECT_NE('d', st.pop());
}

TEST(Stack, Empty) {
  Stack st;
  EXPECT_TRUE(st.isEmpty());

  st.push('c');
  EXPECT_FALSE(st.isEmpty());

  st.pop();
  EXPECT_TRUE(st.isEmpty());
}

TEST(Stack, PushAll) {
  Stack st;
  std::string s = "push";

  push_all(st, s);

  for (int i = 3; i >= 0; --i) {
    EXPECT_EQ(s[i], st.pop());
  }
}

TEST(Stack, PopAll) {
  Stack st;
  std::string s = "push";

  push_all(st, s);

  testing::internal::CaptureStdout();
  pop_all(st);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ("hsup\n", output);
}

// ADD YOUR TESTS HERE:

TEST(Stack, TopReturnsTopWithoutRemoving) {
  Stack st;

  st.push('a');
  st.push('b');

  EXPECT_EQ('b', st.top());
  EXPECT_EQ('b', st.top());

  EXPECT_EQ('b', st.pop());
  EXPECT_EQ('a', st.pop());
}

TEST(Stack, PopEmptyReturnsAtSign) {
  Stack st;

  EXPECT_EQ('@', st.pop());
  EXPECT_TRUE(st.isEmpty());
}

TEST(Stack, TopEmptyReturnsAtSign) {
  Stack st;

  EXPECT_EQ('@', st.top());
  EXPECT_TRUE(st.isEmpty());
}

TEST(Stack, FullAfterMaxPushes) {
  Stack st;

  for (int i = 0; i < STK_MAX; ++i) {
    EXPECT_FALSE(st.isFull());
    st.push('x');
  }

  EXPECT_TRUE(st.isFull());
}

TEST(Stack, DoesNotPushWhenFull) {
  Stack st;

  for (int i = 0; i < STK_MAX; ++i) {
    st.push('x');
  }

  EXPECT_TRUE(st.isFull());

  // This should NOT replace the top 'x'.
  st.push('y');

  EXPECT_EQ('x', st.top());
}

TEST(Stack, PushPopUsesLIFOOrder) {
  Stack st;

  st.push('a');
  st.push('b');
  st.push('c');

  EXPECT_EQ('c', st.pop());
  EXPECT_EQ('b', st.pop());
  EXPECT_EQ('a', st.pop());

  EXPECT_TRUE(st.isEmpty());
}

} // anonymous namespace