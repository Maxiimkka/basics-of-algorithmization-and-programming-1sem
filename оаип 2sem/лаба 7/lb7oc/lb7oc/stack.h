#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
    int size;
public:
    Stack();
    ~Stack();
    bool isEmpty();
    void push(int value);
    int pop();
    int peek();
    int getSize();
    void clear();
    void saveToFile(string filename);
    void loadFromFile(string filename);
    bool hasConsecutiveDuplicates();
};

#endif

