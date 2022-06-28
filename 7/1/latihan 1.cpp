#include <iostream>
#define MAX 5 //menetapkan nilai konstanta MAX = 5 (ukuran antrian)
using namespace std;

///PROGRAM QUEUE DENGAN STRUCTURE ARRAY
//Deklarasi Queue
struct queue{
    int data[MAX];
    int head;
    int tail;
}antrian;

//Buat Queue
void create(){ //membuat antrian kosong
    antrian.head = antrian.tail = -1;
}

//isEmpty
int isEmpty(){ //mengecek apakah antrian kosong
    if (antrian.tail == -1)
        return 1;
    else
        return 0;
}

//isFull
int isFull(){ //mengecek apakah antrian penuh
    if (antrian.tail == MAX -1)
        return 1;
    else
        return 0;
}

//Enqueue
void enqueue(int data){ //menambahkan antrian
    if (isEmpty() == 1){ //jika antrian kosong
        antrian.head = antrian.tail = 0;
        antrian.data[antrian.tail] = data;
        cout << " " << antrian.data[antrian.tail] << " masuk!" << endl;
    }
    else if (isFull() == 0){ //jika antrian tidak penuh
        antrian.tail++;
        antrian.data[antrian.tail] = data;
        cout << " " << antrian.data[antrian.tail] << " masuk!" << endl;
    }
    else{
        cout << " antrian sudah penuh!" << endl;
    }
}

//Dequeue
void dequeue(){ //mengambil antrian
    int dq = antrian.data[antrian.head];
    if (isEmpty() == 0){ //jika antrian tidak kosong
        for (int i = antrian.head; i <= antrian.tail; i++){
            antrian.data[i] = antrian.data[i+1];
        }
        antrian.tail--;
        cout << " antrian depan terhapus." << endl;
        cout << " data terhapus = " << dq << endl;
    }
    else{
        cout << " antrian masih kosong!" << endl;
    }
}

//Clear
void clear(){ //mengosongkan seluruh antrian
    antrian.head = antrian.tail = -1;
    cout << " Data clear" << endl;
}

//Tampil
void display(){ //menampilkan data antrian
    if (isEmpty() == 0){
        for (int i = antrian.head; i <= antrian.tail; i++){
            cout << " " << antrian.data[i] << endl;
        }
    }
    else{
        cout << " antrian masih kosong!" << endl;
    }
}

int main(){
    int pil;
    int data;
    
    create();
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