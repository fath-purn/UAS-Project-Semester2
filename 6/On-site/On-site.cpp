#include <iostream>
using namespace std;

///PROGRAM STACK DENGAN ARRAY
// Deklarasi Global
const int n = 5; //konstanta ukuran array
char stack[n];
int top = -1;

int isEmpty(){ //mengecek apakah tumpukan kosong
    if (top == -1)
    return 1;
    else
    return 0;
}

int isFull(){ //mengecek apakah tumpukan penuh
    if (top == n-1)
    return 1;
    else
    return 0;
}

//Insert Data (Push)
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

//Hapus Data (Pop)
void pop(){
    if (isEmpty() == 0){
        top--;
        cout << " Data teratas terambil" << endl;
    }
    else{
        cout << " Stack masih kosong!" << endl;
    }
}

//Tampilkan Stack
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

// tampilkan stack dari yang pertama di input
void displayFromTop(){
    if (isEmpty() == 0){
        for (int i = 0; i<=top; i++){
            cout << " " << stack[i] << endl;
        }
    }
    else{
        cout << " Stack masih kosong!" << endl;
    }
}

//Hapus Stack
void clear(){
    top = -1;
    cout << " Stack berhasil dihapus" << endl;
}
int main(){
    int pilihan;
    char nilai;
   
    do{
        system("cls");
        cout << "=== Menu ===" << endl;
        cout << " 1. Memasukkan data (Push)" << endl;
        cout << " 2. Menghapus data (Pop)" << endl;
        cout << " 3. Menampilkan data dari bawah" << endl;
        cout << " 4. Menampilkan data dari atas" << endl;
        cout << " 5. Hapus Stack" << endl;
        cout << " 6. Keluar" << endl;
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
            displayFromTop();
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
    }while (pilihan != 5);
    return 0;
}