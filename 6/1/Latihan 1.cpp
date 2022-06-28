// Nama : Fatkhurrohman Purnomo
// NIM : 21102125

#include <iostream>
#define MAX 5 //menetapkan nilai konstanta MAX = 5 (ukuran stack)
using namespace std;

///PROGRAM STACK DENGAN STRUCTURE
//Deklarasi Stack
struct Stack{
    int top;
    int data[MAX]; //array dengan ukuran MAX (5)
}myStack;

void initStack(){//inisialisasi stack
    myStack.top = -1;
}

// mengecek apakah tumpukan kosong
int isEmpty(){ 
    if (myStack.top == -1)
    return 1;
    else
    return 0;
}

// mengecek apakah tumpukan penuh
int isFull(){ 
    if (myStack.top == MAX - 1){
        return 1;
    }
    else {
        return 0;
    }
}

//Insert Data (Push)
void push(int data){
    if (isEmpty() == 1){
        myStack.top++;
        myStack.data[myStack.top] = data;
        cout << " Data " << data << " telah dimasukkan" << endl;
    }
    else if (isFull() == 0){
        myStack.top++;
        myStack.data[myStack.top] = data;
        cout << " Data " << data << " telah dimasukkan" << endl;
    }
    else{
        cout << " Stack penuh!" << endl;
    }
}

//Hapus Data (Pop)
void pop(){
    if (isEmpty() == 0){
        myStack.top--;
        cout << " Data teratas terambil" << endl;
    }
    else{
        cout << " Stack masih kosong!" << endl;
    }
}

//Tampilkan Top
void top(){
    if (isEmpty() == 0){
        cout << " " << myStack.data[myStack.top] << endl;
    }
    else{
        cout << " Stack masih kosong!" << endl;
    }
}

//Tampilkan Stack
void display(){
    if (isEmpty() == 0){
        for (int i = myStack.top; i>=0; i--){
            cout << " " << myStack.data[i] << endl;
        }
    }
    else{
        cout << " Stack masih kosong!" << endl;
    }
}

//Hapus Stack
void clear(){
    myStack.top = -1;
    cout << " Stack berhasil dihapus" << endl;
}

int main(){
    int pilihan, nilai;
    initStack();

    // menu
    do{
        system("cls");
        cout << "=== Menu ===" << endl;
        cout << " 1. Memasukkan data (Push)" << endl;
        cout << " 2. Menghapus data (Pop)" << endl;
        cout << " 3. Menampilkan data teratas (Top)" << endl;
        cout << " 4. Menampilkan data" << endl;
        cout << " 5. Hapus Stack" << endl;
        cout << " 6. Keluar" << endl;
        cout << " Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
        
        // untuk input data
        if (pilihan==1){
            cout << " Masukkan data: ";
            cin >> nilai;
            push(nilai);
        }
        else if (pilihan==2){
            pop();
        }
        else if (pilihan==3){
            top();
        }
        else if (pilihan==4){
            display();
        }
        else if (pilihan==5){
            clear();
        }
        else{
           return 0;
        }
        
        cout << endl;
        system("pause");
    }while (pilihan != 6);
    return 0;
}