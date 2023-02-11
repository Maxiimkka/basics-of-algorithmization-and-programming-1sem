#include <iostream>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "russian");
	int n, i = 0;
	cout << "¬ведите число=";
	cin >> n;
	int v[4] = { 2, 3, 5, 7 };
	while (i < 4) {
		if (n % v[i] == 0) {
			cout << v[i] << " * ";
			n = n / v[i];
		}
		else {
			i = i + 1;
		}
	}
	if (n != 1)
	{
		cout << n;
	}

}