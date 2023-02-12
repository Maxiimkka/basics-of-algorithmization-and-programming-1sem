#include <iostream>
using namespace std;

int sum(int n) {
    int s = 0;
    do {
        s = s + n % 10;
        n = n / 10;
    } while (n > 1);
    return s;
}

void main()
{
    int a, b;
    setlocale(LC_CTYPE, "russian");
    a = sum(9);
    for (int i = 9; i < 1000000; i = i + 10) {
        b = sum(i + 1);
        if (a % 7 == 0 && b % 7 == 0) {
            cout << "Визучие билеты идущие подрят, так сказать 'Везение x2': " << i << "," << i + 1 << endl;
        }
        else a = b;
    }

}