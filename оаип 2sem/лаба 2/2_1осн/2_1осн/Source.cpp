#include <iostream>
#include <string>
using namespace std;

const int MAX_CLIENTS = 100;

union AccountType {
    double interestRate;
    int overdraftLimit;
};

struct BankClient {
    string fullName;
    AccountType accountType;
    int accountNumber;
    double accountBalance;
    string lastModifiedDate;
};

// ������� ��� ����� ������ � �������� ����� � ����������
void inputClients(BankClient clients[], int& count) {
    int n;
    cout << "������� ���������� �������� �����: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "������� ��� �������: ";
        cin >> clients[count].fullName;

        cout << "������� ��� ����� (1 - �������, 2 - ��������): ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << "������� ���������� ������: ";
            cin >> clients[count].accountType.interestRate;
        }
        else if (choice == 2) {
            cout << "������� ����� ����������: ";
            cin >> clients[count].accountType.overdraftLimit;
        }
        else {
            cout << "������������ �����. ����� ����������� ��� ����� �� ���������." << endl;
        }

        cout << "������� ����� �����: ";
        cin >> clients[count].accountNumber;

        cout << "������� ����� �� �����: ";
        cin >> clients[count].accountBalance;

        cout << "������� ���� ���������� ��������� (��.��.����): ";
        cin >> clients[count].lastModifiedDate;

        count++;
    }
}

// ������� ��� ������ ������ � �������� ����� �� �����
void displayClients(BankClient clients[], int count) {
    cout << "������ � �������� �����:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "������ �" << i + 1 << endl;
        cout << "���: " << clients[i].fullName << endl;
        if (clients[i].accountType.interestRate != 0.0 && clients[i].accountType.overdraftLimit == 0) {
            cout << "��� �����: �������" << endl;
            cout << "���������� ������: " << clients[i].accountType.interestRate << endl;
        }
        else if (clients[i].accountType.overdraftLimit != 0) {
            cout << "��� �����: ��������" << endl;
            cout << "����� ����������: " << clients[i].accountType.overdraftLimit << endl;
        }
        cout << "����� �����: " << clients[i].accountNumber << endl;
        cout << "����� �� �����: " << clients[i].accountBalance << endl;
        cout << "���� ���������� ���������: " << clients[i].lastModifiedDate << endl;
        cout << endl;
    }
}

// ������� ��� ������ ������ � �������� ����� �� ������ �����
void searchClients(BankClient clients[], int count) {
    int accountNumber;
    cout << "������� ����� ����� ��� ������: ";
    cin >> accountNumber;
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (clients[i].accountNumber == accountNumber) {
            found = true;
            cout << "������ � ������� � ������� ����� " << accountNumber << ":" << endl;
            cout << "���: " << clients[i].fullName << endl;
            if (clients[i].accountType.interestRate != 0.0) {
                cout << "��� �����: �������" << endl;
                cout << "���������� ������: " << clients[i].accountType.interestRate << endl;
            }
            else if (clients[i].accountType.overdraftLimit != 0) {
                cout << "��� �����: ��������" << endl;
                cout << "����� ����������: " << clients[i].accountType.overdraftLimit << endl;
            }
            cout << "����� �� �����: " << clients[i].accountBalance << endl;
            cout << "���� ���������� ���������: " << clients[i].lastModifiedDate << endl;
            cout << endl;
            break;
        }
    }

    if (!found) {
        cout << "������ � ������� ����� " << accountNumber << " �� ������." << endl;
    }

}

int main() {
    setlocale(LC_CTYPE, "ru");
    BankClient clients[MAX_CLIENTS];
    int count = 0;
    int choice;
    do {
        cout << "�������� ��������:" << endl;
        cout << "1. ���� ������ � �������� �����." << endl;
        cout << "2. ����� ������ � �������� ����� �� �����." << endl;
        cout << "3. ����� ������ � �������� ����� �� ������ �����." << endl;
        cout << "4. �����." << endl;
        cout << "��� �����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            inputClients(clients, count);
            break;
        case 2:
            displayClients(clients, count);
            break;
        case 3:
            searchClients(clients, count);
            break;
        case 4:
            cout << "�� ��������!" << endl;
            break;
        default:
            cout << "������������ �����. ���������� ��� ���." << endl;
        }
    } while (choice != 4);

    return 0;

}
