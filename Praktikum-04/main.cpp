#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    QueueOfInt q;
    createEmpty(q);

    for (int i = 1; i <= 10; i++) enQueue(q, i * 10);   // isi sampai penuh
    enQueue(q, 999);                                    // Queue Sudah Penuh
    viewQueue(q);

    deQueue(q);
    deQueue(q);
    deQueue(q);
    cout << "Setelah 3x deQueue, jumlah elemen = " << nbElmt(q) << endl;

    enQueue(q, 110);                                    // ruang di depan dipakai kembali
    enQueue(q, 120);
    viewQueue(q);

    while (!isEmpty(q)) deQueue(q);
    deQueue(q);                                         // Queue Sudah Kosong!
    return 0;
}
