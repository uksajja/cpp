// virtual functions - example

// C++ includes
#include<iostream>
#include<string>

#include "virtual_functions.h"

void test_virtual_functions(){
    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << "    Test : Virtual Functions                                " << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    
    Book b1("HarryPotter", "J.K.Rowling");
    TextBook Tb1 = TextBook("Fundamentals of Thermodynamics", "Shapiro") ; 
    TextBook Tb2 = {"FEM", "J.N.Reddy"} ;   

    b1.PrintBookDetails();   
    Tb1.PrintBookDetails();
    Tb2.PrintBookDetails();     

    Book& ref = Tb2;
    Tb2.PrintBookDetails();     //GetType()  ==> TextBook->GetType
    ref.PrintBookDetails();     //GetType()  ==> TextBook->GetType() if the function GetType()is defined as virtual
                                //GetType()  ==> Book->GetType() if the function GetType()is NOT defined as virtual
    
    Book* b = new TextBook("CFD", "Anderson");
    b->PrintBookDetails();      //GetType()  ==> TextBook->GetType() if the function GetType()is defined as virtual
                                //GetType()  ==> Book->GetType() if the function GetType()is NOT defined as virtual

    std::cout << "Type:" << b->GetType() << std::endl; //GetType()  ==> TextBook->GetType() if the function GetType()is defined as virtual

    delete b;
}