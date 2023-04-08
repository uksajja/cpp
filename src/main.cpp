//System includes
#include<iostream>
#include<climits>

//Project includes
#include "instantiation.h"
#include "const_specifier.h"
#include "inheritance.h"
#include "operator_overloading.h"
#include "explicit.h"
#include "virtual_functions.h"
#include "pure_virtual_functions.h"
#include "function_pointer.h"
#include "composition.h"
#include "template_function.hpp"
#include "ode.h"


int main(){ 
    test_instantiation();
    test_const_specifier();
    test_inheritance();
    test_inheritance_ptr();
    test_inheritance_ref();
    test_operator_overloading();
    test_explicit_keyword();
    test_virtual_functions();  
    test_pure_virtual_functions();
    test_function_pointer();
    test_composition();
    test_template_function();
    test_ode_solution();
    
    return 0;
}
