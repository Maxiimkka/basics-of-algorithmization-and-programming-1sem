#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <string>

//dop2

using namespace std;

#define MAX_TRAINS 8

struct TRAIN {
    string destination;
    int train_number;
    string departure_time;
};

int main() {
    TRAIN trains[MAX_TRAINS];

    // Ввод данных в массив trains с клавиатуры
    for (int i = 0; i < MAX_TRAINS; i++) {
        cout << "Enter destination for train " << i + 1 << ": ";
        cin >> trains[i].destination;
        cout << "Enter train number for " << trains[i].destination << ": ";
        cin >> trains[i].train_number;
        cout << "Enter departure time for " << trains[i].destination << " (HH:MM format): ";
        cin >> trains[i].departure_time;
    }

    // Сортировка по названию пункта назначения в алфавитном порядке
    sort(trains, trains + MAX_TRAINS, [](TRAIN a, TRAIN b) { return a.destination < b.destination; });

    // Вывод информации о поездах, отправляющихся после введенного времени
    string time;
    cout << "Enter departure time (HH:MM format): ";
    cin >> time;

    bool found = false;
    for (int i = 0; i < MAX_TRAINS; i++) {
        if (trains[i].departure_time > time) {
            cout << "Train " << trains[i].train_number << " to " << trains[i].destination << " departs at " << trains[i].departure_time << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No trains depart after " << time << endl;
    }

    return 0;
}
