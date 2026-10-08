// ------------------------- Your tests - student_gtests.cpp ----------------------------- //
// Your own GoogleTest suite for the Stack module. It is graded: the autograder runs it against
// a correct Stack and against several Stacks with one bug each. A test is worth something only
// when it passes on the correct Stack and fails on a broken one, so a test that always fails
// (or that tests nothing) earns nothing.
//
// Two examples are given. Add tests of your own for pop, push_all, pop_all, and the edges
// (an empty stack, a stack of one character, a full stack).
// --------------------------------------------------------------------------------------- //

#include <gtest/gtest.h>

#include "stack.hpp"

TEST(StackTests, NewStackIsEmptyAndNotFull) {
    Stack stk;
    EXPECT_TRUE(stk.isEmpty());
    EXPECT_FALSE(stk.isFull());
}

TEST(StackTests, PushThenTopSeesTheCharacter) {
    Stack stk;
    stk.push('z');
    EXPECT_EQ(stk.top(), 'z');
}

// ADD YOUR TESTS HERE:

TEST(StackTests, PopReturnsLastPushedCharacter) {
    Stack stk;

    stk.push('a');
    stk.push('b');

    EXPECT_EQ(stk.pop(), 'b');
    EXPECT_EQ(stk.pop(), 'a');
}

TEST(StackTests, TopDoesNotRemoveCharacter) {
    Stack stk;

    stk.push('x');

    EXPECT_EQ(stk.top(), 'x');
    EXPECT_EQ(stk.top(), 'x');
    EXPECT_EQ(stk.pop(), 'x');
}

TEST(StackTests, EmptyStackReturnsAtSign) {
    Stack stk;

    EXPECT_EQ(stk.pop(), '@');
    EXPECT_EQ(stk.top(), '@');
}

TEST(StackTests, StackBecomesFull) {
    Stack stk;

    for (int i = 0; i < STK_MAX; ++i) {
        stk.push('x');
    }

    EXPECT_TRUE(stk.isFull());
}

TEST(StackTests, CannotPushWhenFull) {
    Stack stk;

    for (int i = 0; i < STK_MAX; ++i) {
        stk.push('x');
    }

    stk.push('y');

    EXPECT_EQ(stk.top(), 'x');
}

TEST(StackTests, PushAndPopManyCharacters) {
    Stack stk;

    stk.push('a');
    stk.push('b');
    stk.push('c');
    stk.push('d');
    stk.push('e');

    EXPECT_EQ(stk.top(), 'e');
    EXPECT_EQ(stk.pop(), 'e');
    EXPECT_EQ(stk.top(), 'd');
    EXPECT_EQ(stk.pop(), 'd');
    EXPECT_EQ(stk.top(), 'c');
    EXPECT_EQ(stk.pop(), 'c');
    EXPECT_EQ(stk.top(), 'b');
    EXPECT_EQ(stk.pop(), 'b');
    EXPECT_EQ(stk.top(), 'a');
    EXPECT_EQ(stk.pop(), 'a');

    EXPECT_TRUE(stk.isEmpty());
}