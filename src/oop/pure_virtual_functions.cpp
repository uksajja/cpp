//Interface example - or Pure virtual functions example
//C++ includes
#include <iostream>

//Project includes
#include "pure_virtual_functions.h"

void test_pure_virtual_functions() {  
    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << "    Test : Pure virtual functions example                   " << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    // Shape s_obj(); - Not allowed as Shape class has a virtual method
    // All the virtual functions must be defined in each derived class. Otherwise, derived class objects also cannot be instantiated
    Shape *s1 = new Triangle(5, 8);
    s1->calculate_area();
    s1->PrintDetails();


    Shape *s2 = new Square(9);
    s2->calculate_area();
    s2->PrintDetails();

    //Shape *s2  = new Rectangle(10, 20); // Rectangle Object cannot be initiated as area() function is defined for Rectangle class

}