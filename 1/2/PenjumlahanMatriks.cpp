// Nama : Fatkhurrohman Purnomo
// Kelas : IF-09-D
// NIM : 21102125

#include <iostream>
using namespace std;

//PROGRAM PENJUMLAHAN DUA MATRIKS ORDO 3X5
int main()
{
    //Deklarasi array A
    int A[3][5] = {{10, 20, 30, 40, 50},
    {50, 40, 30, 20, 10},
    {11, 22, 33, 44, 55}};
    
    //Deklarasi array B
    int B[3][5] = {{11, 22, 33, 44, 55},
    {55, 44, 33, 22, 11},
    {10, 20, 30, 40, 50}};
    
    //Deklarasi array C
    int C[3][5]; //array untuk hasil matriks
    
    //Output Untuk Menampilkan Matriks A
    cout << "Matriks A: " << endl;
    for (int m=0; m<3; m++){
        for (int n=0; n<5; n++){
            cout << A[m][n] << ends;
        }
        cout << endl;
    }
    cout << endl;
    
    //Output Untuk Menampilkan Matriks B
    cout << "Matriks B: " << endl;
    for (int m=0; m<3; m++){
            for (int n=0; n<5; n++){
            cout << B[m][n] << ends;
        }
        cout << endl;
    }
    cout << endl;
    
    //Output Untuk Menampilkan Hasil dari penjumlahan, dan disimpan dalam array C
    cout << "Matriks C = A + B :" << endl;
    for (int m=0; m<3; m++){
        for (int n=0; n<5; n++){
            C[m][n] = A[m][n] + B[m][n];
            cout << C[m][n] << ends;
        }
        cout << endl;
    }
    cout << endl;
    return 0; 
}