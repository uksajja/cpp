#include <iostream>
#include <cmath>
#include "ode.h"

using namespace std;

OdeSoln :: OdeSoln(double (*funptr) (double, double), double ival, double isol, double fval, int n, int dbg_level=1){
	// constructor stub
	iniVal = ival;
	iniSoln = isol;
	finalVal = fval;
	nIntervals = n;
	f = funptr;
	echo_level = dbg_level;
}
OdeSoln::~OdeSoln() {
	// TODO Auto-generated destructor stub
}
double OdeSoln :: Euler(){
	double value, h;

	std::cout << " Euler Method" << std::endl;
	h = (finalVal-iniVal)/nIntervals;
	value = iniSoln;
	for(int i=0; i< nIntervals; i++){
		value += h * f(iniVal+ i*h, value);
		if(echo_level>1) std::cout << "y[" <<i <<"] = " << value << std::endl;
	}
	return(value);
}
double OdeSoln :: RK4(){
	double value, h;
	double F1, F2, F3, F4, xk;

	std::cout << " Runge-Kutta Method (4)" << std::endl;
	h = (finalVal-iniVal)/nIntervals;
	value = iniSoln;
	for(int i=0; i<nIntervals; i++){
		xk = iniVal+i*h;
		F1 = h*f(xk, value);
		F2 = h*f(xk+h/2, value+F1/2);
		F3 = h*f(xk+h/2, value+F2/2);
		F4 = h*f(xk+h,   value+F3);
		value = value + (F1+2*F2+2*F3+F4)/6;
		if(echo_level>1) std::cout << "y[" <<i <<"] = " << value << std::endl;
	}
	return(value);
}


double fun(double t, double x){
	return((1-exp(t))*x / (1+exp(t)));
}
double exactSol(double t){
	return(12 * exp(t)/pow((1+exp(t)),2));
}

void test_Euler(){
	double ival = 0;
	double fval = 1.0;
	double isol = 3.0;
	double euler_sol, exact_sol, diff;
	int n = 10;
	OdeSoln ODE(fun, ival, isol, fval, n);
	exact_sol = exactSol(1.0);
	euler_sol = ODE.Euler();
	diff = exact_sol - euler_sol;
	std::cout << " EulerSol: " << euler_sol << " ExactSol: "  << exact_sol << " Difference: " << diff << std::endl;
}
void test_RK4(){
	double ival = 0;
	double fval = 1.0;
	double isol = 3.0;
	double rk4_sol, exact_sol, diff;
	int n = 10;
	OdeSoln ODE(fun, ival, isol, fval, n, 10);
	exact_sol = exactSol(1.0);
	rk4_sol = ODE.RK4();
	diff = exact_sol - rk4_sol;
	std::cout << " RK(4)Sol: " << rk4_sol << " ExactSol: "  << exact_sol << " Difference: " << diff << std::endl;
}
void test_ode_solution(){
	std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << "    Test : Ordinary Differential Equations example           " << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
	test_Euler();
	test_RK4();
}