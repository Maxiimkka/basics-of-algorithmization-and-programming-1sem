#include <iostream>
#include <list>

using namespace std;

void josephus(int n, int k) {
    // Создаем список людей
    list<int> people;
    for (int i = 1; i <= n; i++) {
        people.push_back(i);
    }

    // Начинаем считать от первого человека
    auto it = people.begin();

    // Удаляем каждого k-го человека, пока не останется один
    while (people.size() > 1) {
        for (int i = 0; i < k - 1; i++) {
            // Перемещаем итератор к следующему человеку
            it++;
            // Если достигнут конец списка, то переходим на начало
            if (it == people.end()) {
                it = people.begin();
            }
        }
        // Удаляем k-го человека
        cout << *it << " ";
        it = people.erase(it);
        // Если достигнут конец списка, то переходим на начало
        if (it == people.end()) {
            it = people.begin();
        }
    }
    // Выводим оставшегося человека
    cout << *it << endl;
}

int main() {
    int n;
    cout << "n and k\n";
    cin >> n;// Количество людей
    int k;
    cin >> k;

    josephus(n, k);

    return 0;
}