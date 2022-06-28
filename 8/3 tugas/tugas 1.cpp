// Nama : Fatkhurrohman Purnomo
// NIM : 21102125

#include <iostream>

using namespace std;

///PROGRAM DOUBLE LINKED LIST CIRCULAR

//Deklarasi DLLC
struct Node
{
    int nomor ;
    string nama;
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
void create(int nomor , string nama, char karakter)
{
    baru = new Node;
    baru->nomor = nomor ;
    baru->nama = nama;
    baru->karakter = karakter;
    baru->next = NULL;
    baru->prev = NULL;
}

//Tambah Depan
void insertDepan(int nomor , string nama, char karakter)
{
    create(nomor, nama, karakter);

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
void insertBelakang(int nomor , string nama, char karakter)
{
    create(nomor, nama, karakter);

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
void insertTengah(int posisi, int nomor , string nama, char karakter)
{
    create(nomor, nama, karakter);

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
        cout << "==========================================================" << endl;
        cout << "| No | Huruf | Karakter |" << endl;
        cout << "==========================================================" << endl;
        do{
            cout << "  " << tail->nomor << "  : " << tail->nama << "    : " << tail->karakter << endl;
            tail = tail->next;
        }while (tail != head);
        cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}

// search 
void search(string nama)
{
    if (isEmpty() == 0){
        tail = head;
        cout << "==========================================================" << endl;
        cout << "| No | Huruf | Karakter |" << endl;
        cout << "==========================================================" << endl;
        do{
            if (tail->nama == nama){
                cout << "  " << tail->nomor << "  : " << tail->nama << "    : " << tail->karakter << endl;
            }
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
    int pilih, nomor , posisi;
    string nama;
    char karakter;

    init();

    do {
        system("cls");
        cout << endl;
        cout << "==========================================================" << endl;
        cout << "|                         Pilih Aksi                     |" << endl;
        cout << "==========================================================" << endl;
        cout << " 1. Tambah Depan" << endl;
        cout << " 2. Tambah Belakang" << endl;
        cout << " 3. Tambah Tengah" << endl;
        cout << " 4. Hapus Depan" << endl;
        cout << " 5. Hapus Belakang" << endl;
        cout << " 6. Hapus Tengah" << endl;
        cout << " 7. cari" << endl;
        cout << " 8. Hapus List" << endl;
        cout << " 9. Tampil" << endl;
        cout << " 10. Keluar" << endl;
        cout << " Masukkan pilihan anda : ";
        cin >> pilih;
        cout << "==========================================================" << endl << endl;

        switch (pilih){
            case 1:
                cout << " Masukkan No. : ";
                cin >> nomor ;
                cout << " Masukkan nama : ";
                cin >> nama;
                cout << " Masukkan kode : ";
                cin >> karakter;
                insertDepan(nomor, nama, karakter);
                break;
            case 2:
                cout << " Masukkan No. : ";
                cin >> nomor ;
                cout << " Masukkan nama : ";
                cin >> nama;
                cout << " Masukkan kode : ";
                cin >> karakter;
                insertBelakang(nomor, nama, karakter);
                break;
            case 3:
                cout << " Masukkan posisi : ";
                cin >> posisi;
                cout << " Masukkan No. : ";
                cin >> nomor ;
                cout << " Masukkan nama : ";
                cin >> nama;
                cout << " Masukkan kode : ";
                cin >> karakter;
                insertTengah(posisi, nomor , nama, karakter);
                break;
            case 4:
                hapusDepan();
                break;
            case 5:
                hapusBelakang();
                break;
            case 6:
                cout << " Masukkan posisi : ";
                cin >> posisi;
                hapusTengah(posisi);
                break;
            case 7:
                cout << " Masukkan nama : ";
                cin >> nama;
                search(nama);
                break;
            case 8:
                clearList();
                break;
            case 9:
                tampil();
                break;
            default:
                cout << " Pilihan tidak ada!" << endl;
                break;
        }
    }while (pilih != 10);
    cout << "==========================================================" << endl;

    return 0;
}