// Nama : Fatkhurrohman Purnomo
// NIM : 21102125

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/// PROGRAM PENCARIAN LINTASAN TERPENDEK
// Deklarasi Global
int jumlahSimpul;
string *dataSimpul;
int **dataBusur;
int **jalurTerdekat;
int *jarakDiketahui;
int *kunjungan;
int indeksPosisi, simpulSaatIni, simpulAsal, simpulTujuan, jarakSaatIni, jarakLama, jarakBaru;
int dikunjungi = 1;
int belumDikunjungi = 0;
bool cekMatriks = false;

// Buat Graph
void buatMatriks()
{
    dataSimpul = new string[jumlahSimpul];
    dataBusur = new int *[jumlahSimpul];
    dataBusur[0] = new int[jumlahSimpul * jumlahSimpul];
    for (int i = 1; i < jumlahSimpul; i++)
    {
        dataBusur[i] = dataBusur[i - 1] + jumlahSimpul;
    }
    cout << " Silahkan masukkan nama simpul" << endl;
    
    for (int i = 0; i < jumlahSimpul; i++)
    {
        cout << " Simpul " << i + 1 << ": ";
        cin >> dataSimpul[i];
    }
    cout << endl;
    cout << " Silahkan masukkan bobot antar simpul" << endl;
    
    for (int baris = 0; baris < jumlahSimpul; baris++)
    {
        for (int kolom = 0; kolom < jumlahSimpul; kolom++)
        {
            cout << " " << dataSimpul[baris] << " --> " << dataSimpul[kolom] << ": ";
            cin >> dataBusur[baris][kolom];
        }
    }
    cout << endl;
    cekMatriks = true;
}

// Hitung Jarak Terpendek dengan Algoritma Dijkstra
void jarakTerdekatSatu()
{
    if (cekMatriks)
    {
        jarakDiketahui = new int[jumlahSimpul];
        kunjungan = new int[jumlahSimpul];

        for (int i = 0; i < jumlahSimpul; i++)
        {
            jarakDiketahui[i] = 999; // Nilai 999 dianggap sebagai nilai infinity (tak hingga)
            kunjungan[i] = belumDikunjungi;
        }
        kunjungan[simpulAsal] = dikunjungi;
        jarakDiketahui[simpulAsal] = 0;
        simpulSaatIni = simpulAsal;

        while (simpulSaatIni != simpulTujuan)
        {
            jarakLama = 999;
            jarakSaatIni = jarakDiketahui[simpulSaatIni];
            for (int i = 0; i < jumlahSimpul; i++)
            {
                if (kunjungan[i] == belumDikunjungi)
                {
                    jarakBaru = jarakSaatIni + dataBusur[simpulSaatIni][i];
                    if (jarakBaru < jarakDiketahui[i])
                    {
                        jarakDiketahui[i] = jarakBaru;
                    }
                    if (jarakDiketahui[i] < jarakLama)
                    {
                        jarakLama = jarakDiketahui[i];
                        indeksPosisi = i;
                    }
                }
            }
            simpulSaatIni = indeksPosisi;
            kunjungan[simpulSaatIni] = dikunjungi;
        }
        cout << " Hasil dari algoritma Dijkstra adalah: " << endl;
        cout << " Lintasan terpendek dari simpul indeks ke-" << simpulAsal << " (" << dataSimpul[simpulAsal] << ") " << "ke simpul indeks ke-" << simpulTujuan << " (" << dataSimpul[simpulTujuan] << ")" << " adalah " << jarakDiketahui[simpulTujuan] << endl;
        
        
        delete jarakDiketahui;
        delete kunjungan;
    }
}

