//Templated single linked list with double data type
/*Placing the template member function in a separate imlementation file WON't work.
  Templates aren't functions, they can't be compiled separately.
  Templates have to be used in conjunction with the particular instantiations of templates.
*/
#pragma once 

#include <iostream>
#include<vector>

template<class T>
class TNode{
    public:
        T info;
        TNode<T>*next = nullptr;

        TNode(){
            info = 0;
            next = nullptr;
        }
        TNode(T& data) { 
            info = data;
            next = nullptr;
        }
};

template<class T>
class TList {
    protected:
        TNode<T> *head = nullptr;
    public:
        TList(){ head = nullptr;}
        TList(T& data){
            TNode<T> *new_node = new TNode<T> (data);
            new_node->next = nullptr;
            head = new_node;
        }
        TList(T data[], int n){
            TNode<T>* p = nullptr;
            for (int i=0; i<n; i++){
                TNode<T> *new_node = new TNode<T> (data[i]);
                new_node->next = nullptr;
                (head == nullptr) ? (head = new_node): (p-> next = new_node);
                p = new_node;
            }
        }
        TList(std::vector<T> vec) {
            TNode<T>*parent = nullptr;
            for(unsigned int i = 0; i<vec.size(); i++){
                TNode<T>* new_node = new TNode<T>(vec.at(i));
                (head == nullptr) ? head = new_node : parent->next = new_node;
                parent = new_node;
            }
        }
        void addAtStart(T& data){
            TNode<T>* new_node = new TNode<T>(data);
            new_node -> next = head;
            head = new_node;
        }
        void addAtEnd(T& data){
            TNode<T>* new_node = new TNode<T>(data);
            TNode<T>* inode = nullptr;
            for (inode = head; inode!=nullptr && inode->next != nullptr; inode = inode->next);
            
            if(inode == nullptr){
                head = new_node;
            } else {
                inode->next = new_node;
            }
        }
        T removeAtStart(){
            TNode<T> *p = head;
            if(head ==nullptr) {
                std::cout << "Attempting to delete from an empty list" <<std::endl;
                return T();
            } else {
                T data = p->info;
                head = p->next;
                delete p;
                return data;
            }                        
        }
        T removeByData(const T& data){
            TNode<T>* inode  = nullptr;
            TNode<T>* temp   = nullptr;
            TNode<T>* parent = nullptr;
            unsigned int flag = 0;
            for (inode = head; inode!=nullptr; ){
                if(inode->info == data){
                    flag++;
                    temp = inode;
                    if(inode == head) {
                        (head = inode->next);
                    } else{
                        (parent->next = inode->next);
                    }
                } else {
                    parent = inode;
                }
                inode = inode->next;
                if(temp != nullptr) {
                    delete temp;
                    temp = nullptr;
                }
            }
            if(flag == 0) {
                std::cout << data << " does not exist in the list" <<std::endl;
                return T();
            } else {
                std::cout << flag << " occurrences of " << data << " are deleted from the list." <<std::endl;
                return data;
            }
        }
        T removeAtEnd(){
            TNode<T>* inode = nullptr;
            TNode<T>* p = nullptr;
            for (inode = head; inode!=nullptr && inode->next != nullptr; p = inode, inode = inode->next);
            if(inode ==nullptr){
                std::cout << "Attempting to delete from an empty list" << std::endl;
                return T();
            } else{
                (inode == head) ? (head = inode->next) : (p->next = inode->next); 
                T data = inode->info;
                delete inode;
                return data;
            }  
        }
        void display(){
            if (head == nullptr){
                std::cout << "The list is empty." <<std::endl;
            } else {
                std::cout << "The data items in the list are : " << std::endl;
                for(TNode<T>* inode = head; inode!=nullptr; inode = inode->next){
                    std::cout << inode-> info << " ";
                }
            }
        }
        void freeList(){
            std::cout << "Freeing the list : " << std::endl;
            TNode<T>* inode = head;
            TNode<T>* p = nullptr;
            while(inode!=nullptr){
                p = inode->next;
                delete inode;
                inode = p;   
            }
        }

        void createList(){
            int n = 0;
            T data;
            if(head != nullptr){
                std::cout << "Current list is not empty. Emptying the list before creating the new list." << std::endl;
                freeList();
            }
            std::cout << "Enter Input size  to create the list:" << std::endl;
            std::cin >> n;
            TNode<T>*p = nullptr;
            for (int i=0; i<n; i++){
                std::cout << "Enter Input create the list:" << std::endl;
                std::cin >> data;
                TNode<T> *new_node = new TNode<T>(data);
                new_node->next = nullptr;
                (head == nullptr) ? (head = new_node): (p-> next = new_node);
                p = new_node;
            }
        }
};
template<class T>
void test_single_linked_list_template(TList<T>* list){
    unsigned int ch;
    int EXIT_STATUS = 0;

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
                //list->createList();
                list->display();
            } break;
            case 2: {
                T data;
                std::cout << "Enter data  to add at the beginning of the list: " <<std::endl;               
                std::cin >> data;
                list->addAtStart(data);
                list->display();
            } break;
            case 3:{
                T data;
                std::cout << "Enter data  to add at the end of the list: " <<std::endl;
                std::cin >> data;
                list->addAtEnd(data);
                list->display();
            } break;
            case 4: {            
                list->removeAtStart();
                std::cout << "After removing the first element : " << std::endl;
                list->display();
            } break;
            case 5:{
                list->removeAtEnd();
                std::cout << "After removing the last element : " << std::endl;
                list->display();
            }break;
            case 6:{
                T data;
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