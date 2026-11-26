#include "queue.h"

void createEmpty(QueueOfInt &q) {
    q.head = -1;
    q.tail = -1;
}

bool isEmpty(QueueOfInt q) {
    return (q.head == -1) && (q.tail == -1);
}

void viewQueue(QueueOfInt q) {
    cout << "Isi queue : ";
    if (isEmpty(q)) {
        cout << "[ ]";
    } else {
        int n = nbElmt(q);
        for (int k = 0; k < n; k++) {
            cout << "[" << q.ar[(q.head + k) % maxqueue] << "]";
        }
    }
    cout << endl;
}
