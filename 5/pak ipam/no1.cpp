// Nama : Fatkhurrohman Purnomo
// Nim : 21102125

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

// deklarasi struct node
struct node
{
    int data;
    node *next;
};

node *head;
node *tail;

// input data
void input(node *&head, node *&tail)
{
    int data;
    cout << endl << "Masukkan data : ";
    cin >> data;
    node *baru = new node;
    baru->data = data;
    baru->next = NULL;
    if (head == NULL)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

// hitung jumlah data
int hitungList(node *head)
{
    node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// hapus data secara acak
void hapus(node *&head, node *&tail)
{
    if (head == NULL)
    {
        cout << endl << "List kosong!" << endl;
    }
    else
    {
        node *hapus, *bantu;
        int acak;
        acak = rand() % (hitungList(head) + 1);
        if (acak == 0)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            bantu = head;
            for (int i = 1; i < acak - 1; i++)
            {
                bantu = bantu->next;
            }
            hapus = bantu->next;
            bantu->next = hapus->next;
            delete hapus;
        }
    }
}

bool isEmpty()
{
    if(head == NULL)
        return true;
    else
        return false;
}

// tampilkan data
void tampil(node *head)
{
    if (head == NULL)
    {
        cout<< endl << "List kosong!" << endl;
    }
    else
    {
        node *bantu;
        bantu = head;
        while (bantu != NULL)
        {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    }
}

int main(){
    node *head = NULL;
    node *tail = NULL;
    int pilih;
    do
    {
        cout << endl << "==========================================" << endl;
        cout << "               Pilih menu : " << endl;
        cout << "==========================================" << endl;
        cout << "1. Input data" << endl;
        cout << "2. Hapus data" << endl;
        cout << "3. Tampilkan data" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih : ";
        cin >> pilih;
        switch (pilih)
        {
        case 1:
            input(head, tail);
            break;
        case 2:
            hapus(head, tail);
            break;
        case 3:
            tampil(head);
            break;
        }
    } while (pilih != 4);
    return 0;
}