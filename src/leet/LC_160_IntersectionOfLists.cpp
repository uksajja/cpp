#include <iostream>

#include <gmock/gmock.h>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){ }
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
    if (headA == NULL || headB == NULL) return NULL;
    ListNode* ptr1 = headA;
    ListNode* ptr2 = headB;
    while (ptr1 != NULL && ptr2 != NULL && ptr1 != ptr2){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        if (ptr1 == ptr2) return ptr1;
        if (ptr1 == NULL) ptr1 = headB;
        if (ptr2 == NULL) ptr2 = headA;
    }
    return ptr1;
}

ListNode* getIntersectionNodeGood(ListNode* headA, ListNode* headB){
    int lengthA = 0;
    int lengthB = 0;
    for (ListNode* temp = headA; temp != nullptr; temp = temp->next) lengthA++;
    for (ListNode* temp = headB; temp != nullptr; temp = temp->next) lengthB++;
    if (lengthA > lengthB){
        int diff = lengthA - lengthB;
        for (ListNode* temp = headA; temp != nullptr; temp = temp->next, diff--){
            if (diff <= 0){
                if (temp == headB) return temp;
                headB = headB->next;
            }
        }
    }
    else{
        int diff = lengthB - lengthA;
        for (ListNode* temp = headB; temp != nullptr;temp = temp->next, diff--){
            if (diff <= 0){
                if (temp == headA) return temp;
                headA = headA->next;
            }
        }
    }
    return nullptr;
}
ListNode* getIntersectionNodeBetter(ListNode* headA, ListNode* headB){
    ListNode* PA = headA;
    ListNode* PB = headB;
    while (PA != PB){
        PA = PA == nullptr ? headB : PA->next;
        PB = PB == nullptr ? headA : PB->next;
    }
    return PA;
}
ListNode* getIntersectionNodeBrute(ListNode* headA, ListNode* headB){
    while (headA != NULL){
        for (ListNode* temp = headB; temp != NULL; temp = temp->next){
            if (headA == temp){
                return headA;
            }
        }
        headA = headA->next;
    }
    return NULL;
}
ListNode* getIntersectionNodeHash(ListNode* headA, ListNode* headB){
    std::set<ListNode*> nodeSet{};
    while (headA != NULL){
        nodeSet.insert(headA);
        headA = headA->next;
    }
    while (headB != NULL){
        if (nodeSet.find(headB) != nodeSet.end()){
            return headB;
        }
        headB = headB->next;
    }
    return NULL;
}

TEST(LC, Intersection1){
    ListNode* headA;
    ListNode* headB;
}