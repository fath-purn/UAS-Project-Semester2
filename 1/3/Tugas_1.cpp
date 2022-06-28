// Nama : Fatkhurrohman Purnomo
// Kelas : IF-09-D
// NIM : 21102125

#include <iostream>
#include <string.h>
using namespace std;

// fungsi utama
int main()
{
    // deklarasi variabel dan array untuk menyimpan data
    int n; // banyak data
    string nama[20]; // array untuk menyimpan nama
    int jumlah[20], harga[20], total[20]; // array untuk menyimpan jumlah, harga, dan total
    int total_harga = 0; // variabel untuk menyimpan total harga
    int total_item = 0; // variabel untuk menyimpan total item

    // input jumlah data yang akan dimasukan
    cout << "Masukkan Jumlah Data = "; 
    cin >> n;
    cout << endl;

    // input data Nama, Jumlah, Harga, dan dimasukan ke dalam array yang sudah dibuat
    for (int i=0; i<n; i++) {
        cout << endl;
        cout << "Data ke-" << i+1 << endl;
        cout << "Masukkan Nama = ";
	    cin >> nama[i]; // input nama
        cout << "Masukkan Jumlah = ";
        cin >> jumlah[i]; // input jumlah
        cout << "Masukkan Harga = ";
        cin >> harga[i]; // input harga
        
        total[i] = jumlah[i] * harga[i]; // menghitung total
        total_harga += total[i]; // menjumlahkan total harga
        total_item += jumlah[i]; // menjumlahkan total item
    }

    // output data yang sudah dimasukan berupa Nama, Jumlah, Harga, dan Total Harga
    cout << endl;
    cout << "               Daftar Barang " << endl;
    cout << "=========================================" << endl;
    cout << "Kode    Nama   Jumlah   Harga   Total " << endl;
    cout << "=========================================" << endl;
    for (int i=0; i<n; i++) {
        cout << "00" << i+1 << "    " << nama[i] << "   " << jumlah[i] << "     Rp." << harga[i] << "    Rp." << total[i] << endl;
        cout << "=========================================" << endl;
    }
    
    // output total harga dan total jumlah
    cout << "Jumlah item = " << total_item << endl;
    cout << "Total Pembelian = Rp." << total_harga << endl;

    return 0;
}