#include <iostream>
#include <windows.h>
using namespace std;
char* fnc(char* arr)
{

	int word = 0;
	for (int i = 0; i < strlen(arr); i++) {
		if (i == 0) {
			while (*(arr + i) == '*') {
				i++;
			}

		}

		else if (*(arr + i) == '*') {
			word = *(arr + i - 1);
			while (*(arr + i) == '*') {
				*(arr + i) = word;
			}
		}
		cout << *(arr + i);
	}


	return 0;


}
void main()
{
	const int N = 100;
	char str[N];
	int i, next, l;
	printf("enter text: ");
	gets_s(str);


	*fnc(str);

}
