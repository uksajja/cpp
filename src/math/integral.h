#pragma once 


class Integral {
	private:
		int nIntervals;
		double lower;
		double upper;
		double (*f) (double);
		int echo_level;

	public:
		Integral(double (*f) (double), double a, double b, int n, int echo_level);
		virtual ~Integral();
		double trapezoid();
		double simpson13();
};

double test_fun(double x);
void test_trapezoid();
void test_simpson13();
void test_integral();

