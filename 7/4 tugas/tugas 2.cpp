#include <iostream>
using namespace std;

///PROGRAM QUEUE DENGAN LINKED LIST
//Delarasi
struct antrian{
    string data;
    antrian *next;
};

antrian *head, *tail, *baru, *bantu, *hapus;

// fungsi untuk menghitung jumlah node (elemen) pada queue
int hitungAntrian(){
    if(head == NULL){
        return 0;
    } else{
        int counter = 0;
        bantu = head;
        while(bantu != NULL){ // looping untuk menghitung jumlah elemen pada queue
            counter++;
            bantu = bantu->next;
        }
        return counter;
    }
}

// fungsi untuk mengecek bahwa antrian kosong atau tidak
bool isEmpty(){
    if(hitungAntrian() == 0){
        return true;
    } else{
        return false;
    }
}

// jika antrian sudah penuh, maka tidak dapat menambahkan data
void enqueue(string data){
    if(isEmpty()){
        head = new antrian();
        head->data = data;
        head->next = NULL;
        tail = head;
    } else{
        baru = new antrian();
        baru->data = data;
        baru->next = NULL;
        tail->next = baru;
        tail = baru;
    }
}

// antrian makimal 20 orang
void maksimal(string nama){
    if (hitungAntrian() == 20){
        cout << endl << " Antrian penuh" << endl;
    } else{
        enqueue(nama); 
        cout << " Nama : " << nama << endl;
        cout << " No. Antrian : " << hitungAntrian() << "/20" << endl;
        cout << " Estimasi waktu personal meet & great adalah 5 menit." << endl;
        cout << " Silahkan tunggu " << hitungAntrian() * 5 << " menit lagi untuk tiba giliran anda." << endl;
        cout << endl << " Terima kasih." << endl;

    }
}

// rilis antrian
void rilisAntrian(){
    if(isEmpty()){
        cout << endl << " Antrian kosong" << endl;
    } else{
        cout << endl;
        cout << "============================================" << endl;
        cout << "|               Antrian Rilis              |" << endl;
        cout << "============================================" << endl;
        cout << " Nama              : " << head->data << endl;
        cout << " No. Antrian       : " << hitungAntrian() << endl;
        cout << " Telah keluar" << endl;
        cout << "============================================" << endl;
        hapus = head;
        head = head->next;
        hapus->next = NULL;
        delete hapus;
    }
}

// reset antrian
void resetAntrian(){
    if(isEmpty()){
        cout << " Antrian kosong" << endl;
    } else{
        bantu = head;
        while(bantu != NULL){
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;
        }
        head = NULL;
        tail = NULL;
        cout << " Antrian berhasil direset" << endl;
    }
}

int main(){
    int pil;
    string nama;

    do{
        system("cls");
        cout << endl;
        cout << "============================================" << endl;
        cout << "|               Cetak Antrian              |" << endl;
        cout << "============================================" << endl;
        cout << " 1. Cetak No. antrian" << endl;
        cout << " 2. Rilis antrian" << endl;
        cout << " 3. Reset antrian" << endl;
        cout << " 4. Keluar" << endl;
        cout << " Pilihan: ";
        cin >> pil;

        switch (pil){ // switch case untuk mengakses fungsi yang diinginkan
        case 1:
            cout << " Masukan nama : ";
            cin >> nama;
            cout << endl;
            maksimal(nama);
            break;
        case 2:
            rilisAntrian();
            break;
        case 3:
            resetAntrian();
            break;
        }
        cout << endl;
        system("pause");
    } while (pil != 4);
    return 0;
}

