//21102121_MANSUR JULIANTO

/*
* Buatlah array yang menampung data bebas (minimal 10 data), kemudian buatlah variabel pointer yang  menunjuk ke array tersebut. 
  1. Tampilkan semua nilai data/elemen dari array melalui pointer yang menunjuknya.
  2. Tampilkan semua alamat memori dari tiap elemen array melalui pointer yang menunjuknya.
  3.  Lakukan perubahan (re-inisialisasi) beberapa elemen array (minimal 5 data yang diubah) melalui pointer yang menunjuknya.
*/

#include <iostream>

using namespace std;

int main()
{
    //menampung data 10 data
    // buat variabel pointer yang menunjuk ke array
    int data[] = {1,2,3,4,5,6,7,8,9,10};
    int *pData = data;

    cout << "=================================" << endl; 
    cout << "|\tSemua data dari array\t|" << endl;
    cout << "=================================" << endl;
    //menampilkan semua nilai data/elemen dari array melalui pointer yang menunjuknya
    for (int i = 0; i < 10; i++) //Looping 10 kali
    {
        cout << "| Data ke-" << i + 1 << " : \t" << *(pData + i) << " \t\t|" << endl; //menampilkan data
    }
    cout << "=================================\n\n" << endl;

    cout << "==================================" << endl;
    cout << "|\tSemua alamat memori \t|" << endl;
    cout << "==================================" << endl;
    //menampilkan semua alamat memori dari tiap elemen array melalui pointer yang menunjuknya
    for (int i = 0; i < 10; i++) //Looping 10 kali
    {
        cout << "| Alamat data ke-" << i + 1 << " : \t" << pData + i << " |" << endl; //menampilkan alamat memori
    }
    cout << "==================================\n\n" << endl;

    cout << "=================================" << endl;
    cout << "|\tPerubahan data array \t|" << endl;
    cout << "=================================" << endl;

    cout << "|==>  Data yang diubah\t\t|" << endl;

    //lakukan perubahan (re-inisialisasi) beberapa elemen array (minimal 5 data yang diubah) melalui pointer yang menunjuknya
    for (int i = 0; i < 5; i++) //Looping 5 kali
    {
        *(pData + i) = *(pData + i) + 10; //menambahkan 10 pada data nilai array di ubah
        cout << "| Data ke-" << i + 1 << " : " << *(pData + i) << " \t\t|" << endl; //menampilkan data yang telah diubah
    }

    cout << "|==> Data yang Tidak diubah\t|" << endl;
    //menampilkan semua nilai data/elemen array dari data ke 6 sampai terakhir
    for (int i = 5; i < 10; i++) //Looping 5 kali
    {
        cout << "| Data ke-" << i + 1 << " : " << *(pData + i) << " \t\t|" << endl; //menampilkan data yang tidak diubah dari data ke 6 sampai terakhir
    }
    cout << "=================================\n" << endl;

    return 0;
}