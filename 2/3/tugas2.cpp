// Nama : Fatkurrohman Purnomo
// Nim : 21102125

#include <iostream>
using namespace std;

// program input array 3 dimensi
// ukuran array dari user
int main(){
    // deklarasi array
    int arr[5][5][5]; // menginisialisasi array dengan 3 dimensi
    int n, m, o; // inisialisasi variabel untuk menampung ukuran array / nilai

    // input elemen
    cout << "Masukkan ukuran array : ";
    cin >> n; // input ukuran array dimensi 1
    cout << "Masukkan ukuran array : ";
    cin >> m; // input ukuran array dimensi 2
    cout << "Masukkan ukuran array : ";
    cin >> o; // input ukuran array dimensi 3

    cout << endl << "Masukkan elemen array" << endl << endl;

    // proses input data lalu dimasukan ke dalam array
    for (int x=0; x<n; x++){ // loop untuk mengakses array pertama
        for (int y=0; y<m; y++){ // loop untuk mengakses array kedua
            for (int z=0; z<o; z++){ // loop untuk mengakses array ketiga
                cout << "Elemen[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z]; // input data
            }
        }
        cout << endl;
    }

    // output elemen / data dari inputan dari user tadi. menggunakan for looping untuk mengakses setiap array
    for (int x=0; x<n; x++){ // loop untuk mengakses array pertama
        for (int y=0; y<m; y++){ // loop untuk mengakses array kedua
            for (int z=0; z<o; z++){ // loop untuk mengakses array ketiga
                cout << "Elemen[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }

    cout << endl;

    // tampilan dalam model array
    for (int x=0; x<n; x++){ // loop untuk mengakses array pertama
        for (int y=0; y<m; y++){ // loop untuk mengakses array kedua
            for (int z=0; z<o; z++){ // loop untuk mengakses array ketiga
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
    cout << endl;
    }

    return 0;
}