<p align="right"><b>Laboratorium Teknik Komputer</b></p>

# Praktikum 4 — Queue menggunakan Array

## 4.1 Tujuan Praktikum

- Mahasiswa mampu memahami konsep struktur data queue.
- Mahasiswa mampu mengimplementasikan queue menggunakan array di C++.
- Mahasiswa mampu memecahkan masalah yang diberikan menggunakan queue.

## 4.2 Teori Singkat

### a. Pengenalan queue

Antrian atau **queue** adalah konsep penyimpanan sekumpulan data yang dapat diimplementasikan dengan **array**
maupun **linked list**. Elemen hanya boleh dimasukkan setelah elemen paling akhir (**Tail**) dan hanya boleh
diproses dari elemen paling awal (**Head**). Skema ini disebut **FIFO** (*First In First Out*).

Operasi pada queue:

| Operasi | Fungsi |
|---------|--------|
| `createEmpty` | membuat queue kosong |
| `isEmpty` | memeriksa apakah queue kosong |
| `isFull` | memeriksa apakah queue penuh |
| `enQueue` | menambahkan elemen di Tail |
| `deQueue` | menghapus elemen di Head |
| `nbElmt` | menghitung banyaknya elemen |
| `clear` | mengosongkan queue |

### b. Tiga alternatif representasi queue

| Alternatif | Cara kerja | Kelebihan / kekurangan |
|:----------:|-----------|------------------------|
| **1** | `Head` selalu di indeks 0 bila queue tidak kosong. `enQueue` di indeks setelah `Tail`. `deQueue` menghapus elemen pertama lalu **menggeser** semua elemen setelahnya ke depan. | Paling sederhana dan mirip antrian nyata, tetapi tidak efisien karena setiap `deQueue` menggeser data. |
| **2** | `Head` **bergerak** maju saat `deQueue`. `enQueue` seperti alternatif 1, tetapi jika `Tail` sudah di ujung tabel dan masih ada ruang di depan, elemen dari `Head` sampai `Tail` digeser ke awal tabel. | Efisien (pergeseran hanya jika perlu), tetapi tidak mirip antrian nyata. |
| **3** | `Head` dan `Tail` **berputar** (*circular*) mengelilingi tabel dan kembali ke awal setelah indeks terakhir. | Tidak ada pergeseran elemen sama sekali. |

Ketiga alternatif hanya berbeda pada `isFull`, `enQueue`, dan `deQueue`. Pada seluruh alternatif, queue kosong
ditandai `head = -1` dan `tail = -1`.

## 4.3 Pelaksanaan Praktikum

### a. File header (`queue.h`) — dipakai oleh ketiga alternatif

Tipe data bentukan queue:

```cpp
const int maxqueue = 10;
struct QueueOfInt {
    int ar[maxqueue];
    int head, tail;
};
```

Keseluruhan isi file header:

```cpp
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
```

### b. Primitif yang sama pada semua alternatif (`queue_common.cpp`)

`createEmpty` membuat queue baru, `isEmpty` memeriksa kosong atau tidaknya queue, dan `viewQueue` menampilkan
seluruh isi queue dari `head` ke `tail`.

```cpp
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
```

### c. Alternatif 1 — `Head` selalu di indeks 0

```cpp
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
```

### d. Alternatif 2 — `Head` bergerak

Penuh berarti `head == 0` **dan** `tail == maxqueue - 1`. Jika `tail` di ujung tabel tetapi `head > 0`, elemen
digeser ke awal tabel sebelum `tail` dimajukan.

```cpp
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
```

### e. Alternatif 3 — Circular queue

Indeks dimajukan dengan operator modulo (`% maxqueue`) sehingga kembali ke 0 setelah indeks terakhir. Queue
penuh ketika indeks setelah `tail` adalah `head`.

```cpp
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
```

### f. Program uji (`main.cpp`)

Satu `main.cpp` yang sama dapat dikompilasi bersama salah satu file alternatif:

```cpp
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
```

```bash
g++ -o queue queue_common.cpp queue_alt3.cpp main.cpp   # ganti alt3 dengan alt1 / alt2
```

Ketiga alternatif menghasilkan keluaran yang sama:

```text
Queue Sudah Penuh
Isi queue : [10][20][30][40][50][60][70][80][90][100]
Setelah 3x deQueue, jumlah elemen = 7
Isi queue : [40][50][60][70][80][90][100][110][120]
Queue Sudah Kosong!
```

## 4.4 Latihan Soal

Andi sedang membuka bisnis rental mobil. Ia memiliki antrian mobil yang ingin disewakan kepada pelanggannya.
Buatlah program menggunakan struktur data **queue dengan array** untuk mengelola antrian mobil tersebut dengan
fitur:

1. Menambahkan mobil ke dalam antrian
2. Menghapus mobil dari antrian
3. Menampilkan mobil yang sedang berada di depan antrian
4. Menampilkan semua mobil yang sedang antri
5. Menampilkan jumlah mobil yang sedang antri

## 4.5 Tugas Rumah

Andi ingin membuat program untuk mengantri pembelian tiket konser musik. Setiap pembeli harus memasukkan nomor
identitasnya ke dalam antrian sebelum dapat membeli tiket. Program menampilkan menu untuk:

1. menambahkan pembeli ke dalam antrian,
2. menghapus pembeli dari antrian,
3. melihat pembeli yang sedang berada di depan antrian,
4. melihat semua pembeli yang sedang antri,
5. melihat jumlah pembeli yang sedang antri.

Gunakan salah satu alternatif queue pada praktikum ini.

## 4.6 Tugas Pendahuluan

**Antrian Loket Bank dengan Prioritas**

Sebuah bank memiliki **2 loket** dan dua jenis nasabah: **biasa** dan **prioritas** (lansia, ibu hamil). Aturan:

- Nasabah prioritas dilayani lebih dulu, tetapi nasabah biasa tidak boleh menunggu **lebih dari 5 kali** ada prioritas
  yang mendahuluinya (setelah itu ia wajib dilayani).
- Antrian maksimal 20 orang; nasabah ke-21 ditolak dengan pesan yang jelas.
- Program harus dapat menampilkan antrian aktif, rata-rata waktu tunggu, dan jumlah nasabah yang ditolak.
