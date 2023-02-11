#include<iostream>
#include<math.h>

using namespace std;

//2.1(дихотомия)
int main() {
	setlocale(LC_ALL, "Rus");
	double a = -1, b = 2, e = 0.0001, x;




	while (abs(a - b) > 2 * e) {
		x = (a + b) / 2;


		if (((2 - pow(x, 2) + x) * (2 - pow(a, 2) + a)) < 0) {
			b = x;

		}
		else {
			a = x;
		}

	};
	cout << "x=" << x << endl;
}