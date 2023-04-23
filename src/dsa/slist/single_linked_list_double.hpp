//single linked list with double data type

#pragma once 

#include <iostream>
#include <memory>
#include <vector>

class SNode{
    public:
        double info;
        SNode* next;

        SNode(){
            info =0;
            next = nullptr;
        }
        SNode(double data) { 
            info = data;
            next = nullptr;
        }

};

class SList {
    private:
        SNode* head = nullptr;
    public:
        SList(){head = nullptr;}
        SList(double data){
            SNode *new_node = new SNode(data);
            new_node->next = nullptr;
            head = new_node;
        }
        SList(double data[], int n){
            if(head != nullptr){
                std::cout << "Current list is not empty. Emptying the list before creating the new list." << std::endl;
                //freeList();
            }
            SNode* p = nullptr;
            for (int i=0; i<n; i++){
                SNode *new_node = new SNode(data[i]);
                new_node->next = nullptr;
                (head == nullptr) ? (head = new_node): (p-> next = new_node);
                p = new_node;
            }
        }
        SList(std::vector<double> vec){
            SNode* parent = nullptr;
            SNode*temp = nullptr;
            for(int i=0; i<vec.size(); i++){
                SNode* new_node = new SNode(vec.at(i));
                head==nullptr ? head = new_node : parent->next = new_node;
                parent = new_node;
            }
        }
        
        ~SList(){
            //freeList();
        } 

        void createList();
        void addAtStart(double data);
        void addAtEnd(double data);
        double removeAtStart();
        double removeByData(double data);
        double removeAtEnd();
        void display();
        void freeList(); 
};
void test_single_linked_list_double(SList* list);


