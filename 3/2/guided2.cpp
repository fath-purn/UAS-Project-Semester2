// Nama : Fatkhurrohman Purnomo
// NIM : 21102125

#include <iostream>
using namespace std;

// pointer
int main(){
    int value1 = 5, value2 = 15; // menginisialisasi variabel value1 dengan nilai 5 dan value2 dengan nilai 15
    int *mypointer; // menginisialisasi pointer mypointer dengan nilai NULL

    cout << "value1 = " << value1 << endl; // mencetak nilai variabel value1
    cout << "value2 = " << value2 << endl; // mencetak nilai variabel value2
    cout << endl;

    // inisialisasai ulang dengan menggnakan pointer
    mypointer = &value1; // menginisialisasi pointer mypointer dengan alamat dari variabel value1
    *mypointer = 10; // mengisi nilai dari pointer mypointer dengan 10

    cout << "value1 = " << value1 << endl; // mencetak nilai variabel value1
    cout << "value2 = " << value2 << endl; // mencetak nilai variabel value2

    return 0;
}