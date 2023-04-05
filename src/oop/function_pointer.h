// Example - Explicit keyword
#pragma once 

#include <iostream>
#include <string>

typedef double(*funPtr) (double);
double square(double x);
double trapezoid(funPtr f, double a, double b, int n);
void test_function_pointer();