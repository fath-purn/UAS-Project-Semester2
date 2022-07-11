#include <iostream>
//Innaka Neouerman Bard-21102019
using namespace std;

///PROGRAM BINARY TREE

//Deklarasi Pohon
struct Pohon{
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

//Inisialisasi
void init()
{
    root = NULL;
}

//Cek Node
int isEmpty()
{
    if (root == NULL)
        return 1;   //true
    else
        return 0;   //false
}

//Buat Node Baru
void buatNode(char data )
{
  if(isEmpty() == 1){
    root = new Pohon();
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
    cout << "\n Node " << data << " berhasil dibuat menjadi root." << endl;
  }
  else{
    cout << "\n Pohon sudah dibuat" << endl;
  }
}

//Tambah Kiri
Pohon *insertLeft(char data, Pohon *node )
{
  if(isEmpty() == 1){
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
  }else{
    // cek apakah child kiri ada atau tidak
    if( node->left != NULL ){
      // kalau ada
        cout << "\n Node "<< node->data << " sudah ada child kiri!" << endl;
        return NULL;
    }else{
        // kalau tidak ada
        baru = new Pohon();
        baru->data = data;
        baru->left = NULL;
        baru->right = NULL;
        baru->parent = node;
        node->left = baru;
        cout << "\n Node " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
        return baru;
    }
  }
}

//Tambah Kanan
Pohon *insertRight(char data, Pohon *node )
{
  if( root == NULL ){
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
  }else{
    // cek apakah child kanan ada atau tidak
    if( node->right != NULL ){
      // kalau ada
      cout << "\n Node " << node->data << " sudah ada child kanan!" << endl;
      return NULL;
    }else{
      // kalau tidak ada
      baru = new Pohon();
      baru->data = data;
      baru->left = NULL;
      baru->right = NULL;
      baru->parent = node;
      node->right = baru;
      cout << "\n Node " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
      return baru;
    }
  }
}

// Ubah Data Tree
void update(char data, Pohon *node)
{
  if(isEmpty() == 1){
    cout << "\n Buat tree terlebih dahulu!" << endl;
  }else{
    if( !node )
      cout << "\n Node yang ingin diganti tidak ada!!" << endl;
    else{
      char temp = node->data;
      node->data = data;
      cout << "\n Node " << temp << " berhasil diubah menjadi " << data << endl;
    }
  }
}

// Lihat Isi Data Tree
void retrieve( Pohon *node )
{
  if( !root ){
    cout << "\n Buat tree terlebih dahulu!" << endl;
  }else{
    if( !node )
      cout << "\n Node yang ditunjuk tidak ada!" << endl;
    else{
      cout << "\n Data node : " << node->data << endl;
    }
  }
}

// Cari Data Tree
void find(Pohon *node)
{
  if( !root ){
    cout << "\n Buat tree terlebih dahulu!" << endl;
  }else{
    if( !node )
      cout << "\n Node yang ditunjuk tidak ada!" << endl;
    else{
      cout << "\n Data Node : " << node->data << endl;
      cout << " Root : " << root->data << endl;

      if( !node->parent )
        cout << " Parent : (tidak punya parent)" << endl;
      else
        cout << " Parent : " << node->parent->data << endl;


      if( node->parent != NULL && node->parent->left != node && node->parent->right == node )

        cout << " Sibling : " << node->parent->left->data << endl;

      else if( node->parent != NULL && node->parent->right != node &&
      node->parent->left == node )

        cout << " Sibling : " << node->parent->right->data << endl;

      else

        cout << " Sibling : (tidak punya sibling)" << endl;


      if( !node->left )
        cout << " Child Kiri : (tidak punya Child kiri)" << endl;
      else
        cout << " Child Kiri : " << node->left->data << endl;

      if( !node->right )
        cout << " Child Kanan : (tidak punya Child kanan)" << endl;
      else
        cout << " Child Kanan : " << node->right->data << endl;
    }
  }
}

// Penelurusan (Traversal)
// preOrder
void preOrder(Pohon *node = root)
{
  if(!root)
    cout << "\n Buat tree terlebih dahulu!" << endl;
  else{

    if( node != NULL ){
      cout << " " << node->data << ", ";
      preOrder(node->left);
      preOrder(node->right);
    }
  }
}

// inOrder
void inOrder(Pohon *node = root)
{
  if(!root)
    cout << "\n Buat tree terlebih dahulu!" << endl;
  else{

    if(node != NULL){
      inOrder(node->left);
      cout << " " << node->data << ", ";
      inOrder(node->right);
    }
  }
}

// postOrder
void postOrder(Pohon *node = root)
{
  if(!root)
    cout << "\n Buat tree terlebih dahulu!" << endl;
  else{
    if( node != NULL ){
      postOrder(node->left);
      postOrder(node->right);
      cout << " " << node->data << ", ";
    }
  }
}

// Hapus Node Tree
void deleteTree(Pohon *node)
{
  if(!root)
    cout << "\n Buat tree terlebih dahulu!" << endl;
  else{
    if( node != NULL ){
      if( node != root ){
        node->parent->left = NULL;
        node->parent->right = NULL;
      }
      deleteTree(node->left);
      deleteTree(node->right);

      if( node == root ){
        delete root;
        root = NULL;
      }else{
        delete node;
      }
    }
  }
}

// Hapus SubTree
void deleteSub(Pohon *node){
  if( !root )
    cout << "\n Buat tree terlebih dahulu!" << endl;
  else{
    deleteTree(node->left);
    deleteTree(node->right);
    cout << "\n Node subtree " << node->data << " berhasil dihapus."  << endl;
  }
}

// Hapus Tree
void clear(){
  if( !root )
    cout << "\n Buat tree terlebih dahulu!!" << endl;
  else{
    deleteTree(root);
    cout << "\n Pohon berhasil dihapus."  << endl;
  }
}

// Cek Size Tree
int size(Pohon *node = root){
  if( !root ){
    cout << "\n Buat tree terlebih dahulu!!" << endl;
    return 0;
  }else{

    if( !node ){
      return 0;
    }else{
      return 1 + size( node->left ) + size(node->right);
    }

  }
}

// Cek Height Level Tree
int height( Pohon *node = root )
{
  if( !root ){
      cout << "\n Buat tree terlebih dahulu!" << endl;
      return 0;
    }else{
      if( !node ){
        return 0;
      }else{
        int heightKiri = height( node->left );
        int heightKanan = height( node->right );

        if( heightKiri >= heightKanan ){
          return heightKiri + 1;
        }else{
          return heightKanan + 1;
        }

      }
    }
}

// Karakteristik Tree
void charateristic()
{
  cout << "\n Size Tree : " << size() << endl;
  cout << " Height Tree : " << height() << endl;
  cout << " Average Node of Tree : " << size() / height() << endl;
}

void menu(){
    cout << "-------------------------" << endl;
    cout << "| Innaka Neouerman Bard |" << endl;
    cout << "|        21102019       |" << endl;
    cout << "-------------------------" << endl;
    cout << "1. Buat root" << endl;
    cout << "2. Buat node child" << endl;
    cout << "3. Ubah node" << endl;
    cout << "4. Lihat isi tree" << endl;
    cout << "5. Cari data tree" << endl;
    cout << "6. karakteristik tree" << endl;
    cout << "7. Hapus SubTree" << endl;
    cout << "8. Hapus Tree" << endl;
    cout << "9. exit" << endl;

}

int main()
{

    Pohon *node2, *node3, *node4, *node5, *node6, *node7, *node8, *node9, *node10;
    char data, kiri1, kiri2, kiri3, kiri4, kiri5, kanan1, kanan2, kanan3, kanan4;
    char ubah;
    int pilihUbah;
    int pilih, cari, pilihSub;

main:
    menu();
    cout << "Pilih Menu : "; cin >> pilih;
    switch(pilih){
    case 1:
        cout << "Masukan Data root (Karakter) : "; cin >> data;
        buatNode(data);
        system("pause");
        system("cls");
        goto main;
        break;

    case 2:
        cout << "Membuat node child (karakter)" << endl;

        cout << "Masukan child kiri " << data << " : " ; cin >> kiri1;
        node2 = insertLeft(kiri1, root);
        cout << "Masukan child kanan " << data << " : "; cin >> kanan1;
        node3 = insertRight(kanan1, root);
        cout << "Masukan child kiri " << node2->data << " : "; cin >> kiri2;
        node4 = insertLeft(kiri2, node2);
        cout << "Masukan child kanan " << node2->data << " : "; cin >> kanan2;
        node5 = insertRight(kanan2, node2);
        cout << "Masukan child kiri " << node3->data << " : "; cin >> kiri3;
        node6 = insertLeft(kiri3, node3);
        cout << "masukan child kiri " << node5->data << " : "; cin >> kiri4;
        node7 = insertLeft(kiri4, node5);
        cout << "Masukan child kanan " << node5->data << " : "; cin >> kanan3;
        node8 = insertRight(kanan3, node5);
        cout << "masukan child kiri " << node7->data << " : "; cin >> kiri5;
        node9 = insertLeft(kiri5, node7);
        cout << "Masukan child kanan " << node7->data << " : "; cin >> kanan4;
        node10 = insertRight(kanan4, node7);
        system("pause");
        system("cls");
        goto main;

    case 3:

        update:

          cout << "Mengubah node" << endl;
          cout << "1. Ubah node " << root->data << endl;
          cout << "2. Ubah node " << node2->data << endl;
          cout << "3. Ubah node " << node3->data << endl;
          cout << "4. Ubah node " << node4->data << endl;
          cout << "5. Ubah node " << node5->data << endl;
          cout << "6. Ubah node " << node6->data << endl;
          cout << "7. Ubah node " << node7->data << endl;
          cout << "8. Ubah node " << node8->data << endl;
          cout << "9. Ubah node " << node9->data << endl;
          cout << "10. Ubah node " << node10->data << endl;
          cout << "11. <- Back " << endl;
          cout << "Masukan pilihan : "; cin >> pilihUbah;
          if(pilihUbah == 1){
            cout << "Masukan node baru : "; cin >> ubah;
            update(ubah, root);
            system("pause");
            system("cls");
            goto update;
          }
          else if(pilihUbah == 2) {
            cout << "Masukan node baru : "; cin >> ubah;
            update(ubah, node2);
            system("pause");
            system("cls");
            goto update;
          }
          else if(pilihUbah == 3) {
            cout << "Masukan node baru : "; cin >> ubah;
            update(ubah, node3);
            system("pause");
            system("cls");
            goto update;
          }
          else if(pilihUbah == 4) {
            cout << "Masukan node baru : "; cin >> ubah;
            update(ubah, node4);
            system("pause");
            system("cls");
            goto update;
          }
          else if(pilihUbah == 5) {
            cout << "Masukan node baru : "; cin >> ubah;
            update(ubah, node5);
            system("pause");
            system("cls");
            goto update;
          }
          else if(pilihUbah == 6) {
            cout << "Masukan node baru : "; cin >> ubah;
            update(ubah, node6);
            system("pause");
            system("cls");
            goto update;
          }
          else if(pilihUbah == 7) {
            cout << "Masukan node baru : "; cin >> ubah;
            update(ubah, node7);
            system("pause");
            system("cls");
            goto update;
          }
          else if(pilihUbah == 8) {
            cout << "Masukan node baru : "; cin >> ubah;
            update(ubah, node8);
            system("pause");
            system("cls");
            goto update;
          }
          else if(pilihUbah == 9) {
            cout << "Masukan node baru : "; cin >> ubah;
            update(ubah, node9);
            system("pause");
            system("cls");
            goto update;
          }
          else if(pilihUbah == 10) {
            cout << "Masukan node baru : "; cin >> ubah;
            update(ubah, node10);
            system("pause");
            system("cls");
            goto main;
          }
           else if(pilihUbah == 11) {
            system("pause");
            system("cls");
            goto main;
          }
            else{
                cout << "Pilihan tidak tersedia!!" << endl;
            }

        system("pause");
        system("cls");
        goto main;
        break;
    case 4:
        cout << "Lihat Isi Tree" << endl;
        cout << "1. " << root->data << endl;
        cout << "2. " << node2->data << endl;
        cout << "3. " << node3->data << endl;
        cout << "4. " << node4->data << endl;
        cout << "5. " << node5->data << endl;
        cout << "6. " << node6->data << endl;
        cout << "7. " << node7->data << endl;
        cout << "8. " << node8->data << endl;
        cout << "9. " << node9->data << endl;
        cout << "10. " << node10->data << endl;
        if(data == NULL){
            cout << "Data kosong" << endl;
        }
        system("pause");
        system("cls");
        goto main;
        break;
    case 5:
        cout << "Cari data Tree" << endl;
        cout << "1. " << root->data << endl;
        cout << "2. " << node2->data << endl;
        cout << "3. " << node3->data << endl;
        cout << "4. " << node4->data << endl;
        cout << "5. " << node5->data << endl;
        cout << "6. " << node6->data << endl;
        cout << "7. " << node7->data << endl;
        cout << "8. " << node8->data << endl;
        cout << "9. " << node9->data << endl;
        cout << "10. " << node10->data << endl;
        cout << "pilih : "; cin >> cari;
        if(pilihUbah == 1){
            find(root);
            cout << "\n PreOrder :" << endl;
            preOrder(root);
            cout << "\n" << endl;
            cout << " InOrder :" << endl;
            inOrder(root);
            cout << "\n" << endl;
            cout << " PostOrder :" << endl;
            postOrder(root);
            cout << "\n" << endl;
            system("pause");
            system("cls");
            goto update;
          }
          else if(pilihUbah == 2) {
            find(node2);
            cout << "\n PreOrder :" << endl;
            preOrder(node2);
            cout << "\n" << endl;
            cout << " InOrder :" << endl;
            inOrder(node2);
            cout << "\n" << endl;
            cout << " PostOrder :" << endl;
            postOrder(node2);
            cout << "\n" << endl;
            system("pause");
            system("cls");
            goto update;
          }
          else if(pilihUbah == 3) {
            find(node3);
            cout << "\n PreOrder :" << endl;
            preOrder(node3);
            cout << "\n" << endl;
            cout << " InOrder :" << endl;
            inOrder(node3);
            cout << "\n" << endl;
            cout << " PostOrder :" << endl;
            postOrder(node3);
            cout << "\n" << endl;
            system("pause");
            system("cls");
            goto update;
          }
          else if(pilihUbah == 4) {
            find(node4);
            cout << "\n PreOrder :" << endl;
            preOrder(node4);
            cout << "\n" << endl;
            cout << " InOrder :" << endl;
            inOrder(node4);
            cout << "\n" << endl;
            cout << " PostOrder :" << endl;
            postOrder(node4);
            cout << "\n" << endl;
            system("pause");
            system("cls");
            goto update;
          }
          else if(pilihUbah == 5) {
            find(node5);
            cout << "\n PreOrder :" << endl;
            preOrder(node5);
            cout << "\n" << endl;
            cout << " InOrder :" << endl;
            inOrder(node5);
            cout << "\n" << endl;
            cout << " PostOrder :" << endl;
            postOrder(node5);
            cout << "\n" << endl;
            system("pause");
            system("cls");
            goto update;
          }
          else if(pilihUbah == 6) {
            find(node6);
            cout << "\n PreOrder :" << endl;
            preOrder(node6);
            cout << "\n" << endl;
            cout << " InOrder :" << endl;
            inOrder(node6);
            cout << "\n" << endl;
            cout << " PostOrder :" << endl;
            postOrder(node6);
            cout << "\n" << endl;
            system("pause");
            system("cls");
            goto update;
          }
          else if(pilihUbah == 7) {
            find(node7);
            cout << "\n PreOrder :" << endl;
            preOrder(node7);
            cout << "\n" << endl;
            cout << " InOrder :" << endl;
            inOrder(node7);
            cout << "\n" << endl;
            cout << " PostOrder :" << endl;
            postOrder(node7);
            cout << "\n" << endl;
            system("pause");
            system("cls");
            goto update;
          }
          else if(pilihUbah == 8) {
           find(node8);
           cout << "\n PreOrder :" << endl;
            preOrder(node8);
            cout << "\n" << endl;
            cout << " InOrder :" << endl;
            inOrder(node8);
            cout << "\n" << endl;
            cout << " PostOrder :" << endl;
            postOrder(node8);
            cout << "\n" << endl;
            system("pause");
            system("cls");
            goto update;
          }
          else if(pilihUbah == 9) {
            find(node9);
            cout << "\n PreOrder :" << endl;
            preOrder(node9);
            cout << "\n" << endl;
            cout << " InOrder :" << endl;
            inOrder(node9);
            cout << "\n" << endl;
            cout << " PostOrder :" << endl;
            postOrder(node9);
            cout << "\n" << endl;
            system("pause");
            system("cls");
            goto update;
          }
          else if(pilihUbah == 10) {
            find(node10);
            cout << "\n PreOrder :" << endl;
            preOrder(node10);
            cout << "\n" << endl;
            cout << " InOrder :" << endl;
            inOrder(node10);
            cout << "\n" << endl;
            cout << " PostOrder :" << endl;
            postOrder(node10);
            cout << "\n" << endl;
            system("pause");
            system("cls");
            goto main;
          }
            else{
                cout << "Pilihan tidak tersedia!!" << endl;
            }
          break;
    case 6:
        cout << "Karakteristik" << endl;
        charateristic();
        system("pause");
        system("cls");
        goto main;
        break;
    case 7:
        cout << "Menghapus Subtree" << endl;
        cout << "1. " << root->data << endl;
        cout << "2. " << node2->data << endl;
        cout << "3. " << node3->data << endl;
        cout << "4. " << node4->data << endl;
        cout << "5. " << node5->data << endl;
        cout << "6. " << node6->data << endl;
        cout << "7. " << node7->data << endl;
        cout << "8. " << node8->data << endl;
        cout << "9. " << node9->data << endl;
        cout << "10. " << node10->data << endl;
        cout << "pilih : "; cin >> pilihSub;
        if(pilihSub == 1){

            deleteSub(root);
            cout << "\n PreOrder :" << endl;
            preOrder();
            cout << "\n" << endl;
            system("pause");
            system("cls");
            goto main;
        }
        else if(pilihSub == 2){
            deleteSub(node2);
            cout << "\n PreOrder :" << endl;
            preOrder();
            cout << "\n" << endl;
            system("pause");
            system("cls");
            goto main;
        }
        else if(pilihSub == 3){
            deleteSub(node3);
            cout << "\n PreOrder :" << endl;
            preOrder();
            cout << "\n" << endl;
            system("pause");
            system("cls");
            goto main;
        }
        else if(pilihSub == 4){
            deleteSub(node4);
            cout << "\n PreOrder :" << endl;
            preOrder();
            cout << "\n" << endl;
            system("pause");
            system("cls");
            goto main;
        }
        else if(pilihSub == 5){
            deleteSub(node5);
            cout << "\n PreOrder :" << endl;
            preOrder();
            cout << "\n" << endl;
            system("pause");
            system("cls");
            goto main;
        }
        else if(pilihSub == 6){
            deleteSub(node2);
            cout << "\n PreOrder :" << endl;
            preOrder();
            cout << "\n" << endl;
            system("pause");
            system("cls");
            goto main;
        }
        else if(pilihSub == 7){
            deleteSub(node7);
            cout << "\n PreOrder :" << endl;
            preOrder();
            cout << "\n" << endl;
            system("pause");
            system("cls");
            goto main;
        }
        else if(pilihSub == 8){
            deleteSub(node8);
            cout << "\n PreOrder :" << endl;
            preOrder();
            cout << "\n" << endl;
            system("pause");
            system("cls");
            goto main;
        }
        else if(pilihSub == 9){
            deleteSub(node9);
            cout << "\n PreOrder :" << endl;
            preOrder();
            cout << "\n" << endl;
            system("pause");
            system("cls");
            goto main;
        }
        else if(pilihSub == 10){
            deleteSub(node10);
            cout << "\n PreOrder :" << endl;
            preOrder();
            cout << "\n" << endl;
            system("pause");
            system("cls");
            goto main;
        }
        else{
            cout << "Pilihan tidak tersedia!! " << endl;
        }

        break;

    case 8:
        cout << "Hapus" << endl;
        clear();
        system("pause");
        system("cls");
        goto main;

        break;
    case 9:
        system("pause");
        system("cls");
        break;
    default :
        cout << "pilihan tidak tersedia, silahkan pilih ulang :)" << endl;
        goto main;

    }
}

