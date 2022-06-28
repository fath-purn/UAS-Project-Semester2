// Nama : Fatkhurrohman Purnomo
// NIM : 21102125

#include <iostream>

using namespace std;

///PROGRAM DOUBLE LINKED LIST NON-CIRCULAR (DLLNC)

//Deklarasi DLLNC
struct Node
{
    int angka;
    string huruf;
    bool keterangan;
    Node *next;
    Node *prev;
};
Node *head, *tail, *baru, *bantu, *bantu2, *hapus;

//Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}

//IsEmpty
int isEmpty()
{
    if (head == NULL && tail == NULL)
        return 1;   //true
    else
        return 0;   //false
}

//Buat Node Baru
void create(int angka, string huruf, bool keterangan)
{
    baru = new Node;
    baru->angka = angka;
    baru->huruf = huruf;
    baru->keterangan = keterangan;
    baru->next = NULL;
    baru->prev = NULL;
}

//Tambah Depan
void insertDepan(int angka, string huruf, bool keterangan)
{
    create(angka, huruf, keterangan);

    if (isEmpty() == 1){
        head = baru;
        tail = head;
    }
    else{
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
}

//Tambah Belakang
void insertBelakang(int angka, string huruf, bool keterangan)
{
    create(angka, huruf, keterangan);

    if (isEmpty() == 1){
        head = baru;
        tail = head;
    }
    else{
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
}

//Hitung List
int countList()
{
    int counter = 0;
    bantu = head;

    while(bantu != NULL){
        counter++;
        bantu = bantu->next;
    }

    return counter;
}

//Tambah Tengah
void insertTengah(int angka, int posisi, string huruf, bool keterangan)
{
    create(angka, huruf, keterangan);

    if (posisi < 1 || posisi > countList()){
            cout << " Posisi di luar jangkauan!" << endl;
    }
    else if ( posisi == 1){
        cout << " Posisi bukan posisi tengah!" << endl;
    }
    else{
        bantu = head;
        int counter = 1;

        while (counter < posisi-1){
            bantu = bantu->next;
            counter++;
        }

        bantu2 = bantu->next;
        baru->prev = bantu;
        baru->next = bantu2;
        bantu->next = baru;
        bantu2->prev = baru;
    }
}

//Hapus Depan
void hapusDepan()
{
    if (isEmpty() == 0){
        hapus = head;
        head = head->next;
        head->prev = NULL;
        delete hapus;
    }
    else{
        cout << " List masih kosong!" << endl;
    }
}

//Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0){
        hapus = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete hapus;
    }
    else{
        cout << " List masih kosong!" << endl;
    }
}

//Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0){
        if (posisi < 1 || posisi > countList()){
            cout << " Posisi di luar jangkauan!" << endl;
        }
        else if (posisi == 1 || posisi == countList()){
            cout << " Posisi bukan posisi tengah!" << endl;
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
    else{
        cout << " List masih kosong!" << endl;
    }
}

//Ubah Depan
void ubahDepan(int angka, string huruf, bool keterangan)
{
    if (isEmpty() == 0){
        head->angka = angka;
        head->huruf = huruf;
        head->keterangan = keterangan;
    }
    else{
        cout << " List masih kosong!" << endl;
    }
}

//Ubah Belakang
void ubahBelakang(int angka, string huruf, bool keterangan)
{
    if (isEmpty() == 0){
        tail->angka = angka;
        tail->huruf = huruf;
        tail->keterangan = keterangan;
    }
    else{
        cout << " List masih kosong!" << endl;
    }
}

//Ubah Tengah
void ubahTengah(int posisi, int angka, string huruf, bool keterangan)
{
    if (isEmpty() == 0){
        if (posisi < 1 || posisi > countList()){
            cout << " Posisi di luar jangkauan!" << endl;
        }
        else if (posisi == 1 || posisi == countList()){
            cout << " Posisi bukan posisi tengah!" << endl;
        }
        else{
            bantu = head;
            int counter = 1;
            while (counter < posisi){
                bantu = bantu->next;
                counter++;
            }
            bantu->angka = angka;
            bantu->huruf = huruf;
            bantu->keterangan = keterangan;
        }
    }
    else{
        cout << " List masih kosong!" << endl;
    }
}

//Hapus List
void clearList()
{
    bantu = head;

    while (bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << " List berhasil terhapus!" << endl;
}

//Tampilkan List
void tampil()
{
    bantu = head;

    if (isEmpty() == 0){
        while (bantu != NULL){
            cout  << bantu->angka << " = " << bantu->huruf << endl;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << " List masih kosong!" << endl;
    }
}

int main()
{
    init();
    insertDepan(3, "ganjil", true);
    tampil();
    insertBelakang(5, "genap", false);
    tampil();
    insertDepan(2, "ganjil", true);
    tampil();
    insertDepan(1, "genap", false);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(4, 2, "ganjil", false);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1, "ganjl", true);
    tampil();
    ubahBelakang(8, "genap", true);
    tampil();
    ubahTengah(14, 2, "genap", true);
    tampil();

    return 0;
}