#include <iostream>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "RUS");
	int  n;
	double C[100] = {};
	cout << "Введите количество элементов n=";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> C[i];
		

	}
	for (int i = 0; i < n; i++) {
		if (i % 3 == 0) {
			C[i + 2] = (C[i] + C[i + 1]) / 2;
		}
		cout << C[i] << endl;
	}
	
	
}