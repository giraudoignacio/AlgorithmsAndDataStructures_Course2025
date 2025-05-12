
#include <gtest/gtest.h>
#include "stack.hpp"

/** ===== BORRAME CUANDO TENGAS TODO LISTO =====
TEST(StackTest, PushPopTop) {
    Stack<int> s;
    EXPECT_TRUE(s.isEmpty());
    s.push(42);
    EXPECT_FALSE(s.isEmpty());
    EXPECT_EQ(s.top(), 42);
    s.pop();
    EXPECT_TRUE(s.isEmpty());
}

TEST(StackTest, PopOnEmptyThrows) {
    Stack<int> s;
    EXPECT_THROW(s.pop(), std::underflow_error);
}

TEST(StackTest, TopOnEmptyThrows) {
    Stack<int> s;
    EXPECT_THROW(s.top(), std::underflow_error);
}

TEST(StackTest, StackSize) {
    Stack<std::string> s;
    s.push("uno");
    s.push("dos");
    s.push("tres");
    EXPECT_EQ(s.size(), 3);
    s.pop();
    EXPECT_EQ(s.size(), 2);
}
===== BORRAME CUANDO TENGAS TODO LISTO ===== */