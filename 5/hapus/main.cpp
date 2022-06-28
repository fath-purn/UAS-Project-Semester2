#include <iostream>

using namespace std;

//PROGRAM SINGLE LINKED LIST NON - CIRCULAR

//Declarasi Struct Node
struct node
{
    int data;
    string nama;
    int nim;
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
    if( posisi < 1 || posisi > HitungList() ){
        cout << "Posisi diluar jangkauan" << endl;
    }else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }else{
        node *baru, *bantu;
        baru = new node();
        baru ->data = data;

        //Tranversing
        bantu = head;
        int nomor = 1;
        while ( nomor < posisi - 1 ){
            bantu = bantu->next;
            nomor++;
        }
        baru ->next = bantu->next;
        bantu ->next = baru;
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
    node *bantu, *hapus, *sebelum;
    if ( posisi < 1 || posisi > HitungList()){
        cout << "Posisi diluar jangkauan" << endl;
    }else if ( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
        }else{
            int nomor = 1;
            bantu = head;
            while ( nomor <= posisi ){
            if (nomor == posisi-1){
                sebelum = bantu;
            }
            if (nomor == posisi){
                hapus = bantu;
            }
            bantu = bantu ->next;
            nomor++;
            }
            sebelum ->next = bantu;
            delete hapus;
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
void tampil2()
{
    node *bantu;
    bantu = head;

    if(isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->nama << bantu ->nim << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "List Masih Kosong!" << endl;
    }
}
//Buat Node Baru
//Muhammad Makhdum Wahid - 21102007

void BuatNodeBaru( string nama, int nim )
{
    node *baru = new node;
    baru ->nama = nama;
    baru ->nim = nim;


    if (isEmpty() == true){
        head = tail = baru;
        tail ->next = NULL;
    }
    else{
        baru ->next = head;
        head = baru;
    }
}
int main()
{
    init();
    InsertDepan(3);
    tampil();
    InsertBelakang(5);
    tampil();
    InsertDepan(2);
    tampil();
    InsertDepan(1);
    tampil();
    hapusdepan();
    tampil();
    hapusbelakang();
    tampil();
    InsertTengah(7,2);
    tampil();
    hapustengah(2);
    tampil();
    clearlist();
    tampil();
    cout << endl;
    cout << "LIST DARI NODE BARU" << endl;
    cout << "===================" << endl;
    cout << "Nama    NIM" << endl;
    cout << "===================" << endl;
    BuatNodeBaru( "Makhdum ", 21102007 );
    tampil2();


    return 0;
}