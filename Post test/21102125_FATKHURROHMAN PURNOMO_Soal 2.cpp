// Nama : Fatkhurrohman Purnomo
// NIM : 21102125

#include <iostream>
#include <conio.h>
#define maxstack 2000

using namespace std;

// Program Yang Dapat Membalikkan Kalimat Dengan Menggunakan Stack
struct STACK_21102125 // membuat jenis data abstrak stack
{
    int top_21102125;
    char data_21102125[maxstack]; // pendeklarasian untuk menginputkan suatu kalimat dengan maks 200
};

char data_21102125_21102125[maxstack];
struct STACK_21102125 stackbaru;

bool isfull() // fungsi untuk mengetahui apakah stack dalam kondisi penuh (menggunakan boolean)
{
    if (stackbaru.top_21102125 == maxstack - 1)
        return true; // jika pengkondisian stack dalam keadaan penuh maka benar
    else
        return false;
}

bool isempty() // fungsi untuk mengetahui apakah stack dalam kondisi kosong
{
    if (stackbaru.top_21102125 == -1)
        return true;
    else
        return false;
}
void push(char data_21102125_21102125) // fungsi untuk proses push
{
    if (isfull() == false) // jika kondisi stack tidak penuh
    {
        stackbaru.top_21102125++;
        stackbaru.data_21102125[stackbaru.top_21102125] = data_21102125_21102125;
    }
    else // jika stack dalam kondisi penuh
    {
        cout << "\nMaaf Stack penuh";
    }
}

void pop() // mengambil isi stack
{
    while (isempty() == false) // jika kondisi stack tidak kosong
    {
        cout << stackbaru.data_21102125[stackbaru.top_21102125];
        stackbaru.top_21102125--;
    }
}

void print() // mencetak stack
{
    system("cls");
    cout << "\nKalimat awal : ";
    for (int i = 0; i <= stackbaru.top_21102125; i++)
    {
        cout << stackbaru.data_21102125[i];
    }
}

void clear()
{
    stackbaru.top_21102125 = -1;
}

int main()
{
    char kata[200]; // menampung inputan

    cout << "===================================================" << endl;
    cout<<"            >>  PROGRAM MEMBALIK KATA   <<           "<<endl;
    cout << "===================================================" << endl;
    cout << "Masukkan kalimat : ";
    gets(kata);
    cout << endl;
    for (int i = 0; kata[i]; i++)
    {
        push(kata[i]);
    }
    print();
    cout << "\n\nDibalik jadi : ";
    pop();
    cout << endl;
}