#include <iostream>

using namespace std;

int main()
{
    char s[50], res[100], * a = s, * b = res;
    cin.getline(s, sizeof(s));
    for (; *b = *a; ++a)
    {
        if ('*' != *b)
        {
            *b++ = *a;
            ++b;
        }
    }
    cout << res << endl;
    return 0;
}