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
void create(int angka, string huruf)
{
    baru = new Node;
    baru->angka = angka;
    baru->huruf = huruf;
    baru->next = NULL;
    baru->prev = NULL;
}

//Tambah Depan
void insertDepan(int angka, string huruf)
{
    create(angka, huruf);

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
void insertBelakang(int angka, string huruf)
{
    create(angka, huruf);

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
void insertTengah(int angka, int posisi, string huruf)
{
    create(angka, huruf);

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
void ubahDepan(int angka, string huruf)
{
    if (isEmpty() == 0){
        head->angka = angka;
        head->huruf = huruf;
    }
    else{
        cout << " List masih kosong!" << endl;
    }
}

//Ubah Belakang
void ubahBelakang(int angka, string huruf)
{
    if (isEmpty() == 0){
        tail->angka = angka;
        tail->huruf = huruf;
    }
    else{
        cout << " List masih kosong!" << endl;
    }
}

//Ubah Tengah
void ubahTengah(int posisi, int angka, string huruf)
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
    bantu = tail;

    cout << endl << " List : " << endl;
    if (isEmpty() == 0){
        while (bantu != NULL){
            cout << bantu->angka << " = " << bantu->huruf << endl;
            bantu = bantu->prev;
        }
        cout << endl;
    }
    else{
        cout << " List masih kosong!" << endl;
    }
}

int main()
{
    int pilih, nomor, posisi;
    string nama;

    do{
        cout << endl << " Menu : " << endl;
        cout << " 1. Tambah Depan" << endl;
        cout << " 2. Tambah Belakang" << endl;
        cout << " 3. Tambah Tengah" << endl;
        cout << " 4. Hapus Depan" << endl;
        cout << " 5. Hapus Belakang" << endl;
        cout << " 6. Hapus Tengah" << endl;
        cout << " 7. Ubah Depan" << endl;
        cout << " 8. Ubah Belakang" << endl;
        cout << " 9. Ubah Tengah" << endl;
        cout << " 10. Hapus List" << endl;
        cout << " 11. Tampilkan List" << endl;

        cout << " Masukkan pilihan: ";
        cin >> pilih;
        cout << endl;

        switch(pilih){
            case 1:
                cout << " Masukkan nomor: ";
                cin >> nomor;
                cout << " Masukkan huruf: ";
                cin >> nama;
                insertDepan(nomor, nama);
                break;
            case 2:
                cout << " Masukkan nomor: ";
                cin >> nomor;
                cout << " Masukkan huruf: ";
                cin >> nama;
                insertBelakang(nomor, nama);
                break;
            case 3:
                cout << " Masukkan nomor: ";
                cin >> nomor;
                cout << " Masukkan huruf: ";
                cin >> nama;
                cout << " Masukkan posisi: ";
                cin >> posisi;
                insertTengah(posisi, nomor, nama);
                break;
            case 4:
                hapusDepan();
                break;
            case 5:
                hapusBelakang();
                break;
            case 6:
                cout << " Masukkan posisi: ";
                cin >> posisi;
                hapusTengah(posisi);
                break;
            case 7:
                cout << " Masukkan nomor: ";
                cin >> nomor;
                cout << " Masukkan huruf: ";
                cin >> nama;
                ubahDepan(nomor, nama);
                break;
            case 8:
                cout << " Masukkan nomor: ";
                cin >> nomor;
                cout << " Masukkan huruf: ";
                cin >> nama;
                ubahBelakang(nomor, nama);
                break;
            case 9:
                cout << " Masukkan nomor: ";
                cin >> nomor;
                cout << " Masukkan huruf: ";
                cin >> nama;
                cout << " Masukkan posisi: ";
                cin >> posisi;
                ubahTengah(posisi, nomor, nama);
                break;
            case 10:
                clearList();
                break;
            case 11:
                tampil();
                break;
            default:
                cout << " Pilihan tidak ada!" << endl;
        }
    }while(pilih != 0);

    return 0;
}

