// Nama : Fatkhurrohman Purnomo
// Nim  : 21102125

#include <iostream>
using namespace std;

// structure
struct dagangan{ // struktur
    int kodeBarang; // variabel
    string namaBarang; // variabel
    int stok; // variabel
    long harga; // variabel
};

int main() {
    dagangan barang[10]; // array

    // input
    for (int i = 0; i < 10; i++){ // looping untuk inputan data
        cout << "==========================================================" << endl;
        cout << "|                  Masukkan kode barang :                 |" << endl;
        cout << "==========================================================" << endl;
        cout << "Masukkan kode barang            : "; 
        cin >> barang[i].kodeBarang; // inputan kode barang
        cout << "Masukkan nama barang            : ";
        cin >> barang[i].namaBarang; // inputan nama barang
        cout << "Masukkan stok barang            : ";
        cin >> barang[i].stok; // inputan stok barang
        cout << "Masukkan harga barang           : ";
        cin >> barang[i].harga; // inputan harga barang
    }

    // output
    cout << endl << endl;
    cout << "==========================================================" << endl;
    cout << "|                  Daftar barang yang ada :              |" << endl;
    cout << "==========================================================" << endl;
    for (int i = 0; i < 10; i++){ // looping untuk outputan data
        cout << "Kode barang : " << barang[i].kodeBarang << endl; // outputan kode barang
        cout << "Nama barang : " << barang[i].namaBarang << endl; // outputan nama barang
        cout << "Stok barang : " << barang[i].stok << endl; // outputan stok barang
        cout << "Harga barang : " << barang[i].harga << endl; // outputan harga barang
        cout << endl;
    }

    return 0;
}