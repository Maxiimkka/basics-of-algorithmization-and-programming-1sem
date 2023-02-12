#include <iostream>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    int  n, k, l = 0;
    bool f = false;
    cout << "Введите размер массива x = ";
    cin >> n;
    int* x = new int(n);
    for (int i = 0; i < n; i++) {
        cout << "элемент массива x  ";
        cin >> x[i];
    }
    cout << "Введите размер массива y = ";
    cin >> k;
    int* y = new int(k);
    for (int i = 0; i < k; i++) {
        cout << "элемент массива y  ";
        cin >> y[i];
    }
    for (int i = 0; i < k;) {
        for (int u = l; u < n; u++) {
            if (x[u] == y[i]) {
                i++;
                l = u;
            }
        }
        if (i == k) {
            f = true;
        }
    }
    if (f == true) {
        cout << "y является подпоследовательностью x";
    }
    else {
        cout << "y не является подпоследовательностью x";
    }
}