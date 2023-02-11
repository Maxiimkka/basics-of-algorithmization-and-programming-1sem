#include <iostream>
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int k;
	puts("Вы играете в хартстоун? (1-да, 2-нет)");
	std::cin >> k;
	switch (k)
	{
	case 1: { puts("Какой ваш любимый персонаж? (1- маг, 2-воин, 3-жрец)");
		std::cin >> k;
		switch (k)
		{
		case 1: puts("Не слабо"); break;
		case 2: puts("Отлично"); break;
		case 3: puts("Супер");break;
		}
		break;
	}
	case 2: puts("очень зря"); break;
	default: puts("Некорректный вариант"); break;
	}
	return 0;
}

