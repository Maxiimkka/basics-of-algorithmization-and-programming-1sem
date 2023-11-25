#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum AccountType {
    SAVINGS,
    CURRENT,
    FIXED_DEPOSIT,
    RECURRING_DEPOSIT
};

struct BankAccount {
    string name;
    AccountType accountType;
    int accountNumber;
    double balance;
    struct {
        unsigned int day : 5;
        unsigned int month : 4;
        unsigned int year : 12;
    } lastModified;
};

vector<BankAccount> accounts;

void addAccount() {
    BankAccount account;
    cout << "Enter name: ";
    getline(cin, account.name);
    cout << "Enter account type (0 - SAVINGS, 1 - CURRENT, 2 - FIXED_DEPOSIT, 3 - RECURRING_DEPOSIT): ";
    int type;
    cin >> type;
    account.accountType = static_cast<AccountType>(type);
    cout << "Enter account number: ";
    cin >> account.accountNumber;
    cout << "Enter balance: ";
    cin >> account.balance;
    cout << "Enter last modified date (dd-mm-yyyy): ";
    unsigned int day, month, year;
    cin >> day >> month >> year;
    account.lastModified.day = day;
    account.lastModified.month = month;
    account.lastModified.year = year;

    accounts.push_back(account);
}

void printAccount(const BankAccount& account) {
    cout << "Name: " << account.name << endl;
    cout << "Account type: " << account.accountType << endl;
    cout << "Account number: " << account.accountNumber << endl;
    cout << "Balance: " << account.balance << endl;
    cout << "Last modified date: " << account.lastModified.day << "-"
        << account.lastModified.month << "-"
        << account.lastModified.year << endl;
}

void printAccounts() {
    for (const auto& account : accounts) {
        printAccount(account);
    }
}

void deleteAccount(int accountNumber) {
    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if (it->accountNumber == accountNumber) {
            accounts.erase(it);
            cout << "Account deleted." << endl;
            return;
        }
    }
    cout << "Account not found." << endl;
}

void searchAccounts(double minBalance, double maxBalance) {
    for (const auto& account : accounts) {
        if (account.balance >= minBalance && account.balance <= maxBalance) {
            printAccount(account);
        }
    }
}

int main() {
    int choice;
    do {
        cout << "1. Add account\n";
        cout << "2. Print accounts\n";
        cout << "3. Delete account\n";
        cout << "4. Search accounts by balance\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            addAccount();
            break;
        case 2:
            printAccounts();
            break;
        case 3: {
            int accountNumber;
            cout << "Enter account number: ";
            cin >> accountNumber;
            deleteAccount(accountNumber);
            break;
        }
        case 4: {
            double minBalance, maxBalance;
            cout << "Enter minimum balance: ";
            cin >> minBalance;
            cout << "Enter maximum balance: ";
            cin >> maxBalance;
            searchAccounts(minBalance, maxBalance);
            break;
        }
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);
    return 0;
}
