#include<gtest/gtest.h>
#include<integral.h>

double test_function(double x){
	return (x*x);
}
TEST(TestIntegral, Trapezoid){
	int n = 99;
	double a = 0, b = 5, integral_value, exact_sol, diff;
	Integral I(test_function, a, b, n);
	exact_sol = 125.0/3;
	integral_value = I.trapezoid();	
	diff = exact_sol - integral_value;
    ASSERT_NEAR(integral_value, 41.6688, 0.00001);
    ASSERT_NEAR(diff, -0.0021256, 0.000001);
}
TEST(TestIntegral, Simpson13){
	int n = 10;
	double a = 0, b = 5, integral_value, exact_sol, diff;	
	Integral I(test_fun, a, b, n);
	exact_sol = 125.0/3;
	integral_value = I.simpson13();
	diff = exact_sol - integral_value;
    ASSERT_NEAR(integral_value, 41.6667, 0.0001);
    ASSERT_NEAR(diff, 0.0, 0.000001);
}