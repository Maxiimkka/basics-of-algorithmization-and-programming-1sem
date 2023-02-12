#include <iostream>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    int  n, m,max=0,k=0;
    cout << "Введите размер массива A = ";
    cin >> n;
    double* A = new double(n);
    for (int i = 0; i < n; i++) {
        cout << "элемент массива А ";
        cin >> A[i];
    }
    cout << "Введите размер массива B = ";
    cin >> m;
    double* B = new double(m);
    for (int i = 0; i < m; i++) {
        cout << "элемент массива В ";
        cin >> B[i];
    }
    for (int i = 0; i < n; i++) {
        if (A[0]<A[i]) {
            A[i] = max;
        }
    }
    for (int i = 0; i < m; i++) {
        if (B[i] == max) {
            cout << "Наибольший элемент массива A содержится в массиве В";
            k = 1;
            i = m;
        }
    }
    if (k == 0) {
        cout << "Наибольший элемент массива A не содержится в массиве В";
        }
    


}