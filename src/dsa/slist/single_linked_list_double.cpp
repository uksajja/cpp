
//single linked list with double data type

#include <iostream>
#include <memory>
#include<vector>
#include "single_linked_list_double.hpp"

void SList::addAtStart(double data){
    SNode* new_node = new SNode(data);
    new_node -> next = head;
    head = new_node;
}
void SList::addAtEnd(double data){
    SNode* new_node = new SNode(data);
    SNode* inode = nullptr;
    for (inode = head; inode!=nullptr && inode->next != nullptr; inode = inode->next);
    
    if(inode == nullptr){
        head = new_node;
    } else {
        inode->next = new_node;
    }
}
double SList::removeAtStart(){
    SNode *p = head;
    double data = -1.0e99;
    if(head ==nullptr) {
        std::cout << "Attempting to delete from an empty list" <<std::endl;
        return(data);
    } 
    data = p->info;
    head = p->next;
    delete p;
    return data;
}
double SList::removeByData(double data){
    SNode* inode  = nullptr;
    SNode* temp   = nullptr;
    SNode* parent = nullptr;
    unsigned int flag = 0;
    for (inode = head; inode!=nullptr; ){
        if(inode->info == data){
            flag++;
            temp = inode;
            if(inode == head) {
                head = inode->next;
            } else {
                parent->next = inode->next;
            }
        } else {
            parent = inode;
        }
        inode = inode->next;
        if (temp!=nullptr) {
            delete temp;
            temp = nullptr;
        }
    }
    if(flag == 0) {
        std::cout << data << " does not exist in the list" <<std::endl;
        return(-1.0e99);
    } else {
        std::cout << flag << " occurrences of " << data << " are deleted from the list." <<std::endl;
        return data;
    }
    return data;
}
double SList::removeAtEnd(){
    SNode* inode = nullptr;
    SNode* p = nullptr;
    for (inode = head; inode!=nullptr && inode->next != nullptr; p = inode, inode = inode->next);
    double data = -1.0e99;
    if(inode ==nullptr){
        std::cout << "Attempting to delete from an empty list" << std::endl;
    } else{
        (inode == head) ? (head = inode->next) : (p->next = inode->next);     
        data = inode->info;
        delete inode;
    }  
    return data;
}
void SList::display(){
    if (head == nullptr){
        std::cout << "The list is empty." <<std::endl;
    } else {
        std::cout << "The data items in the SList are : " << std::endl;
        for(SNode* inode = head; inode!=nullptr; inode = inode->next){
            std::cout << inode-> info << " ";
        }
    }
}
void SList::freeList(){
    std::cout << "Freeing the list : " << std::endl;
    SNode* inode = head;
    SNode* p = nullptr;
    while(inode!=nullptr){
        p = inode->next;
        delete inode;
        inode = p;   
    }
}
void SList::createList(){
    if(head != nullptr){
        std::cout << "Current list is not empty. Emptying the list before creating the new list." << std::endl;
        SList::freeList();
    }
    int n = 0;
    double data=0;
    std::cout << "Enter Input size  to create the list:" << std::endl;
    std::cin >> n;
    SNode* p = nullptr;
    for (int i=0; i<n; i++){
        std::cout << "Enter Input to create the list:" << std::endl;
        std::cin >> data;
        SNode *new_node = new SNode(data);
        new_node->next = nullptr;
        (head == nullptr) ? (head = new_node): (p-> next = new_node);
        p = new_node;
    }
} 
void test_single_linked_list_double(SList* list){
    unsigned int ch;
    int EXIT_STATUS = 0;
    double data;
    while (1){               
        std::cout << "\n\nTest Options:" << std::endl;
        std::cout << "1. Create" <<std::endl;
        std::cout << "2. addAtStart" <<std::endl;
        std::cout << "3. addAtEnd" <<std::endl;
        std::cout << "4. removeAtStart" <<std::endl;
        std::cout << "5. removeAtEnd" <<std::endl;
        std::cout << "6. removeByData" <<std::endl;
        std::cout << "7. EXIT" <<std::endl;
        std::cout << "Choose the option to test : " << std::endl;
        std::cin >> ch;
        
        switch(ch) {
            case 1:{
                double a[]= {10, 20, 30, 40, 50};
                list = new SList(a, 5);                
                list->display();
            } break;
            case 2: {
                std::cout << "Enter data  to add at the beginning of the list: " <<std::endl;               
                std::cin >> data;
                list->addAtStart(data);
                list->display();
            } break;
            case 3:{
                std::cout << "Enter data  to add at the end of the list: " <<std::endl;
                std::cin >> data;
                list->addAtEnd(data);
                list->display();
            } break;
            case 4: {               
                data = list-> removeAtStart();
                std::cout << "After removing the first element : " << data << std::endl;
                list->display();
            } break;
            case 5:{
                data = list-> removeAtEnd();
                std::cout << "After removing the last element : " << data << std::endl;
                list->display();
            }break;
            case 6:{
                std::cout << "Enter data  to to be removed from the list: " <<std::endl;
                std::cin >> data;
                list->removeByData(data);
                list->display();
            }break;
            case 7:{
                EXIT_STATUS = 1;
            }break;
            default:
                break;
        }
        if(EXIT_STATUS) {
            break;
        }         
    }
}

