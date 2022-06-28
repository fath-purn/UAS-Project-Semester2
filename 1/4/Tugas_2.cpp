// Nama : Fatkhurrohman Purnomo
// Kelas : IF-09-D
// NIM : 21102125

#include <iostream>
using namespace std;

// banyak data, rata-rata, jumlah
int main()
{
    // deklarasi variabel
    int n; // banyak data
    int nilai[30]; // array untuk menyimpan nilai
    int total = 0; // variabel untuk menyimpan total
    int rata_rata = 0; // variabel untuk menyimpan rata-rata
    int jumlah = 0; // variabel untuk menyimpan jumlah
    int i; // variabel looping

    // input jumlah data
    cout << "Masukkan Jumlah Data = ";
    cin >> n;
    cout << endl;

    // input data / nilai
    for (i=0; i<n; i++) { // looping untuk input data
        cout << "Masukkan Nilai ke-" << 1+i << " = "; // input nilai
        cin >> nilai[i]; // input nilai
        total += nilai[i]; // total nilai
        jumlah++; // jumlah data
    }
    cout << endl;


    // output Banyak data
    cout << "Banyak data = " << jumlah << endl << endl;


    // output data total nilai / jumlah
    cout << "Jumlah = ";
    for (i=0; i<n; i++) { // looping untuk output data
        cout << nilai[i]; // output nilai
        if (i < n-1) { // kondisi untuk menandai data yang akan ditambahkan
            cout << " + "; // menambahkan tanda +
        }
    }
    
    cout << " = " << total << endl;
    cout << endl;

    // output rata-rata
    cout << "Rata-rata Nilai = " << total << " / " << jumlah << " = " << total/jumlah << endl;

    return 0;
}