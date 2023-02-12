#include <iostream>
#include <conio.h>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    int n;
    cout << "¬ведите пор€док квадратной матрицы: ";
    cin >> n;

    int** arr = new int* [n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[n];

    cout << "¬ведите а1, а2, ... , a" << n << " : ";

    for (int i = 0; i < n; i++)
        cin >> arr[0][i];

    for (int i = 1; i < n; i++)
        for (int j = 0; j < n; ++j)
            arr[i][j] = arr[i - 1][(j + 1) % n];

    cout << "¬веденный массив: " << endl;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout <<  arr[i][j];
        }
        cout << endl;
    }

}