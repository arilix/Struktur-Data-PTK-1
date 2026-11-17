<p align="right"><b>Laboratorium Teknik Komputer</b></p>

# Praktikum 2 — Array, Struktur, Pointer, Fungsi dan Prosedur

## 2.1 Tujuan Praktikum

- Mahasiswa mampu memahami konsep array dan struktur pada C++.
- Mahasiswa mampu memahami konsep pointer pada C++.
- Mahasiswa mampu memahami konsep fungsi dan prosedur pada C++.

## 2.2 Teori Singkat

### a. Array

**Array** adalah **kumpulan nilai** dengan tipe yang sama yang ditempatkan pada lokasi memori yang berurutan dan
diakses melalui indeks. Array dipakai untuk menyimpan data dalam jumlah besar dan menyederhanakan kode.

```cpp
int angka[5] = {10, 20, 30, 40, 50};
```

Variabel `angka` adalah array bilangan bulat dengan 5 elemen, masing-masing diinisialisasi dengan nilai di dalam
kurung kurawal. Elemen diakses dengan sintaks `angka[index]`. Indeks dimulai dari **0** dan berakhir pada
**ukuran array − 1**.

```cpp
int elemen_ke_2 = angka[1];   // angka[1] adalah elemen kedua (nilai 20)
```

### b. Struktur (`struct`)

**Struktur** adalah **kumpulan variabel** dengan tipe yang berbeda yang dikelompokkan menjadi satu kesatuan. Struktur
dipakai untuk merepresentasikan konsep yang kompleks, seperti objek nyata atau entitas dalam program.

```cpp
struct Buku {
    string judul;
    string penulis;
    int tahun_terbit;
};
```

`Buku` adalah sebuah tipe struktur dengan tiga anggota: `judul` (string), `penulis` (string), dan `tahun_terbit`
(integer). Variabel bertipe struktur dibuat dan diakses dengan operator titik (`.`):

```cpp
Buku buku_1;
buku_1.judul = "Pemrograman C++";
buku_1.penulis = "Bjarne Stroustrup";
buku_1.tahun_terbit = 1985;
```

Berhati-hatilah agar tidak mengakses elemen yang belum didefinisikan atau melebihi batas ukuran array, karena hal
itu dapat menyebabkan kesalahan saat program dieksekusi.

**Contoh program** — array berisi struktur:

```cpp
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    int umur;
    double ipk;
};

int main() {
    const int JUMLAH_MHS = 3;
    Mahasiswa daftar_mhs[JUMLAH_MHS];

    for (int i = 0; i < JUMLAH_MHS; i++) {
        cout << "Masukkan nama mahasiswa ke-" << i + 1 << ": ";
        cin >> daftar_mhs[i].nama;

        cout << "Masukkan umur mahasiswa ke-" << i + 1 << ": ";
        cin >> daftar_mhs[i].umur;

        cout << "Masukkan IPK mahasiswa ke-" << i + 1 << ": ";
        cin >> daftar_mhs[i].ipk;

        cout << endl;
    }

    cout << "Daftar mahasiswa yang dimasukkan: " << endl;
    for (int i = 0; i < JUMLAH_MHS; i++) {
        cout << "Mahasiswa ke-" << i + 1 << ":" << endl;
        cout << "Nama: " << daftar_mhs[i].nama << endl;
        cout << "Umur: " << daftar_mhs[i].umur << endl;
        cout << "IPK: " << daftar_mhs[i].ipk << endl;
        cout << endl;
    }

    return 0;
}
```

Contoh keluaran:

```text
Masukkan nama mahasiswa ke-1: Andi
Masukkan umur mahasiswa ke-1: 20
Masukkan IPK mahasiswa ke-1: 3.5

Masukkan nama mahasiswa ke-2: Budi
Masukkan umur mahasiswa ke-2: 21
Masukkan IPK mahasiswa ke-2: 3.75

Masukkan nama mahasiswa ke-3: Cici
Masukkan umur mahasiswa ke-3: 19
Masukkan IPK mahasiswa ke-3: 3.25

Daftar mahasiswa yang dimasukkan:
Mahasiswa ke-1:
Nama: Andi
Umur: 20
IPK: 3.5

Mahasiswa ke-2:
Nama: Budi
Umur: 21
IPK: 3.75

Mahasiswa ke-3:
Nama: Cici
Umur: 19
IPK: 3.25
```

### c. Pointer

**Pointer** adalah variabel yang berisi **alamat memori** dari variabel atau objek lain. Pointer memungkinkan
pemrogram memanipulasi memori secara langsung dan efisien. Setiap variabel memiliki alamat memori unik saat
program dijalankan.

