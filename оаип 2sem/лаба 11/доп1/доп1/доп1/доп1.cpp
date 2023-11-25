#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void generate_numbers(ofstream& file, int a, string current_number) {
    // ���� ������� ����� ��� ����� ����� A, ���������� ��� � ����
    if (current_number.length() == a) {
        file << current_number << endl;
        return;
    }

    // ��������� � �������� ����� ��� ��������� ����� �� 1 �� A
    for (int i = 1; i <= a; i++) {
        string new_number = current_number + to_string(i);
        generate_numbers(file, a, new_number);
    }
}

int main() {
    setlocale(LC_CTYPE, "rus");
    int a;
    cout << "������� ����� A: ";
    cin >> a;

    ofstream file("numbers.txt");
    if (!file) {
        cerr << "�� ������� ������� ���� ��� ������." << endl;
        return 1;
    }

    // ���������� ��� ����� � ���������� �� � ����
    generate_numbers(file, a, "");

    cout << "������. ����� �������� � ���� numbers.txt" <<endl;
    return 0;
}
