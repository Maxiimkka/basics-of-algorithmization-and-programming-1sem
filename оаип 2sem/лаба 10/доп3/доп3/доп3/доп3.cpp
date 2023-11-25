#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");
    const int n = 5;
    int nums[n];

    cout << "���� " << n << " ����������� �����: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + n);

    cout << "��� ������������:" << endl;
    do {
        for (int i = 0; i < n; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    } while (next_permutation(nums, nums + n));

    return 0;
}