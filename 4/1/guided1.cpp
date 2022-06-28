// Nama : Fatkhurrohman Purnomo
// NIM : 21102125

#include <iostream>
using namespace std;

struct mahasiswa{ // struktur mahasiswa
    int nim; // membuat variabel nim
    string nama; // membuat variabel nama
    string alamat; // membuat variabel alamat
    string jurusan; // membuat variabel jurusan
};

int main(){ 
    mahasiswa mhs; // membuat variabel mahasiswa
    mhs.nim = 21102125; // inputan nim
    mhs.nama = "Fatkhurrohman Purnomo" ; // inputan nama
    mhs.jurusan = "Teknik Informatika"; // inputan jurusan
    mhs.alamat = "Jl. Surya Kencana No.1"; // inputan alamat

    cout << "Nama       : " << mhs.nama << endl; // outputan nama
    cout << "Nim        : " << mhs.nim << endl; // outputan nim
    cout << "Jurusan    : " << mhs.jurusan << endl; // outputan jurusan
    cout << "Alamat     : " << mhs.alamat << endl; // outputan alamat

    return 0;
}
