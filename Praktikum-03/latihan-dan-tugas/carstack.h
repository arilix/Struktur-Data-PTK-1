#ifndef CARSTACK_H_INCLUDED
#define CARSTACK_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE 50

struct mobil {
    string merk;
    string warna;
    int tahun;
};

struct Stack {
    mobil data[MAX_SIZE];
    int top;
};

void initStack(Stack &s);
bool isEmpty(Stack s);
bool isFull(Stack s);
void push(Stack &s, mobil x);
mobil pop(Stack &s);
mobil peek(Stack s);
void showMobil(Stack s);
int searchMobil(Stack s, string merk);

#endif // CARSTACK_H_INCLUDED
