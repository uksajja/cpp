//Instantiation of Objects -- Implict Conversion and Explicit keyword

//C++ includes
#include <iostream>

//Project includes
#include "instantiation.h"


void test_instantiation() {
    std::cout << "Testing Instantiation of the class objects" << std::endl;
    Employee e0 = Employee("Mark"); //INVOKES A CONSTRUCTOR WITH STRING AS THE ONLY PARAMETER
    Employee e1("John");            // Implict conversion of const char[] "John" to std::string and invoking Employee class object by using constructor receing the string

    // Employee e2 = "Kumar"; 
    // This does NOT work. because it requires two implicit conversions.
    // 1. implicit conversion from const char[] to std::string and 2. imjplicit conversion of string to Employee object through the use of constructor of Employee
    //C++ allows only one implicit conversion.
    Employee e2 = std::string("Steve"); // std:string is a class. It has a constructor receiving a char* or const char* . Only one implicit conversion needed from string to Employee

    Employee emp0 = Employee(100);
    Employee emp1(300);
    Employee emp2 = 400; // Implicit conversion of integer into employee object through the use of the constructor receiving the integer
}