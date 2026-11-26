#include "queue.h"

bool isFull(QueueOfInt q) {
    return q.tail == maxqueue - 1;
}

int nbElmt(QueueOfInt q) {
    return isEmpty(q) ? 0 : q.tail - q.head + 1;
}

void enQueue(QueueOfInt &q, int elm) {
    if (isFull(q)) {
        cout << "Queue Sudah Penuh" << endl;
    } else {
        if (isEmpty(q)) {
            q.head = 0;
            q.tail = 0;
        } else {
            q.tail++;
        }
        q.ar[q.tail] = elm;
    }
}

void deQueue(QueueOfInt &q) {
    if (isEmpty(q)) {
        cout << "Queue Sudah Kosong!" << endl;
    } else if (q.head == q.tail) {
        createEmpty(q);
    } else {
        for (int i = q.head + 1; i <= q.tail; i++) {
            q.ar[i - 1] = q.ar[i];   // geser semua elemen ke depan
        }
        q.tail--;
    }
}
