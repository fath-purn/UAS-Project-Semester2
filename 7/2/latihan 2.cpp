#include <iostream>
using namespace std;

///PROGRAM QUEUE DENGAN LINKED LIST
//Delarasi
struct antrian{
    int data;
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

// penambahan data antrian
void enqueue(int data){
    if(isEmpty()){
        head = new antrian();
        head->data = data;
        head->next = NULL;
        tail = head;
        cout << " berhasil menambahkan elemen baru" << endl;
    } else{
        baru = new antrian();
        baru->data = data;
        baru->next = NULL;
        tail->next = baru;
        tail = baru;
        cout << " berhasil menambahkan elemen baru" << endl;
    }
}

// pengeluaran data antrian
void dequeue(){
    if(isEmpty()){
        cout << " Antrian kosong" << endl;
    } else{
        hapus = head;
        head = head->next;
        hapus->next = NULL;
        delete hapus;
        cout << " berhasil mengeluarkan elemen pertama" << endl;
    }
}

// fungsi untuk mencetak nilai pada antrian
void display(){
    cout << " Data Antrian:" << endl;
    if(isEmpty()){ 
        cout << " Antrian kosong" << endl;
    } else{
        cout << " Jumlah data: " << hitungAntrian() << endl;
        bantu = head;
        while(bantu != NULL){ // mencetak data antrian
            cout << bantu->data << endl;
            bantu = bantu->next;
        }
    }
    cout << endl;
}

// fungsi untuk menghapus seluruh data pada antrian
void clear(){
    if(isEmpty()){ // jika antrian kosong
        cout << " Antrian Kosong" << endl;
    } else {
        head->next = NULL;
        head = NULL;
        cout << " menghapus seluruh data pada Queue" << endl;
        bantu = head;
    
        while(bantu != NULL){ // menghapus data antrian
            hapus = bantu;
            bantu = bantu->next;
            // menghapus node
            hapus->next = NULL;
            delete hapus;
        }
        head = NULL;
    }
}

int main(){
    int pil;
    int data;

    do{
        system("cls");
        cout << " 1. Enqueue" << endl;
        cout << " 2. Dequeue" << endl;
        cout << " 3. Tampil" << endl;
        cout << " 4. Clear" << endl;
        cout << " 5. Exit" << endl;
        cout << " Pilihan: ";
        cin >> pil;

        switch (pil){ // switch case untuk mengakses fungsi yang diinginkan
        case 1:
            cout << " Data = ";
            cin >> data;
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            clear();
            break;
        }
        cout << endl;
        system("pause");
    } while (pil != 5);
    return 0;
}