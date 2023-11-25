#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum AccountType {
    SAVINGS,
    CHECKING,
    MONEY_MARKET
};

union Account {
    double amount;
    int number;
    AccountType type;
};

struct Client {
    string fullName;
    Account account;
    string lastModified;
};

void inputClient(Client& client) {
    cout << "Enter client's full name: ";
    getline(cin, client.fullName);

    cout << "Enter account type (0 for savings, 1 for checking, 2 for money market): ";
    int type;
    cin >> type;
    client.account.type = static_cast<AccountType>(type);

    cout << "Enter account number: ";
    cin >> client.account.number;

    cout << "Enter account balance: ";
    cin >> client.account.amount;

    cout << "Enter date of last modification (dd.mm.yyyy): ";
    cin >> client.lastModified;
}

void outputClient(const Client& client) {
    cout << "Full name: " << client.fullName << endl;
    cout << "Account type: ";
    switch (client.account.type) {
    case SAVINGS:
        cout << "Savings" << endl;
        break;
    case CHECKING:
        cout << "Checking" << endl;
        break;
    case MONEY_MARKET:
        cout << "Money market" << endl;
        break;
    }
    cout << "Account number: " << client.account.number << endl;
    cout << "Account balance: " << client.account.amount << endl;
    cout << "Last modified: " << client.lastModified << endl;
}

int findClientByAccountNumber(const vector<Client>& clients, int accountNumber) {
    for (int i = 0; i < clients.size(); ++i) {
        if (clients[i].account.number == accountNumber) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<Client> clients;
    int choice;
   
     do {
       
        cout << "1. Add client" << endl;
        cout << "2. Print all clients" << endl;
        cout << "3. Find client by account number" << endl;
        cout << "4. Exit" << endl;

        cout << "enter your choice" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            Client client;
            cin.ignore();
            inputClient(client);
            clients.push_back(client);
            break;

        case 2:
            for (const auto& client : clients) {
                outputClient(client);
                cout << endl;
            }
            break;

        case 3:
            int accountNumber;
            cout << "Enter account number: ";
            cin >> accountNumber;
            int index = findClientByAccountNumber(clients, accountNumber);
            if (index != -1) {
                outputClient(clients[index]);
            }
            else {
                cout << "Client with account number " << accountNumber << " not found." << endl;
            }
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    } while (choice != 4);
    

    
}
