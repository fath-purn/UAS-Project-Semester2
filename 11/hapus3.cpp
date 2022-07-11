#include <iostream>
#define MAX 100
using namespace std;

// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon
{
    char data[MAX];
    Pohon *left, *right, *parent;
};
Pohon *root, *baru;

// Inisialisasi
void init()
{
    root = NULL;
}

// Cek Node
int isEmpty()
{
    if (root == NULL)
        return 1; // true
    else
        return 0; // false
}

// abut Node Baru

// Tambah kiri

// Tambah kanan

// Ubah data Tree

// Lihat Isi Data Tree

// Cari Data Tree

// Penelusuran (Traversal)
// preOrder Tree

// inOrder Data Tree

// postOrder Data Tree

// Hapus Node TREE

// Hapus subTree TREE

// Hapus Tree

// Cek Size Tree

// Cek Height Level Tree

// Karakteristik Tree

