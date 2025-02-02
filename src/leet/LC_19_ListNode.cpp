/*

19. Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

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
#include<iostream>
#include<vector>
#include "LC_LinkedList.hpp"
class LeetProb19 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head;
        ListNode* slow = head;
        if(head ==nullptr) return head;
        
        for(int i=1; i<=n; i++){
            fast = fast->next;
        }
        if(fast==nullptr) return head->next;

        while(fast->next!=nullptr){
            fast= fast->next;
            slow=slow->next;
        }
        slow->next = (slow->next)->next;
        return head;
    }
    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        ListNode*temp=head;
        ListNode*p=nullptr;
        std::vector<ListNode*> vec;
        vec.push_back(head);
        int i = 0;
        while(temp!=nullptr){
            vec.push_back(temp);
            temp=temp->next;
            i++;
        }
        if(i-n == 0){
            head = head->next;
        } else {
            p = vec[i-n];
            p->next = (p->next)->next;
        }
        return head;
    }
    void Display(ListNode* head){
        std::cout << std::endl;
        for(ListNode*temp = head; temp!=nullptr; temp=temp->next){
            std::cout <<  temp->val   <<"  " ;
        }
        std::cout << std::endl;
    }
};

void test_leet_prob19(){
    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << "    Test : LeetProb19 : nth Node from last                  " << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    LeetProb19 p = LeetProb19();
    int a[] = {1,2,3,4,5};
    int n = 5;
    ListNode*parent = nullptr, *head = nullptr;
    for(int i=0; i<n; i++){
        ListNode* temp= new ListNode(a[i]);        
        if(parent==nullptr){
            head = temp;
        }else {
            parent->next = temp;
        }
        parent = temp;
    }
    p.Display(head);

    p.removeNthFromEnd(head, 2);
    std::cout << "After Removal :" <<std::endl;
    p.Display(head);
    p.removeNthFromEnd1(head, 2);
    std::cout << "After Removal :" <<std::endl;
    p.Display(head);
}