// Nama : Fatkhurrohman Purnomo
// Nim  : 21102125

#include <iostream>
using namespace std;

struct fakultas{ // struktur fakultas
    string namaFakultas; // membuat variabel nama fakultas
};

struct jurusan{ // struktur jurusan
    fakultas fakultas; // membuat variabel fakultas
    string namaJurusan; // membuat varabel nanaJurusan
    string kelas; // membuat variabel kelas
};

int main(){
    fakultas f1; // membuat variabel fakultas
    jurusan j1; // membuat variabel jurusan

    // input
    f1.namaFakultas = "Informatika"; // inputan nama fakultas
    j1.fakultas.namaFakultas = "Informatika"; // inputan nama fakultas
    j1.namaJurusan = "Teknik Informatika"; // inputan nama jurusan
    j1.kelas = "IFD"; // inputan kelas

    // output
    cout << "Nama Fakultas : " << f1.namaFakultas << endl; // outputan nama fakultas
    cout << "Nama Fakultas Jurusan : " << j1.fakultas.namaFakultas << endl; // outputan nama fakultas jurusan
    cout << "Nama Jurusan  : " << j1.namaJurusan << endl; // outputan nama jurusan
    cout << "Kelas         : " << j1.kelas << endl; // outputan kelas

    return 0;
}