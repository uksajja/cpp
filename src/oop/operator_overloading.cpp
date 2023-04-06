// Operators

#include <iostream>
#include <string>
#include "operator_overloading.h"

std::ostream& operator<<(std::ostream& stream, const PosVector& A) {
    stream << "(x, y, z): " << "(" <<A.m_X << "," << A.m_Y << ","<< A.m_Z << ")" ;
    return stream;
}

void test_operator_overloading(){
    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << "    Test : Operator Overloading Example                     " << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    PosVector P1 = {1.0f, 2.0f, 3.0f};
    PosVector P2(10.0f, 11.0f, 12.0f);
    PosVector P3, P4, P5, P6, P7;

    P7 = P1;
    std::cout << "P1: " << P1 << std::endl;
    std::cout << "P7: " << P7 << std::endl;

    P3 = P1+P2;
    P4 = P1-P2;
    P5 = P1*P2;

    P1.Print();
    P2.Print();
    P3.Print();
    P4.Print();
    std::cout << P5 << std::endl;

    P6 = P3-P2;
    if (P6 == P1) {
        std::cout << P6  << " and " << P1 << " are equal" << std::endl;

    }
    P7 = P5;
    std::cout << "P5: " << P5 << std::endl;
    std::cout << "P7: " << P7 << std::endl;
}