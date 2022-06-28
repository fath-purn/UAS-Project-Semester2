#include <iostream>
using namespace std;

///PROGRAM MENAMPILKAN DATA GRAPH
//Deklarasi Node/Simpul

string simpul[7] = {"Jakarta",
                    "Bandung",
                    "Bekasi",
                    "Tasikmalaya",
                    "Semarang",
                    "Purwokerto",
                    "Yogyakarta"};

//Deklarasi Edge/Busur
int busur[7][7] = { {0,7,8,0,0,0,0},
                    {0,0,5,0,0,15,0},
                    {0,6,0,0,5,0,0},
                    {0,5,0,0,0,4,0},
                    {23,0,0,10,0,0,8},
                    {0,0,0,0,7,0,3},
                    {0,0,0,0,9,4,0}};

//Tampil Data Graph
void tampilGraph()
{
    for (int baris = 0; baris < 7; baris++){
        cout << " " << simpul[baris] << ": ";
        for (int kolom = 0; kolom < 7; kolom++){
            if (busur[baris][kolom] != 0){
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom] << ")" << " ";
            }
        }
    cout << endl;
    }
}

int main()
{
    tampilGraph();
    return 0;
}