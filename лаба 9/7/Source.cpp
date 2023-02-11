#include <iostream>

using namespace std;
//7dop
int main() {
	setlocale(LC_CTYPE, "RUS");
	int n;
	double x[100] = {}, max = 0, min = 0, m = 1, b = 1;
	cout << "¬ведите количество элементов n=";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "¬ведите элемент ";
		cin >> x[i];

		if (x[i] < 0) {
			while (m == 1)
			{
				min = x[i];
				m = 0;
			}
			if (min < x[i]) {
				min = x[i];
			}
		}


		if (x[i] > 0) {
			while (b == 1) {
				max = x[i];
				b = 0;
			}
			if (max < x[i]) {
				max = x[i];
			}
		}

	}
	if (max != 0) {
		cout << "максимальный положительный элемент=" << max << endl;
	}
	else {
		cout << "положительные отсутствуют" << endl;
	}
	if (min != 0) {
		cout << "максимальный отрицательный элемент=" << min;
	}
	else {
		cout << "отрицательные отсутствуют" << endl;
	}

}