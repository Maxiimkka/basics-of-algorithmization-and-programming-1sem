#include <iostream>
using namespace std;
int main() { 
    int x, y, z;
    cin >> x >> y >> z;

    if (z < y) {
        z -= y;
        y += z;
        z = y - z;
    }

    if (y < x) {
        y -= x;
        x += y;
        y = x - y;
    }

    if (z < x) {
        z -= x;
        x += z;
        z = x - z;
    }

    cout << x << ' ' << y << ' ' << z << endl;

	

	
		
}
