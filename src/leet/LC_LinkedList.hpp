/*
Linked List Header
*/
#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include <gmock/gmock.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createList();
ListNode* createList(std::vector<int> v);
void showLinkedList(ListNode* list);
