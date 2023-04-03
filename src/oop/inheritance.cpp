//inheritence - example

//C++ includes
#include<iostream>
#include<string>

//Project includes
#include "sport.h"


void PrintSportInfo(const Sport& s){
    s.PrintDetails();
}
void PrintSportInfo(Sport* sptr){
    sptr->PrintDetails();
}

void test_inheritance(){
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "    Test : Inheritance - Object                             " << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;

    //Instantiating an Object
    Sport sp1;
    Cricket c1;
    Baseball b1;
    Soccer s1;
    Basketball bk1; 

    sp1.PrintDetails();
    c1.PrintDetails();
    b1.PrintDetails();
    s1.PrintDetails();
    bk1.PrintDetails();
}

void test_inheritance_ptr(){
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "    Test : Inheritance - Ptr                                " << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    //Instantiating an Object Pointer
    Sport* sp_ptr1 = new Sport();
    Cricket* cptr1 = new Cricket();
    Baseball* bptr1 = new Baseball();
   
    sp_ptr1->PrintDetails();
    cptr1->PrintDetails();
    bptr1->PrintDetails();

    //Base Ptr pointing to derived object
    //Following doesn't give intended results - Correction: Use virtual functions
    //See virtual functions example
    Sport* base_ptr = new Cricket(); // This is allowed - Base pointer can be used to store derived object
    //Constructor of Cricket is invoked - members are initialized according to Cricket constructor
    //However, other NON-VIRTUAL base class functions ( with the same name ) are called and not Cricket class functions
    base_ptr->PrintDetails(); // Sport->PrintDetails will be invoked instead of Cricket->PrintDetails

    delete sp_ptr1;
    delete cptr1;
    delete bptr1;
    delete base_ptr;
}

void test_inheritance_ref(){
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "    Test : Inheritance - Ref                                " << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    
    //Following doesn't give intended results - Correction: Use virtual functions
    //See virtual functions example

    Cricket c;
    PrintSportInfo(c);

    Basketball *bptr = new Basketball();
    PrintSportInfo(bptr);

}