#ifndef REVERSE_H_INCLUDED
#define REVERSE_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#define MAX_STACK 100

struct StackArr {
    int top;
    char info[MAX_STACK];
};

// Primitif dasar (sama seperti praktikum sebelumnya, tetapi bertipe char)
void createStack(StackArr &S);
bool isEmpty(StackArr S);
bool isFull(StackArr S);
void push(StackArr &S, char x);
char pop(StackArr &S);

// Primitif tambahan yang harus Anda buat
void viewStack(StackArr S);      // menampilkan isi stack dari puncak (top) ke dasar
void balikStack(StackArr &S);    // membalik urutan isi stack

#endif // REVERSE_H_INCLUDED
