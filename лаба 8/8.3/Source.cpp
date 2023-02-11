#include<iostream>
#include<math.h>
using namespace std;
//(трапеции)
int main() {
	setlocale(LC_ALL, "Rus");
	double a=8, y, b=12, n, h, x, s;
	x = a;
	s = 0;
	h = (b - a) / n;
	y = b - h;
	while (x < y) {
		s = s + abs(h * ((5 - pow(x, 2)) + (5 - pow((a + h), 2)))) / 2;
		x = x + h;
		y = b - h;
	}

	cout << "y=" << y << endl;
}