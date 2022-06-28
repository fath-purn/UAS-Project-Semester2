#include <iostream>
using namespace std;

// struct Node
struct Node
{
    int data;
    string nama;
    Node *next;
};

Node *head;
Node *tail;

// tambah depan
void tambahDepan(Node *&head, string nama, int nim)
{
    Node *baru = new Node;
    baru ->data = nim;
    baru ->nama = nama;
    baru ->next = NULL;
    
    if (head == NULL)
    {
        head = tail = baru;
        tail ->next = NULL;
    }
    else
    {
        baru ->next = head;
        head = baru;
    }
}

// tambah belakang
void tambahBelakang(Node *&head, string nama, int nim)
{
    Node *baru = new Node;
    baru ->data = nim;
    baru ->nama = nama;
    baru ->next = NULL;
    
    if (head == NULL)
    {
        head = tail = baru;
        tail ->next = NULL;
    }
    else
    {
        tail ->next = baru;
        tail = baru;
    }
}

// tambah tengah
void tambahTengah(Node *&head, string nama, int nim, int posisi)
{
    Node *baru = new Node;
    baru ->data = nim;
    baru ->nama = nama;
    baru ->next = NULL;
    
    if (head == NULL)
    {
        head = tail = baru;
        tail ->next = NULL;
    }
    else
    {
        Node *temp = head;
        for (int i = 1; i < posisi; i++)
        {
            temp = temp ->next;
        }
        baru ->next = temp ->next;
        temp ->next = baru;
    }
}

// ubah depan
void ubahDepan(Node *&head, string nama, int nim)
{
    if (head == NULL)
    {
        cout << "List kosong" << endl;
    }
    else
    {
        head ->data = nim;
        head ->nama = nama;
    }
}

// ubah belakang
void ubahBelakang(Node *&head, string nama, int nim)
{
    if (head == NULL)
    {
        cout << "List kosong" << endl;
    }
    else
    {
        tail ->data = nim;
        tail ->nama = nama;
    }
}

// ubah tengah
void ubahTengah(Node *&head, string nama, int main, int posisi)
{
    if (head == NULL)
    {
        cout << "List kosong" << endl;
    }
    else
    {
        Node *temp = head;
        for (int i = 1; i < posisi; i++)
        {
            temp = temp ->next;
        }
        temp ->data = main;
        temp ->nama = nama;
    }
}

// hapus depan
void hapusDepan(Node *&head)
{
    // jika list kosong
    if (head == NULL)
    {
        cout << "List kosong" << endl;
    }
    else
    {
        // jika list hanya satu elemen
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            Node *hapus = head;
            head = head->next;
            delete hapus;
        }
    }
}

// hapus belakang
void hapusBelakang(Node *&head)
{
    // jika list kosong
    if (head == NULL)
    {
        cout << "List kosong" << endl;
    }
    else
    {
        // jika list hanya satu elemen
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            Node *previous = NULL;
            Node *current = head;

            while (current->next != NULL)
            {
                previous = current;
                current = current->next;
            }

            delete current;
            previous->next = NULL;
            tail = previous;
        }
    }
}

// hapus tengah
void hapusTengah(Node *&head, int posisi)
{
    // jika list kosong
    if (head == NULL)
    {
        cout << "List kosong" << endl;
    }
    else
    {
        // transversing
        Node *previous = NULL;
        Node *current = head;
        int counter = 1;

        while (current != NULL && counter != posisi)
        {
            previous = current;
            current = current->next;
            counter++;
        }

        // jika posisi melebihi jumlah elemen list
        if (current == NULL && counter != posisi)
        {
            cout << "Posisi melebihi jumlah elemen list" << endl;
        }
        else
        {
            // jika posisi di awal
            if (previous == NULL)
            {
                head = current->next;
                delete current;
            }
            else
            {
                previous->next = current->next;
                delete current;
            }
        }
    }
}

// hapus List
void hapusList(Node *&head)
{
    // jika list kosong
    if (head == NULL)
    {
        cout << "List kosong" << endl;
    }
    else
    {
        Node *current = head;
        Node *next;

        while (current != NULL)
        {
            next = current->next;
            delete current;
            current = next;
        }

        head = NULL;
        tail = NULL;
    }
}

// tampilkan list
void tampilkanList(Node *head)
{
    if (head == NULL)
    {
        cout << "List kosong" << endl;
    }
    else
    {
        Node *current = head;
        cout << endl << "Data Mahasiswa" << endl;
        cout << " NIM       |       Nama" << endl;
        while (current != NULL)
        {
            cout << " " << current->data << "  |  " << current->nama << endl;
            current = current->next;
        }
        cout << endl;
    }
}

