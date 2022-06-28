// Nama : Fatkhurrohman Purnomo
// Kelas : IF-09-D
// NIM : 21102125

#include <iostream>
using namespace std;

int main()
{
    // deklarasi variabel
    int n;
    string nama[10], status[10];
    int nilai[10];

    // input jumlah data dan dimasukan ke variabel n
    cout << "Masukkan Jumlah Data = ";
    cin >> n;
    cout << endl;

    // input data ke array nama, nilai, dan menentukan status lulus atau tidak dengan nilai diatas 50 maka lulus
    for (int i=0; i<n; i++) {
        cout << endl;
        cout << "Data ke-" << i+1 << endl;
        cout << "Masukkan Nama = ";
        cin >> nama[i];
        cout << "Masukkan Nilai = ";
        cin >> nilai[i];
        
        // menentukan status lulus atau tidak dengan nilai diatas 50
        if (nilai[i] <= 50) {
            status[i] = "Tidak Lulus";
        } else {
            status[i] = "Lulus";
        }
    }

    // output data dari input yang dimasukan tadi
    cout << endl;
    cout << " DAFTAR  NILAI MAHASISWA " << endl;
    cout << "=========================================" << endl;
    cout << "No.   Nama   Nilai   Status " << endl;
    cout << "=========================================" << endl;
    for (int i=0; i<n; i++) {
        cout << i+1 << "     " << nama[i] << "   " << nilai[i] << "  " << status[i] << endl;
        cout << "=========================================" << endl;
    }
    return 0;
}