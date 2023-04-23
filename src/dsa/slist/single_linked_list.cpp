//Test Linked List

#include<iostream>
#include "single_linked_list.hpp"


class emp{
    
    public:
        std::string name;
        int id;
        emp() = default; // This is needed. What is the purpose?
        emp(const std::string& n, const int i): name(n), id(i){}
        ~emp(){}
        friend bool operator==(const emp& e1, const emp& e2);
        friend std::ostream& operator<<(std::ostream& stream, const emp& e);
        friend std::istream& operator>>(std::istream& input, emp& e);
};
bool operator==(const emp& e1, const emp& e2){
    return(e1.name==e2.name  && e1.id==e2.id);
}
std::ostream& operator<<(std::ostream& stream, const emp& e){
    stream << "(" << e.name <<"," << e.id <<")" <<std::endl;
    return stream;
}
std::istream& operator>>(std::istream& input, emp& e) {
    std::cout << "Enter name: " ; input >> e.name;
    std::cout << "Enter id: " ; input >> e.id;
    //e.name = nm; e.id = n;
    //e = emp(nm, n);
    return input;
}
void test_single_linked_list(){
    unsigned int ch;
    bool EXIT_STATUS = 0;
    double a[] = {10, 10, 20, 10, 10 ,30, 30, 40, 10, 10};
    std::vector<double> dvec = {10.0, 10.0, 20.0, 10.0, 10.0 ,30.0, 30.0, 40.0, 10.0, 10.0};
    std::vector<std::string> strvec = {"Ud", "Va", "Pr", "Sh", "Me", "c++", "py"};
    std::vector<emp> evec = {emp("Ku", 1), emp("Van", 2), emp("Pran", 3), emp("Sam", 2)};
    std::vector<std::string> namevec = {"Ud", "Va", "Pr", "Sh"};
    std::vector<emp> empvec = {emp(namevec.at(0), 1), emp(namevec.at(1), 2), emp(namevec.at(2), 3), emp(namevec.at(3), 4)};
    
    while(1) {
        std::cout << "\nChoose Option \n 1. SingleLinkedList(double) \n 2. SingleLinkedListTemplate(double) \n 3. SingleLinkedListTemplate(string) \n 4. SingleLinkedListTemplate(employee)" << std::endl;
        std::cout << " 5. SingleLinkedListSmart(double)\n 6. SingleLinkedListSmart(string) \n 7. SingleLinkedListSmart(employee) \n 8. Exit: \n" << std::endl;
        std::cin >> ch;
        switch(ch){
            case 1:{
                SList* list_double = new SList(dvec);
                test_single_linked_list_double(list_double);
            }   break;
            case 2:{                
                TList<double> *tlist = new TList<double>(a, 10);
                test_single_linked_list_template(tlist);
            }   break;
            case 3:{
                TList<std::string> *strTList = new TList<std::string>(strvec);
                test_single_linked_list_template(strTList);
            }   break;
            case 4:{
                TList<emp> *empTList = new TList<emp>(empvec);
                test_single_linked_list_template(empTList);
            }   break;
            case 5:{
                SmartList<double> *smartList = new SmartList<double>(a, 10);
                test_single_linked_list_smart(smartList);
            }   break;
            case 6:{                
                SmartList<std::string> *strList = new SmartList<std::string>(strvec);
                test_single_linked_list_smart(strList);
            }      break;
            case 7:{
                SmartList<emp> *empList = new SmartList<emp>(evec);
                test_single_linked_list_smart(empList);
            }   break;
            case 8:{
                EXIT_STATUS = 1;
            }   break;
        }
        if(EXIT_STATUS) {
            break;
        }
    } 
}