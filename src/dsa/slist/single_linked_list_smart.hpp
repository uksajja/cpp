// Singly Linked List With Smart Pointers
#pragma once

#include<iostream>
#include<memory>
#include<vector>

template<class T>
class SmartNode{

    public:
        T info;
        std::shared_ptr<SmartNode<T>> next = nullptr;        
        SmartNode(){next = nullptr;}
        SmartNode(const T& data){
            info = data;
            next = nullptr;
        }
        SmartNode (const T& data, SmartNode* next_node){
            info = data;
            next = next_node;
        }       
};
template<class T>
class SmartList{
    public:
        SmartList(){head = nullptr;}
        SmartList(T data[], int n){
            std::shared_ptr<SmartNode<T>> p = nullptr;
            for(int i=0; i<n; i++){
                std::shared_ptr<SmartNode<T>> new_node = std::make_shared<SmartNode<T>>(data[i]);
                (p == nullptr) ? (head = new_node) : (p->next = new_node);
                p = new_node;
            }
        }
        SmartList(std::vector<T> data){
            std::shared_ptr<SmartNode<T>> p= nullptr;
            //for(std::vector<T>::Iterator it=data.begin(); it!=data.end(); ++it){
            //Iterator method is not defined for custom class (emp). Hence changed to the regular loop
            for (size_t i=0; i<data.size(); i++){
                std::shared_ptr<SmartNode<T>>new_node = std::make_shared<SmartNode<T>>(data.at(i));
                (p==nullptr) ? (head = new_node) : (p->next = new_node);
                p = new_node;
            }
        }
        void addAtStart(const T& data){
            std::shared_ptr<SmartNode<T>> new_node = std::make_shared<SmartNode<T>>(data);
            new_node->next = head;       
            head = new_node;
        }
        void addAtEnd(const T& data){
            std::shared_ptr<SmartNode<T>> inode = nullptr;
            for(inode = head; inode!=nullptr && inode->next != nullptr; inode = inode->next );
            std::shared_ptr<SmartNode<T>> new_node = std::make_shared<SmartNode<T>> (data);
            new_node -> info  = data;
            new_node -> next = nullptr;
            if(inode == nullptr){
                head = new_node;
            } else {
                inode-> next = new_node;
            }        
        }
        T removeByData(const T& data){
            std::shared_ptr<SmartNode<T>> temp = nullptr;
            std::shared_ptr<SmartNode<T>> parent = nullptr;
            std::shared_ptr<SmartNode<T>> inode = head;
            unsigned int flag = 0;
            while(inode!=nullptr) {                
                if (inode->info == data){
                    flag++;
                    temp = inode;
                    if(inode == head) {
                        head = inode->next;
                     } else{
                        parent->next=inode->next;
                     }                                                                                 
                } else {
                    parent = inode;
                }
                inode = inode->next;                             
                if (temp!=nullptr) temp = nullptr;//delete should not be used when using make_shared to create
            }
            if(flag == 0){
                std::cout << data << " does not exist in the list" <<std::endl;
                return T();
            } else {
                std::cout << flag << " occurrences of " << data << " are deleted from the list." <<std::endl;
                return data;
            }

        }
        T removeAtStart() {        
            if(head ==nullptr) {
                std::cout << "Attempting to delete from an empty list" <<std::endl;
                return T();
            } else {
                std::shared_ptr<SmartNode<T>> p = head;
                head = p->next;
                T data = p->info;
                p = nullptr;
                return data;
                //delete p;//delete should not be used when using make_shared to create
            }
        }
        T removeAtEnd() {
            if(head ==nullptr) {
                std::cout << "Attempting to delete from an empty list" <<std::endl;
                return T();
            } else {
                std::shared_ptr<SmartNode<T>> p = nullptr;
                std::shared_ptr<SmartNode<T>> inode = nullptr;
                for(inode = head; inode->next !=nullptr; inode = inode->next ){
                    p = inode;
                };
                (inode == head) ? (head = inode->next) : (p->next = inode->next);
                T data = inode->info;
                inode = nullptr;
                //delete inode;//delete should not be used when using make_shared to create
                return data;
            }
        }
        void display(){
            if (head == nullptr){
                std::cout << "The list is empty." <<std::endl;
            } else {
                std::cout << "The data items in the list are : " << std::endl;
                for(std::shared_ptr<SmartNode<T>>inode = head; inode!=nullptr; inode=inode->next){
                    std::cout << inode->info ;
                }
            }
        }
        void freeList(){
            std::cout << "Freeing the list : " << std::endl;
            SmartNode<T> inode = head;
            SmartNode<T> p = nullptr;
            while(inode!=nullptr){
                p = inode->next;
                inode = nullptr;
                //delete inode;  //is delete needed here as make_shared is used to create?
                inode = p;   
            }
        }
    protected:
        std::shared_ptr<SmartNode<T>> head = nullptr;
};

template<class T>
void test_single_linked_list_smart(SmartList<T>* list){
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
                //double a[] = {10, 10, 20, 10, 10 ,30, 30, 40, 10, 10};
                //list = new SmartList(a, 10);
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
                std::cout << "Enter data  to be removed from the list: " <<std::endl;
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