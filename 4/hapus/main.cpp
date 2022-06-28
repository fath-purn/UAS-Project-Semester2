/*
    buat struct "aku"
    int nim
    string namaLengkap
    char jenisKelamin
    srinf hobi
    bool isGanjil (apakah kamu ganjil atau bukan) = True

    buat objek dengan diinisialisasi dengan diri kalian
    buat objek yang ditanya di inputkan dari user
*/


#include <iostream>
using namespace std;

struct aku{
    int nim;
    string namaLengkap;
    char jenisKelamin;
    string hobi;
    bool isGanjil;
};

int main(){
    aku A;
    A.nim = 21102125;
    A.namaLengkap = "Fatkhurrohman Purnomo";
    A.jenisKelamin = 'L';
    A.hobi = "Bermain Game";
    A.isGanjil = true;

    cout << "=================================================" << endl;
    cout << "\t         Data Mahasiswa" << endl;
    cout << "=================================================" << endl;
    cout << "NIM                    : " << A.nim << endl;
    cout << "Nama Lengkap           : " << A.namaLengkap << endl;
    cout << "Jenis Kelamin          : " << A.jenisKelamin << endl;
    cout << "Hobi                   : " << A.hobi << endl;
    cout << "Ganjil                 : " << A.isGanjil << endl;

    cout << endl;
    cout << "=================================================" << endl;
    cout << "\t    Masukan Data Mahasiswa" << endl;
    cout << "=================================================" << endl;
    aku B;
    cout << "Masukkan NIM           : ";
    cin >> B.nim;
    cout << "Masukkan Nama Lengkap  : ";
    cin >> B.namaLengkap;
    cout << "Jenis Kelamin (l/p)    : ";
    cin >> B.jenisKelamin;
    cout << "Masukkan Hobi          : ";
    cin >> B.hobi;
    cout << "NIM ganjil (1/0)       : ";
    cin >> B.isGanjil; 

    cout << endl;
    cout << "=================================================" << endl;
    cout << "\t         Data Mahasiswa" << endl;
    cout << "=================================================" << endl;
    cout << "NIM                    : " << B.nim << endl;
    cout << "Nama Lengkap           : " << B.namaLengkap << endl;
    cout << "Jenis Kelamin          : " << B.jenisKelamin << endl;
    cout << "Hobi                   : " << B.hobi << endl;
    
    if (B.isGanjil == true){
        cout << "Ganjil                 : " << "true" << endl;
    } else {
        cout << "Ganjil                 : " << "false" << endl;
    }

    return 0;
}

