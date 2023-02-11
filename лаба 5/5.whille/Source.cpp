#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "russian");
    double i = 0, c, d, y = 1.6e-4, x = -1, k = 6;

    while (i <= 3)
    {
        cout << "Äëÿ i = " << i << endl;
        c = i / k - sqrt(y) / 0.4;
        d = exp(1 - c) + 4.9 * (pow(x, 2) + 1);
        cout << "c = " << c << endl;
        cout << "d = " << d << endl;
        i = i + 0.5;
    } 
}