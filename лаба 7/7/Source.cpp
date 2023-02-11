#include <iostream>

using namespace std;

int main() {
    double  w, n=5, a = 1.5, b = -4.15, v[5] = { 1, 1.5 , -4, -1.9, 3 };
   
    for (int i = 0; i < n; i++) {
        if (v[i] <= 0) {
            w = b / v[i];

        }
        else {
            w = a + v[i];

        }
        cout << w << endl;
    }
       
    
    

   
}