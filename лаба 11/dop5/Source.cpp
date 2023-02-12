#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "RUS");
    int a[100] = {}, n, l = 0, p = 0;


    cout << "¬ведите кол-во чисел n=";
    cin >> n;
    cout << "¬вод чисел :" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {

        for (int u = 0; u < n; u++) {
            if (u != i) {
                if (a[i] == a[u])
                {
                    p = p + 1;
                }
            }

        }
        if (p == 0) {
            l = l + 1;
        }
        p = 0;
    }
    cout << "неповтор€ющие эелементы=" << l;

}
