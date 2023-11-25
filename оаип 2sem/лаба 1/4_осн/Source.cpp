#include <iostream>
#include <fstream>
#include <windows.h>

# define str_len 30                         
# define size 30

using namespace std;

void enter_new(), del(), out(), poisk_po_avtory(), input_and_otput();

struct Library {
    int train_number;
    char arrival_time[str_len], departure_time[str_len], station_of_destination[str_len], following_dats[str_len];
};
struct Library list[size];
struct Library empty_struct;

int current_size = 0, choice = 0;

int main() {
    setlocale(LC_CTYPE, "Russian");

    cout << "Введите:" << endl;
    cout << "1 - для удаления записи" << endl;
    cout << "2 - для ввода новой записи" << endl;
    cout << "3 - для вывода записи(-ей)" << endl;
    cout << "4 - для поиска по автору" << endl;
    cout << "5 - для записи (или вывода) информации в (из) файл(-а)" << endl;
    cout << "6 - для выхода" << endl;

    do {
        cin >> choice;
        switch (choice) {
        case 1:  del();  break;
        case 2:  enter_new();  break;
        case 3:  out();  break;
        case 4:  poisk_po_avtory(); break;
        case 5:   input_and_otput(); break;
        }
    } while (choice != 6);
}

void enter_new() {
    cout << "Ввод информации" << endl;
    if (current_size < size) {
        SetConsoleCP(1251);
        cout << "Автор книги:" << current_size + 1 << endl;
        cout << "Название книги: " << current_size + 1;
        cin >> list[current_size].train_number;
        cout << "Год издания: ";
        cin >> list[current_size].station_of_destination;
        cout << "Раздел: ";
        cin >> list[current_size].following_dats;
        cout << "Происхождение: ";
        cin >> list[current_size].arrival_time;
        cout << "Наличие: ";
        cin >> list[current_size].departure_time;
        current_size++;
        cout << "Что дальше?" << endl;
        SetConsoleCP(866);
    }
    else {
        cout << "Введено максимальное количество строк, что дальше?" << endl;
        cin >> choice;
    }
}

void del() {
    int d;
    cout << "Введите номер строки, которую необходимо удалить (для удаления всех строк введите 99)" << endl;
    cin >> d;

    if (d != 99) {
        for (int de1 = (d - 1); de1 < current_size; de1++) {
            list[de1] = list[de1 + 1];
            current_size = current_size - 1;
        }
    }

    if (d == 99) {
        for (int i = 0; i < size; i++) {
            list[i] = empty_struct;
        }
    }

    cout << "Что дальше?" << endl;
    cin >> choice;
}

void out() {
    int sw, n;
    cout << "Введите " << endl;
    cout << "1 - для вывода 1 строки" << endl;
    cout << "2 - для вывода всех строк" << endl;
    cin >> sw;

    if (sw == 1) {
        cout << "Номер выводимой строки " << endl;
        cin >> n;  cout << endl;
        cout << "Номер поезда: ";
        cout << list[n - 1].train_number << endl;
        cout << "Пункт назначения: ";
        cout << list[n - 1].station_of_destination << endl;
        cout << "Дата следования: ";
        cout << list[n - 1].following_dats << endl;
        cout << "Время отправления: ";
        cout << list[n - 1].arrival_time << endl;
        cout << "Время прибытия: ";
        cout << list[n - 1].departure_time << endl;
    }

    if (sw == 2) {
        for (int i = 0; i < current_size; i++) {
            cout << "Номер поезда: ";
            cout << list[i].train_number << endl;
            cout << "Пункт назначения: ";
            cout << list[i].station_of_destination << endl;
            cout << "Дата следования: ";
            cout << list[i].following_dats << endl;
            cout << "Время отправления: ";
            cout << list[i].arrival_time << endl;
            cout << "Время прибытия: ";
            cout << list[i].departure_time << endl;
        }
    }

    cout << "Что дальше?" << endl;
    cin >> choice;
}

        void poisk_po_avtory() {
            for (int u = 0; u < current_size; u++) {
                for (int g = u + 1; g < current_size; g++) {
                    if (strcmp(list[u].station_of_destination, list[g].station_of_destination) == 0 && u != g) {
                        cout << "Поезда под номерами " << list[u].train_number << " и " << list[g].train_number << " отправляются из одного города (из " << list[g].station_of_destination << ")." << endl;
                    }
                }
            }
        }

        void input_and_otput() {
            string path = "base.txt";
            fstream fs;

            fs.open(path, fstream::in | fstream::out | fstream::app); // in - возможность чтения, out - записи, app - добавления

            if (!fs.is_open()) {
                cout << "Ошибка" << endl;
            }
            else {
                int value;
                cout << "Файл открылся" << endl;
                cout << "Введите" << endl;
                cout << "1 - для записи сообщения в файл" << endl;
                cout << "2 - для считывания всех сообщений в файле" << endl;
                cout << "3 - для удаления всех сообщений" << endl;
                cin >> value;

                if (value == 1) {
                    for (int x = 0; x < current_size; x++) {
                        fs << list[x].train_number << "\n";
                        fs << list[x].station_of_destination << "\n";
                        fs << list[x].following_dats << "\n";
                        fs << list[x].arrival_time << "\n";
                        fs << list[x].departure_time << "\n";
                    }
                }

                if (value == 2) {
                    cout << "Чтение данных из файла" << endl;
                    for (int x = 0; !fs.eof(); x++) {
                        fs >> list[x].train_number;
                        cout << "Номер поезда: " << list[x].train_number << endl;
                        fs >> list[x].station_of_destination;
                        cout << "Пункт прибытия: " << list[x].station_of_destination << endl;
                        fs >> list[x].following_dats;
                        cout << "Дата следования: " << list[x].following_dats << endl;
                        fs >> list[x].arrival_time;
                        cout << "Время прибытия: " << list[x].arrival_time << endl;
                        fs >> list[x].departure_time;
                        cout << "Время отправления: " << list[x].departure_time << endl << endl;
                    }
                }

                if (value == 3) {
                    ofstream file(path);
                    file << "";
                }
            }
            fs.close();
        }

        void find_the_city() {
            SetConsoleCP(1251);
            char find_city[size];
            cout << "Введите город, в который должен прибыть поезд: ";
            cin >> find_city;
            for (int q = 0; q < current_size; q++) {
                if (strcmp(list[q].station_of_destination, find_city) == 0) {
                    cout << "Поезд под номером " << list[q].train_number << " приезжает в указанный вами город" << endl;
                }
                else {
                    cout << "Поезд под номером " << list[q].train_number << " выходит из другого города." << endl;
                }
            }
            SetConsoleCP(866);
        }

       