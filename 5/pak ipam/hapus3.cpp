#include <iostream>
#include <stdlib.h>
using namespace std;

//PROGRAM SINGLE LINKED LIST NON - CIRCULAR

//Declarasi Struct Node
struct node
{
    int data;
    node *next;
};

node *head;
node *tail;

//Inisialisasi Mode
void init()
{
    head = NULL;
    tail = NULL;
}

//Pengecekan
bool isEmpty()
{
    if(head == NULL)
        return true;
    else
        return false;
}

//Tambah Depan
void InsertDepan(int nilai)
{
    //Buat Node Baru
    node *baru = new node;
    baru ->data = nilai;
    baru ->next = NULL;

    if (isEmpty() == true){
        head = tail = baru;
        tail ->next = NULL;
    }
    else{
        baru ->next = head;
        head = baru;
    }
}

//Tambah Belakang
void InsertBelakang(int nilai)
{
    //buat Node Baru
    node *baru = new node;
    baru ->data = nilai;
    baru ->next = NULL;

    if (isEmpty() == true){
        head = tail = baru;
        tail ->next = NULL;
    }
    else{
        tail ->next = baru;
        tail = baru;
    }
}

//Hitung
int HitungList(){
    node *hitung;
    hitung = head;
    int jumlah = 0;
    while( hitung != NULL ){
        jumlah++;
        hitung = hitung ->next;
    }
    return jumlah;
}

//Tambah Tengah
void InsertTengah(int data, int posisi)
{
    //Buat Node Baru
    node *baru = new node;
    baru ->data = data;
    baru ->next = NULL;

    if (isEmpty() == true){
        head = tail = baru;
        tail ->next = NULL;
    }
    else{
        node *temp = head;
        for(int i = 1; i < posisi; i++){
            temp = temp ->next;
        }
        baru ->next = temp ->next;
        temp ->next = baru;
    }
}

//Hapus Depan
void hapusdepan()
{
    node *hapus;

    if (isEmpty() == false){
        if (head ->next != NULL){
            hapus = head;
            head = head ->next;
            delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List Kosong!" << endl;
    }
}

//Hapus Belakang
void hapusbelakang()
{
    node *hapus;
    node *bantu;

    if (isEmpty() == false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next != tail){
                bantu = bantu ->next;
            }
            tail = bantu;
            tail ->next = NULL;
            delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List Kosong!" << endl;
    }
}

//Hapus Tengah
void hapustengah(int posisi)
{
    node *hapus;
    node *bantu;

    if (isEmpty() == false){
        if (head != tail){
            bantu = head;
            for(int i = 1; i < posisi; i++){
                bantu = bantu ->next;
            }
            hapus = bantu ->next;
            bantu ->next = hapus ->next;
            delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List Kosong!" << endl;
    }
}

//Hapus List
void clearlist()
{
    node *bantu, *hapus;
    bantu = head;

    while (bantu != NULL){
        hapus = bantu;
        bantu = bantu ->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

//Tampilkan List
void tampil()
{
    node *bantu;
    bantu = head;

    if(isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "List Masih Kosong!" << endl;
    }
}

int main()
{
    // input jumlah data
    int jumlah;
    cout << "Masukkan jumlah data : ";
    cin >> jumlah;

    if (jumlah == 1) {
        cout << "Masukkan data : ";
        int data;
        cin >> data;
        InsertDepan(data);
    }
    else if (jumlah == 2) {
        cout << "Masukkan data : ";
        int data;
        cin >> data;
        InsertBelakang(data);
    }
    else if (jumlah > 3) {
        cout << "Masukkan data : ";
        int data;
        cin >> data;
        InsertDepan(data);

        for (int i = 1; i < jumlah-1; i++) {
            cout << "Masukkan data : ";
            cin >> data;
            InsertTengah(data, i+1);
        }

        cout << "Masukkan data : ";
        cin >> data;
        InsertBelakang(data);
    }

    tampil();

    // hapus secara random
    while (isEmpty() == false) {
        int random = rand() % 3;
        cout << "Random : " << random << endl;
        if (random == 0) {
            hapusdepan();
            tampil();
        }
        else if (random == 1) {
            hapusbelakang();
            tampil();
        }
        else {
            int posisi = rand() % (HitungList()-1) + 1;
            hapustengah(posisi);
            tampil();
        }
    }
    
    // tampilkan
    tampil();


    return 0;
}