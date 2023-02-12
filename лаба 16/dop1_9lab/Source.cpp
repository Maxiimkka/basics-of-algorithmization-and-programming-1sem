#include <iostream>
#include <iomanip>
#include <stdio.h>

int main() {
    setlocale(LC_CTYPE, "Russian");
    using namespace std;
    int x[50], n, k, sum = 0, l = 0, s[50];
    cout << "Неделя 1: ";
    for (int i = 0; i < 7; i++)
    {
        x[i] = rand() % 10;
        sum += x[i];
    }
    s[l] = sum;
    cout << s[l] << endl;
    l++;
    sum = 0;
    cout << "Неделя 2: ";
    for (int i = 0; i < 7; i++)
    {
        x[i] = rand() % 10;
        sum += x[i];
    }
    s[l] = sum;
    cout << s[l] << endl;
    l++;
    sum = 0;
    cout << "Неделя 3: ";
    for (int i = 0; i < 7; i++)
    {
        x[i] = rand() % 10;
        sum += x[i];
    }
    s[l] = sum;
    cout << s[l] << endl;
    l++;
    sum = 0;
    cout << "Неделя 4: ";
    for (int i = 0; i < 7; i++)
    {
        x[i] = rand() % 10;
        sum += x[i];
    }
    s[l] = sum;
    cout << s[l] << endl;
    int max = 0;
    for (int i = 0; i < l; i++)
    {
        if (s[i] > max)
        {
            max = s[i];
        }
    }
    cout << "Максимальное количество осадков: " << max;
}