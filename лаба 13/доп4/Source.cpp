#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "¬ведите пор€док квадратной матрицы ";
	cin >> n;

	int Mass[17][17], d = n, k, count = 1, i, j, p;

	for (p = 0; count <= pow(n, 2); p++) {

		for (k = p; k < d; k++)
			Mass[p][k] = count++;

		for (k = p + 1; k < d - 1; k++)
			Mass[k][n - (p + 1)] = count++;

		for (k = n - (p + 1); k >= p; k--)
			Mass[n - (p + 1)][k] = count++;

		for (k = n - (p + 2); k > p; k--)
			Mass[k][p] = count++;

		d--;
	}
	if (n % 2 == 1)
		Mass[n / 2][n / 2] = pow(n, 2);
	cout << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout.width(2);
			cout << Mass[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}