//const - keyword - demonstrations

//C++ inludes
#include<iostream>

void test_const_specifier(){

    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "    Test : const - specifier                                " << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    
    int x = 100;
    int y = 200;
    //x, y are variables and can take different valuyes at different times as needed

    const int a = 10; // value of a CANNOT be changed
    //a = 5;   // NOT allowed

    const int *b = &x; // Contents of b CANNOT be changed directly
    int const *c = &y; // Contents of c CANNOT be changed directly
    // the above two statements represent two different ways for similar behavior
    // contents of b or c cannot be changed directly by de-reference operator(*)
    // However, b or c can point to different memory addresses at different times
    
    //*b = 10; // changing the contents of b directly is NOT allowed
    b = &y;    // b can be changed and can point to another int

    //*c = 50; // contents of c cannot be changed
    c = &x;    // c can be changed.

    int *const d = new int(30); // d is a pointer that is constant. d always should point to the same memory
    *d = x;    // contents of d can be changed
    //d = &x;  //d cannot store another address - d cannotbe changed

    std::cout << "a=" << a  << std::endl;
    std::cout << "b=" << *b << std::endl;
    std::cout << "c=" << *c << std::endl;
    std::cout << "d=" << *d << std::endl;

    delete d;
}