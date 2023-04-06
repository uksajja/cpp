
#include<iostream>

#include "function_pointer.h"



double square(double x){
	return(x*x);
}

double trapezoid(funPtr f, double a, double b, int n){
	double integral=0.0, h;
	h = (b-a)/n;

	for(int i=1; i<n; i++){
		integral += f(a+i*h);
	}
	integral = 0.5 * h * (f(a)+f(b)+ 2*integral);
	return(integral);
}
void test_function_pointer(){
	std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << "    Test : Function Pointer example                         " << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
	int n;
	double a, b, integral;
	funPtr f=square;

	std::cout << "Enter number of intervals: " << std::endl;
	std::cin >> n;
	std::cout << std::endl << "Enter lower and upper limit :"<< std::endl;
	std::cin >> a >> b;

	integral = trapezoid(f, a, b, n);
	std::cout << "Trapezoid rule: Integral value is : " <<integral << std::endl;
}

