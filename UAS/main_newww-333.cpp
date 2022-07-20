#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string>

using namespace std;

int maksimal_antrian_barang; // mengurutkan sesuai dg antrian barang  apa sajayg akan dilakukan pengecekan oleh admid dalam 1 minggu kedepan
int pilihan, pilih, pil;
string kode_barang, kode_rak; // dg memasukkan kode barang
void menu_utama();

int menu, jh, m_idx, cari, dataedite; // jh jumlah data

// prosedur menu login ke aplikasi
void menuLogin()
{

    string username;
    int password;
    int i;

    cout << "====================================================================================\n";
    cout << "       SELAMAT DATANG DI APLIKASI MANAJEMEN GUDANG TOKO ANEKA JAYA PURWOKERTO      \n";
    cout << "====================================================================================\n" << endl;
    string user = "a";
    int pass = 1;
    int login = 0;
    i = 0;

    do
    {
        cout << "\n Username : ";
        cin >> username;
        cout << "\n Password : ";
        cin >> password;
        if (username == user && password == pass)
        {
            i = 4;
            login = 1;
            menu_utama();
        }
        else
        {
            cout << "\n ___________________________________\n"<< endl;
            cout << "\n|     Maaf ID & PASSWORD Salah!!!   | \n";
            cout << "\n|___________________________________|\n" << endl;
            i++;
        }
    } while (i != 3);
    if (login != 1)
    {
        cout << "Anda Telah 3x Memasukan ID & PASSWORD Yang Salah" << endl;
        cout << "Mohon Login Kembali Setelah 30 abad, Terima Kasih.." << endl << endl;
        system("pause");
    }
}

// menu list antrian barang yang akan di lakukan pengecekan dalam 1 minggu kedepan
// dicek berdasarkan antian barang yang dimasukkan terlebih dahulu
// jadi dicek secara berurutan berdasarkan no.antrian barang
struct antrian_pengecekan_barang
{
    int depan;
    int belakang;
    string *kodebr = new string[maksimal_antrian_barang];
} urutan_pengecekan;

void nilai_awal()
{
    urutan_pengecekan.depan = -1;
    urutan_pengecekan.belakang = -1;
}

