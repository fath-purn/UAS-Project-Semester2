// Nama : Fatkhurrohman Purnomo
// Nim : 21102125

#include <iostream>
using namespace std;

// implementasi list berkait dimana setiap node / simbol memuat informasi struktur info dengan spesifikasi
// program entri data Tiket
struct Simpul
{
    string info;
    Simpul *next;
};

// asumsi list selalu menyimpan pointer Head dan Tail
Simpul *Head, *Tail;

// Menambah simpul di belakang tail (ekor), update tail lalu mereturn pointer tail yang baru
Simpul *AddData(string data)
{
    Simpul *baru = new Simpul;
    baru->info = data;
    baru->next= NULL;
    if (Head == NULL)
    {
        Head = Tail = baru;
    }
    else
    {
        Tail->next = baru;
        Tail = baru;
    }
    return Tail;
}

void inputTiket()
{
    // nomor, kelas, nomor kursi, tanggal
    string nomor, kelas, nomor_kursi, tanggal;

    // masukkan data
    cout << endl;
    cout << "Masukkan nomor tiket   : ";
    cin >> nomor;
    cout << "Masukkan kelas         : ";
    cin >> kelas;
    cout << "Masukkan nomor kursi   : ";
    cin >> nomor_kursi;
    cout << "Masukkan tanggal       : ";
    cin >> tanggal;

    // tambahkan data di belakang tail
    Tail = AddData(nomor);
    Tail = AddData(kelas);
    Tail = AddData(nomor_kursi);
    Tail = AddData(tanggal);

}

// Menelusuri dari head sampai tail dan print datanya
void PrintList()
{
    Simpul *p = Head;
    while (p != NULL)
    {
        cout << endl;
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

int main(){
    // inisialisasi list kosong
    Head = Tail = NULL;
    char pilih;

    do {
        cout << endl << "=======================================" << endl;
        cout << "               Pilih Menu : " << endl;
        cout << "=======================================" << endl;
        cout << "1. Entri tiket" << endl;
        cout << "2. Print list" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilih;

        switch (pilih)
        {
        case '1':
            inputTiket();
            break;
        case '2':
            PrintList();
            break;
        case '3':
            break;
        default:
            cout << "Pilihan tidak ada" << endl;
            break;
        }
    } while (pilih != '3');

    return 0;
}