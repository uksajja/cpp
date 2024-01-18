//vector operations

//C++ inlcudes
#include <iostream>
#include <vector>

#include "stl_vector.hpp"


class A {
    private:
        int m_X, m_Y;
    public:
        A(int x, int y): m_X(x), m_Y(y) {
            std::cout << "Constructor" <<std::endl;
        }
        void PrintDetails() {
            std::cout <<"x: " << m_X << "  y = " << m_Y << std::endl;
        }
};

// array is fixed size
// vector dynamic size - automatically takes care of memory management
// copy one vector to another is possible

void test_stl_vector_operations(){
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "    Test : STL - vector                                     " << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    
    std::vector<int> v; //empty vector
    
    v.assign(5, 100); //Fill the vector with a value 100 for 5 times

    v.push_back(1);   // Append 1 to the vecor
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);

    v.insert(v.end(), 100);   // First argument is an iterator
    v.erase(v.begin());       // Argument is an iterator

    std::cout << "Capacity:" << v.capacity() << "   Size:" << v.size() << std::endl;
    std::cout << "Font:" << v.front() << std::endl; //First element
    std::cout << "Back:" << v.back() << std::endl;  //Last element
    for (std::vector<int>::iterator it =v.begin(); it !=v.end(); ++ it){
        std::cout << *it << std::endl;
    }
    
    //upsizing
    //new elements with a value of 0 will be created until the size becomes 15
    v.resize(15); 
    std::cout << "After resize to 10, Capacity:" << v.capacity() << "   Size:" << v.size() << std::endl;
    for (size_t i=0; i< v.size(); i++) {
        std::cout << v.at(i)<< std::endl;
    }

    //upsizing
    //new elements with a value of 1000 will be created until the size becomes 20
    v.resize(20, 1000); 
    std::cout << "After resize to 20 and initialize with 1000, Capacity:" << v.capacity() << "   Size:" << v.size() << std::endl;
    for (size_t i=0; i< v.size(); i++) {
        std::cout << v.at(i)<< std::endl;
    }

    // downsizing
    //vector will be  cut down to 5 elements. Later elements will be removed. However, capacity will remain the same.
    v.resize(5); 
    std::cout << "After resize to 5, Capacity:" << v.capacity() << "   Size:" << v.size() << std::endl;
    for (std::vector<int>::iterator it =v.begin(); it !=v.end(); ++ it) {
        std::cout << *it << std::endl;
    }

    //reserve memory for 100 elements
    v.reserve(100);
    std::cout << "After reserve to 100, Capacity:" << v.capacity()  << "   Size:" << v.size() << std::endl;
    for (std::vector<int>::iterator it =v.begin(); it !=v.end(); ++ it) {
        std::cout << *it << std::endl;
    }

    std::cout << "\nIs the vector empty? : " << v.empty() << std::endl;
    v.clear();  // removes all the elements
    std::cout << "After clearing the vector, Capacity:" << v.capacity() << "   Size:" << v.size() << std::endl;
    for (size_t i=0; i< v.size(); i++) {
        std::cout << v.at(i)<< std::endl;
    }
    std::cout << "Is the vector empty? : " << v.empty() << std::endl;
}

void test_vector_initializations(){
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "    Test : STL - vector - initializations                   " << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    std::vector<int> vn(5);            // vector with n elements of zero
    std::vector<int> vn_val(5, -1);    // vector with n elements of -1
    std::vector<double> vd{3.5, -4.5}; //vector with two elements with values 3.5 and -4.5
    std::vector<double> vd2(10, -1.5); //vector with 10 elements each with a value of -1.5
    for (size_t i=0; i< vn.size(); i++) {
        std::cout << vn.at(i)<< std::endl;
    }
    for (size_t i=0; i< vn_val.size(); i++) {
        std::cout << vn_val.at(i)<< std::endl;
    }
    for (size_t i=0; i< vd.size(); i++) {
        std::cout << vd.at(i)<< std::endl;
    }
    for (size_t i=0; i< vd2.size(); i++) {
        std::cout << vd2.at(i)<< std::endl;
    }

    std::vector<int> vv[3]; //array of 3 vectors of std::vector<int> type
    vv[1] = vn;
    vv[2] = vn_val;
    // vv[3] = vd; This is NOT allowed as type is different
    for (int i=0; i< 3; i++){
        for (size_t j=0; j< vv[i].size(); j++) {
            std::cout << vv[i].at(j)<< std::endl;
        }
    }
}
void test_push_back_emplace(){
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "    Test : STL - vector - push_back() emplace_back()        " << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    //emplace_back - constructs directly an object into a container without a temporary at all
    //where as push_back requires a temporary object to be created
    //In the following examples, an object of type A is created and send as an agument whenever push_back() is used
    //whereas emplace_back() directly takes the member types as arguments and directly places it in the container(in this case, vector) with creting a temporary object first.
    
    std::vector<A> v;
    v.push_back(A(1,2));
    v.push_back({100,200});
    v.emplace_back(10,20); //Note that just the member arguments are sent as arguments, not an object of type A
    for (size_t i = 0; i != v.size(); i++) {
       (v.at(i)).PrintDetails();
    }

    v.erase(v.begin()+1);
    for (size_t i = 0; i != v.size(); i++) {
       v[i].PrintDetails();
    }
    v.reserve(5);
    v[1] = A(30,300);
    v.emplace_back(40, 400);
    v[1] = A(50, 500);
    v[2] = A(60, 600);
    v[3] = A(70, 700);

    std::cout << "size: " << v.size() << std::endl;
    for( A& ivec : v){
        ivec.PrintDetails();
    }
}

