//System includes
#include<iostream>
#include<climits>

//Project includes
#include "instantiation.h"
#include "const_specifier.h"
#include "inheritance.h"

int main(){ 
    test_instantiation();
    test_const_specifier();
    test_inheritance();
    test_inheritance_ptr();
    test_inheritance_ref();

    return 0;
}
