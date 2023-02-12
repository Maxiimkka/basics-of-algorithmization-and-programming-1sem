#include <iostream>
#include <vector>

using namespace std;

// Функция, которая уменьшает все элементы столбца в матрице вдвое
void halveColumn(vector<vector<int>>& matrix, int col) {
    for (int i = 0; i < matrix.size(); i++) {
        matrix[i][col] /= 2;
    }
}

int main() {
    // Считываем размеры матрицы
    int n, m;
    cin >> n >> m;

    // Создаем динамический двумерный массив
    vector<vector<int>> matrix(n, vector<int>(m));

    // Считываем элементы матрицы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    // Проходим по строкам матрицы
    for (int i = 0; i < n; i++) {
        // Проверяем, все ли элементы строки равны нулю
        bool allZeros = true;
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {
                allZeros = false;
                break;
            }
        }

        // Если все элементы строки равны нулю, то уменьшаем все элементы столбца
        // вдвое и завершаем работу цикла
        if (allZeros) {
            halveColumn(matrix, i);
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