| Sintaks | Arti |
|---------|------|
| `int *alamat;` | `alamat` adalah pointer ke variabel bertipe `int` |
| `alamat = &angka;` | operator `&` mengambil **alamat** variabel `angka` |
| `int nilai = *alamat;` | operator `*` (dereferensi) mengambil **nilai** yang ditunjuk pointer |
| `*alamat = 20;` | mengubah nilai variabel yang ditunjuk pointer |

```cpp
int angka = 10;
int *alamat;
alamat = &angka;        // alamat menyimpan alamat memori angka
int nilai = *alamat;    // nilai = 10
*alamat = 20;           // angka sekarang bernilai 20
```

Gunakan pointer dengan hati-hati: kesalahan dalam mengakses atau memanipulasi memori dapat menyebabkan program
crash. Pahami konsep dan aturannya sebelum memakainya.

**Contoh program:**

```cpp
#include <iostream>
using namespace std;

int main() {
    int number = 10;
    int *pNumber = &number;

    cout << "Nilai variabel number: " << number << endl;
    cout << "Alamat memori variabel number: " << &number << endl;
    cout << "Nilai yang ditunjuk oleh pointer pNumber: " << *pNumber << endl;
    cout << "Alamat memori yang ditunjuk oleh pointer pNumber: " << pNumber << endl;

    return 0;
}
```

Contoh keluaran (alamat memori akan berbeda pada tiap komputer):

```text
Nilai variabel number: 10
Alamat memori variabel number: 0x7ffee777ed7c
Nilai yang ditunjuk oleh pointer pNumber: 10
Alamat memori yang ditunjuk oleh pointer pNumber: 0x7ffee777ed7c
```

### d. Fungsi dan prosedur

Fungsi dan prosedur adalah blok kode yang dapat dipanggil dari program utama untuk menyelesaikan tugas tertentu.
Keduanya dapat menerima parameter, memakai variabel lokal, dan didefinisikan di dalam atau di luar program utama.

- **Fungsi** adalah blok kode yang **mengembalikan nilai** setelah dieksekusi.
- **Prosedur** adalah blok kode yang **tidak mengembalikan nilai** (bertipe `void`).

**Contoh fungsi:**

```cpp
#include <iostream>
using namespace std;

int tambah(int a, int b) {
    int hasil = a + b;
    return hasil;
}

int main() {
    int x = 10, y = 20;
    int hasil = tambah(x, y);
    cout << "Hasil penjumlahan: " << hasil << endl;
    return 0;
}
```

Fungsi `tambah` menerima dua parameter, menjumlahkannya, dan mengembalikan hasilnya ke program utama.

**Contoh prosedur:**

```cpp
#include <iostream>
using namespace std;

void pesan() {
    cout << "Halo, selamat datang di program ini!" << endl;
}

int main() {
    pesan();
    return 0;
}
```

Prosedur `pesan` hanya mencetak teks; dipanggil cukup dengan namanya, tanpa menyimpan hasil ke variabel.

## 2.3 Pelaksanaan Praktikum

Program berikut mengelola data mahasiswa dengan struktur, array, fungsi, dan prosedur.

**Langkah 1 — Deklarasikan struktur.**

```cpp
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;    // atribut nama bertipe string
    int umur;       // atribut umur bertipe integer
    double ipk;     // atribut ipk bertipe double
};
```

**Langkah 2 — Deklarasikan fungsi dan prosedur** (`cetakMahasiswa`, `sortMahasiswa`, `hitungRataRata`).

**Langkah 3 — Buat fungsi utama** yang mengisi array data, memanggil `cetakMahasiswa`, `hitungRataRata`, lalu
`sortMahasiswa`.

**Kode lengkap:**

```cpp
#include <iostream>
#include <string>
using namespace std;

// Deklarasi tipe data bentukan Mahasiswa
struct Mahasiswa {
    string nama;    // atribut nama bertipe string
    int umur;       // atribut umur bertipe integer
    double ipk;     // atribut ipk bertipe double
};

// Prosedur untuk mencetak daftar mahasiswa
void cetakMahasiswa(Mahasiswa m[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nama: " << m[i].nama
             << ", Umur: " << m[i].umur
             << ", IPK: " << m[i].ipk << endl;
    }
}

// Prosedur untuk mengurutkan mahasiswa berdasarkan IPK (tertinggi ke terendah)
void sortMahasiswa(Mahasiswa m[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (m[j].ipk > m[i].ipk) {
                Mahasiswa temp = m[i];
                m[i] = m[j];
                m[j] = temp;
            }
        }
    }
}

// Fungsi untuk menghitung rata-rata IPK seluruh mahasiswa
double hitungRataRata(Mahasiswa m[], int n) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += m[i].ipk;
    }
    return total / n;
}

int main() {
    const int jumlahData = 5;
    Mahasiswa dataMahasiswa[jumlahData] = {
        {"Andi", 20, 3.75},
        {"Budi", 21, 3.8},
        {"Cici", 19, 3.65},
        {"Dini", 22, 3.9},
        {"Eka", 20, 3.7}
    };

    cout << "Daftar Mahasiswa:" << endl;
    cetakMahasiswa(dataMahasiswa, jumlahData);

    double rataRataIPK = hitungRataRata(dataMahasiswa, jumlahData);
    cout << "\nRata-rata IPK: " << rataRataIPK << endl;

    cout << "\nDaftar Mahasiswa setelah diurutkan berdasarkan IPK:" << endl;
    sortMahasiswa(dataMahasiswa, jumlahData);
    cetakMahasiswa(dataMahasiswa, jumlahData);

    return 0;
}
```

