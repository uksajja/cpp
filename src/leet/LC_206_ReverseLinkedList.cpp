/*
206. Reverse Linked List
Given the head of a singly linked list, reverse the list, and return the reversed list.
*/
#include <iostream>

#include <vector>

#include <gmock/gmock.h>
#include "LC_LinkedList.hpp"

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* ptr = head;

    while (ptr != nullptr){
        ListNode* nextptr = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = nextptr;
    }
    return prev;
}

TEST(LC, ListReverse){
    std::vector<int> v = {1,2,3,4,5};
    ListNode* list = createList(v);
    ListNode* rlist = reverseList(list);
    int i = 4;
    for (ListNode* ptr = rlist; ptr != nullptr; ptr = ptr->next) {
        EXPECT_THAT(ptr->val, v[i--]);
    }
    //showLinkedList(rlist);
}
