// Nama : Fatkurrohman Purnomo
// Nim : 21102125

#include <iostream>
using namespace std;

//PROGRAM INPUT ARRAY 3 DIMENSI
int main()
    {
    //Deklarasi array untuk menyimpan data
    int arr[2][2][2];

    //Input elemen dengan menggunakan for, untuk mengakses setiap array
    for (int x=0; x<2; x++){ //untuk mengakses array pertama
        for (int y=0; y<2; y++){ //untuk mengakses array kedua
            for (int z=0; z<2; z++){ //untuk mengakses array ketiga
                cout << "Elemen[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z]; // input data
            }
        }
        cout << endl;
    }

    //Output elemen / data dari inputan dari user tadi. menggunakan for looping untuk mengakses setiap array
    for (int x=0; x<2; x++){ //untuk mengakses array pertama
        for (int y=0; y<2; y++){ //untuk mengakses array kedua
            for (int z=0; z<2; z++){ //untuk mengakses array ketiga
                cout << "Elemen[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl; // menampilkan data
            }
        }
    }
    cout << endl;

    //Output elemen / data dari inputan dari user tadi. menggunakan for looping untuk mengakses setiap array
    for (int x=0; x<2; x++){
        for (int y=0; y<2; y++){
            for (int z=0; z<2; z++){ 
                cout << arr[x][y][z] << ends; // menampilkan data
            }
            cout << endl;
        }
    cout << endl;
    }

    return 0;
}