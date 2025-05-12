
#include <gtest/gtest.h>
#include "queue.hpp"

/** ===== BORRAME CUANDO TENGAS TODO LISTO =====
TEST(QueueTest, EnqueueDequeueFront) {
    Queue<int> q;
    EXPECT_TRUE(q.isEmpty());
    q.enqueue(10);
    q.enqueue(20);
    EXPECT_EQ(q.front(), 10);
    q.dequeue();
    EXPECT_EQ(q.front(), 20);
    q.dequeue();
    EXPECT_TRUE(q.isEmpty());
}

TEST(QueueTest, DequeueOnEmptyThrows) {
    Queue<int> q;
    EXPECT_THROW(q.dequeue(), std::underflow_error);
}

TEST(QueueTest, FrontOnEmptyThrows) {
    Queue<int> q;
    EXPECT_THROW(q.front(), std::underflow_error);
}

TEST(QueueTest, QueueSize) {
    Queue<std::string> q;
    q.enqueue("A");
    q.enqueue("B");
    EXPECT_EQ(q.getSize(), 2);
    q.dequeue();
    EXPECT_EQ(q.getSize(), 1);
}
===== BORRAME CUANDO TENGAS TODO LISTO ===== */