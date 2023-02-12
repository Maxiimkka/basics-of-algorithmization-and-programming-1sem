#include <iostream>
#include <cmath>
#include <stdarg.h>

using namespace std;

int kvadr(int num_args, ...) {
    // Объявление переменной типа va_list
    va_list args;

    // Инициализация va_list с первым аргументом num_args
    va_start(args, num_args);

    // Переменная для хранения результата
    int count = 0;

    // Перебор аргументов
    for (int i = 0; i < num_args; i++) {
        // Получение текущего аргумента
        int arg = va_arg(args, int);

        // Проверка, является ли число точным квадратом
        int sqrt_arg = sqrt(arg);
        if (sqrt_arg * sqrt_arg == arg) {
            count++;
        }
    }

    // Очистка va_list
    va_end(args);

    return count;
}

int main() {
    // Три обращения к функции с различным количеством параметров
    cout << kvadr(5, 2, 4, 9, 16, 25) << endl;
    cout << kvadr(3, 1, 4, 9) << endl;
    cout << kvadr(4, 2, 4, 9, 16) << endl;


    return 0;
}