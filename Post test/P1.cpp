/*
Nama:Sri Rejeki
NIM :21102240
Kelas:S1 IF 09 G
*/
#include <iostream>
using namespace std;
struct data_node
{
    char nama[50];
    char nim[20];
};
struct dlinkedlist
{
    dlinkedlist *prev;
    data_node data;
    dlinkedlist *next;
};
dlinkedlist *head;
dlinkedlist *tail;
dlinkedlist *vertex;
void inisialisasi()
{
    head = NULL;
    tail = NULL;
}
bool dLinkKosong()
{
    if (head == NULL && tail == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void tambahDepan(data_node du)
{
    if (dLinkKosong() == true)
    {
        vertex = new dlinkedlist;
        vertex->data = du;
        vertex->prev = NULL;
        vertex->next = NULL;
        head = vertex;
        tail = vertex;
    }
    else
    {
        vertex = new dlinkedlist;
        vertex->data = du;
        vertex->prev = NULL;
        vertex->next = NULL;
        vertex->next = head;
        head->prev = vertex;
        head = vertex;
    }
}
void tambahBelakang(data_node du)
{
    if (dLinkKosong() == true)
    {
        vertex = new dlinkedlist;
        vertex->data = du;
        vertex->prev = NULL;
        vertex->next = NULL;
        head = vertex;
        tail = vertex;
    }
    else
    {
        vertex = new dlinkedlist;
        vertex->data = du;
        vertex->prev = NULL;
        vertex->next = NULL;
        tail->next = vertex;
        vertex->prev = tail;
        tail = vertex;
    }
}
void tambahTengah(data_node du)
{
    dlinkedlist *helper;
    dlinkedlist *helper2;
    int nomor = 2, pos;
    vertex = new dlinkedlist;
    vertex->data = du;
    vertex->prev = NULL;
    vertex->next = NULL;
    cout << "Masukkan Posisi: ";
    cin >> pos;
    if (head == NULL)
    {
        cout << "List masih kosong!" << endl;
    }
    else if (pos == 1)
    {
        cout << "Posisi bukan posisi tengah!" << endl;
    }
    else if (pos < 1)
    {
        cout << "Posisi diluar jangkauan!" << endl;
    }
    else
    {
        helper = head;
        while (helper)
        {
            if (nomor == pos)
            {
                helper2 = helper->next;
                vertex->next = helper2;
                helper2->prev = vertex;
                helper->next = vertex;
                vertex->prev = helper;
                break;
            }
            helper = helper->next;
            nomor++;
        }
    }
}
void hapusDepan()
{
    if (dLinkKosong() == true)
    {
        cout << "List Masih Kosong!" << endl;
    }
    else
    {
        dlinkedlist *helper, simpan;
        simpan.data = head->data;
        cout << "Data " << simpan.data.nama << " berhasil dihapus!" << endl;
        helper = head;
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
            delete helper;
        }
        else
        {
            head = head->next;
            head->prev = NULL;
            helper->next = NULL;
            delete helper;
        }
    }
}
void hapusBelakang()
{
    if (dLinkKosong() == true)
    {
        cout << "List Masih Kosong!" << endl;
    }
    else
    {
        if (head == tail)
        {
            dlinkedlist *helper, simpan;
            simpan.data = tail->data;
            cout << "Data " << simpan.data.nama << " berhasil dihapus!" << endl;
            helper = head;
            head = NULL;
            tail = NULL;
            delete helper;
        }
        else
        {
            dlinkedlist *helper, simpan;
            helper = tail;
            tail = tail->prev;
            tail->next = NULL;
            helper->prev = NULL;
            delete helper;
        }
    }
}
void hapusTengah()
{
    int nomor = 1, pos;
    dlinkedlist *hapus, *helper, *helper2;
    cout << "Masukkan Posisi: ";
    cin >> pos;
    if (head == NULL)
    {
        cout << "List masih kosong!" << endl;
    }
    else if (pos == 1)
    {
        cout << "Posisi bukan posisi tengah!" << endl;
    }
    else if (pos < 1)
    {
        cout << "Posisi diluar jangkauan!" << endl;
    }
    else
    {
        hapus = head;
        while (hapus)
        {
            if (nomor == pos)
            {
                helper2 = hapus->next;
                helper = hapus->prev;
                helper->next = helper2;
                helper2->prev = helper;
                delete hapus;
            }
            hapus = hapus->next;
            nomor++;
        }
    }
}
void tampil()
{
    if (dLinkKosong() == true)
    {
        cout << "List Masih Kosong!" << endl;
    }
    else
    {
        dlinkedlist *helper;
        helper = head;
        while (helper != NULL)
        {
            cout << helper->data.nama << " \t" << helper->data.nim << endl;
            helper = helper->next;
        }
    }
}
int main()
{
    inisialisasi();
    dlinkedlist temp;
    int pilih;
menu:
    system("cls");
    cout << "PROGRAM DOUBLE LINKED LIST NON-CIRCULAR" << endl;
    cout << "\n";
    cout << "1. Tambah Depan" << endl;
    cout << "2. Tambah Belakang" << endl;
    cout << "3. Tambah Tengah" << endl;
    cout << "4. Hapus Depan" << endl;
    cout << "5. Hapus Belakang" << endl;
    cout << "6. Hapus Tengah" << endl;
    cout << "7. Tampilkan List" << endl;
    cout << "0. KELUAR" << endl;
    cout << "\n";
    cout << "Pilih Operasi : ";
    cin >> pilih;
    cout << "\n";
    switch (pilih)
    {
    case 1:
        if (pilih == 1)
        {
            cout << "-Tambah Depan-" << endl;
            cout << "Masukkan Nama : ";
            cin >> temp.data.nama;
            cout << "Masukkan NIM : ";
            cin >> temp.data.nim;
            cout << "Data " << temp.data.nama << " berhasil diinput!" << endl;
            tambahDepan(temp.data);
        }
        break;
    case 2:
        if (pilih == 2)
        {
            cout << "-Tambah Belakang-" << endl;
            cout << "Masukkan Nama : ";
            cin >> temp.data.nama;
            cout << "Masukkan NIM : ";
            cin >> temp.data.nim;
            cout << "Data " << temp.data.nama << " berhasil diinput!" << endl;
            tambahBelakang(temp.data);
        }
        break;
    case 3:
        if (pilih == 3)
        {
            cout << "-Tambah Tengah-" << endl;
            cout << "Masukkan Nama : ";
            cin >> temp.data.nama;
            cout << "Masukkan NIM : ";
            cin >> temp.data.nim;
            tambahTengah(temp.data);
            cout << "Data " << temp.data.nama << " berhasil diinput!" << endl;
        }
        break;
    case 4:
        if (pilih == 4)
        {
            hapusDepan();
        }
        break;
    case 5:
        if (pilih == 5)
        {
            hapusBelakang();
        }
        break;
    case 6:
        if (pilih == 6)
        {
            hapusTengah();
            cout << "Data berhasil dihapus!" << endl;
        }
        break;
    case 7:
        if (pilih == 7)
        {
            cout << "DATA MAHASISWA" << endl;
            cout << "\n";
            tampil();
        }
        break;
    case 0:
        if (pilih == 0)
        {
            system("cls");
        }
        break;
    default:
        exit(0);
    }
    cout << "\n";
    system("pause");
    goto menu;
    cout << "/n";
    return 0;
}