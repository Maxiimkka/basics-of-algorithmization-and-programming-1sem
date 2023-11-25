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

    cout << "�������:" << endl;
    cout << "1 - ��� �������� ������" << endl;
    cout << "2 - ��� ����� ����� ������" << endl;
    cout << "3 - ��� ������ ������(-��)" << endl;
    cout << "4 - ��� ������ �� ������" << endl;
    cout << "5 - ��� ������ (��� ������) ���������� � (��) ����(-�)" << endl;
    cout << "6 - ��� ������" << endl;

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
    cout << "���� ����������" << endl;
    if (current_size < size) {
        SetConsoleCP(1251);
        cout << "����� �����:" << current_size + 1 << endl;
        cout << "�������� �����: " << current_size + 1;
        cin >> list[current_size].train_number;
        cout << "��� �������: ";
        cin >> list[current_size].station_of_destination;
        cout << "������: ";
        cin >> list[current_size].following_dats;
        cout << "�������������: ";
        cin >> list[current_size].arrival_time;
        cout << "�������: ";
        cin >> list[current_size].departure_time;
        current_size++;
        cout << "��� ������?" << endl;
        SetConsoleCP(866);
    }
    else {
        cout << "������� ������������ ���������� �����, ��� ������?" << endl;
        cin >> choice;
    }
}

void del() {
    int d;
    cout << "������� ����� ������, ������� ���������� ������� (��� �������� ���� ����� ������� 99)" << endl;
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

    cout << "��� ������?" << endl;
    cin >> choice;
}

void out() {
    int sw, n;
    cout << "������� " << endl;
    cout << "1 - ��� ������ 1 ������" << endl;
    cout << "2 - ��� ������ ���� �����" << endl;
    cin >> sw;

    if (sw == 1) {
        cout << "����� ��������� ������ " << endl;
        cin >> n;  cout << endl;
        cout << "����� ������: ";
        cout << list[n - 1].train_number << endl;
        cout << "����� ����������: ";
        cout << list[n - 1].station_of_destination << endl;
        cout << "���� ����������: ";
        cout << list[n - 1].following_dats << endl;
        cout << "����� �����������: ";
        cout << list[n - 1].arrival_time << endl;
        cout << "����� ��������: ";
        cout << list[n - 1].departure_time << endl;
    }

    if (sw == 2) {
        for (int i = 0; i < current_size; i++) {
            cout << "����� ������: ";
            cout << list[i].train_number << endl;
            cout << "����� ����������: ";
            cout << list[i].station_of_destination << endl;
            cout << "���� ����������: ";
            cout << list[i].following_dats << endl;
            cout << "����� �����������: ";
            cout << list[i].arrival_time << endl;
            cout << "����� ��������: ";
            cout << list[i].departure_time << endl;
        }
    }

    cout << "��� ������?" << endl;
    cin >> choice;
}

        void poisk_po_avtory() {
            for (int u = 0; u < current_size; u++) {
                for (int g = u + 1; g < current_size; g++) {
                    if (strcmp(list[u].station_of_destination, list[g].station_of_destination) == 0 && u != g) {
                        cout << "������ ��� �������� " << list[u].train_number << " � " << list[g].train_number << " ������������ �� ������ ������ (�� " << list[g].station_of_destination << ")." << endl;
                    }
                }
            }
        }

        void input_and_otput() {
            string path = "base.txt";
            fstream fs;

            fs.open(path, fstream::in | fstream::out | fstream::app); // in - ����������� ������, out - ������, app - ����������

            if (!fs.is_open()) {
                cout << "������" << endl;
            }
            else {
                int value;
                cout << "���� ��������" << endl;
                cout << "�������" << endl;
                cout << "1 - ��� ������ ��������� � ����" << endl;
                cout << "2 - ��� ���������� ���� ��������� � �����" << endl;
                cout << "3 - ��� �������� ���� ���������" << endl;
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
                    cout << "������ ������ �� �����" << endl;
                    for (int x = 0; !fs.eof(); x++) {
                        fs >> list[x].train_number;
                        cout << "����� ������: " << list[x].train_number << endl;
                        fs >> list[x].station_of_destination;
                        cout << "����� ��������: " << list[x].station_of_destination << endl;
                        fs >> list[x].following_dats;
                        cout << "���� ����������: " << list[x].following_dats << endl;
                        fs >> list[x].arrival_time;
                        cout << "����� ��������: " << list[x].arrival_time << endl;
                        fs >> list[x].departure_time;
                        cout << "����� �����������: " << list[x].departure_time << endl << endl;
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
            cout << "������� �����, � ������� ������ ������� �����: ";
            cin >> find_city;
            for (int q = 0; q < current_size; q++) {
                if (strcmp(list[q].station_of_destination, find_city) == 0) {
                    cout << "����� ��� ������� " << list[q].train_number << " ��������� � ��������� ���� �����" << endl;
                }
                else {
                    cout << "����� ��� ������� " << list[q].train_number << " ������� �� ������� ������." << endl;
                }
            }
            SetConsoleCP(866);
        }

       