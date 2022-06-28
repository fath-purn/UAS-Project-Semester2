#include <iostream>
using namespace std;

///PROGRAM REPRESENTASI GRAPH DENGAN MATRIKS BERDASARKAN INPUT USER
//Deklarasi

int jumlahSimpul = 7;
string *dataSimpul; //digunakan untuk membuat array dinamis
int **dataBusur; //digunakan untuk membuat array dinamis dua dimensi
bool cekMatriks = false;

//Buat Matriks Graph
void buatMatriks()
{
    dataSimpul = new string[jumlahSimpul]; //membuat array string dinamis

    //Membuat simpul dengan jumlah yang dimasukkan user
    dataBusur = new int*[jumlahSimpul]; //membuat pointer array integer dinamis
    dataBusur[0] = new int[jumlahSimpul * jumlahSimpul]; //menginisialisasi array busur indeks-0 dengan array integer dinamis berindeks pointer
    
    for (int i = 1; i < jumlahSimpul; i++){
        dataBusur[i] = dataBusur[i-1] + jumlahSimpul;
    }

    //Membuat matriks 2 dimensi dengan ukuran sesuai masukan user
    //Proses input nama simpul
    cout << " Silahkan masukkan nama simpul" <<endl; //input nama simpul sebanyak jumlah simpul
    for (int i = 0; i < jumlahSimpul; i++){
        cout << " Simpul " <<i+1<< " : ";
        cin >> dataSimpul[i];
    }

    //Proses input nilai busur (bobot)
    cout << " Silahkan masukkan bobot antar simpul" << endl; //input bobot busur antar simpul
    for (int baris = 0; baris < jumlahSimpul; baris++){
        for (int kolom = 0; kolom < jumlahSimpul; kolom++){
            cout << " " << dataSimpul[baris] << " --> " << dataSimpul[kolom] << " : "; //input bobot sebagai baris dan kolom
            cin >> dataBusur[baris][kolom];
        }
    }
    
    cout << endl;
    //Inisialisasi Pengecekan Matriks
    cekMatriks = true; //atur keberadaan matriks menjadi ada/true
}

//Tampil Matriks Graph
void tampilMatriks()
{
    if (cekMatriks){ //jika matriks ada
        cout << " ";
        for (int i = 0; i < jumlahSimpul; i++){ //membuat kolom nama simpul
            cout << dataSimpul[i] << " ";
        }
        cout << endl;
    
        for (int baris = 0; baris < jumlahSimpul; baris++){ //membuat kolom bobot
            cout << " " << dataSimpul[baris] << " "; //membuat baris nama simpul
            for (int kolom = 0; kolom < jumlahSimpul; kolom++){ //membuat baris bobot
                cout << dataBusur[baris][kolom] << " ";
            }
        cout << endl;
        }
    }
    else{ //jika matriks belum ada
        cout << " Tidak ada matriks" << endl;
    }
}

int main()
{
    cout << " Silahkan masukkan jumlah simpul: "; //input jumlah simpul
    cin >> jumlahSimpul;

    buatMatriks();
    tampilMatriks();
    return 0;
}