#include <iostream>

using namespace std;

///dop8
int main() {
    setlocale(LC_CTYPE, "russian");
    using namespace std;

    int   kol = 0, k, kol1 = 0, size, a[100];

    cout << "введите размер массива ";
    cin >> size;

    for (int i = 0; i < size; i++) {
        cout << "элемент массива= ";
        cin >> a[i];

    }

    for (int i = 0; i < size; i++) {

        for (int y = 0; y < size; y++) {

            if (a[i] > a[y]) {
                kol1 = kol1 + 1;
            }
            if (a[i] < a[y]) {
                kol = kol + 1;
            }

            if (kol1 == kol && kol1 != 0) {
                k = a[i];



            }

        }
        kol = 0;
        kol1 = 0;
    }
    cout << "средний элемент= " << k;
}