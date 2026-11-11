#include <iostream>
using namespace std;

int penjumlahan(int a, int b) {
    return a + b;
}

int pengurangan(int a, int b) {
    return a - b;
}

int perkalian(int a, int b) {
    return a * b;
}

int pembagian(int a, int b) {
    return a / b;
}

int main() {
    int angkaPertama, angkaKedua;
    cout << "Masukkan Angka Pertama : ";
    cin >> angkaPertama;
    cout << "Masukkan Angka Kedua : ";
    cin >> angkaKedua;

    cout << "Hasil penjumlahan : " << penjumlahan(angkaPertama, angkaKedua) << endl;
    cout << "Hasil pengurangan : " << pengurangan(angkaPertama, angkaKedua) << endl;
    cout << "Hasil perkalian   : " << perkalian(angkaPertama, angkaKedua) << endl;

    if (angkaKedua != 0) {
        cout << "Hasil pembagian   : " << pembagian(angkaPertama, angkaKedua) << endl;
    } else {
        cout << "Pembagian tidak dapat dilakukan (pembagi = 0)" << endl;
    }

    return 0;
}
