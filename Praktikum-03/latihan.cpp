#include <iostream>
#include "latihan.h"

using namespace std;

void initStack(Stack &s) {
    s.top = -1;
}

bool isEmpty(Stack s) {
    return s.top == -1;
}

bool isFull(Stack s) {
    return s.top == MAX_STACK - 1;
}

void push(Stack &s, int x) {
    if (isFull(s)) {
        cout << "Stack Penuh" << endl;
    } else {
        s.top++;
        s.S[s.top] = x;
    }
}

void pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack Kosong" << endl;
    } else {
        s.top--;
    }
}

int peek(Stack s) {
    if (isEmpty(s)) {
        cout << "Stack Kosong" << endl;
        return -1;
    }
    return s.S[s.top];
}
