// Nama : Fatkurrohman Purnomo
// Nim : 21102125

#include <iostream>
using namespace std;

// nilai maksimum dan minimum
int main(){
    int nilai[5]; // inisialisasi array integer
    int max = nilai[0]; // inisialisasi nilai maksimum
    int min = nilai[0]; // inisialisasi nilai minimum
    int i; // inisialisasi variabel untuk menampung nilai array

    // input nilai
    for (i = 0; i < 5; i++){ // loop untuk menginputkan nilai array
        cout << "Nilai ke-" << i + 1 << ": "; // menampilkan nilai array
        cin >> nilai[i]; // input nilai array
    }

    // mencari nilai maksimum dan minimum
    for (i = 0; i < 5; i++){ // loop untuk mencari nilai maksimum dan minimum
        if (nilai[i] > max){ // perbandingan untuk mencari nilai maksimum
            max = nilai[i]; // nilai maksimum
        }
        if (nilai[i] < min){ // perbandingan untuk mencari nilai minimum
            min = nilai[i]; // nilai minimum
        }
    }

    cout << endl; // mencetak enter

    // mencetak nilai maksimum dan minimum
    cout << "Nilai maksimum: " << max << endl; // mencetak nilai maksimum
    cout << "Nilai minimum: " << min << endl; // mencetak nilai minimum

    return 0;
}