// Example - Explicit keyword

#include <iostream>
#include <string>

#include "explicit.h"


void test_explicit_keyword(){
    std::cout << "\nTesting the usage of explicit keyword." << std::endl;
    Player p1 = 100; // Allowed
    Player P2 = std::string("James"); 
    
    // Team T1 = 100; // NOT allowed as the corresponding constructor is marked explict. i.e., implicit conversion from integer to Team is NOT possible
    // Team T2 = std::string("USA"); // NOT allowed as the corresponding constructor is marked explict. i.e., implicit conversion from std::string to Team is NOT possible

    //Removing explicit from the constructor definitions allow the above instantiations possible
}