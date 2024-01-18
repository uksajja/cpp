#include "stl_set.hpp"

std::ostream& operator<<(std::ostream& stream, Point A) {
    stream << "( " << A.getX() << "," << A.getY() <<")" ;
    return stream;
}

std::ostream& operator<<(std::ostream& stream, std::pair<int,int> A) {
    stream << "( " << A.first << "," << A.second <<")" ;
    return stream;
}
//Show methods

void show_auto(const std::set<int>& s){
    if(s.empty()){
        std::cout << " The set is empty " << std::endl;
        return;
    }
    std::cout << "The elements in the set are (auto): " << std::endl;
    for(auto& it : s){
        std::cout << it << "  " ;

    }
    std::cout << std::endl;
}
void show_auto(const std::set<int, std::greater<int>>& s){
    if(s.empty()){
        std::cout << " The set is empty " << std::endl;
        return;
    }
    std::cout << "The elements in the set(greater) are (auto): " << std::endl;
    for(auto& it : s){
        std::cout << it << "  " ;

    }
    std::cout << std::endl;
}
void show_auto(const std::set<int, compare_object>& s){
    if(s.empty()){
        std::cout << " The set is empty " << std::endl;
        return;
    }
    std::cout << "The elements in the set are (auto): " << std::endl;
    for(auto it : s){
        std::cout << it << "  " ;

    }
    std::cout << std::endl;
}



void show1(const std::set<int>& s){
    if(s.empty()){
        std::cout << " The set is empty " << std::endl;
        return;
    }
    std::cout << "The elements in the set are (iterator): " << std::endl;
    for(std::set<int>::iterator it = s.begin(); it!=s.end(); it++){
        std::cout << *it << "  " ;

    }
    std::cout << std::endl;
}
void show2(const std::set<int>& s){
    if(s.empty()){
        std::cout << " The set is empty " << std::endl;
        return;
    }
    std::cout << "The elements in the set are (const_iterator): " << std::endl;
    for(std::set<int>::const_iterator it = s.cbegin(); it!=s.cend(); it++){
        std::cout << *it << "  " ;

    }
    std::cout << std::endl;
}
void show3(const std::set<int>& s){
    if(s.empty()){
        std::cout << " The set is empty " << std::endl;
        return;
    }
    std::cout << "The elements in the set in reverse order are (reverse_iterator): " << std::endl;
    for(std::set<int>::const_reverse_iterator it = s.rbegin(); it!=s.rend(); it++){
        std::cout << *it << "  " ;

    }
    std::cout << std::endl;
}
void show4(const std::set<int>& s){
    if(s.empty()){
        std::cout << " The set is empty " << std::endl;
        return;
    }
    std::cout << "The elements in the set in reverse order are (const_reverse_iterator): " << std::endl;
    for(std::set<int>::const_reverse_iterator it = s.crbegin(); it!=s.crend(); it++){
        std::cout << *it << "  " ;

    }
    std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& os, std::set<char>& u){
    for(auto& i : u){
        os << i <<  "  " ;
    }
    os << "\n";
    return os;
}