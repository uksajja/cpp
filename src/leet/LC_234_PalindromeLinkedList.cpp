
/*
234. Palindrome LinkedList
Given the head of a singly linked list, return true if it is a 
palindrome  or false otherwise.

 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
*/
#include <gmock/gmock.h>

#include "LC_LinkedList.hpp"

class LeetProb_234 {
    public: 
    bool isPalindrome(ListNode* head){
        ListNode* slowptr = head;
        ListNode* fastptr = head;
        if (head == nullptr) return true;
        if (head->next == nullptr) return true;
        if (head->next->next == nullptr) return (head->val == head->next->val);
        //Linkedlist --> FirstHalf + SecondHalf
        while (fastptr->next != nullptr && fastptr->next->next != nullptr){
            slowptr = slowptr->next;
            if (fastptr->next != nullptr){
                fastptr = fastptr->next->next;
            }
        }
        //slowptr will be pointing to the last node in first half 

        //Reverse Second Half of the list
        ListNode* prev = nullptr;
        ListNode* ptr = slowptr->next;
        while (ptr != nullptr){
            ListNode* nextptr = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = nextptr;
        }
        //prev points to the first node of the second half after reverse i.e, last node of the original linked list
        ListNode* secondhalfptr = prev; //Reversed second half 
        ptr = head; //First Half
        while (secondhalfptr != nullptr){
            if (ptr->val != secondhalfptr->val) return false;
            ptr = ptr->next;
            secondhalfptr = secondhalfptr->next;
        }
        return true;
    }
};

TEST(LC, listpalindrome1){
    LeetProb_234 sol=LeetProb_234();
    std::vector v = {1,2,2,1};
    ListNode* list = createList(v);
    EXPECT_EQ(true, sol.isPalindrome(list));
}
TEST(LC, listpalindrome2){
    LeetProb_234 sol = LeetProb_234();
    std::vector v = { 1,2 };
    ListNode* list = createList(v);
    EXPECT_EQ(false, sol.isPalindrome(list));
}
TEST(LC, listpalindrome3){
    LeetProb_234 sol = LeetProb_234();
    std::vector v = { 1,1,2,1 };
    ListNode* list = createList(v);
    EXPECT_EQ(false, sol.isPalindrome(list));
}