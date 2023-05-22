//System includes
#include<iostream>
#include<climits>
#include<cmath>

#include<gtest/gtest.h>

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
#include "vector-stl.h"


int main(int argc, char* argv[]){

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

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

    //STL
    test_vector_initializations();
    test_stl_vector_operations();
    test_push_back_emplace();

   
    return 0;
}
