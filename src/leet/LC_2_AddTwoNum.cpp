
/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//Example 1
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
//Example 2
Input: l1 = [0], l2 = [0]
Output: [0]
//Example 3
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class LeetProb2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*l3=nullptr, *p = nullptr;
        int c = 0;
        while(l1!=nullptr || l2!=nullptr || c!=0){                
            ListNode* new_node = new ListNode();
            if(l1!=nullptr ) {
                c += l1->val; l1 = l1->next;
            }
            if(l2!=nullptr ) {
                c += l2->val; l2 = l2->next;
            }        
            new_node->val = c%10;
            c = c/10; 
            if (l3 ==nullptr )  {
                l3 = new_node; 
            } else {
                p->next = new_node;
            }   
            p = new_node;       
        }
        return l3;
    }
    void Print(ListNode* n){
        while(n!=nullptr){
            std::cout << n->val << " ";
            n=n->next;
        }
        std::cout << "\n";
    }
};
void test_leet_prob2(){
    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << "    Test : LeetCode Problem 2                               " << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    LeetProb2 p = LeetProb2();
    ListNode* n1= new ListNode(10);
    ListNode* n2= new ListNode(20);
    ListNode*n3=nullptr;
    n3 = p.addTwoNumbers(n1, n2);
    p.Print(n3);
    delete(n1);
    delete(n2);
}