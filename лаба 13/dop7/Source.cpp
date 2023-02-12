#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    const int SIZE = 5;
    int A[SIZE][SIZE];
    int i, j;
    int nad, pod, k, p, sum, max;
    srand((unsigned)time(NULL));
    for (i = 0; i < SIZE; ++i)
    {
        for (j = 0; j < SIZE; ++j)
        {
            A[i][j] = rand() % 10;
        }

    }
    for (i = 0; i < SIZE; ++i)
    {
        for (j = 0; j < SIZE; ++j)
        {
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }
    k = 0; nad = 0; p = SIZE; max = 0;
    cout << " сумма верхней части: ";
    for (i = 0; i < SIZE; i++)
    {
        for (j = k; j < SIZE; j++)
        {
            nad = nad + A[i][j];
            if (A[i][j] > max)
            {
                max = A[i][j];
            }

        }
        k++;
        p--;
    }
    cout << nad << endl;
    k = SIZE; pod = 0; p = 0;
    cout << " сумма нижней части: ";
    for (i = 0; i < SIZE; i++)
    {
        for (j = k; j > p; j--)
        {
            pod = pod + A[i][j];
            if (A[i][j] > max)
            {
                max = A[i][j];
            }
        }
        k--;
        p++;
    }
    cout << pod << endl;
    sum = pod + nad - A[SIZE / 2][SIZE / 2];
    cout << "сумма заштрихованной части: ";
    cout << sum << endl;
    cout << "максимальное значение: ";
    cout << max;
}