// Hitung Lintasan Terpendek dengan menggabungkan algoritma Dijkstra dan Floyd – Warshall
void jarakTerdekatDua()
{
    if (cekMatriks)
    {
        // Membuat matriks yang sama dengan matriks dataBusur
        jalurTerdekat = new int *[jumlahSimpul];
        jalurTerdekat[0] = new int[jumlahSimpul * jumlahSimpul];
        for (int i = 1; i < jumlahSimpul; i++)
        {
            jalurTerdekat[i] = jalurTerdekat[i - 1] + jumlahSimpul;
        }
        
        // Duplikasi isi matriks dataBusur ke dalam matriks jalurTerdekat
        for (int baris = 0; baris < jumlahSimpul; baris++)
        {
            for (int kolom = 0; kolom < jumlahSimpul; kolom++)
            {
                jalurTerdekat[baris][kolom] = dataBusur[baris][kolom];
            }
        }
        
        for (int k = 0; k < jumlahSimpul; k++)
        {
            for (int baris = 0; baris < jumlahSimpul; baris++)
            {
                for (int kolom = 0; kolom < jumlahSimpul; kolom++)
                {
                    if (jalurTerdekat[baris][k] + jalurTerdekat[k][kolom] < jalurTerdekat[baris][kolom])
                    {
                        jalurTerdekat[baris][kolom] = jalurTerdekat[baris][k] + jalurTerdekat[k][kolom];
                    }
                }
            }
        }

        // Tampilkan hasil
        cout << " Hasil dari algoritma Floyd-Warshall: " << endl;
        cout << left << setw(4) << " ";
        for (int i = 0; i < jumlahSimpul; i++)
        {
            cout << left << setw(5) << dataSimpul[i] << " ";
        }
        cout << endl;
        
        for (int baris = 0; baris < jumlahSimpul; baris++)
        {
            cout << " " << setw(5) <<  dataSimpul[baris] << left << setw(2) << " ";
            for (int kolom = 0; kolom < jumlahSimpul; kolom++)
            {
                cout << left << setw(5) << jalurTerdekat[baris][kolom] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

// Tampil Data Graph
void tampilMatriks()
{
    if (cekMatriks)
    {
        cout << " Data Graph: " << endl;
        cout << left << setw(4) << " ";
        for (int i = 0; i < jumlahSimpul; i++)
        {
            cout << left << setw(5) << dataSimpul[i] << " ";
        }
        cout << endl;

        for (int baris = 0; baris < jumlahSimpul; baris++)
        {
            cout << " " << setw(5) << dataSimpul[baris] << left << setw(2) << " ";
            for (int kolom = 0; kolom < jumlahSimpul; kolom++)
            {
                cout << left << setw(5) << dataBusur[baris][kolom] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    else
    {
        cout << " Graph masih kosong!" << endl;
        cout << endl;
    }
}

int main()
{
    char keluar;
    int pilih;
    cout << " Silahkan masukkan jumlah simpul: ";
    cin >> jumlahSimpul;
    cout << endl;
    buatMatriks();
    tampilMatriks();

    do 
    {
        cout << endl << "===================================================" << endl;
        cout << "           Mencari lintasan terpendek" << endl;
        cout << "===================================================" << endl;
        cout << " Silahkan pilih menu: " << endl;
        cout << " 1. Algortitma Dijkstra" << endl;
        cout << " 2. Algoritma Floyd-Warshall" << endl;
        cout << " 3. Dua Algoritma" << endl;
        cout << " 4. Keluar" << endl;
        cout << " Pilih: ";
        cin >> pilih;
        cout << endl;

        switch (pilih)
        {
        case 1:
            cout << " Silahkan masukkan indeks simpul asal [0 - " << jumlahSimpul - 1 << "]: ";
            cin >> simpulAsal;
            cout << " Silahkan masukkan indeks simpul tujuan [0 - " << jumlahSimpul - 1 << "]: ";
            cin >> simpulTujuan;
            cout << endl;
            jarakTerdekatSatu();
            break;
        case 2:
            jarakTerdekatDua();
            break;
        case 3:
            cout << " Silahkan masukkan indeks simpul asal [0 - " << jumlahSimpul - 1 << "]: ";
            cin >> simpulAsal;
            cout << " Silahkan masukkan indeks simpul tujuan [0 - " << jumlahSimpul - 1 << "]: ";
            cin >> simpulTujuan;
            cout << endl;
            jarakTerdekatSatu();
            cout << endl;
            jarakTerdekatDua();
            break;
        default:
            break;
        }
    } while (pilih != 4);   // Selama pilih bukan 4, maka akan mengulangi program

    return 0;
}