#include <iostream>
using namespace std;

struct mhs
{
    string nama;
    string nim;
};

int main()
{
    mhs A, B, C, D, E, F;

    A.nama = "Deva Apriana";
    A.nim = "20102082";

    B.nama = "Naeli Fitria Rokhmawati";
    B.nim = "20102081";

    C.nama = "Sadewa Anla Handika";
    C.nim = "20102161";

    D.nama = "Safira Anggraini Irawan";
    D.nim = "20102162";

    E.nama = "Varrel Bramasta Nugraha";
    E.nim = "20102201";

    F.nama = "Yuni Nur Fari'ah";
    F.nim = "20102208";

    cout << "|Nama|\t\t\t\t|NIM|\n";
    cout << "========================================\n";
    cout << A.nama << "\t\t\t" << A.nim << endl;
    cout << B.nama << "\t\t" << B.nim << endl;
    cout << C.nama << "\t\t" << C.nim << endl;
    cout << D.nama << "\t\t" << D.nim << endl;
    cout << E.nama << "\t\t" << E.nim << endl;
    cout << F.nama << "\t\t" << F.nim;
}