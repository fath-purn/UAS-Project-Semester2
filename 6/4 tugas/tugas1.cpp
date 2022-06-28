// Nama : Fatkhurrohman Purnomo
// NIM : 21102125

#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

// stack
class Stack { 
    public: 
    int top; 
    unsigned cap; 
    char* arr; 
};

// inisilasi stack
Stack* createst(unsigned cap) { 
    Stack* st = new Stack(); 
    st->cap = cap; 
    st->top = -1; 
    st->arr = new char[(st->cap * sizeof(char))]; 
    return st; 
}

// cek apakah stack kosong
int isEmpty(Stack* st) 
{ return st->top == -1; }

// cek apakah stack penuh
int isFull(Stack* st) 
{ return st->top == st->cap - 1; }

// push
void push(Stack* st, char character) 
{ 
    if (isFull(st)) 
        return; 
    st->arr[++st->top] = character; 
}

// pop
char pop(Stack* st) { 
    if (isEmpty(st)) 
        return -1; 
    return st->arr[st->top--]; 
}

// reverse stack
void reversestring(char string[]) 
{ 
    // Membuat stack
    int strsm = strlen(string); 
    Stack* st = createst(strsm); 

    // Melakukan push
    for (int i = 0; i < strsm; i++) 
        push(st, string[i]); 

    // Melakukan pop
    for (int i = 0; i < strsm; i++) 
        cout << pop(st); 
}

int main(){
    char kalimat[100];
    cout << " Masukkan kalimat: ";
    cin.getline(kalimat, sizeof(kalimat));
    int panjang = strlen(kalimat);

    cout << " Hasil setelah dibalik: ";
    reversestring(kalimat);

    return 0;
}
