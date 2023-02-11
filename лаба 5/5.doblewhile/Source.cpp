#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "russian");
    double  i , c, d, y , k = 6;
    for (int n = 1; n <= 3; n++)
    {
        double x = 1;
        cout << "¬ведите y = ";  cin >> y;
        cout << "¬ведите i = ";  cin >> i;
        do
        {           
            c = i / k - sqrt(y) / 0.4;
            d = exp(1 - c) + 4.9 * (pow(x, 2) + 1);
            cout << "c = " << c << endl;
            cout << "d = " << d << endl;

            x = x + 0.1;
        } while (x <= 2);
    }
}