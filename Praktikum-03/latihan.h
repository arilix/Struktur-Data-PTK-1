#ifndef LATIHAN_H_INCLUDED
#define LATIHAN_H_INCLUDED

#define MAX_STACK 100

struct Stack {
    int top;
    int S[MAX_STACK];
};

void initStack(Stack &s);
bool isEmpty(Stack s);
bool isFull(Stack s);
void push(Stack &s, int x);
void pop(Stack &s);
int peek(Stack s);

#endif // LATIHAN_H_INCLUDED
