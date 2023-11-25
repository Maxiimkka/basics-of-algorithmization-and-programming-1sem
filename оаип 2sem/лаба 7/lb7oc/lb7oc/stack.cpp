#include "stack.h"

Stack::Stack() {
    top = nullptr;
    size = 0;
}

Stack::~Stack() {
    clear();
}

bool Stack::isEmpty() {
    return top == nullptr;
}

void Stack::push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    size++;
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "Стек пуст!" << endl;
        return -1;
    }
    else {
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
        return value;
    }
}

int Stack::peek() {
    if (isEmpty()) {
        cout << "Стек пуст!" << endl;
        return -1;
    }
    else {
        return top->data;
    }
}

int Stack::getSize() {
    return size;
}

void Stack::clear() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::saveToFile(string filename) {
    ofstream outFile;
    outFile.open(filename);
    Node* current = top;
    while (current != nullptr) {
        outFile << current->data << endl;
        current = current->next;
    }
    outFile.close();
}

void Stack::loadFromFile(string filename) {
    clear();
    ifstream inFile;
    inFile.open(filename);
    int value;
    while (inFile >> value) {
        push(value);
    }
    inFile.close();
}

bool Stack::hasConsecutiveDuplicates() {
    if (isEmpty()) {
        return false;
    }
    else {
        Node* current = top;
        while (current->next != nullptr) {
            if (current->data == current->next->data) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
}
