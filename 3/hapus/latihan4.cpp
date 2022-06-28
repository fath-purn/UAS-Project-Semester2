// latihan on site
// buat variabel berikut
// string nama
// int usia
// float tinggi
// bool ganjilgenap (true/false)

// tampilkan semua nilai dan alamt memori data di atas menggunakan pointer

#include <iostream>
using namespace std;

int main(){
    string nama = "Fatkhurrohman Purnomo";
    int usia = 18;
    float tinggi = "1.75";
    bool ganjilgenap = true;

    // pointer
    string *pNama = &nama;
    int *pUsia = &usia;
    float *pTinggi = &tinggi;
    bool *pGanjilgenap = &ganjilgenap;

    cout << "nama = " << &nama << endl;
    cout << "usia = " << &usia << endl;
    cout << "tinggi = " << &tinggi << endl;
    cout << "ganjilgenap = " << &ganjilgenap << endl;

    return 0;
}