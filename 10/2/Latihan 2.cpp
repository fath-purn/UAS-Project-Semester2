// Nama : Fatkhurrohman Purnomo
// NIM : 21102125

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

///PROGRAM PENCARIAN LINTASAN TERPENDEK (ALGORITMA FLOYD-WARSHALL)

//Deklarasi Global
int jumlahSimpul;
string *dataSimpul;
int **dataBusur;
int **jalurTerdekat;
bool cekMatriks = false;

//Buat Matriks Graph
void buatMatriks()
{
    dataSimpul = new string[jumlahSimpul];
    dataBusur = new int*[jumlahSimpul];
    dataBusur[0] = new int[jumlahSimpul * jumlahSimpul];

    for (int i=1; i<jumlahSimpul; i++){
        dataBusur[i] = dataBusur[i-1] + jumlahSimpul;
    }

    cout << " Silahkan memasukkan nama simpul" << endl;
    for (int i=0; i<jumlahSimpul; i++){
        cout << " Simpul " << i+1 << ": ";
        cin >> dataSimpul[i];
    }
    cout << endl;

    cout << " Silahkan masukkan bobot antar simpul" << endl;
    for (int baris = 0; baris < jumlahSimpul; baris++){
        for (int kolom = 0; kolom < jumlahSimpul; kolom++){
            cout << " " << dataSimpul[baris] << " --> " << dataSimpul[kolom] << ": ";
            cin >> dataBusur[baris][kolom];
        }
    }
    cout << endl;

    cekMatriks = true;
}

//Hitung Lintasan Terpendek
void jarakTerdekat()
{
    if (cekMatriks){
        //Membuat matriks yang sama dengan matriks dataBusur
        jalurTerdekat = new int*[jumlahSimpul];
        jalurTerdekat[0] = new int[jumlahSimpul * jumlahSimpul];

        for (int i=1; i<jumlahSimpul; i++){
            jalurTerdekat[i] = jalurTerdekat[i-1] + jumlahSimpul;
        }

        //Duplikasi isi matriks dataBusur ke dalam matriks jalurTerdekat
        for (int baris = 0; baris < jumlahSimpul; baris++){
            for (int kolom = 0; kolom < jumlahSimpul; kolom++){
                jalurTerdekat[baris][kolom] = dataBusur[baris][kolom];
            }
        }

        for (int k=0; k<jumlahSimpul; k++){
            for (int baris = 0; baris < jumlahSimpul; baris++){
                for (int kolom = 0; kolom < jumlahSimpul; kolom++){
                    if (jalurTerdekat[baris][k] + jalurTerdekat[k][kolom] < jalurTerdekat[baris][kolom]){
                        jalurTerdekat[baris][kolom] = jalurTerdekat[baris][k] + jalurTerdekat[k][kolom];
                    }
                }
            }
        }

        //Tampilkan hasil
        cout << left << setw(4) << " ";
        for (int i = 0; i < jumlahSimpul; i++){
            cout  << left << setw(5) << dataSimpul[i] << " ";
        }
        cout << endl;

        for (int baris = 0; baris < jumlahSimpul; baris++){
            cout << " " << dataSimpul[baris] << left << setw(2) << " ";
            for (int kolom = 0; kolom < jumlahSimpul; kolom++){
                cout << left << setw(5) << jalurTerdekat[baris][kolom] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

//Tampil
void tampilMatriks()
{
    if (cekMatriks){
        cout << left << setw(4) << " ";
        for (int i=0; i<jumlahSimpul; i++){
            cout  << left << setw(5) << dataSimpul[i] << " ";
        }
        cout << endl;

        for (int baris = 0; baris < jumlahSimpul; baris++){
            cout << " " << dataSimpul[baris] << left << setw(2) << " ";
            for (int kolom = 0; kolom < jumlahSimpul; kolom++){
                cout << left << setw(5) << dataBusur[baris][kolom] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    else{
        cout << " Matriks masih kosong!" << endl;
        cout << endl;
    }
}

int main()
{
    cout << " Silahkan masukkan jumlah simpul: ";
    cin >> jumlahSimpul;

    buatMatriks();
    tampilMatriks();
    jarakTerdekat();

    return 0;
}