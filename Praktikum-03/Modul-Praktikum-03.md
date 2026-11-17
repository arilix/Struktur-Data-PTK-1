<p align="right"><b>Laboratorium Teknik Komputer</b></p>

# Praktikum 3 — ADT Stack menggunakan Tabel

## 3.1 Tujuan Praktikum

- Mahasiswa mampu memahami konsep dasar struktur data stack.
- Mahasiswa mampu memahami aplikasi struktur data stack dalam kehidupan sehari-hari.
- Mahasiswa mampu mengimplementasikan stack menggunakan tabel (array) dalam bahasa C++.

## 3.2 Teori Singkat

### a. Abstract Data Type (ADT)

**Abstract Data Type (ADT)** adalah definisi **TYPE** dan sekumpulan **PRIMITIF** (operasi dasar) terhadap TYPE
tersebut. ADT yang lengkap juga menyertakan definisi invarian dari TYPE dan aksioma yang berlaku. Dalam C++, TYPE
diterjemahkan sebagai tipe terdefinisi (misalnya `struct`), dan primitif diimplementasikan sebagai fungsi atau prosedur.

Implementasi ADT di C++ terdiri dari dua modul dan satu program utama:

| File | Isi |
|------|-----|
| `*.h` (header) | spesifikasi: library, tipe data bentukan, dan *header* fungsi/prosedur |
| `*.cpp` (source) | realisasi (isi) fungsi dan prosedur yang dideklarasikan di header |
| `main.cpp` | program utama: tampilan dan alur yang memanggil primitif |

Dengan ADT, pemrogram memisahkan spesifikasi dari implementasi sehingga kode lebih mudah dipahami dan dimodifikasi.

### b. Definisi stack

**Stack** adalah tumpukan data yang hanya dapat diakses pada ujungnya, yaitu **top** (puncak). Stack bersifat
**LIFO** (*Last In First Out*): data yang terakhir masuk adalah yang pertama keluar.

Stack dapat diimplementasikan dengan **tabel (array)** atau **linked list**. Praktikum ini memakai array.

| Operasi | Fungsi |
|---------|--------|
| `push` | menambahkan data ke stack |
| `pop` | mengeluarkan data dari stack |
| `peek` | melihat data di puncak tanpa mengeluarkannya |
| `isEmpty` | memeriksa apakah stack kosong |
| `isFull` | memeriksa apakah stack penuh |

### c. Aplikasi stack

- **Evaluasi ekspresi matematika** — menyimpan operan dan operator.
- **Pemanggilan fungsi** — variabel lokal dan alamat kembali disimpan di stack.
- **Undo/Redo** — menyimpan tindakan pengguna agar dapat dibatalkan atau diulang.
- **Backtracking** — menyimpan status pencarian agar dapat kembali ke langkah sebelumnya.
- **Kehidupan sehari-hari** — tumpukan buku atau piring: benda terakhir yang diletakkan diambil pertama.

## 3.3 Pelaksanaan Praktikum

### a. Membuat project dan file ADT di Code::Blocks

1. Buka Code::Blocks, pilih **File → New → Project**.
2. Pilih **Console Application**, klik **Go**.
3. Pilih bahasa **C++**, klik **Next**.
4. Beri judul project dan tentukan lokasi penyimpanan, klik **Next**.
5. Pada bagian *Compiler*, pilih **GNU GCC Compiler**, lalu klik **Finish**.

**Membuat file header (`.h`):**

1. Klik **File → New → File**.
2. Pilih **C/C++ header**, klik **Go**.
3. Klik tombol `...`, beri nama `latihan.h`, centang **Debug** dan **Release**, lalu klik **Finish**.

**Membuat file source (`.cpp`):**

1. Klik **File → New → File**.
2. Pilih **C/C++ source**, klik **Go**.
3. Klik tombol `...`, beri nama `latihan.cpp`, centang **Debug** dan **Release**, lalu klik **Finish**.

### b. Membuat ADT modul

**`latihan.h`** — spesifikasi tipe dan primitif:

```cpp
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
```

**`latihan.cpp`** — realisasi primitif:

