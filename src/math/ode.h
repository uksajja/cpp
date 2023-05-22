

#pragma once 

class OdeSoln {
private:
	double iniVal;
	double iniSoln;
	double finalVal;
	int    nIntervals;
	double (*f) (double, double);
public:
	OdeSoln(double (*funptr) (double, double), double ival, double isol, double fval, int n);
	virtual ~OdeSoln();
	double Euler();
	double RK4();
};
double fun(double t, double x);
double exactSol(double t);
void test_Euler();
void test_RK4();
void test_ode_solution();

