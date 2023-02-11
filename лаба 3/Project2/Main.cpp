
#include <stdio.h> 
#include <conio.h>
#include <clocale>

void main()

{
	setlocale(LC_CTYPE, "Russian");
	int i, n;
	float cost, p, buf;
	{
		printf("Введите первоначальную стоимость : "); scanf_s("%f", &cost);
		printf("Введите процент p % : "); scanf_s("%f", &p);
		printf("Введите n число лет : "); scanf_s("%u", &n);

		for (int i = 0; i < n; i++)
		{
			printf("Лет %u\n", i + 1);
			buf = cost * p / 100;
			printf("Стоимость за зиму +: %f\n", cost += buf);
			
			printf("Стоимость за лето -: %f\n", cost -= buf);
		}
		printf("Стоимость %u Лет %f", i, cost); 
	} 

}
