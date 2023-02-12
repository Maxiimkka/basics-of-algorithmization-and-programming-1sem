#include <iostream>

using namespace std;
void zad1();
void zad2();

int main(void)
{
    setlocale(LC_CTYPE, "Russian");
    int c;
    do
    {
        cout << endl;
        cout << "Введите" << endl;
        cout << "1-одномерный массив" << endl;
        cout << "2-работа с матрицей" << endl;
        cout << "3-выход" << endl;
        cin >> c;
        switch (c)
        {
        case 1: zad1(); break;
        case 2: zad2(); break;
        case 3: break;
        }
    } while (c != 3);
}




void zad1()
{
  
    int n, count = 0, imin;
    float temp, min = 0, sum = 0;
    cout << "Введите размер массива: ";
    cin >> n;
    float* p = new float(n);
    for (int i = 0; i < n; i++) {
        cout << "элемент массива: ";
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        if (p[i] == 0) {
            count++;
         }
    }
   cout << "Элементы массива = 0: " << count << endl << endl;
   min = p[0];
   for (int i = 0; i < n; i++) {
       if (p[i] < min) {
           min = p[i];
           imin = i;
        }
   }
   cout << "минимальный элемент: " << min << endl;
   cout << "Позиция минимального элемента: " << imin+1 << endl;

   for (int i = imin+1; i < n; i++) {
       sum += p[i];
   }
   cout << "сумма элементов расположенных после минимального: " << sum << endl;
}

void zad2() {
 
    
        int A[20][20], n, m,max = 0, simvol;
        int i, j, t = 0, k, r;
        cout << "введи n,m: ";
        cin >> n >> m;
        
        for (i = 0; i < n; i++){
            for (j = 0; j < m; j++){
                cin >> A[i][j];
            }
        }
           
       

        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
            {
                if (A[i][j] == A[i][j + 1] && j + 1 < m)
                {
                    t++;
                    k = i;
                }
                if (j == m - 1)
                {
                    if (t > max)
                    {
                        max = t;
                        simvol = k;
                        t = 0;
                    }
                }
            }
        cout << "номер строки, в которой находится самая длинная серия одинаковых элементов " << simvol << endl;
    
        for (j = 0; j < m; j++)
            for (i = 0; i < n; i++)
            {
                if (A[i][j] == 0)
                {
                    t++;
                    k = j;
                }
                if (i == n - 1 && r != k)
                {
                    r = k;
                    cout << "Количество столбцов, содержащих хотя бы один нулевой элемент " << k << endl;
                    t = 0;
                }
            }
}


