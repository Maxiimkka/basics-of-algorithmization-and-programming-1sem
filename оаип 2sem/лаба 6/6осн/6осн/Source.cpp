#include <iostream>
#include <fstream>

using namespace std;

// ��������� ��� �������� ������
struct Node {
    char data;
    Node* next;
};

// ����� ��� ������
class List {
private:
    Node* head;

public:
    // �����������
    List() {
        head = NULL;
    }

    // ������� ��� ���������� �������� � ����� ������
    void append(char data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // ������� ��� �������� �������� �� ������
    void remove(char data) {
        if (head == NULL) {
            return;
        }

        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != NULL && current->next->data != data) {
            current = current->next;
        }
        if (current->next != NULL) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    // ������� ��� ������ �������� � ������
    Node* search(char data) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == data) {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }

    // ������� ��� ������ ������ � ���������� ����
    void print() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // ������� ��� ������ ������ � ����
    void writeToFile(string filename) {
        ofstream file(filename.c_str());
        if (!file.is_open()) {
            return;
        }

        Node* current = head;
        while (current != NULL) {
            file << current->data << " ";
            current = current->next;
        }

        file.close();
    }

    // ������� ��� ���������� ������ �� �����
    void readFromFile(string filename) {
        ifstream file(filename.c_str());
        if (!file.is_open()) {
            return;
        }

        char data;
        while (file >> data) {
            append(data);
        }

        file.close();
    }

    // ������� ��� ������ ������� � ������ ������� � ����������
    void findAndPrint(char data) {
        Node* current = search(data);
        if (current != NULL && current->next != NULL) {
            cout << current->data << " " << current->next->data << endl;


        }
        else {
            cout << "������ �� ������ ��� ���������� ������� ���." << endl;
        }
    }
};

int main() {
    List list;
    int choice;
    char data;
    setlocale(LC_CTYPE, "ru");

    do {
        cout << "����:" << endl;
        cout << "1. �������� �������" << endl;
        cout << "2. ������� �������" << endl;
        cout << "3. ����� �������" << endl;
        cout << "4. ������� ������ � ���������� ����" << endl;
        cout << "5. �������� ������ � ����" << endl;
        cout << "6. ������� ������ �� �����" << endl;
        cout << "7. ����� ������ � ������� ������ � ���������" << endl;
        cout << "8. �����" << endl;
        cout << "�������� ��������: ";
        cin >> choice;
        string filename;
        switch (choice) {
        case 1:
            cout << "������� ������: ";
            cin >> data;
            list.append(data);
            break;

        case 2:
            cout << "������� ������: ";
            cin >> data;
            list.remove(data);
            break;

        case 3:
            cout << "������� ������: ";
            cin >> data;
            if (list.search(data) != NULL) {
                cout << "������ ������." << endl;
            }
            else {
                cout << "������ �� ������." << endl;
            }
            break;

        case 4:
            list.print();
            break;

        case 5:
            cout << "������� ��� �����: ";
            
            cin >> filename;
            list.writeToFile(filename);
            break;

        case 6:
            cout << "������� ��� �����: ";
            cin >> filename;
            list.readFromFile(filename);
            break;

        case 7:
            cout << "������� ������: ";
            cin >> data;
            list.findAndPrint(data);
            break;

        case 8:
            cout << "����� �� ���������." << endl;
            break;

        default:
            cout << "������������ �����." << endl;
            break;
        }

    } while (choice != 8);

    return 0;
}