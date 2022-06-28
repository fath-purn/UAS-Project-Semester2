/*Jaler Pandya Mahesa
21102135
IF-09-D*/
#include <iostream>
#define MAX 10 //menetapkan nilai konstanta MAX = 10

using namespace std;

///Program Queue dengan Structure Array

struct angka{
    int nomor;
    string huruf;
}ang[MAX];

//Deklarasi Queue
struct queue{
    int head;
    int tail;
}antrian;

//Buat Queue
void create(){ //membuat antrian kosong
    antrian.head = antrian.tail = -1;
}

int isEmpty(){  //mengecek apakah antrian kosong
    if (antrian.tail == -1)
        return 1;
    else
        return 0;
}

int isFull(){ //mengecek apakah antrian penuh
    if (antrian.tail == MAX - 1)
        return 1;
    else
        return 0;
}

void enqueue(){ //menambahkan antrian
    if (isEmpty() == 1){
        int nomor;
        string huruf;

        cout << "Masukkan Angka/Nomor : ";
        cin >> nomor;
        cout << "Pelafalan : ";
        cin >> huruf;

        antrian.head = antrian.tail = 0;
        ang[antrian.tail].nomor = nomor;
        ang[antrian.tail].huruf = huruf;
        cout << "\n " << ang[antrian.tail].nomor << "\t" << ang[antrian.tail].huruf << " Masuk !" << endl;
    }
    else if (isFull() == 0){
        int nomor;
        string huruf;

        cout << "Masukkan Angka/Nomor : ";
        cin >> nomor;
        cout << "Pelafalan : ";
        cin >> huruf;

        antrian.tail++;
        ang[antrian.tail].nomor = nomor;
        ang[antrian.tail].huruf= huruf;
        cout << "\n " << ang[antrian.tail].nomor << "\t" << ang[antrian.tail].huruf << " Masuk !" << endl;
    }
    else{
        cout << " Data penuh !" << endl;
    }
}

//Dequeue
int dequeue(){ //mengambil antrian
    for (int i = antrian.head; i <= antrian.tail -1; i++){
        ang[i].nomor = ang[i+1].nomor;
        ang[i].huruf = ang[i+1].huruf;
    }
    antrian.tail--;
    cout << "Data berhasil dihapus" << endl;
    cout << endl;
}

//clear
void clear(){ //mengosongkan seluruh data antrian
    antrian.head = antrian.tail =  -1;
    cout << "Data Clear" << endl;
}

//Tampil
void display(){ //menampilkan data
    int jum;
    if (isEmpty() == 0){
        for (int i = antrian.head; i <= antrian.tail; i++){
            cout << " " << ang[i].nomor << "\t" << ang[i].huruf << endl;
        }
    }
    else{
        cout << " data kosong !" << endl;
    }
}

int main()
{
    int pil;
    int data;
    create();

    do{
        system("cls");
        cout << " 1. Enqueue" << endl;
        cout << " 2. Dequeue" << endl;
        cout << " 3. Tampil"  << endl;
        cout << " 4. Clear "  << endl;
        cout << " 5. Exit "   << endl;
        cout << " Pilihan : ";
        cin >> pil;

        switch (pil){
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            clear();
            break;
        }
        cout << endl;
        system("pause");
    }
    while (pil != 5);

    return 0;
}
