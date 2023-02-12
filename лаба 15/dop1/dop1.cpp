#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "russian");
	int a, b;
	char c;
	do
	{
		cout << "Введите число a = "; cin >> a;
		cout << "Введите число b = "; cin >> b;
		cout << "Введите операцию (%, /, +. -. *) : "; cin >> c;
		switch (c)
		{
		case '+': cout << "Ответ: " << a + b; break;
		case '-': cout << "Ответ: " << a - b; break;
		case '%': cout << "Ответ: " << a % b; break;
		case '*': cout << "Ответ: " << a * b; break;
		case '/': cout << "Ответ: " << a*1.0 / b; break;
		}
		cout << endl;
	} while (a > 0);
}