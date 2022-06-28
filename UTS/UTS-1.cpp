#include <iostream>
using namespace std;

// array 2 dimensi
int main() {
    // array 2 dimensi
    int nim[6][6];
    string nama[6][6];
    
    // alamat memori
    int *p;
    string *q;
    p = &nim[0][0];
    q = &nama[0][0];

    // input array
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Nama: ";
            cin >> nama[i][j];
            cout << "Nim: ";
            cin >> nim[i][j];
            cout << endl;
        }
    }

    cout << "NAMA \t\t NIM" << endl;
    // output array
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << nama[i][j] << "\t\t" << nim[i][j] << endl;
        }
    }

    // output array
    cout << endl << "NAMA \t\t NIM" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << *q << "\t\t" << *p << endl;
            p++;
            q++;
        }
    }

    return 0;
}