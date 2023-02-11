#include <iostream>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");
    int sz, min = 0, max = 0, num = 0;
    cout << "¬ведите sz: ";
    cin >> sz;
   
    int* a = new int[sz]; 
  
    for (int i = 0; i < sz; i++)
    {
        cout << "¬ведите элементы массива =";
        cin >> a[i];
       
        if (a[min] < a[i])
            min = i;
        if (a[max] > a[i])
            max = i;
    }

    

    int* b = new int[sz];
    for (int i = 0; i <max; i++)
        b[num++] = a[i];
    for (int i = min; i >= max; i--)
        b[num++] = a[i];
   
    for (int i = 0; i < sz; i++)
        cout << b[i] << " ";
}