#include <iostream>
#include <cmath>

using namespace std;

int numsq(int a, int b) {
    if (b == 0) {
        return 0;
    }
    int count = a / b;
    int new_a = b;
    int new_b = a - count * b;
    return count + numsq(new_a, new_b);
}

int main() {
    setlocale(LC_CTYPE, "rus");
    int a, b;
    cout << "Введите a и b:";
    cin >> a >> b;
    int result = numsq(a, b);
    cout << "Необходимое количество квадратов равно:" << result << endl;
    return 0;
}
