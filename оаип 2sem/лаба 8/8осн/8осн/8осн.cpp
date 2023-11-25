#include <iostream>
#include <queue>
using namespace std;

void input(queue<char>& q, int max_size) {
    char ch;
    int k = 0;
    int g = 0;
    int h = 0;
    cout << "Enter characters: ";
    while (g != 100) {
        k++;
        if (k > (max_size)) {
            cout << "Queue is full!\n";
            break;
        }
        cin >> ch;
        q.push(ch);
        if (k == max_size - 1) {
            h = ch;

        }




    }

    if (q.size() >= 4 && h == q.back() && g == 0) {
        q.pop();
        q.pop();
        q.pop();
        g++;

    }
}

void output(queue<char>& q) {
    if (q.empty()) {
        cout << "Queue is empty!\n";
        return;
    }
    cout << "Queue contents: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void size(queue<char>& q) {
    cout << "Queue size: " << q.size() << endl;
}

int main() {
    int max_size;
    cout << "Enter maximum queue size: ";
    cin >> max_size;
    queue<char> q;
    int choice;
    do {
        cout << "\nQueue operations:\n";
        cout << "1. Input\n";
        cout << "2. Output\n";
        cout << "3. Size\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            input(q, max_size);
            break;
        case 2:
            output(q);
            break;
        case 3:
            size(q);
            break;
        case 4:
            cout << "Quitting program.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (choice != 4);
    return 0;
}