//System includes
#include<iostream>
#include<climits>
#include<cmath>

//Project includes
//OOP includes
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
#include "template_class.hpp"

//Math includes
#include "ode.h"
#include "integral.h"

//DSA includes
#include "hash_table.h"
#include "single_linked_list.hpp"


int main(){
    //OOP Tests 
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
    test_template_class();

    //Math Tests
    test_ode_solution();
    test_integral();

    //DSA Tests
    test_hash_table();
    test_single_linked_list();


    
    return 0;
}
