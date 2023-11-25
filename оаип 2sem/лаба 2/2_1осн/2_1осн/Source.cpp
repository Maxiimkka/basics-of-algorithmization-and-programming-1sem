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

// функция для ввода данных о клиентах банка с клавиатуры
void inputClients(BankClient clients[], int& count) {
    int n;
    cout << "Введите количество клиентов банка: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Введите ФИО клиента: ";
        cin >> clients[count].fullName;

        cout << "Введите тип счета (1 - срочный, 2 - льготный): ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << "Введите процентную ставку: ";
            cin >> clients[count].accountType.interestRate;
        }
        else if (choice == 2) {
            cout << "Введите лимит овердрафта: ";
            cin >> clients[count].accountType.overdraftLimit;
        }
        else {
            cout << "Некорректный выбор. Будет использован тип счета по умолчанию." << endl;
        }

        cout << "Введите номер счета: ";
        cin >> clients[count].accountNumber;

        cout << "Введите сумму на счете: ";
        cin >> clients[count].accountBalance;

        cout << "Введите дату последнего изменения (ДД.ММ.ГГГГ): ";
        cin >> clients[count].lastModifiedDate;

        count++;
    }
}

// функция для вывода данных о клиентах банка на экран
void displayClients(BankClient clients[], int count) {
    cout << "Данные о клиентах банка:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "Клиент №" << i + 1 << endl;
        cout << "ФИО: " << clients[i].fullName << endl;
        if (clients[i].accountType.interestRate != 0.0 && clients[i].accountType.overdraftLimit == 0) {
            cout << "Тип счета: срочный" << endl;
            cout << "Процентная ставка: " << clients[i].accountType.interestRate << endl;
        }
        else if (clients[i].accountType.overdraftLimit != 0) {
            cout << "Тип счета: льготный" << endl;
            cout << "Лимит овердрафта: " << clients[i].accountType.overdraftLimit << endl;
        }
        cout << "Номер счета: " << clients[i].accountNumber << endl;
        cout << "Сумма на счете: " << clients[i].accountBalance << endl;
        cout << "Дата последнего изменения: " << clients[i].lastModifiedDate << endl;
        cout << endl;
    }
}

// функция для поиска данных о клиентах банка по номеру счета
void searchClients(BankClient clients[], int count) {
    int accountNumber;
    cout << "Введите номер счета для поиска: ";
    cin >> accountNumber;
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (clients[i].accountNumber == accountNumber) {
            found = true;
            cout << "Данные о клиенте с номером счета " << accountNumber << ":" << endl;
            cout << "ФИО: " << clients[i].fullName << endl;
            if (clients[i].accountType.interestRate != 0.0) {
                cout << "Тип счета: срочный" << endl;
                cout << "Процентная ставка: " << clients[i].accountType.interestRate << endl;
            }
            else if (clients[i].accountType.overdraftLimit != 0) {
                cout << "Тип счета: льготный" << endl;
                cout << "Лимит овердрафта: " << clients[i].accountType.overdraftLimit << endl;
            }
            cout << "Сумма на счете: " << clients[i].accountBalance << endl;
            cout << "Дата последнего изменения: " << clients[i].lastModifiedDate << endl;
            cout << endl;
            break;
        }
    }

    if (!found) {
        cout << "Клиент с номером счета " << accountNumber << " не найден." << endl;
    }

}

int main() {
    setlocale(LC_CTYPE, "ru");
    BankClient clients[MAX_CLIENTS];
    int count = 0;
    int choice;
    do {
        cout << "Выберите действие:" << endl;
        cout << "1. Ввод данных о клиентах банка." << endl;
        cout << "2. Вывод данных о клиентах банка на экран." << endl;
        cout << "3. Поиск данных о клиентах банка по номеру счета." << endl;
        cout << "4. Выход." << endl;
        cout << "Ваш выбор: ";
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
            cout << "До свидания!" << endl;
            break;
        default:
            cout << "Некорректный выбор. Попробуйте еще раз." << endl;
        }
    } while (choice != 4);

    return 0;

}
