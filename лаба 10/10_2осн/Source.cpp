#include <iostream>
using namespace std;
//1.	Установить в единицу каждый второй значащий бит целого числа А.//
void zad1() {
	setlocale(LC_CTYPE, "Russian");
	int A, mask = 0xAA; char tmp[33];
	cout << " ВВедите число А: " << endl;
	cin >> A;
	_itoa_s(A, tmp, 2);
	cout << " Число А: " << tmp << endl;
	_itoa_s(mask, tmp, 2);
	cout << " Маска для А: " << tmp << endl;
	_itoa_s(A | mask, tmp, 2);
	cout << " Результат: " << tmp << endl << endl;
}


//2.	Извлечь 3 бита числа А, начиная с позиции n, и вставить в число В, начиная с позиции m	
void zad2() {
	setlocale(LC_CTYPE, "Russian");
	char tmp[33];
	int A, B, maskA, maskB;
	int n, m;
	cout << "Первое число="; cin >> A;
	cout << "Второе число="; cin >> B;
	_itoa_s(A, tmp, 2); cout << "A=" << tmp << endl;
	_itoa_s(B, tmp, 2); cout << "B=" << tmp << endl;
	cout << "ВВедите n:" << endl;
	cin >> n;//n=2
	cout << "ВВедите m:" << endl;
	cin >> m;
	_itoa_s(pow(2, n) - 1, tmp, 2);
	cout << tmp << endl;
	maskA = pow(2, n) - 1;
	_itoa_s(maskA, tmp, 2);
	cout << tmp << endl;
	maskA = maskA >> (n - 3) << (n - 3);
	_itoa_s(maskA, tmp, 2);
	cout << tmp << endl;// 11100011 & 111
	_itoa_s(A & maskA, tmp, 2); // 1 & 0=0 1&1=1 0 & 0=0 0&1=0 
	cout << "Маска А" << endl;//0111
	cout << tmp << endl;
	maskB = ~maskA >> m;//0111>>2 01 = 10
	_itoa_s(B & maskB, tmp, 2);//10011101 10011100
	cout << "Маска B" << endl;
	cout << tmp << endl;
	_itoa_s(((B & maskB) | ((A & maskA) >> m)), tmp, 2);//10011100 0001 =10011101
	cout << "В с изменнёнными битами " << tmp;
}

void main()
{
	zad1();
	zad2();
}