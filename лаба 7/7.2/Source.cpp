#include <iostream>

using namespace std;

int main() {
    double a, n=6,  d =5.5e-4, x[6] = { 0.7, 6 , -7, 9, -4, 1 };

    for (int i = 0; i < n; i++) {
        a = (exp(-x[i]) * sin(x[i])) / (sqrt(d + cos(x[i])));
        cout << a << endl;
    }

}