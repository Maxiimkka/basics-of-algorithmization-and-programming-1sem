#include <iostream>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "rus");
	int N, M, k, max = 0, min = 0,m = 1, b = 1,imin =0,imax =0,jmin =0,jmax =0;
	int A[20][20];
	cout << "¬ведите количество строк матрицы: ";
	cin >> N;
	cout << "¬ведите количество столбцов матрицы: ";
	cin >> M;
	for (int i = 0; i < N; i++) {
		cout << "=====\n";
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
				while (m == 1)
				{
					min = A[i][j];
					m = 0;
				}
				if (min > A[i][j]) {
					min = A[i][j];
					imin = i;
					jmin = j;
				}
		
				while (b == 1) {
					max = A[i][j];
					b = 0;
				}
				if (max < A[i][j]) {
					max = A[i][j];
					imax = i;
					jmax = j;
				}	   
		}
	}
	k = A[imin][jmin];
	A[imin][jmin] = A[imax][jmax];
	A[imax][jmax] = k;

	cout << "изменЄнна€ матрица:\n";
	for (int i = 0; i < N; i++) {
		cout << "=====\n";
		for (int j = 0; j < M; j++) {
			cout << A[i][j] << endl;
		}
	}
}