#include <iostream>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "rus");
	int N,M,k=0,b=1,g=0;
	int A[20][20];
	cout << "Введите количество строк матрицы: ";
	cin >> N;
	cout << "Введите количество столбцов матрицы: ";
	cin >> M;
	for (int i = 0; i < N; i++) {
		cout << "=====\n";
		for (int j = 0; j < M; j++) {
			
			cin >> A[i][j];
			if (A[i][j] % 2 == 0) {
				g = A[i][j] / 2;
				if (g % 2 != 0) {
					k += A[i][j];
					b *= A[i][j];
					
				}
			}


		}
	}
	
	cout << "Cумма: " << k <<endl;
	cout << "Произведение: " << b;



}