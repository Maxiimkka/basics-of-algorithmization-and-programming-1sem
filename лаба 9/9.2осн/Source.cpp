#include <iostream>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "rus");
	int  n;
	double C[100] = {};
	cout << "Введите количество элементов n=";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> C[i];
    
	}
	cout << "====" << endl;
	int min = C[0];
	for (int i = 0; i < n; i++) {

		if (min > C[i]) {
			min = C[i];
		}
		
	}
	for (int i = 0; i < n; i++) {
		cout << C[i] << endl;

	}
	for (int i = 0; i < n; i++) {
		if (C[i] == min) {
			for (int k = i; k < n; k++) {
				C[k] = C[k + 1];
			}
			n--;		
		}
	}
	cout << "===="<<endl;
	for (int i = 0; i < n; i++) {
		cout << C[i] << endl;

	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += C[i];
	}
	sum = sum / n;
	for (int i = n; i >= 0; i--) {
		
		C[i - 3] = C[i];
	}
	n += 3;
	cout << "===="<<endl;
		for (int i = 0; i < n; i++) {
			cout << C[i] << endl;

		}
		for (int i = 0; i < 3; i++) {
			C[i] = sum;
		}
		cout << "====" << endl;
		for (int i = 0; i < n; i++) {
			cout << C[i] << endl;

		}
}