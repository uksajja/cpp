#include <iostream>

#include "integral.h"

Integral::Integral(double (*fun) (double), double a, double b, int n){
	// constructor stub
	nIntervals = n;
	lower = a;
	upper = b;
	f = fun;
}

Integral::~Integral() {
	// TODO Auto-generated destructor stub
}

double Integral :: trapezoid(){
	double sum=0.0, h;
	h = (upper-lower)/nIntervals;
	for(int i=1; i<nIntervals; i++){
		sum += f(lower+i*h);
	}
	sum = 0.5*h*(f(lower)+f(upper)+2*sum);
	return(sum);
}

double Integral :: simpson13(){
	double sum=0.0, sum1=0.0, sum2=0.0, h;
	h = (upper-lower)/nIntervals;
	for(int i=1; i<nIntervals; i=i+2){
		sum1 += f(lower+i*h);
	}
	for(int i=2; i<nIntervals; i=i+2){
		sum2 += f(lower+i*h);
	}
	sum = h/3.0*(f(lower) + f(upper) + 4*sum1 + 2*sum2);
	return(sum);
}

double test_fun(double x){
	return (x*x);
}

void test_trapezoid(){
    std::cout << " Trapezoid Method " << std::endl;
	int n = 99;
	double a = 0, b = 5, integral_value, exact_sol, diff;

	Integral I(test_fun, a, b, n);
	exact_sol = 125.0/3;
	integral_value = I.trapezoid();	
	diff = exact_sol - integral_value;
	std::cout << " Integral(Trapezoidal): " << integral_value << " ExactSolution: " << exact_sol << " Difference: " << diff << std::endl;	
}
void test_simpson13(){
    std::cout << " Simpson1/3 Method " << std::endl;
	int n = 10;
	double a = 0, b = 5, integral_value, exact_sol, diff;
	
	Integral I(test_fun, a, b, n);
	exact_sol = 125.0/3;
	integral_value = I.simpson13();
	diff = exact_sol - integral_value;
	std::cout << " Integral(Simpson1/3): " << integral_value << " ExactSolution: " << exact_sol << " Difference: " << diff << std::endl;	
}

void test_integral(){
	std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << "    Test : Integral evaluation example                       " << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
	test_trapezoid();
	test_simpson13();
}
