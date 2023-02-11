#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");


	int a;
	printf_s("¬ведите a = ");

	scanf_s("%d", &a);

	switch (a) {

	case 1: case 2: case 12:
		printf("«има\n");
		break;
	case 3: case 4: case 5:
		printf("весна\n");
		break;
	case 6: case 7: case 8:
		printf("Ћето\n");
		break;
	case 9: case 10: case 11:
		printf("осень\n");
		break;
	default:
		printf("ошибка\n");
		break;
	}

}