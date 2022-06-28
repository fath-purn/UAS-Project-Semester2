#include <iostream>
using namespace std;

///PROGRAM DOUBLE LINKED LIST CIRCULAR
//Deklarasi DLLC
struct Node{
    string data;
    Node *next;
    Node *prev;
};

//Deklarasi Node
Node *head, *tail, *baru, *bantu, *bantu2, *hapus;

//Inisialisasi Node
void init(){
    head = NULL;
    tail = head;
}

//isEmpty
int isEmpty(){
    if (head == NULL && tail == NULL)
    return 1; //true
    else
    return 0; //false
}

//Buat Node Baru
void create(string input){
    baru = new Node;
    baru->data = input;
    baru->next = NULL;
    baru->prev = NULL;
}

//Tambah Depan
void insertDepan(string input){

    create(input);

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
void insertBelakang(string input){

    create(input);

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
void insertTengah(string input, int posisi){

    create(input);

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
void hapusDepan(){

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
void hapusBelakang(){

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
void hapusTengah(int posisi){

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
void clearList(){
    
    if (isEmpty() == 0){
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
void tampil(){

    if (isEmpty() == 0){
        tail = head;
        do{
            cout << tail->data << ends;
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
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    insertDepan("Babi");
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}