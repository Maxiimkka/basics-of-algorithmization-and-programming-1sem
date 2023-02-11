#include <iostream> 
#include <stdio.h> 
#include <cmath> 
using namespace std;
//парабола
int main() {
	setlocale(LC_ALL, "Rus");
	double a=8, b=12, h, x, s=0, s1, s2, z;
	int n = 200;

	h = (b - a) / (2 * n);
	x = a + 2 * h;
	s1 = 0;
	s2 = 0;
	for (int i = 1; i < n; i++) {


		s2 = s2 +(5 - pow(x, 2));
		x = x + h;
		s1 = s1 +(5 - pow(x, 2));
		x = x + h;




	}
	z = (h / 3) * (5 - pow(a, 2) + 4 * (5 - pow((a + h), 2)) + 4 * s1 + 2 * s2 + (5 - pow(b, 2)));

	cout << "z=" << z << endl;
}