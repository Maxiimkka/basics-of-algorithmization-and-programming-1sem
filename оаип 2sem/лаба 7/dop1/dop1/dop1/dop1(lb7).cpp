#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    cin >> a;

    int half_size = a.size() / 2;
    for (int i = half_size - 1; i >= 0; --i) {
        b += a[i];
    }
    for (int i = a.size() - 1; i >= half_size; --i) {
        b += a[i];
    }

    cout << b << endl;
    return 0;
}