Contoh keluaran:

```text
Daftar Mahasiswa:
Nama: Andi, Umur: 20, IPK: 3.75
Nama: Budi, Umur: 21, IPK: 3.8
Nama: Cici, Umur: 19, IPK: 3.65
Nama: Dini, Umur: 22, IPK: 3.9
Nama: Eka, Umur: 20, IPK: 3.7

Rata-rata IPK: 3.76

Daftar Mahasiswa setelah diurutkan berdasarkan IPK:
Nama: Dini, Umur: 22, IPK: 3.9
Nama: Budi, Umur: 21, IPK: 3.8
Nama: Andi, Umur: 20, IPK: 3.75
Nama: Eka, Umur: 20, IPK: 3.7
Nama: Cici, Umur: 19, IPK: 3.65
```

## 2.4 Latihan Soal

**1. Rata-rata N bilangan.** Buatlah program yang menghitung rata-rata dari N buah bilangan yang dimasukkan
pengguna, menggunakan array dan fungsi.

```text
Masukkan banyaknya elemen: 5
Masukkan elemen ke-1: 1
Masukkan elemen ke-2: 2
Masukkan elemen ke-3: 3
Masukkan elemen ke-4: 4
Masukkan elemen ke-5: 5
Elemen pada array: 1 2 3 4 5
Rata-rata: 3
```

**2. Array of struct.** Diberikan struktur berikut:

```cpp
struct Mobil {
    string merk;
    string warna;
    int tahun;
};
```

Buatlah program C++ yang meminta input pengguna untuk membuat array mobil sebanyak *n*, kemudian menampilkan
informasi semua mobil yang telah dibuat.

```text
Masukkan jumlah mobil: 2
Mobil 1
Merk: Toyota
Warna: Hitam
Tahun: 2021

Mobil 2
Merk: Honda
Warna: Putih
Tahun: 2019

DAFTAR ISI MOBIL ADALAH :
Mobil 1
Merk: Toyota
Warna: Hitam
Tahun: 2021

Mobil 2
Merk: Honda
Warna: Putih
Tahun: 2019
```

**3. Pointer.** Buatlah program yang menggunakan **pointer** untuk menukar isi dari dua variabel integer yang
diinputkan pengguna.

```text
Masukkan nilai x: 5
Masukkan nilai y: 10

Sebelum swap:
x = 5, y = 10

Setelah swap:
x = 10, y = 5
```

**4. Faktorial dengan prosedur.** Buatlah program C++ untuk menghitung nilai faktorial dari sebuah bilangan yang
diinputkan pengguna dengan menggunakan **prosedur**.

```text
Masukkan bilangan: 5
5! = 120
```

## 2.5 Tugas Rumah

Buatlah program untuk memesan makanan dengan menggunakan **pointer dan prosedur**, lalu tampilkan total harga yang
harus dibayar. Menu makanan boleh ditulis langsung di kode atau meminta pengguna menginputkan daftar menunya.

```text
==========================
          MENU
==========================
1. Nasi Goreng Rp15000
2. Mie Goreng   Rp12000
3. Ayam Goreng  Rp20000
==========================
Masukkan nomor menu: 2
Masukkan jumlah pesanan: 3
Anda memesan 3 porsi Mie Goreng
Total harga: Rp36000
```

## 2.6 Tugas Pendahuluan

**Sistem Inventori Toko Kecil**

Sebuah toko membutuhkan program inventori dengan data barang: kode, nama, harga, dan stok. Fitur:
tambah barang, jual barang (mengurangi stok), cari barang, tampilkan barang dengan stok di bawah batas minimum,
dan tampilkan 3 barang dengan nilai stok (harga × stok) terbesar.

Batasan: jumlah barang tidak diketahui sejak awal (maksimal 1.000), dan kode barang harus unik.
