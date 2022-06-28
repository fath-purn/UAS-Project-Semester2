// Nama : Fatkhurrohman Purnomo
// Nim  : 21102125

#include <iostream>
using namespace std;

struct pegawai{ // struktur pegawai
    string nama, alamat; // membuat variabel nama, alamat
    long gaji; // membuat variabel gaji
};

int main(){
    pegawai p1[3] = { // melakukan deklarasi array p1 dengan 3 elemen
        {"Fatkhurrohman Purnomo", "Purwokerto", 5000000}, // isi array 
        {"Rizki", "Bandung", 4000000}, // isi array
        {"Rahman", "Sukabumi", 65000000} // isi array
    };
 
    for (int i = 0; i < 3; i++){ // looping untuk outputan data
        cout << "Nama       : " << p1[i].nama << endl; // outputan nama
        cout << "Alamat     : " << p1[i].alamat << endl; // outputan alamat
        cout << "Gaji       : " << p1[i].gaji << endl; // outputan gaji
        cout << endl;
    }

    return 0;
}