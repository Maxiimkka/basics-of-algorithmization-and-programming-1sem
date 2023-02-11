#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	char k, space = ' ';
	cout << "Введите символ ";
	cin >> k;

	cout << setw(3) << setfill(space) << space;
	cout << setw(1) << setfill(k) << k << endl;
	cout << setw(3) << setfill(space) << space;
	cout << setw(1) << setfill(k) << k << endl;
	cout << setw(7) << setfill(k) << k << endl;
	cout << setw(3) << setfill(space) << space;
	cout << setw(1) << setfill(k) << k << endl;
	cout << setw(3) << setfill(space) << space;
	cout << setw(1) << setfill(k) << k << endl;

	cout << endl;

	int n, m = 0;

	cout << "Введите число \n";
	cin >> n;
	while (n != 0)
	{
		m = (m * 10) + n % 10;
		n = n / 10;
	}
	cout << m;




}

