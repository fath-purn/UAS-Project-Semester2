// Nama : Fatkhurrohman Purnomo
// Nim  : 21102125

#include <iostream>
using namespace std;

// structure
struct hewan{ // membuat struktur hewan
    string nama_Hewan; // membuat variabel nama_Hewan
    string jenis_Kelamin; // membuat variabel jenis_Kelamin
    string kembangbiak; // membuat variabel kembangbiak
    string nafas; // membuat variabel nafas
    string hidup; // membuat variabel hidup
    string pemakan; // membuat variabel pemakan
};

struct darat{ // membuat struktur darat
    hewan h; // membuat variabel darat
    int jumlah_kaki; // membuat variabel jumlah_kaki
    string menyusui; // membuat variabel menyusui
    string suara; // membuat variabel suara
};

struct laut{
    hewan h; // membuat variabel laut
    string sirip; // membuat variabel sirip
    string bertahan; // membuat variabel bertahan
};

int main() {
    // deklarasi
    darat d; // deklarasi d
    laut l; // deklarasi l

    // input data
    cout << "==========================================================" << endl;
    cout << "|              Masukkan data hewan:                      |" << endl;
    cout << "==========================================================" << endl;
    cout << "Masukkan nama hewan            : ";
    cin >> d.h.nama_Hewan; // inputan nama hewan darat
    cout << "Masukkan jenis kelamin hewan   : ";
    cin >> d.h.jenis_Kelamin; // inputan jenis kelamin hewan
    cout << "Cara berkembangbiak hewan      : ";
    cin >> d.h.kembangbiak; // inputan cara berkembangbiak hewan
    cout << "Masukkan alat pernafasan hewan : ";
    cin >> d.h.nafas; // inputan alat pernafasan hewan
    cout << "Tempat hidup (darat/laut)      : ";
    cin >> d.h.hidup; // inputan tempat hidup    
    cout << "Karnivora?                     : ";
    cin >> d.h.pemakan; // inputan karnivora?

    // percabangan antara hidup di darat dan di laut
    if (d.h.hidup == "darat"){ // jika hidup di darat
        cout << "Masukkan jumlah kaki hewan     : ";
        cin >> d.jumlah_kaki; // inputan jumlah kaki hewan
        cout << "Apakah hewan menyusui?         : ";
        cin >> d.menyusui; // inputan apakah hewan menyusui?
        cout << "Masukkan suara hewan           : ";
        cin >> d.suara; // inputan suara hewan
    } else if (d.h.hidup == "laut"){ // jika hidup di laut
        cout << "Masukkan sirip hewan           : ";
        cin >> l.sirip; // inputan sirip hewan
        cout << "Pertahanan diri?               : ";
        cin >> l.bertahan; // inputan apakah hewan bertahan?
    }

    cout << endl << endl;

    // output hewan darat
    cout << "==========================================================" << endl;
    cout << "|                     Output hewan :                     |" << endl;
    cout << "==========================================================" << endl;
    cout << "Nama hewan                     : " << d.h.nama_Hewan << endl;
    cout << "Jenis kelamin hewan            : " << d.h.jenis_Kelamin << endl;
    cout << "Kembangbiak hewan              : " << d.h.kembangbiak << endl;
    cout << "Alat pernafasan hewan          : " << d.h.nafas << endl;
    cout << "Tempat hidup                   : " << d.h.hidup << endl;
    cout << "Karnivora                      : " << d.h.pemakan << endl;

    // percabangan antara hidup di darat dan di laut
    if (d.h.hidup == "darat"){
        cout << "Jumlah kaki hewan              : " << d.jumlah_kaki << endl;
        cout << "Apakah hewan menyusui?         : " << d.menyusui << endl;
        cout << "Suara hewan                    : " << d.suara << endl;
    } else if (d.h.hidup == "laut"){
        cout << "Sirip hewan                    : " << l.sirip << endl;
        cout << "Pertahanan diri                : " << l.bertahan << endl;
    }

    return 0;
}