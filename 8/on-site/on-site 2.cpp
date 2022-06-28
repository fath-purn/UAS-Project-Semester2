// Nama : Fatkhurrohman Purnomo
// NIM : 21102125

#include <iostream>

using namespace std;

///PROGRAM DOUBLE LINKED LIST CIRCULAR

//Deklarasi DLLC
struct Node
{
    int angka;
    string huruf;
    char karakter;
    Node *next;
    Node *prev;
};

//Deklarasi Node
Node *head, *tail, *baru, *bantu, *bantu2, *hapus;

//Inisialisasi Node
void init()
{
    head = NULL;
    tail = head;
}

//isEmpty
int isEmpty()
{
    if (head == NULL && tail == NULL)
        return 1; //true
    else
        return 0; //false
}

//Buat Node Baru
void create(int angka, string huruf, char karakter)
{
    baru = new Node;
    baru->angka = angka;
    baru->huruf = huruf;
    baru->karakter = karakter;
    baru->next = NULL;
    baru->prev = NULL;
}

//Tambah Depan
void insertDepan(int angka, string huruf, char karakter)
{
    create(angka, huruf, karakter);

    if (isEmpty() == 1){
        head = baru;
        tail = head;
        head->prev = tail;
        tail->next = head;
    }
    else{
        baru->next = head;
        head->prev = baru;
        head = baru;
        head->prev = tail;
        tail->next = head;
    }
}

//Tambah Belakang
void insertBelakang(int angka, string huruf, char karakter)
{
    create(angka, huruf, karakter);

    if (isEmpty() == 1){
        head = baru;
        tail = head;
        head->prev = tail;
        tail->next = head;
    }
    else{
        baru->prev = tail;
        tail->next = baru;
        tail = baru;
        tail->next = head;
        head->prev = tail;
    }
}

//Tambah Tengah
void insertTengah(int posisi, int angka, string huruf, char karakter)
{
    create(angka, huruf, karakter);

    if (isEmpty() == 1){
        cout << " List masih kosong!" << endl;
    }
    else{
        if (posisi == 1){
            cout << " Posisi bukan posisi tengah!" << endl;
        }
        else if (posisi < 1){
            cout << " Posisi di luar jangkauan!" << endl;
        }
        else{
            int counter = 1;
            bantu = head;

            while (counter < posisi-1){
                bantu = bantu->next;
                counter++;
            }

            bantu2 = bantu->next;
            bantu->next = baru;
            bantu2->prev = baru;
            baru->prev = bantu;
            baru->next = bantu2;
        }
    }
}

//Hapus Depan
void hapusDepan()
{
    if (isEmpty() == 0){
        hapus = head;
        tail = head;
        if (hapus->next == head){
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else{
            while (tail->next != hapus){
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}

//Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0){
        hapus = head;
        tail = head;

        if (hapus->next == head){
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else{
            while (hapus->next != head){
                hapus = hapus->next;
            }
            while (tail->next != hapus){
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}

//Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 1){
        cout << " List masih kosong!" << endl;
    }
    else{
        if (posisi == 1){
            cout << " Posisi bukan posisi tengah!" << endl;
        }
        else if (posisi < 1){
            cout << " Posisi di luar jangkauan!" << endl;
        }
        else{
            int counter = 1;
            bantu = head;

            while (counter < posisi-1){
                bantu = bantu->next;
                counter++;
            }

            hapus = bantu->next;
            bantu2 = hapus->next;
            bantu->next = bantu2;
            bantu2->prev = bantu;
            delete hapus;
        }
    }
}

//Hapus List
void clearList()
{   if (isEmpty() == 0){
        hapus = head;

        while (hapus->next != head){
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;
        }
        head = NULL;
        tail = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

//Tampil
void tampil()
{
    if (isEmpty() == 0){
        tail = head;
        do{
            cout << tail->angka << " : " << tail->huruf << " : " << tail->karakter << endl;
            tail = tail->next;
        }while (tail != head);
        cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
    init();
    insertDepan(2, "Ayam", 'A');
    tampil();
    insertDepan(4, "Bebek", 'B');
    tampil();
    insertBelakang(10, "Cicak", 'C');
    tampil();
    insertBelakang(18, "Domba", 'D');
    tampil();
    hapusBelakang();
    tampil();
    insertDepan(0, "Babi", 'B');
    tampil();
    hapusDepan();
    tampil();
    insertTengah(2, 5, "Ekor", 'E');
    tampil();
    hapusTengah(2);
    tampil();
//    clearList();
//    tampil();

    return 0;
}