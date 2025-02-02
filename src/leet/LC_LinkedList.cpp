#include "LC_LinkedList.hpp"


void showLinkedList(ListNode* list) {
    std::cout <<"\n" <<std::endl;
    for(ListNode* ptr = list; ptr!=nullptr; ptr=ptr->next){
        std::cout << ptr->val << "    ";
    }
    std::cout <<"\n" <<std::endl;
}
ListNode* createList() {
    ListNode* list= nullptr;
    ListNode* plist = nullptr;
    int n, val;
    std::cout << "Enter number of nodes: " << std::endl;
    std::cin >> n;
    for(int i=0; i<n; i++) {
        std::cout << "Enter value: " << std::endl;
        std::cin >> val;
        ListNode* node = (ListNode*) new ListNode(val);
        if(list==nullptr){
            list = node;
            plist = list;
        } else {
            plist->next = node;
            plist = node;
        }
    }
    return list;
}
ListNode* createList(std::vector<int> v){
    ListNode* list = nullptr;
    ListNode* plist = nullptr;
    int n, val;
    for (int val : v){
        ListNode* node = (ListNode*) new ListNode(val);
        if (list == nullptr){
            list = node;
            plist = list;
        } else{
            plist->next = node;
            plist = node;
        }
    }
    return list;
}

TEST(LC, ListCreate){
    std::vector<int> v = { 1,2,3,4,5 };
    ListNode* list = createList(v);
    int i = 0;
    for (ListNode* ptr = list; ptr != nullptr; ptr = ptr->next){
        EXPECT_THAT(ptr->val, v[i++]);
    }
    //showLinkedList(rlist);
}
