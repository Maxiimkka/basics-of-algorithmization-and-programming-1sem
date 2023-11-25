// proectStack.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//

#include <iostream>
#include "stack.h"

using namespace std;

void printMenu() {
    cout << "����:" << endl;
    cout << "1. �������� ������� � ����" << endl;
    cout << "2. ������� ������� �� �����" << endl;
    cout << "3. ������� ������� ������� �����" << endl;
    cout << "4. ������� ������ �����" << endl;
    cout << "5. �������� ����" << endl;
    cout << "6. ��������� ���� � ����" << endl;
    cout << "7. ��������� ���� �� �����" << endl;
    cout << "8. ��������� ������� ������������������" << endl;
    cout << "9. �����" << endl;
    cout << "�������� ��������: ";
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
            cout << "������� ��������: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            value = stack.pop();
            if (value != -1) {
                cout << "����������� �������: " << value << endl;
            }
            break;
        case 3:
            value = stack.peek();
            if (value != -1) {
                cout << "������� �������: " << value << endl;
            }
            break;
        case 4:
            cout << "������ �����: " << stack.getSize() << endl;
            break;
        case 5:
            stack.clear();
            cout << "���� ������." << endl;
            break;
        case 6:
            cout << "������� ��� �����: ";
            cin >> filename;
            stack.saveToFile(filename);
            cout << "���� �������� � ����." << endl;
            break;
        case 7:
            cout << "������� ��� �����: ";
            cin >> filename;
            stack.loadFromFile(filename);
            cout << "���� �������� �� �����." << endl;
            break;
        case 8:
            if (stack.hasConsecutiveDuplicates()) {
                cout << "���� �������� ���������������� ���������." << endl;
            }
            else {
                cout << "���� �� �������� ���������������� ����������." << endl;
            }
            break;
        case 9:
            cout << "�����." << endl;
            break;
        default:
            cout << "�������� �����. ���������� ��� ���." << endl;
        }
    } while (choice != 9);

    return 0;
}
