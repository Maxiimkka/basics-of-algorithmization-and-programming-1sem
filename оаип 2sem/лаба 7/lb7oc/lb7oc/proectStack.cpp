// proectStack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "stack.h"

using namespace std;

void printMenu() {
    cout << "Меню:" << endl;
    cout << "1. Добавить элемент в стек" << endl;
    cout << "2. Извлечь элемент из стека" << endl;
    cout << "3. Вывести верхний элемент стека" << endl;
    cout << "4. Вывести размер стека" << endl;
    cout << "5. Очистить стек" << endl;
    cout << "6. Сохранить стек в файл" << endl;
    cout << "7. Загрузить стек из файла" << endl;
    cout << "8. Проверить наличие последовательности" << endl;
    cout << "9. Выход" << endl;
    cout << "Выберите действие: ";
}

int main() {
    setlocale(LC_CTYPE, "rus");
    Stack stack;
    int choice, value;
    string filename;
    do {
        printMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите значение: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            value = stack.pop();
            if (value != -1) {
                cout << "Извлеченный элемент: " << value << endl;
            }
            break;
        case 3:
            value = stack.peek();
            if (value != -1) {
                cout << "Верхний элемент: " << value << endl;
            }
            break;
        case 4:
            cout << "Размер стека: " << stack.getSize() << endl;
            break;
        case 5:
            stack.clear();
            cout << "Стек очищен." << endl;
            break;
        case 6:
            cout << "Введите имя файла: ";
            cin >> filename;
            stack.saveToFile(filename);
            cout << "Стек сохранен в файл." << endl;
            break;
        case 7:
            cout << "Введите имя файла: ";
            cin >> filename;
            stack.loadFromFile(filename);
            cout << "Стек загружен из файла." << endl;
            break;
        case 8:
            if (stack.hasConsecutiveDuplicates()) {
                cout << "Стек содержит последовательные дубликаты." << endl;
            }
            else {
                cout << "Стек не содержит последовательных дубликатов." << endl;
            }
            break;
        case 9:
            cout << "Выход." << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте еще раз." << endl;
        }
    } while (choice != 9);

    return 0;
}
