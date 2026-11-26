#include "queue.h"

bool isFull(QueueOfInt q) {
    return !isEmpty(q) && ((q.tail + 1) % maxqueue == q.head);
}

int nbElmt(QueueOfInt q) {
    if (isEmpty(q)) return 0;
    return (q.tail - q.head + maxqueue) % maxqueue + 1;
}

void enQueue(QueueOfInt &q, int elm) {
    if (isFull(q)) {
        cout << "Queue Sudah Penuh" << endl;
    } else {
        if (isEmpty(q)) {
            q.head = 0;
            q.tail = 0;
        } else {
            q.tail = (q.tail + 1) % maxqueue;   // kembali ke 0 setelah indeks terakhir
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
        q.head = (q.head + 1) % maxqueue;
    }
}
