#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	for (int n = 10; n <= 31; n++) {
		if (((n % 2 == 0) || (n % 3 == 0) || (n % 5 == 0) || (n % 7 == 0)) == false) {
			int num = n * n;
			a = num % 10;
			num = num / 10;
			b = num % 10;
			num = num / 10;
			c = num % 10;
			if ((a > b) && (b > c)) {
				cout << n * n << endl;

			}
		}
	}
}