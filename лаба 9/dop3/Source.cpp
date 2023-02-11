#include <iostream>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");
    int sz, num = 0;
    cout << "¬ведите sz: ";
    cin >> sz;
    int* a = new int[sz];
    for (int i = 0; i < sz; i++)
    {
        cout << "¬ведите элементы массива =";
        cin >> a[i];
    }
    for (int i = 0; i < sz; i++) {
        if (a[i] = a[i + 1]) {
            num++;
        }
       
    cout << "количество пар соседних элементов массива с одинаковыми значени€ми =" << num;
}