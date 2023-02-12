#include <iostream>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "rus");
	double n, k = 1, kmax = 0, a[100] = {};
	cout << "Введите количество элементов";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		while (a[i] == a[i + 1]) {
			k++;
			i++;
		}
		if (k > kmax) {
			kmax = k;
		}
		k = 1;
	}
	cout << "Найбольшее количество=" << kmax;
}
