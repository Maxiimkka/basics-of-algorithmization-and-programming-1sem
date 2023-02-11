#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "russian");
	double r, p, q;
	cout << "Введите радиус r = "; cin >> r;
	cout << endl << "Введите  диагональ p = "; cin >> p;
	cout << endl << "Введите  диагональ q = "; cin >> q;
	if (r < sqrt(p / 2 * q / 2))
		cout << endl << "Может";
	else cout << endl << "Не может";
}