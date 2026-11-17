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
