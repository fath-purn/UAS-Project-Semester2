#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST CIRCULAR
//Deklarasi Struct Node
struct Node
{
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus; // membuat variabel head, tail, baru, bantu, hapus

//Inisialisasi Node
void init()
{
    head = NULL;
    tail = head;
}

//Pengecekan
int isEmpty()
{
    if (head == NULL) // jika head kosong
        return 1; //true
    else
        return 0; //false
}

//Buat Node Baru
void buatNode(string data)
{
    baru = new Node; // membuat node baru
    baru->data = data; // mengisi data
    baru->next = NULL; // mengisi next dengan NULL
}

//Hitung List
int hitungList()
{
    bantu = head; // membuat bantu menunjuk head
    int jumlah = 0; // membuat variabel jumlah

    while (bantu != NULL){ // jika bantu tidak kosong
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

//Tambah Depan
void insertDepan(string data)
{
    //Buat Node baru
    buatNode(data);

    if (isEmpty() == 1){ // jika list kosong
        head = baru;
        tail = head;
        baru->next = head;
    }
    else{ // jika list tidak kosong
        while (tail->next != head){ // jika tail tidak menunjuk head
            tail = tail->next;
            }
            baru->next = head;
            head = baru;
            tail->next = head;
    }
}

//Tambah Belakang
void insertBelakang(string data)
{
    //Buat Node baru
    buatNode(data);

    if (isEmpty() == 1){ // jika list kosong
        head = baru;
        tail = head;
        baru->next = head;
    }
    else{ // jika list tidak kosong
        while (tail->next != head){ // jika tail tidak menunjuk head
            tail = tail->next;
            }
            tail->next = baru;
            baru->next = head;
    }
}
//Tambah Tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 1){ // jika list kosong
        head = baru;
        tail = head;
        baru->next = head;
    }
    else{ // jika list tidak kosong
        baru->data = data;
    
    //transversing
    int nomor = 1;
    bantu = head;
    
    while (nomor < posisi - 1){ // jika nomor kurang dari posisi - 1
        bantu = bantu->next; 
        nomor++;
    }
    baru->next = bantu->next; // mengisi next dengan bantu->next
    bantu->next = baru; // mengisi bantu->next dengan baru
    }
}

//Hapus Depan
void hapusDepan()
{
    if (isEmpty() == 0){ // jika list tidak kosong
        hapus = head;
        tail = head;
        if (hapus->next == head){ // jika head menunjuk head
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else{ // jika head tidak menunjuk head
            while (tail->next != hapus){
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus; // menghapus data
        }
    }   
    else{
        cout << "List masih kosong!" << endl;
    }
}

//Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0){ // jika list tidak kosong
        hapus = head; // membuat hapus menunjuk head
        tail = head; // membuat tail menunjuk head
        if (hapus->next == head){ // jika head menunjuk head
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else{ // jika head tidak menunjuk head
            while (hapus->next != head){ // jika hapus tidak menunjuk head
                hapus = hapus->next;
            }
            while (tail->next != hapus){ // jika tail tidak menunjuk hapus
                tail = tail->next;
            }

            tail->next = head; // mengisi tail->next dengan head
            hapus->next = NULL; // mengisi hapus->next dengan NULL
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
    if (isEmpty() == 0){ // jika list tidak kosong
        //transversing
        int nomor = 1;
        bantu = head;
        
        while (nomor < posisi - 1){ // jika nomor kurang dari posisi - 1
            bantu = bantu->next; 
            nomor++;
        }

        hapus = bantu->next; // membuat hapus menunjuk bantu->next 
        bantu->next = hapus->next; // mengisi bantu->next dengan hapus->next
        delete hapus;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}

//Hapus List
void clearList()
{
    if (head != NULL){ // jika head tidak kosong
        hapus = head->next;
        while (hapus != head){ // jika hapus tidak menunjuk head
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }

        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

//Tampilkan List
void tampil()
{
    if (isEmpty() == 0){ // jika list tidak kosong
        tail = head;
        do{ // jika tail tidak menunjuk head
            cout << tail->data << ends;
            tail = tail->next;
        }while (tail != head); // jika tail tidak menunjuk head
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
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();

    return 0;
}