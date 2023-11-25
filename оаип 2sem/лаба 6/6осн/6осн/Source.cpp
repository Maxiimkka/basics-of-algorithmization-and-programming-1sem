#include <iostream>
#include <fstream>

using namespace std;

// структура для элемента списка
struct Node {
    char data;
    Node* next;
};

// класс для списка
class List {
private:
    Node* head;

public:
    // конструктор
    List() {
        head = NULL;
    }

    // функция для добавления элемента в конец списка
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

    // функция для удаления элемента из списка
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

    // функция для поиска элемента в списке
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

    // функция для вывода списка в консольное окно
    void print() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // функция для записи списка в файл
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

    // функция для считывания списка из файла
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

    // функция для поиска символа и вывода символа и следующего
    void findAndPrint(char data) {
        Node* current = search(data);
        if (current != NULL && current->next != NULL) {
            cout << current->data << " " << current->next->data << endl;


        }
        else {
            cout << "Символ не найден или следующего символа нет." << endl;
        }
    }
};

int main() {
    List list;
    int choice;
    char data;
    setlocale(LC_CTYPE, "ru");

    do {
        cout << "Меню:" << endl;
        cout << "1. Добавить элемент" << endl;
        cout << "2. Удалить элемент" << endl;
        cout << "3. Найти элемент" << endl;
        cout << "4. Вывести список в консольное окно" << endl;
        cout << "5. Записать список в файл" << endl;
        cout << "6. Считать список из файла" << endl;
        cout << "7. Найти символ и вывести символ и следующий" << endl;
        cout << "8. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        string filename;
        switch (choice) {
        case 1:
            cout << "Введите символ: ";
            cin >> data;
            list.append(data);
            break;

        case 2:
            cout << "Введите символ: ";
            cin >> data;
            list.remove(data);
            break;

        case 3:
            cout << "Введите символ: ";
            cin >> data;
            if (list.search(data) != NULL) {
                cout << "Символ найден." << endl;
            }
            else {
                cout << "Символ не найден." << endl;
            }
            break;

        case 4:
            list.print();
            break;

        case 5:
            cout << "Введите имя файла: ";
            
            cin >> filename;
            list.writeToFile(filename);
            break;

        case 6:
            cout << "Введите имя файла: ";
            cin >> filename;
            list.readFromFile(filename);
            break;

        case 7:
            cout << "Введите символ: ";
            cin >> data;
            list.findAndPrint(data);
            break;

        case 8:
            cout << "Выход из программы." << endl;
            break;

        default:
            cout << "Неправильный выбор." << endl;
            break;
        }

    } while (choice != 8);

    return 0;
}