```cpp
#include <iostream>
#include "latihan.h"

using namespace std;

void initStack(Stack &s) {
    s.top = -1;
}

bool isEmpty(Stack s) {
    return s.top == -1;
}

bool isFull(Stack s) {
    return s.top == MAX_STACK - 1;
}

void push(Stack &s, int x) {
    if (isFull(s)) {
        cout << "Stack Penuh" << endl;
    } else {
        s.top++;
        s.S[s.top] = x;
    }
}

void pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack Kosong" << endl;
    } else {
        s.top--;
    }
}

int peek(Stack s) {
    if (isEmpty(s)) {
        cout << "Stack Kosong" << endl;
        return -1;
    }
    return s.S[s.top];
}
```

**`main.cpp`** — program utama:

```cpp
#include <iostream>
#include "latihan.h"
using namespace std;

int main() {
    Stack s;
    initStack(s);
    push(s, 10);
    push(s, 20);
    push(s, 30);
    cout << peek(s) << endl;   // 30
    pop(s);
    cout << peek(s) << endl;   // 20
    pop(s);
    cout << peek(s) << endl;   // 10
    pop(s);
    pop(s);                    // Stack Kosong
    return 0;
}
```

Jalankan program, lalu lihat hasilnya:

```text
30
20
10
Stack Kosong
```

## 3.4 Latihan Soal

Buatlah program untuk **membalikkan sebuah kata** menggunakan ADT Stack dengan tabel. Program meminta input sebuah
kata, memasukkan setiap karakternya ke dalam stack, lalu mengeluarkan karakter-karakter dari stack untuk
menghasilkan kata yang sudah dibalik.

Implementasikan primitif dasar seperti pada praktikum di atas (kali ini bertipe `char`), dan tambahkan dua
primitif pada file header:

- `void viewStack(StackArr S);` — menampilkan isi stack dari puncak ke dasar.
- `void balikStack(StackArr &S);` — membalik urutan isi stack.

**`reverse.h`** (lengkapi realisasinya pada `reverse.cpp`):

```cpp
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
```

**Program utama (`main.cpp`):**

```cpp
#include <iostream>
#include "reverse.h"

using namespace std;

int main() {
    StackArr S;
    createStack(S);

    string kata;
    cout << "Masukkan kata: ";
    cin >> kata;

    for (int i = 0; i < (int)kata.length(); i++) {
        push(S, kata[i]);
    }
    cout << "Kata asli: " << kata << endl << endl;
    cout << "Kata yang masuk ke dalam Stack : ";
    viewStack(S);

    balikStack(S);
    cout << "Kata setelah dibalik : ";
    viewStack(S);

    return 0;
}
```

## 3.5 Tugas Rumah

Buatlah program **ADT stack** yang berisi data kendaraan (merek, warna, dan tahun produksi). Program memiliki
operasi dasar stack ditambah operasi **searching** dan **view all**.

File header (`carstack.h`) yang harus dipakai:

```cpp
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
```

Lengkapi `carstack.cpp` dan `main.cpp` dengan ketentuan:

- `showMobil` menampilkan seluruh isi stack dari puncak ke dasar.
- `searchMobil` mengembalikan indeks mobil pertama yang bermerek sama dengan `merk`, atau `-1` jika tidak ada.
- `pop` dan `peek` harus menangani kasus stack kosong tanpa membuat program crash.
- `main.cpp` menyediakan menu interaktif untuk seluruh operasi.

## 3.6 Tugas Pendahuluan

**Editor Teks dengan Undo, Redo, dan Pemeriksa Kurung**

Rancang inti sebuah editor teks sederhana yang memakai **stack**:

1. **Undo/Redo:** pengguna dapat mengetik karakter/kata, menghapus, lalu membatalkan (*undo*) dan mengulang (*redo*).
   Jika pengguna mengetik sesuatu yang baru setelah *undo*, riwayat *redo* harus dihapus.
2. **Pemeriksa kurung:** menentukan apakah teks seperti `{[a+b]*(c-d)}` memiliki kurung `()`, `[]`, `{}` yang seimbang,
   dan melaporkan **posisi** kesalahan pertama bila tidak seimbang.
