#include <iostream>
#include <list>

using namespace std;

void josephus(int n, int k) {
    // ������� ������ �����
    list<int> people;
    for (int i = 1; i <= n; i++) {
        people.push_back(i);
    }

    // �������� ������� �� ������� ��������
    auto it = people.begin();

    // ������� ������� k-�� ��������, ���� �� ��������� ����
    while (people.size() > 1) {
        for (int i = 0; i < k - 1; i++) {
            // ���������� �������� � ���������� ��������
            it++;
            // ���� ��������� ����� ������, �� ��������� �� ������
            if (it == people.end()) {
                it = people.begin();
            }
        }
        // ������� k-�� ��������
        cout << *it << " ";
        it = people.erase(it);
        // ���� ��������� ����� ������, �� ��������� �� ������
        if (it == people.end()) {
            it = people.begin();
        }
    }
    // ������� ����������� ��������
    cout << *it << endl;
}

int main() {
    int n;
    cout << "n and k\n";
    cin >> n;// ���������� �����
    int k;
    cin >> k;

    josephus(n, k);

    return 0;
}