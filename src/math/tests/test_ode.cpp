#include<gtest/gtest.h>
#include<ode.h>

double test_function_ode(double t, double x){
    return((1-exp(t))*x / (1+exp(t)));
}
double exactSol_ode(double t){
	return(12 * exp(t)/pow((1+exp(t)),2));
}
TEST(TestODE, Euler){
	double ival = 0;
	double fval = 1.0;
	double isol = 3.0;
	double euler_sol, exact_sol, diff;
	int n = 100;
	OdeSoln ODE(test_function_ode, ival, isol, fval, n);
	exact_sol = exactSol_ode(1.0);
	euler_sol = ODE.Euler();
	diff = exact_sol - euler_sol;
	std::cout << " EulerSol: " << euler_sol << " ExactSol: "  << exact_sol << " Difference: " << diff << std::endl;
    ASSERT_NEAR(exact_sol, euler_sol, 0.005);
}
TEST(TestODE, RK4){
	double ival = 0;
	double fval = 1.0;
	double isol = 3.0;
	double rk4_sol, exact_sol, diff;
	int n = 10;
	OdeSoln ODE(test_function_ode, ival, isol, fval, n);
	exact_sol = exactSol_ode(1.0);
	rk4_sol = ODE.RK4();
	diff = exact_sol - rk4_sol;
	std::cout << " RK(4)Sol: " << rk4_sol << " ExactSol: "  << exact_sol << " Difference: " << diff << std::endl;
    ASSERT_NEAR(exact_sol, rk4_sol, 0.000001);
}