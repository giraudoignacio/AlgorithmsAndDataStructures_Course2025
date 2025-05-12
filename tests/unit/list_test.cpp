#include <gtest/gtest.h>
#include "list.hpp"

 /**===== BORRAME CUANDO TENGAS TODO LISTO =====
TEST(LinkedListTest, PushFrontAndPrint) {
    LinkedList<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    EXPECT_EQ(list.take(0, 3)->data, 1);
}

TEST(LinkedListTest, RemoveAt) {
    LinkedList<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    list.remove_at(1);
    EXPECT_EQ(list.take(0, 2)->next->data, 3);
}

TEST(LinkedListTest, TakeWithinBounds) {
    LinkedList<int> list;
    for (int i = 0; i < 5; ++i)
        list.push_front(5 - i);
    auto newList = list.take(1, 3);
    EXPECT_EQ(newList->data, 2);
    EXPECT_EQ(newList->next->data, 3);
    EXPECT_EQ(newList->next->next->data, 4);
}

TEST(DoublyLinkedListTest, PushBackAndPrint) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_EQ(list.get_head()->data, 1);
    EXPECT_EQ(list.get_head()->next->data, 2);
    EXPECT_EQ(list.get_head()->next->next->data, 3);
}

TEST(DoublyLinkedListTest, PushFront) {
    DoublyLinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    EXPECT_EQ(list.get_head()->data, 2);
    EXPECT_EQ(list.get_head()->next->data, 1);
}

TEST(DoublyLinkedListTest, RemoveAt) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.remove_at(1);
    EXPECT_EQ(list.get_head()->next->data, 3);
}

TEST(DoublyLinkedListTest, CopyList) {
    DoublyLinkedList<int> list1;
    list1.push_back(1);
    list1.push_back(2);

    DoublyLinkedList<int> list2;
    list2.copy_list(list1);

    EXPECT_EQ(list2.get_head()->data, 1);
    EXPECT_EQ(list2.get_head()->next->data, 2);
}
 ===== BORRAME CUANDO TENGAS TODO LISTO =====*/