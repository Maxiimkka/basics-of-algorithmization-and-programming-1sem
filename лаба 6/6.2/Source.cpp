#include <iostream>
#include <stdio.h>

using namespace std;

int main() 
{
	setlocale(LC_CTYPE, "rus");
	int n;
	cout << "¬ведите n="; cin >> n;

	for (int i = 1; i <= n; i++) {
		cout << "i=" << i*2*3*5 << endl;
	}
}
		
				
	
	
