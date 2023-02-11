#include <iostream>;
#include <math.h>;

using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");
     float p , q,  j=5,  m=4, y=1.4e-3, x=0.2;
   while(j<=11) {

        p = exp(sin(j / x)) * log(x / y) * x;
       
        j = j + 2;
        if (p <= pow(y, 2)) {
            q = sqrt(p / m);
        }
        if (p > pow(y, 2)) {
            q = sqrt(2*x) / (j + p);
        }
        cout << "p=" << p << endl;

        cout << "q=" << q << endl;
    }
}
