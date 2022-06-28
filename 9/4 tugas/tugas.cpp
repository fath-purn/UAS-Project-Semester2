#include <iostream>
#include <string>
using namespace std;

///PROGRAM REPRESENTASI GRAPH DENGAN LINKED LIST
//Deklarasi Global

int jumlahSimpul = 7;
string *dataSimpul; //digunakan untuk membuat array dinamis
int **dataBusur; //digunakan untuk membuat array dinamis dua dimensi

//Deklarasi Linked List
struct Graph
{
    string data;
    Graph *kanan;
    Graph *kiri;
};

Graph *simpul, *busur, *awal, *akhir, **alamat, *bantu, *bantu2;

//Inisialisasi
void init()
{
    awal = NULL;
    akhir = NULL;
}

//isEmpty
int isEmpty()
{
    if (awal == NULL && akhir == NULL)
    return 1; //true
    else
    return 0; //false
}

//Buat Matriks
void buatMatriks()
{
    dataSimpul = new string[jumlahSimpul];
    dataBusur = new int*[jumlahSimpul];
    dataBusur[0] = new int[jumlahSimpul * jumlahSimpul]; //inisialisasi ukuran elemen matriks

    for (int i = 1; i < jumlahSimpul; i++){
        dataBusur[i] = dataBusur[i-1] + jumlahSimpul;
    }

    //Membuat matriks 2 dimensi dengan ukuran sesuai masukan user
    //Proses input nama simpul
    cout << " Silahkan masukkan nama kota" <<endl; //input nama simpul sebanyak jumlah simpul
    for (int i = 0; i < jumlahSimpul; i++){
        cout << " Kota " <<i+1<< " : ";
        cin >> dataSimpul[i];
    }
    
    //Proses input nilai busur (bobot)
    cout << endl << " Silahkan masukkan bobot antar kota" << endl; //input bobot busur antar simpul
    for (int m = 0; m < jumlahSimpul; m++){
        for (int n = 0; n < jumlahSimpul; n++){
            cout << " " << dataSimpul[m] << " --> " << dataSimpul[n] << " : "; //input bobot sebagai baris dan kolom
            cin >> dataBusur[m][n];
        }
    }
}

//Buat Simpul Graph
void buatSimpulGraph()
{
    alamat = new Graph*[jumlahSimpul]; //membuat pointer alamat sebanyak jumlah simpul
    buatMatriks();

    for (int i=0; i<jumlahSimpul; i++){
        if (isEmpty() == 1){
            simpul = new Graph;
            simpul->data = dataSimpul[i];
            simpul->kanan = NULL;
            simpul->kiri = NULL;
            awal = simpul;
            akhir = simpul;
            alamat[i] = awal;
        }
        else{
            simpul = new Graph;
            simpul->data = dataSimpul[i];
            akhir->kiri = simpul;
            akhir = simpul;
            simpul->kiri = NULL;
            simpul->kanan = NULL;
            alamat[i] = akhir;
        }
    }
    bantu = awal;
    for (int m=0; m<jumlahSimpul; m++){
        bantu2 = bantu;
        for (int n=0; n<jumlahSimpul; n++){
            if (dataBusur[m][n] != 0){
                simpul = new Graph;
                simpul->data = to_string(dataBusur[m][n]);
                bantu2->kanan = simpul;
                simpul->kiri = alamat[n];
                simpul->kanan = NULL;
                bantu2 = simpul;
            }
        }
        bantu = bantu->kiri;
    }
}

//Tampil
void tampilGraph()
{
    cout << endl << " Hasil graph: " << endl;
    if (isEmpty() == 0){
        bantu = awal;
        while (bantu != NULL){
            cout << " " << bantu->data << ": ";
            bantu2 = bantu->kanan;
            while (bantu2 != NULL){
                cout << bantu2->kiri->data << ": " << bantu2->data << " ";
                bantu2 = bantu2->kanan;
            }
            cout << endl;
            bantu = bantu->kiri;
        }
    }
    else{
    cout << " Graph masih kosong!" << endl;
    }
}

// fungsi mencari busur terpendek
void cariBusur()
{
    for (int i=0; i<jumlahSimpul; i++){
        for (int m=0; m<jumlahSimpul; m++){
            if (dataBusur[i][m] != 0){
                // mencari simpul yang memiliki busur terpendek
                if (dataBusur[i][m] < dataBusur[i][m+1]){
                    dataBusur[i][m+1] = dataBusur[i][m];
                }
            }
        }
    }
    cout << endl << " Simpul terpendek: " << dataBusur[jumlahSimpul-1][jumlahSimpul-1] << endl;

}

int main()
{
    init();
    cout << " Silahkan masukkan jumlah kota: ";
    cin >> jumlahSimpul;
    cout << endl;

    buatSimpulGraph();
    tampilGraph();
    cariBusur();
    return 0;
}