#include <iostream>


using namespace std;

int main(void)
{
	setlocale(LC_CTYPE, "rus");
	char s[100]; 
	char a[10][100];
	int cnt = 0;
	int cnti = 0;
	int i, j, palindrom, maxpalindrom, index;

	printf("Ввод строки: \n");
	gets_s(s);
	maxpalindrom = 0;
	index = -1;
	for (i = 0; s[i] != 0; i++)
	{
		if (s[i] == ' ')
		{
			if (cnti != 0)
			{
				a[cnt][cnti] = 0;
				// проверка на палиндром
				palindrom = 1;
				for (j = 0; j < (cnti - 1) / 2; j++)
				{
					if (a[cnt][j] != a[cnt][cnti - 1 - j]) { palindrom = 0; break; }
				}
				if (palindrom == 1) if (maxpalindrom < cnti - 1) { maxpalindrom = cnti - 1; index = cnt; }
				cnt++; cnti = 0;
			}
		}
		else { a[cnt][cnti++] = s[i]; }
	}
	if (cnti != 0) { a[cnt][cnti] = 0; }

	// Вывод всех слов на англ
	for (i = 0; i < cnt; i++)
	{
		printf("%s\n", a[i]);
	};

	if (index != -1)
		printf("%s%s\n", "Максимальный полендром: ", a[index]);
	else printf("%s\n", "Нет полиндромов");

	
}