int antrian_barang_penuh()
{
    if (urutan_pengecekan.belakang == maksimal_antrian_barang - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int antrian_barang_kosong()
{
    if (urutan_pengecekan.depan == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void masukkan_antrian_pengecekan(string kode_barang)
{ // memasukkan kode barang apa saja yg akan di cek dalam 1 minggu kedepan
    if (antrian_barang_kosong() == true)
    {
        urutan_pengecekan.depan = 0;
        urutan_pengecekan.belakang = 0;
        urutan_pengecekan.kodebr[urutan_pengecekan.belakang] = kode_barang;
        urutan_pengecekan.belakang++;
        cout << "Kode Barang Sudah Masuk" << endl;
    }
    else if (antrian_barang_penuh() == false)
    {
        urutan_pengecekan.belakang++;
        urutan_pengecekan.kodebr[urutan_pengecekan.belakang] = kode_barang;
        cout << "Kode Barang Sudah Masuk" << endl;
    }
    else
    {
        cout << "Antrian Pengecekan Barang Sudah Penuh" << endl;
    }
}

void hapus_antrian_pengecekan()
{ // jika pengecekan sudah selesai maka data bisa dihapus
    if (antrian_barang_kosong() == false)
    {
        urutan_pengecekan.depan++;
        cout << "Kode [" << urutan_pengecekan.kodebr[urutan_pengecekan.depan] << "] sudah dihapus" << endl;
        urutan_pengecekan.kodebr[urutan_pengecekan.depan] = "";
    }
    else
    {
        cout << "Antrian Pengecekan Barang Kosong" << endl;
    }
}

void tampil_data_pengecekan()
{
    if (antrian_barang_kosong() == false)
    {
        cout << "Data Pengecekan Barang : " << endl;
        for (int i = urutan_pengecekan.depan + 1; i <= urutan_pengecekan.belakang; i++)
        {

            cout << "Kode Barang : " << urutan_pengecekan.kodebr[i] << endl;
        }
    }
    else
    {
        cout << "Antrian Pengecekan Barang Kosong" << endl;
    }
}

// prosedur untuk membuat pelatakkan rak barang menggunakan dlinkedlist
struct dlinkedlist_rak
{ // untuk membuat menu tempat peletakkan barang
    dlinkedlist_rak *prev;
    string kode;
    dlinkedlist_rak *next;
};

dlinkedlist_rak *head;
dlinkedlist_rak *tail;
dlinkedlist_rak *vertex;

void inisialisasi_rak()
{
    head = NULL;
    tail = NULL;
}

bool rak_kosong()
{
    if (head == NULL && tail == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void tambahDepan(string kode_rak)
{
    if (rak_kosong() == true)
    {
        vertex = new dlinkedlist_rak;
        vertex->kode = kode_rak;
        vertex->prev = NULL;
        vertex->next = NULL;
        head = vertex;
        tail = vertex;
    }
    else
    {
        vertex = new dlinkedlist_rak;
        vertex->kode = kode_rak;
        vertex->prev = NULL;
        vertex->next = NULL;
        vertex->next = head;
        vertex->prev = vertex;
        head = vertex;
    }
}

void tambahBelakang(string kode_rak)
{
    if (rak_kosong() == true)
    {
        vertex = new dlinkedlist_rak;
        vertex->kode = kode_rak;
        vertex->prev = NULL;
        vertex->next = NULL;
        head = vertex;
        tail = vertex;
    }
    else
    {
        vertex = new dlinkedlist_rak;
        vertex->kode = kode_rak;
        vertex->prev = NULL;
        vertex->next = NULL;
        tail->next = vertex;
        vertex->prev = tail;
        tail = vertex;
    }
}

void hapusDepan()
{
    if (rak_kosong() == true)
    {
        cout << "Rak Barang Kosong..!!!" << endl
            << endl;
    }
    else
    {
        dlinkedlist_rak *helper;
        helper = head;
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
            delete helper;
        }
        else
        {
            head = head->next;
            head->prev = NULL;
            helper->next = NULL;
            delete helper;
        }
    }
}

void hapusBelakang()
{
    if (rak_kosong() == true)
    {
        cout << "Rak Barang Kosong..!!!" << endl
            << endl;
    }
    else
    {
        if (head == tail)
        {
            dlinkedlist_rak *helper;
            helper = head;
            head = NULL;
            tail = NULL;
            delete helper;
        }
        else
        {
            dlinkedlist_rak *helper;
            helper = tail;
            tail = tail->prev;
            tail->next = NULL;
            helper->prev = NULL;
            delete helper;
        }
    }
}

// hapus semua
void hapusSemua()
{
    if (rak_kosong() == true)
    {
        cout << "Rak Barang Kosong..!!!" << endl;
    }
    else
    {
        dlinkedlist_rak *helper;
        helper = head;
        while (head != NULL)
        {
            head = head->next;
            delete helper;
            helper = head;
        }
        head = NULL;
        tail = NULL;
    }
}

void tampilData()
{
    if (rak_kosong() == true)
    {
        cout << "Rak Barang Kosong..!!!" << endl << endl;
    }
    else
    {
        cout << "Kode Rak Yang Tersedia:" << endl;
        dlinkedlist_rak *helper;
        helper = head;
        while (helper != NULL)
        {
            cout << helper->kode << " ";
            helper = helper->next;
        }
    }
}

// menu data barang
struct data_barang
{
    string nama_barang;
    char kd_barang;
    int no, jumlah_stock, harga_barang;
} data[50];

int init[50]={0};
int t = 1;

void input_data_barang()
{
    cout << " Masukkan Kode Barang  : ";
    cin >> data[t].kd_barang;
    cout << " Masukkan Nama Barang  : ";
    cin >> data[t].nama_barang;
    cout << " Masukkan Jumlah Stock : ";
    cin >> data[t].jumlah_stock;
    cout << " Harga Barang          : Rp. ";
    cin >> data[t].harga_barang;
    
    init[t] = 1;
    
    t++;
}

void data_Brng()
{
    for (int i = 1; i < 5; i++)
    {   
        if (init[i] != 0)
        {
            cout << " Barang yang tersedia [" << i << "] : " << endl;
            cout << " Kode Barang : " << data[i].kd_barang << endl;
            cout << " Nama Barang : " << data[i].nama_barang << endl;
            cout << " Jumlah Stock : " << data[i].jumlah_stock << endl;
            cout << " Harga Barang : Rp. " << data[i].harga_barang << endl;
            cout << "_________________________________________________________" << endl;
        }
    }
}

void edit_data_barang()
{
    int pilih;
    cout << " Masukkan Kode Barang yang ingin di edit : ";
    cin >> pilih;
    if (init[pilih] != 0)
    {
        cout << " Masukkan Kode Barang  : ";
        cin >> data[pilih].kd_barang;
        cout << " Masukkan Nama Barang  : ";
        cin >> data[pilih].nama_barang;
        cout << " Masukkan Jumlah Stock : ";
        cin >> data[pilih].jumlah_stock;
        cout << " Harga Barang          : Rp. ";
        cin >> data[pilih].harga_barang;
    }
    else
    {
        cout << " Barang tidak ditemukan..!!!" << endl;
    }
}


void pembelian_barang()
{
    int jumlah_beli;
    char kode;

    cout << " Kode Barang : ";
    cin >> kode;

    for (int i = 1; i < 5; i++)
    {
        if(data[i].kd_barang == kode)
        {
            cout << " Jumlah Barang yang dibeli : ";
            cin >> jumlah_beli;
            data[i].jumlah_stock = data[i].jumlah_stock - jumlah_beli;
            int bayar = jumlah_beli * data[i].harga_barang;
            
            cout << " Total Pembayaran : Rp. " << bayar << endl;
            cout << " Barang berhasil dibeli..!!!" << endl;
        }
        else 
        {
            cout << " Barang tidak ditemukan..!!!" << endl; 
        }
    }
}

// data supplier
struct supplier
{
    // int depan;
    // int belakang;
    string *sup = new string[5];

} kode_suplier, nama_suplier, alamat, kota, provinsi, telepon;

int supp[50] = {0};
int b = 1;

// tambah supplier
void addSup()
{
    cout << " Masukkan Kode Supplier     : ";
    cin >> kode_suplier.sup[b];
    cout << " Masukkan Nama Supplier     : ";
    cin >> nama_suplier.sup[b];
    cout << " Masukkan Alamat Supplier   : ";
    cin >> alamat.sup[b];
    cout << " Masukkan Kota Supplier     : ";
    cin >> kota.sup[b];
    cout << " Masukkan Provinsi Supplier : ";
    cin >> provinsi.sup[b];
    cout << " Masukkan Telepon Supplier  : ";
    cin >> telepon.sup[b];
    cout << endl << "       Data Berhasil Ditambahkan" << endl << endl;

    supp[b] = 1;
    b++;
}

// menampilkan kode supplier
void kodeSup()
{
    for (int i = 1; i < 5; i++)
    {
        if (supp[i] != 0)
            cout << " Kode Supplier [" << i << "] " << nama_suplier.sup[i] << endl;
    }
    cout << endl;
}

// hapus supplier
void hapusSup()
{
    kodeSup();
    int i = 1;
    cout << " Kode Supplier (sesuai angka): ";
    cin >> i;
    
    kode_suplier.sup[i] = ""; 
    nama_suplier.sup[i] = "";
    alamat.sup[i] = "";
    provinsi.sup[i] = "";
    telepon.sup[i] = "";

    supp[i] = 0;
}

// menampilkan supplier
void tampilSup()
{
    kodeSup();
    int i = 1;
    cout << " Kode Supplier (sesuai angka) : ";
    cin >> i;
    cout << endl;
    cout << "           Data supplier        " << endl;
    cout << " Nama Supplier      : " << kode_suplier.sup[i] << endl;
    cout << " Alamat Supplier    : " << nama_suplier.sup[i] << endl;
    cout << " Kota Supplier      : " << alamat.sup[i] << endl;
    cout << " Provinsi Supplier  : " << provinsi.sup[i] << endl;
    cout << " Telepon Supplier   : " << telepon.sup[i] << endl << endl;
}

//menu 4 (konsep graph) jarak antar gudang
//deklarasikan variabel global
//deklarasikan variabel global
int jumlahSimpul = 5;
string *dataSimpul;//digunakan untuk membuat array dinamis
int **dataBusur;//digunakan untuk membuat array dinamis dua dimensi
bool cekMatrik = false;
int indeksPosisi, simpulSaatIni, simpulAsal, simpulTujuan, jarakSaatIni, jarakLama, jarakBaru;
int dikunjungi = 1;
int belumDikunjungi = 0;
int *jarakDiketahui;
int *kunjungan;

//buat matriks
void buatMatriks(){
    dataSimpul = new string[jumlahSimpul];
    dataBusur = new int*[jumlahSimpul];
    dataBusur[0] = new int[jumlahSimpul * jumlahSimpul];//inisiaisasi ukuran elemen array
    for(int i = 1; i < jumlahSimpul; i++){
            //ukuran matriks sesuai masukkan user
        dataBusur[i] = dataBusur[i-1] + jumlahSimpul;
    }
    //proses input nama simpul
    cout<<" Silahkan masukkan nama cabang"<<endl;
    for(int i = 0; i < jumlahSimpul; i++){
        cout<<" Cabang "<<i+1<<" : ";
        cin>>dataSimpul[i];
    }//memberi nama simpul sesuai inputan user
    cout<<endl<<endl;
    //proses pemberian nilai busur (bobot)
    cout<<" Silahkan masukkan jarak antar cabang"<<endl;
    for(int baris = 0; baris < jumlahSimpul; baris++){
        for(int kolom = 0; kolom < jumlahSimpul; kolom++){
            cout<<dataSimpul[baris]<<" --> "<<dataSimpul[kolom]<<" : ";//pemberian bobot sebagao baris dan kolom
            cin>> dataBusur[baris][kolom];
        }
    }
    cekMatrik = true;
    cout<<endl<<endl;
}

//menhitung jarak terdekat/lintasan terpendek
void hitungJarakTerdekat(){
    if(cekMatrik){
        jarakDiketahui = new int[jumlahSimpul];//mengecek apakah matriks sudah terisi
        kunjungan = new int[jumlahSimpul];
        for(int i = 0; i < jumlahSimpul; i++){
            jarakDiketahui[i] = 999; //Nilai 999 dianggap sebagai infinity atau tak hingga
            kunjungan[i] = belumDikunjungi;
         }
         kunjungan[simpulAsal] = dikunjungi;
         jarakDiketahui[simpulAsal] = 0;
         simpulSaatIni = simpulAsal;
         while(simpulSaatIni != simpulTujuan){
            jarakLama = 999;
            jarakSaatIni = jarakDiketahui[simpulSaatIni];
            for(int i = 0; i < jumlahSimpul; i++){
                if(kunjungan[i] == belumDikunjungi){
                    jarakBaru = jarakSaatIni + dataBusur[simpulSaatIni][i];
                    if(jarakBaru < jarakDiketahui[i]){
                        jarakDiketahui[i] = jarakBaru;
                    }
                    if(jarakDiketahui[i] < jarakLama){
                        jarakLama = jarakDiketahui[i];
                        indeksPosisi = i;
                    }
                }
            }
            simpulSaatIni = indeksPosisi;
            kunjungan[simpulSaatIni] = dikunjungi;
        }
         cout<<endl;
         cout << " Lintasan terpendek dari cabang " << dataSimpul[simpulAsal] << " ke cabang " << dataSimpul[simpulTujuan] << " adalah " << jarakDiketahui[simpulTujuan] << endl;
         delete jarakDiketahui;
         delete kunjungan;
    }
}

//prosedur menampilakan metriks
void tampilMatriks(){
    if(cekMatrik){
        for(int i = 0; i < jumlahSimpul; i++){
            cout<<dataSimpul[i]<<" ";
         }
         cout<<endl;
         for(int baris = 0; baris < jumlahSimpul; baris++){
            for(int kolom = 0; kolom < jumlahSimpul; kolom++){
            cout<<dataBusur[baris][kolom]<<" ";
            }
            cout<<endl;
         }
     }else{
        cout<<" Tidak ada matriks"<<endl;
     }
}


void menu_utama()
{
    int n = 0, nomor_barang = 1, kode_Barang;
    system("cls");
    do
    {
        cout << "\t==============================================" << endl;
        cout << "\t           MENU UTAMA  MANAJEMEN GUDANG       " << endl;
        cout << "\t                  TOKO CRAFTORYX              " << endl;
        cout << "\t==============================================" << endl;
        cout << "\t 1. Mendata Antrian Barang Yang Akan Di-cek" << endl;
        cout << "\t 2. Mendata Persediaan Rak Barang" << endl;
        cout << "\t 3. Mendata Supplier" << endl;
        cout << "\t 4. Input / beli barang" << endl;
        cout << "\t 5. Cabang toko Craftoryx" << endl;
        cout << "\t 0. Keluar program." << endl;
        cout << "\t===============================================" << endl;
        cout << "  Masukkan Pilihan Menu (1-6) : ";
        cin >> pilih;
        cout << endl << endl;

        switch (pilih)
        {
        case 1:
            do
            {
                cout << "=========================================================" << endl;
                cout << "|           Antrian Pengecekan Barang Dalam 1 Minggu    |" << endl;
                cout << "|                   Toko Aneka Jaya Purwokerto          |" << endl;
                cout << "=========================================================" << endl;
                cout << "| 1. Masukkan Jumlah Maksimal Barang Yang Akan Di-cek   |" << endl;
                cout << "| 2. Masukkan Kode Barang Yang Akan Di-cek              |" << endl;
                cout << "| 3. Hapus Kode Barang [Jika Telah Di-cek]              |" << endl;
                cout << "| 4. Tampilkan Kode Barang Yang Akan Di-cek             |" << endl;
                cout << "| 5. Keluar                                             |" << endl;
                cout << "Masukkan Pilihan Menu (1-5) : ";
                cin >> pilihan;
                cout << endl << endl;
                switch (pilihan)
                {
                case 1:
                    cout << "Masukkan Jumlah Maksimal Barang Yang Akan Di-Cek [Bilangan Bulat] : ";
                    cin >> maksimal_antrian_barang;
                    cout << endl << endl;
                    cout << " Pengaturan Pengecekan Barang Untuk 1 Minggu Kedepan Selesai" << endl;
                    break;
                case 2:
                    cout << " Silahkan Masukkan Kode Barang  : ";
                    cin >> kode_barang;
                    cout << "________________________________________________________" << endl;
                    masukkan_antrian_pengecekan(kode_barang);
                    break;
                case 3:
                    hapus_antrian_pengecekan();
                    break;
                case 4:
                    tampil_data_pengecekan();
                    break;
                case 5:
                    cout << "________________________________________________________" << endl;
                    cout << "\t             ANDA TELAH lOGOUT ! ! ! " << endl;
                    cout << "________________________________________________________" << endl;
                    menu_utama();
                    break;
                default:
                    cout << "\t Pilihan Menu Tidak Tersedia !!!" << endl;
                    cout << "________________________________________________________" << endl;
                }
            } while (pilihan != 5);
            break;

        case 2:
            do
            { // masukkan kode rak
                cout << endl << endl;
                cout << "==============================================" << endl;
                cout << " Pendataan Persediaan Rak Barang" << endl;
                cout << "==============================================" << endl;
                cout << " 1. Tambahkan Rak Barang di Depan" << endl;
                cout << " 2. Tambahkan Rak Barang di Belakang" << endl;
                cout << " 3. Kosongkan Rak Barang di Depan" << endl;
                cout << " 4. Kosongkan Rak Barang Dari Belakang" << endl;
                cout << " 5. Kosongkan Semua Barang di Rak" << endl;
                cout << " 6. Tampilkan Rak Barang Yang Tersedia" << endl;
                cout << " 7. Kembali Ke Menu Utama" << endl;
                cout << "==============================================" << endl;
                cout << " Silahkan Masukkan Pilihan Anda [1-6] : ";
                cin >> pil;
                cout << endl;

                switch (pil)
                {
                case 1:
                    cout << "Silahkan Masukkan Kode Rak : ";
                    cin >> kode_rak;
                    tambahDepan(kode_rak);
                    break;
                case 2:
                    cout << "Silahkan Masukkan Kode Rak : ";
                    cin >> kode_rak;
                    tambahBelakang(kode_rak);
                    break;
                case 3:
                    hapusDepan();
                    break;
                case 4:
                    hapusBelakang();
                    break;
                case 5: 
                    hapusSemua();
                case 6:
                    tampilData();
                    break;
                case 7:
                    cout << "________________________________________________________" << endl;
                    cout << "\t            ANDA TELAH LOGOUT ! ! ! " << endl;
                    cout << "________________________________________________________" << endl;
                    menu_utama();
                    break;
                default:
                    cout << "\t Pilihan Menu Tidak Tersedia !!!" << endl;
                }
            } while (pil != 8);
            break;
        case 3: // masih banyak bug
            do
            {
                cout << "=========================================================" << endl;
                cout << "|                                                       |" << endl;
                cout << "|                     Data Suplier                      |" << endl;
                cout << "|                                                       |" << endl;
                cout << "=========================================================" << endl;
                cout << "| 1. Tambah Data Suplier                                |" << endl;
                cout << "| 2. Hapus Data Suplier                                 |" << endl;
                cout << "| 3. Tampilkan Data Suplier                             |" << endl;
                cout << "| 4. Kembali Ke Menu Utama                              |" << endl;
                cout << "Masukkan Pilihan Menu : ";
                cin >> pilihan;
                cout << endl << endl;
                switch (pilihan)
                {
                case 1:
                    addSup();
                    break;
                case 2:
                    hapusSup();
                    break;
                case 3:
                    tampilSup();
                    break;
                case 4:
                    cout << "________________________________________________________" << endl;
                    cout << "\t             ANDA TELAH lOGOUT ! ! ! " << endl;
                    cout << "________________________________________________________" << endl;
                    menu_utama();
                    break;
                default:
                    cout << "\t Pilihan Menu Tidak Tersedia !!!" << endl;
                    cout << "________________________________________________________" << endl;
                }
            } while (pilihan != 4);
            break;
        case 4:
            do
            {
                cout << "=========================================================" << endl;
                cout << "|                                                       |" << endl;
                cout << "|                  Input / beli barang                  |" << endl;
                cout << "|                                                       |" << endl;
                cout << "=========================================================" << endl;
                cout << "| 1. Input data barang                                  |" << endl;
                cout << "| 2. Edit data barang                                   |" << endl;
                cout << "| 3. Tampilkan data barang                              |" << endl;
                cout << "| 4. pembelian                                          |" << endl;
                cout << "| 5. Keluar                                             |" << endl;
                cout << "Masukkan Pilihan Menu : ";
                cin >> pilihan;
                cout << endl << endl;
                switch (pilihan)
                {
                case 1:
                    input_data_barang();
                    break;
                case 2:
                    edit_data_barang();
                    break;
                case 3:
                    data_Brng();
                    break;
                case 4:
                    pembelian_barang();
                    break;
                case 5:
                    cout << "________________________________________________________" << endl;
                    cout << "\t             ANDA TELAH lOGOUT ! ! ! " << endl;
                    cout << "________________________________________________________" << endl;
                    menu_utama();
                    break;
                default:
                    cout << "\t Pilihan Menu Tidak Tersedia !!!" << endl;
                    cout << "________________________________________________________" << endl;
                }
            } while (pilihan != 5);
            break;
        case 5:
            do
            {
                cout << "=========================================================" << endl;
                cout << "|                                                       |" << endl;
                cout << "|                  Cabang Craftoryx                     |" << endl;
                cout << "|                                                       |" << endl;
                cout << "=========================================================" << endl;
                cout << "| 1. Tambah cabang                                      |" << endl;
                cout << "| 2. Cabang Craftoryx                                   |" << endl;
                cout << "| 3. Jarak antar cabang                                 |" << endl;
                cout << "| 4. Keluar                                             |" << endl;
                cout << "Masukkan Pilihan Menu : ";
                cin >> pilihan;
                cout << endl << endl;
                switch (pilihan)
                {
                case 1:
                    cout<<" Silahkan masukkan jumlah cabang  : ";
                    cin>>jumlahSimpul;
                    cout << endl;
                    buatMatriks();
                    break;
                case 2:
                    tampilMatriks();
                    break;
                case 3:
                    cout<<" Silahkan masukkan cabang asal (0 - "<<jumlahSimpul-1<<") : ";
                    cin>>simpulAsal;
                    cout<<" Silahkan masukkan cabang tujuan (0 - "<<jumlahSimpul-1<<") : ";
                    cin>>simpulTujuan;
                    hitungJarakTerdekat();
                    break;
                case 4:
                    cout << "________________________________________________________" << endl;
                    cout << "\t             ANDA TELAH lOGOUT ! ! ! " << endl;
                    cout << "________________________________________________________" << endl;
                    menu_utama();
                    break;
                default:
                    cout << "\t Pilihan Menu Tidak Tersedia !!!" << endl;
                    cout << "________________________________________________________" << endl;
                }
            } while (pilihan != 4);
            break;
        default:
            cout << "\t Pilihan Menu Tidak Tersedia !!!" << endl;
            cout << "________________________________________________________" << endl;
        }
    } while (pil != 0);
}

int main()
{
    menuLogin();
    return 0;
}