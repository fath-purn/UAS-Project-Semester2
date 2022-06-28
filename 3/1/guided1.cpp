// Nama : Fatkhurrohman Purnomo
// NIM : 21102125


#include <iostream>
using namespace std;

// pointer
int main(){
    int v = 7; // menginisialisasi variabel v dengan nilai 7
    int *p; // menginisialisasi pointer p dengan nilai NULL

    cout << "v = " << v << endl; // mencetak nilai variabel v
    cout << "p = " << *p << endl; // mencetak nilai pointer p
    cout << "v = " << &v << endl; // mencetak alamat dari variabel v
    cout << "p = " << &p << endl; // mencetak alamat dari pointer p

    return 0;
}