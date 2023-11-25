#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void generate_numbers(ofstream& file, int a, string current_number) {
    // Если текущее число уже имеет длину A, записываем его в файл
    if (current_number.length() == a) {
        file << current_number << endl;
        return;
    }

    // Добавляем к текущему числу все возможные цифры от 1 до A
    for (int i = 1; i <= a; i++) {
        string new_number = current_number + to_string(i);
        generate_numbers(file, a, new_number);
    }
}

int main() {
    setlocale(LC_CTYPE, "rus");
    int a;
    cout << "Введите число A: ";
    cin >> a;

    ofstream file("numbers.txt");
    if (!file) {
        cerr << "Не удалось открыть файл для записи." << endl;
        return 1;
    }

    // Генерируем все числа и записываем их в файл
    generate_numbers(file, a, "");

    cout << "Готово. Числа записаны в файл numbers.txt" <<endl;
    return 0;
}
