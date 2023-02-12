#include <iostream>
#include <string>
using namespace std;
void main()
{
	setlocale(0, "");
	string s; long n, i = 0, k;
	cout << "Введите строку : ";
	cin >> s;
	n = s.size();
	while (i <= n)
	{
		if (s[i] == '(') break;
		cout << s[i];
		i++;
	}
	k = i;
	while (i <= n)
	{
		i++;
		if (s[i] == ')') break;
	}
	i++;
	while (i <= n)
	{
		cout <<"строка: "<< s[i];
		i++;
	}
}