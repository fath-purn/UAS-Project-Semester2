// Nama : Fatkhurrohman Purnomo
// NIM : 21102125

#include <iostream>
using namespace std;

int main(){
    int data[] = {1,2,3,4,5}; // menginisialisasi array data dengan nilai 1,2,3,4,5
    int *pData = data; // menginisialisasi pointer pData dengan alamat dari array data

    cout << pData[0] << endl; // mencetak nilai dari array data dengan index 0
    cout << pData[1] << endl; // mencetak nilai dari array data dengan index 1
    cout << pData[2] << endl; // mencetak nilai dari array data dengan index 2
    cout << pData[3] << endl; // mencetak nilai dari array data dengan index 3
    cout << pData[4] << endl; // mencetak nilai dari array data dengan index 4

    return 0;
}