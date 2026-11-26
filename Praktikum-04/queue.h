#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>
using namespace std;

const int maxqueue = 10;

struct QueueOfInt {
    int ar[maxqueue];
    int head, tail;
};

void createEmpty(QueueOfInt &q);
bool isEmpty(QueueOfInt q);
bool isFull(QueueOfInt q);
void enQueue(QueueOfInt &q, int elm);
void deQueue(QueueOfInt &q);
int nbElmt(QueueOfInt q);
void viewQueue(QueueOfInt q);

#endif // QUEUE_H_INCLUDED
