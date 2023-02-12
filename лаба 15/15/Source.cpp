#include <iostream>
#include <windows.h>
using namespace std;

double cycleForB(double h, double e, double a, double b, double x) {
	while (h > 2 * e) {
		h = abs(a - b);
		x = (a + b) / 2;
		b = x;
	}
	return 0;
	cout << "Methood dihotomii " << x << endl;

}

double cycleForA(double h, double e, double a, double b, double x) {
	while (h > 2 * e) {
		h = abs(a - b);
		x = (a + b) / 2;
		a = x;
	}

	cout << "Methood dihotomii " << x << endl;
	return 0;

}
double processing(double a, double b) {
	double x = (a + b) / 2;
	double y = 2 - pow(a, 2) + a;
	double yx = 2 - pow(x, 2) + x;
	double h = 1, e = 0.0001;
	if (y * yx <= 0) {
		double(*cycle)(double h, double e, double a, double b, double x);
		cycle = cycleForB;
		cycle(h, e, a, b, x);
	}
	else {
		double(*cycle)(double h, double e, double a, double b, double x);
		cycle = cycleForA;
		cycle(h, e, a, b, x);
	}
	return 0;

}
void main()
{
	double a = 0, b = 1;
	double (*p_proccesing)(double a, double b);
	p_proccesing = processing;
	p_proccesing(a, b);
}