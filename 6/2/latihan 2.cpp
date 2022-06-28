// Nama : Fatkhurrohman Purnomo
// NIM : 21102125

#include <iostream>
using namespace std;

// PROGRAM STACK DENGAN ARRAY
// Deklarasi Global
const int n = 5; //konstanta ukuran array
int stack[n];
int top = -1;

// Mengecek apakah tumpukan kosong
int isEmpty(){
    if (top == -1)
        return 1;
    else
        return 0;
}

// Mengecek apakah tumpukan penuh
int isFull(){ 
    if (top == n-1)
    return 1;
    else
    return 0;
}

// Insert Data (Push)
void push(int data){
    if (isEmpty() == 1){
        top++;
        stack[top] = data;
        cout << " Data " << data << " telah dimasukkan" << endl;
    }
    else if (isFull() == 0){
        top++;
        stack[top] = data;
        cout << " Data " << data << " telah dimasukkan" << endl;
    }
    else{
        cout << " Stack penuh!" << endl;
    }
}

// Hapus Data (Pop)
void pop(){
    if (isEmpty() == 0){
        top--;
        cout << " Data teratas terambil" << endl;
    }
    else{
        cout << " Stack masih kosong!" << endl;
    }
}

// Tampilkan Stack
void display(){
    if (isEmpty() == 0){
        for (int i = top; i>=0; i--){
            cout << " " << stack[i] << endl;
        }
    }
    else{
        cout << " Stack masih kosong!" << endl;
    }
}

// Hapus Stack
void clear(){
    top = -1;
    cout << " Stack berhasil dihapus" << endl;
}
int main(){
    int pilihan, nilai;
   
    // Menu
    do{
        system("cls");
        cout << "=== Menu ===" << endl;
        cout << " 1. Memasukkan data (Push)" << endl;
        cout << " 2. Menghapus data (Pop)" << endl;
        cout << " 3. Menampilkan data" << endl;
        cout << " 4. Hapus Stack" << endl;
        cout << " 5. Keluar" << endl;
        cout << " Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;
        
        if (pilihan==1){
            cout << " Masukkan data: ";
            cin >> nilai;
            push(nilai);
        }
        else if (pilihan==2){
            pop();
        }
        else if (pilihan==3){
            display();
        }
        else if (pilihan==4){
            clear();
        }
        else{
           return 0;
        }
        
        cout << endl;
        system("pause");
    }while (pilihan != 5);
    return 0;
}