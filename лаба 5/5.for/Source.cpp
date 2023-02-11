#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "russian");
    float i, c, d, y=1.6e-4, x=-1, k=6;
    for (int n = 1; n <= 3; n++)
    {
        cout << "¬ведите i = ";  cin >> i;
        c = i / k - sqrt(y) / 0.4;
        d = exp(1 - c) + 4.9 * (pow(x, 2) + 1);
        cout << "c = " << c << endl;
        cout << "d = " << d << endl;
    }
}