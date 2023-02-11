#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "rus");
	double a=0, b=1, i, x, n,l=0,k=0;
	cout << "Введите повторы  n= ";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << "Введите число x=";
		cin >> x;
		if (x >= 0)
		{
			a += x;
			k = 1;
		}
		else {
			b *= x;
			l = 1;
		}
	}
	if (n > 0) {
		if (k == 0) {
			cout << "нету положительных чисел" << endl;
		}
		else cout << a << endl;
		
		if (l == 0) {
			cout << "нету отрицательных чисел";
		}
		else cout << b;
		
	}
	else cout << "Неправильное значение";
}