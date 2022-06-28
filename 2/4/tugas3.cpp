// Nama : Fatkurrohman Purnomo
// Nim : 21102125

#include <iostream>
using namespace std;

void inputUser(int matriks1[3][3], int matriks2[3][3]){
    cout << "============================================" << endl;

    // input matriks 1
    cout << endl << "Input matriks 1: " << endl; // output untuk menunjukkan bahwa input akan dimasukan ke matriks 1
    for (int i = 0; i < 3; i++){ // loop untuk mengakses array pertama
        for (int j = 0; j < 3; j++){ // loop untuk mengakses array kedua
            cout << "matriks1[" << i << "][" << j << "] = "; // output untuk user untuk menginputkan data pada array ke
            cin >> matriks1[i][j]; // input data
        }
        cout << endl;
    }

    // input matriks 2
    cout << "Input matriks 2: " << endl; // output untuk menunjukkan bahwa input akan dimasukan ke matriks 2
    for (int i = 0; i < 3; i++){ // loop untuk mengakses array pertama
        for (int j = 0; j < 3; j++){ // loop untuk mengakses array kedua
            cout << "matriks2[" << i << "][" << j << "] = "; // output untuk user untuk menginputkan data pada array ke
            cin >> matriks2[i][j]; // input data
        }
        cout << endl;
    }

    cout << "============================================" << endl;

    // matriks 1
    cout << "Matriks 1: " << endl; // output untuk menampilkan matriks 1
    for (int i = 0; i < 3; i++){ // loop untuk mengakses array pertama
        for (int j = 0; j < 3; j++){ // loop untuk mengakses array kedua
            cout << "\t" << matriks1[i][j] << " "; // output untuk menampilkan data pada array
        } 
        cout << endl; // output untuk membuat baris baru
    }

    cout << endl; // output untuk membuat baris baru

    // matriks 2
    cout << "Matriks 2: " << endl; // output untuk menampilkan matriks 2
    for (int i = 0; i < 3; i++){ // loop untuk mengakses array pertama
        for (int j = 0; j < 3; j++){ // loop untuk mengakses array kedua
            cout << "\t" << matriks2[i][j] << " "; // output untuk menampilkan data pada array
        }
        cout << endl; // output untuk membuat baris baru
    }

    cout << "============================================" << endl << endl; // output untuk

}

// kalkulator matriks
// penjumlahan, pengurangan, perkalian, transpose
int main(){
    
    // array untuk menyimpan matriks
    int matriks1[3][3]; // menginisialisasi array dengan 3 dimensi
    int matriks2[3][3]; // menginisialisasi array dengan 3 dimensi
    int pilihan; // menyimpan pilihan user

    // menu 
    cout << "Pilih operasi yang ingin dilakukan : " << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "3. Perkalian" << endl;
    cout << "4. Transpose" << endl;
    cout << "5. Keluar" << endl;
    cout << "Masukkan pilihan : ";
    cin >> pilihan; // input pilihan user

    // penjumlahan
    if (pilihan == 1){
        inputUser(matriks1, matriks2); // input user

        cout << "Hasil penjumlahan: " << endl; // output untuk menampilkan hasil penjumlahan
        for (int i = 0; i < 3; i++){ // loop untuk mengakses array pertama
            for (int j = 0; j < 3; j++){ // loop untuk mengakses array kedua
                cout << "\t" << matriks1[i][j] + matriks2[i][j] << " "; // output untuk menampilkan hasil penjumlahan
            }
            cout << endl; // output untuk membuat baris baru
        }
    }
    
    // pengurangan
    else if (pilihan == 2){
        inputUser(matriks1, matriks2); // input user

        cout << "Hasil pengurangan: " << endl; // output untuk menampilkan hasil pengurangan
        for (int i = 0; i < 3; i++){ // loop untuk mengakses array pertama
            for (int j = 0; j < 3; j++){ // loop untuk mengakses array kedua
                cout << "\t" << matriks1[i][j] - matriks2[i][j] << " "; // output untuk menampilkan hasil pengurangan
            }
            cout << endl; // output untuk membuat baris baru
        }
    }

    // perkalian
    else if (pilihan == 3){
        inputUser(matriks1, matriks2); // input user
        
        cout << "Hasil perkalian: " << endl; // output untuk menampilkan hasil perkalian
        for (int i = 0; i < 3; i++){ // loop untuk mengakses array pertama
            for (int j = 0; j < 3; j++){ // loop untuk mengakses array kedua
                cout << "\t" << matriks1[i][j] * matriks2[i][j] << " "; // output untuk menampilkan hasil perkalian
            }
            cout << endl; // output untuk membuat baris baru
        }
    }

    // transpose
    else if (pilihan == 4){
        inputUser(matriks1, matriks2); // input user
        
        cout << "Hasil transpose: " << endl; // output untuk menampilkan hasil transpose
        for (int i = 0; i < 3; i++){ // loop untuk mengakses array pertama
            for (int j = 0; j < 3; j++){ // loop untuk mengakses array kedua
                cout << "\t" << matriks2[j][i] << " "; // output untuk menampilkan hasil transpose
            }
            cout << endl; // output untuk membuat baris baru
        }
    }

    // keluar
    else if (pilihan == 5){
        cout << "============================================" << endl << endl;

        cout << "Terima kasih telah menggunakan program ini" << endl; // output untuk menampilkan bahwa program telah berakhir
    }

    // jika pilihan tidak ada
    else{
        cout << "============================================" << endl << endl;

        cout << "Pilihan tidak ada" << endl; // output untuk menampilkan bahwa pilihan tidak ada
    }

    return 0;
}