// mencari nilai
bool cariNilai(Node *head, int nilai)
{
    // jika list kosong
    if (head == NULL)
    {
        return false;
    }
    else
    {
        Node *current = head;

        while (current != NULL)
        {
            if (current->data == nilai)
            {
                return true;
            }
            current = current->next;
        }
    }

    return false;
}

int main(){
    Node *head = NULL;
    int pilihan;
    int nilai;
    int posisi;
    string nama;
    int nim;

    do
    {
        cout << "===========================================================" << endl;
        cout << "|                        Daftar Menu                      |" << endl;
        cout << "===========================================================" << endl;
        cout << "   1. Tambah depan" << endl;
        cout << "   2. Tambah tengah" << endl;
        cout << "   3. Tambah belakang" << endl;
        cout << "   4. Ubah depan" << endl;
        cout << "   5. Ubah tengah" << endl;
        cout << "   6. Ubah belakang" << endl;
        cout << "   7. Hapus depan" << endl;
        cout << "   8. Hapus belakang" << endl;
        cout << "   9. Hapus tengah" << endl;
        cout << "  10. Hapus list" << endl;
        cout << "  11. Tampilkan list" << endl;
        cout << "  12. Cari nilai" << endl;
        cout << "  13. Keluar" << endl;
        cout << "  Pilihan : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "Masukan Nama       : ";
            cin >> nama;
            cout << "Masukan NIM        : ";
            cin >> nim;
            tambahDepan(head, nama, nim);
            cout << "Data " << nama << " Berhasil Diinput" << endl << endl;
            break;
        case 2:
            cout << "Masukan Nama       : ";
            cin >> nama;
            cout << "Masukan NIM        : ";
            cin >> nim;
            cout << "Masukan Posisi     : ";
            cin >> posisi;
            tambahTengah(head, nama, nim, posisi);
            cout << "Data " << nama << " Berhasil Diinput" << endl << endl;
            break;
        case 3:
            cout << "Masukan Nama       : ";
            cin >> nama;
            cout << "Masukan NIM        : ";
            cin >> nim;
            tambahBelakang(head, nama, nim);
            cout << "Data " << nama << " Berhasil Diinput" << endl << endl;
            break;
        case 4:
            cout << "Masukan Nama       : ";
            cin >> nama;
            cout << "Masukan NIM        : ";
            cin >> nim;
            cout << "Data Berhasil Diinput" << endl << endl;
            ubahDepan(head, nama, nim);
            break;
        case 5:
            cout << "Masukan Nama       : ";
            cin >> nama;
            cout << "Masukan NIM        : ";
            cin >> nim;
            cout << "Masukan Posisi     : ";
            cin >> posisi;
            cout << "Data " << head << " Berhasil Diubah" << endl << endl;
            ubahTengah(head, nama, nim, posisi);
            break;
        case 6:
            cout << "Masukan Nama       : ";
            cin >> nama;
            cout << "Masukan NIM        : ";
            cin >> nim;
            cout << "Data Berhasil Diubah" << endl << endl;
            ubahBelakang(head, nama, nim);
            break;
        case 7:
            hapusDepan(head);
            cout << "Data " << head <<" Berhasil Dihapus" << endl << endl;
            break;
        case 8:
            hapusBelakang(head);
            cout << "Data " << head <<" Berhasil Dihapus" << endl << endl;
            break;
        case 9:
            cout << "Posisi : ";
            cin >> posisi;
            hapusTengah(head, posisi);
            cout << "Data " << head <<" Berhasil Dihapus" << endl << endl;
            break;
        case 10:
            hapusList(head);
            cout << "Data " << head <<" Berhasil Dihapus" << endl << endl;
            break;
        case 11:
            tampilkanList(head);
            break;
        case 12:
            cout << "Masukan Nilai : ";
            cin >> nilai;
            if (cariNilai(head, nilai))
            {
                cout << "Nilai " << nilai << " Ditemukan" << endl << endl;
            }
            else
            {
                cout << "Nilai " << nilai << " Tidak Ditemukan" << endl << endl;
            }
            break;
        case 13:
            break;
        default:
            cout << "Pilihan tidak ada" << endl << endl;
            break;
        }
    } while (pilihan != 13);








    return 0;
}
