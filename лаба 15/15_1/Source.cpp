#include <iostream>

using namespace std;


double processing(double a, double b) {
	
	double y = 2 - pow(a, 2) + a;
	double ydif = -(2*a) + 1;
	double x1, e = 0.0001;
	if (y * ydif > 0) {
		x1 = a;
	}
	else {
		x1 = b;
	}
	 y = 2 - pow(x1, 2) + x1;
	 ydif = -(2*x1) + 1;
	
	double x = (y / ydif);


	while (x1 - x > e) {
		 y = 2 - pow(x, 2) + x;
		 ydif = -(2*x) + 1;
		
		x1 = x - (y / ydif);
		x = x1;

	}
	cout << "Methood tanget " << x1 << endl;

	return 0;
}

void main() {
	double a = -1, b = 2;

	double(*m)(double a, double b);
	m = processing;
	m(a, b);
}
