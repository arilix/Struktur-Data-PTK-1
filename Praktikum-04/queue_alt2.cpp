#include "queue.h"

bool isFull(QueueOfInt q) {
    return (q.head == 0) && (q.tail == maxqueue - 1);
}

int nbElmt(QueueOfInt q) {
    return isEmpty(q) ? 0 : q.tail - q.head + 1;
}

void enQueue(QueueOfInt &q, int elm) {
    if (isFull(q)) {
        cout << "Queue Sudah Penuh" << endl;
    } else if (isEmpty(q)) {
        q.head = 0;
        q.tail = 0;
        q.ar[q.tail] = elm;
    } else {
        if (q.tail == maxqueue - 1) {
            // tail di ujung tabel tetapi masih ada ruang di depan head:
            // geser semua elemen dari head..tail ke awal tabel
            int i = 0;
            for (int j = q.head; j <= q.tail; j++) {
                q.ar[i] = q.ar[j];
                i++;
            }
            q.head = 0;
            q.tail = i - 1;
        }
        q.tail++;
        q.ar[q.tail] = elm;
    }
}

void deQueue(QueueOfInt &q) {
    if (isEmpty(q)) {
        cout << "Queue Sudah Kosong!" << endl;
    } else if (q.head == q.tail) {
        createEmpty(q);
    } else {
        q.head++;
    }
}
