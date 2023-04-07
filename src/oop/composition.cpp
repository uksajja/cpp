//Composition example

#include <iostream>
#include <string>

#include "composition.h"

void test_composition(){
    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << "    Test : composition example                               " << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
	StartDate doj(5,24,2011);
	Emp emp("Uday","HX",doj);
	emp.printEmpInfo();
}
