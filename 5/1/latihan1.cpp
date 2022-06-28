// Nama : Fatkhurrohman Purnomo
// NIM : 21102125

#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node
{
    int data;
    Node *next;
};

Node *head;
Node *tail;

//Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}

//Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}

//Tambah Depan
void insertDepan(int nilai)
{
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    // Jika list kosong
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    } 
    else{
        baru->next = head;
        head = baru;
    }
}

//Tambah Belakang
void insertBelakang(int nilai)
{
    //Buat Node baru
    Node *baru = new Node; 
    baru->data = nilai;
    baru->next = NULL;
    
    // Jika list kosong
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
        tail->next = baru;
        tail = baru;
    }
}

//Hitung Jumlah List
int hitungList()
{
    Node *hitung; //Node bantu
    hitung = head; //Node bantu diinisialisasi dengan head
    int jumlah = 0; //Inisialisasi jumlah dengan 0

    // Hitung jumlah elemen
    while( hitung != NULL ){ 
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

//Tambah Tengah
void insertTengah(int data, int posisi)
{
    if( posisi < 1 || posisi > hitungList() ){ //Jika posisi tidak sesuai
        cout << "Posisi diluar jangkauan" << endl;
    }else if( posisi == 1){ //Jika posisi pertama
        cout << "Posisi bukan posisi tengah" << endl;
    }else{ //Jika posisi tengah
        Node *baru, *bantu; //Deklarasi Node baru dan bantu
        baru = new Node(); //Membuat Node baru
        baru->data = data; //Mengisi data

        // tranversing
        bantu = head;
        int nomor = 1;
        
        while( nomor < posisi - 1 ){ //Posisi sebelum posisi tengah
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next; //Posisi tengah
        bantu->next = baru; //Posisi sebelum posisi tengah 
    }
}

//Hapus Depan
void hapusDepan()
    {
    Node *hapus;
    if (isEmpty() == false){ //Jika list tidak kosong
        if (head->next != NULL){ //Jika list hanya memiliki 1 elemen
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else{ 
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}

//Hapus Belakang
void hapusBelakang()
{
    Node *hapus; //Node yang akan dihapus
    Node *bantu; //Node yang akan menunjuk ke node sebelum hapus

    if (isEmpty() == false){ //Jika list tidak kosong
        if (head != tail){ //Jika list tidak berisi 1 elemen
            hapus = tail;
            bantu = head;
            while (bantu->next != tail){ //Transversing
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else{ 
            head = tail = NULL;
        }
    }
    else{ 
        cout << "List kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *bantu, *hapus, *sebelum; //Deklarasi variabel
    
    if( posisi < 1 || posisi > hitungList() ){ //Jika posisi tidak sesuai
        cout << "Posisi di luar jangkauan" << endl;
    }else if( posisi == 1){ //Jika posisi pertama
        cout << "Posisi bukan posisi tengah" << endl;
    }else{ //Jika posisi tengah
        int nomor = 1; //Nomor posisi
        bantu = head;
        
        while( nomor <= posisi ){ //Transversing
        if( nomor == posisi-1 ){ //Jika posisi sebelumnya
            sebelum = bantu;
        }
            if( nomor == posisi ){ //Jika posisi yang dihapus
                hapus = bantu;
            }
            bantu = bantu->next; //Transversing
            nomor++;
        }
        
        sebelum->next = bantu;
        delete hapus;
    }
}

//Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == 0){ //Jika list tidak kosong
        head->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}

//Ubah Tengah
void ubahTengah(int data, int posisi)
    {
    
    Node *bantu;
    if (isEmpty() == 0){ //Jika list tidak kosong
        if( posisi < 1 || posisi > hitungList() ){ //Jika posisi tidak sesuai
            cout << "Posisi diluar jangkauan" << endl;
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if( posisi == 1){ //Jika posisi pertama
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else{ //Jika posisi tengah
            bantu = head;
            int nomor = 1;
            
            while (nomor < posisi){
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }else{ //Jika list kosong
        cout << "List masih kosong!" << endl;
    }
}

//Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == 0){ //Jika list tidak kosong
        tail->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}

//Hapus List
void clearList()
{
    Node *bantu, *hapus; //bantu untuk transversing, hapus untuk menghapus
    bantu = head; //bantu di set head

    while (bantu != NULL){ //Transversing
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }

    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

//Tampilkan List
void tampil()
{
    Node *bantu; //bantu untuk transversing
    bantu = head; //bantu di set head

    if (isEmpty() == false){ //Jika list tidak kosong
        while (bantu != NULL){ //Transversing
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
    init(); 
    insertDepan(3); 
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();

    return 0;
}