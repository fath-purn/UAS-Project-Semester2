// Nama : Fatkhurrohman Purnomo
// Kelas : IF-09-D
// NIM : 21102125

#include <iostream>
using namespace std;

// matriks determinan, adjoin, invers 
int main(){
    // operasi matriks determinan
    int matriks[3][3]; // membuat array 3x3
    float det = 0; // membuat variabel untuk menampung hasil determinan
    int i, j; // membuat variabel untuk menampung indeks

    cout << "Masukkan Matriks 3x3 = " << endl; // menampilkan tulisan
    for (i=0; i<3; i++) { // membuat perulangan untuk memasukkan nilai matriks
        for (j=0; j<3; j++) { // membuat perulangan untuk memasukkan nilai matriks
            cout << "Masukan nilai: "; // menampilkan tulisan
            cin >> matriks[i][j]; // memasukkan nilai matriks
        }
    }
    cout << endl;

    cout << endl << "Matriks yang anda masukkan = "; // menampilkan tulisan
    for(i = 0; i < 3; i++){ // membuat perulangan untuk menampilkan matriks
        cout << endl; // menampilkan baris baru
        for(j = 0; j < 3; j++){ // membuat perulangan untuk menampilkan matriks
            cout << matriks[i][j] << "\t"; // menampilkan matriks
        }
    }

    for(i = 0; i < 3; i++){ // membuat perulangan untuk menghitung determinan
        det = det + (matriks[0][i] * (matriks[1][(i+1)%3] * matriks[2][(i+2)%3] - matriks[1][(i+2)%3] * matriks[2][(i+1)%3])); // menghitung determinan
    }
    cout << "\n\nDeterminant: " << det << endl << endl; // menampilkan hasil determinan

    //operasi matriks adjoint
    int adj[3][3]; // membuat array 3x3

    // menghitung adjoint
    adj[0][0] = matriks[1][1] * matriks[2][2] - matriks[1][2] * matriks[2][1]; 
    adj[0][1] = matriks[0][2] * matriks[2][1] - matriks[0][1] * matriks[2][2];
    adj[0][2] = matriks[0][1] * matriks[1][2] - matriks[0][2] * matriks[1][1];
    adj[1][0] = matriks[1][2] * matriks[2][0] - matriks[1][0] * matriks[2][2];
    adj[1][1] = matriks[0][0] * matriks[2][2] - matriks[0][2] * matriks[2][0];
    adj[1][2] = matriks[0][2] * matriks[1][0] - matriks[0][0] * matriks[1][2];
    adj[2][0] = matriks[1][0] * matriks[2][1] - matriks[1][1] * matriks[2][0];
    adj[2][1] = matriks[0][1] * matriks[2][0] - matriks[0][0] * matriks[2][1];
    adj[2][2] = matriks[0][0] * matriks[1][1] - matriks[0][1] * matriks[1][0];

    cout << "Matriks Adjoint = " << endl; // menampilkan tulisan
    for (i=0; i<3; i++) { // membuat perulangan untuk menampilkan matriks adjoint
        for (j=0; j<3; j++) { // membuat perulangan untuk menampilkan matriks adjoint
            cout << adj[i][j] << "\t" << " "; // menampilkan matriks adjoint
        }
        cout << endl;
    }
    cout << endl;

    cout<<"Inverse of matrix is: " << endl; // menampilkan tulisan
    for(i = 0; i < 3; i++){ // membuat perulangan untuk menampilkan matriks invers
        for(j = 0; j < 3; j++){ // membuat perulangan untuk menampilkan matriks invers
            cout << ((matriks[(j+1)%3][(i+1)%3] * matriks[(j+2)%3][(i+2)%3]) - (matriks[(j+1)%3][(i+2)%3] * matriks[(j+2)%3][(i+1)%3]))/ det<<"\t"; // menampilkan matriks invers
        }
        cout << "\n"; // menampilkan baris baru
    }

    return 0; // mengembalikan nilai 0

}