#include <iostream>
#define MAX 100
using namespace std;

struct Pohon
{
    // int alamat;  
    char data; 
    char posisi[100];
    Pohon *left, *right, *parent;
};           
Pohon *root; 
Pohon *baru; 



// inisialisasi
void init()
{
    root = NULL;
}

// cek Node
int isEmpty()
{
    if (root == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru
void buatNode(char data)
{
    if (isEmpty() == 1)
    {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\n Pohon sudah dibuat" << endl;
    }
}

// Tambah Kiri
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat root terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        // cek apakah child kiri ada atau tidak
        if (node->left != NULL)
        {
            // kalau ada
            cout << "\n Node " << node << " sudah ada child kiri!" << endl;
            return NULL;
        }
        else
        {
            // kalau tidak
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\n Node " << data << " berhasil ditambahkan sebagai child kiri dari " << baru->parent->data << endl;
            return baru;
        }
    }
}
// Tambah Kanan
Pohon *insertRight(char data, Pohon *node)
{
    if (root == NULL)
    {
        cout << "\n Buat root terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        // cek apakah child kanan ada atau tidak
        if (node->right != NULL)
        {
            // kalau ada
            cout << "\n Node " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        }
        else
        {
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

// ubah data tree
void update(char data, Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat root terlebih dahulu!" << endl;
    }
    else
    {
        node->data = data;
        cout << "\n Data " << data << " berhasil diubah menjadi " << node->data << endl;
    }
}

// lihat isi data Tree
void retrieve(Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat root terlebih dahulu!" << endl;
    }
    else
    {
        cout << "\n Isi data tree : " << endl;
        cout << " Root : " << root->data << endl;
        cout << " Left : ";
        if (root->left == NULL)
        {
            cout << "NULL" << endl;
        }
        else
        {
            cout << root->left->data << endl;
        }
        cout << " Right : ";
        if (root->right == NULL)
        {
            cout << "NULL" << endl;
        }
        else
        {
            cout << root->right->data << endl;
        }
    }
}

// cari data tree
void find(char data, Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat root terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Data " << data << " tidak ditemukan!" << endl;
        }
        else
        {
            // parent
            if (!node->parent)
            {
                cout << "\n Parent : " << data << " tidak ditemukan" << endl;
            }
            else
            {
                cout << " Parent : " << node->parent->data << endl;
            }

            // sibling
            if (!node->parent)
            {
                cout << " Sibling : " << data << " tidak ditemukan" << endl;
            }
            else
            {
                if (node->parent->left == node)
                {
                    cout << " Sibling : " << node->parent->right->data << endl;
                }
                else
                {
                    cout << " Sibling : " << node->parent->left->data << endl;
                }
            }

            // child kiri
            if (!node->left)
            {
                cout << " Child kiri : " << data << " tidak ditemukan" << endl;
            }
            else
            {
                cout << " Child kiri : " << node->left->data << endl;
            }

            // child kanan
            if (!node->right)
            {
                cout << " Child kanan : " << data << " tidak ditemukan" << endl;
            }
            else
            {
                cout << " Child kanan : " << node->right->data << endl;
            }
        }
    }
}

// Traversal
// PreOrder
void preOrder(Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat root terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// InOrder
void inOrder(Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat root terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }
}

// PostOrder
void postOrder(Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat root terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data << " ";
        }
    }
}

// hapus sub tree
void deleteSub(Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat Tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node->left == NULL && node->right == NULL)
        {
            // jika node tidak memiliki anak
            if (node->parent->left == node)
            {
                node->parent->left = NULL;
            }
            else
            {
                node->parent->right = NULL;
            }
            delete node;
        }
        else if (node->left != NULL && node->right == NULL)
        {
            // jika node memiliki anak kiri
            if (node->parent->left == node)
            {
                node->parent->left = node->left;
            }
            else
            {
                node->parent->right = node->left;
            }
            delete node;
        }
        else if (node->left == NULL && node->right != NULL)
        {
            // jika node memiliki anak kanan
            if (node->parent->left == node)
            {
                node->parent->left = node->right;
            }
            else
            {
                node->parent->right = node->right;
            }
            delete node;
        }
        else
        {
            // jika node memiliki anak kiri dan anak kanan
            Pohon *temp = node->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            temp->left = node->left;
            if (node->parent->left == node)
            {
                node->parent->left = node->right;
            }
            else
            {
                node->parent->right = node->right;
            }
            delete node;
        }
    }
}

// hapus tree
void deleteTree(Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat Tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node->left != NULL)
        {
            deleteTree(node->left);
        }
        if (node->right != NULL)
        {
            deleteTree(node->right);
        }
        delete node;
    }
}

// cek size tree
int size(Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat Tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (node == NULL)
        {
            return 0;
        }
        else
        {
            return (size(node->left) + 1 + size(node->right));
        }
    }
}

// cek Height level tree
int height(Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat Tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (node == NULL)
        {
            return 0;
        }
        else
        {
            int leftHeight = height(node->left);
            int rightHeight = height(node->right);
            if (leftHeight > rightHeight)
            {
                return (leftHeight + 1);
            }
            else
            {
                return (rightHeight + 1);
            }
        }
    }
}

// cek leaf tree
int leaf(Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat Tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (node == NULL)
        {
            return 0;
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                return 1;
            }
            else
            {
                return (leaf(node->left) + leaf(node->right));
            }
        }
    }
}

// cek full tree
int full(Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat Tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (node == NULL)
        {
            return 0;
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                return 0;
            }
            else
            {
                if (node->left != NULL && node->right != NULL)
                {
                    return (full(node->left) + full(node->right));
                }
                else
                {
                    return 0;
                }
            }
        }
    }
}

// karakteristik tree
void charateristic()
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat Tree terlebih dahulu!" << endl;
    }
    else
    {
        cout << "\n Karakteristik Tree : " << endl;
        cout << " Jumlah node : " << size(root) << endl;
        cout << " Tinggi tree : " << height(root) << endl;
        cout << " Jumlah leaf : " << leaf(root) << endl;
        cout << " Average Node of tree : " << (size(root) / (height(root) + 1)) << endl;
    }
}

// menu tambah node kanan kiri
void addNode(Pohon *node, char posisi)
{
    // deklarasi node
    Pohon *iniNode = new Pohon;
    Pohon *newNode = new Pohon;
    // Pohon *oldNode;
    int i = height(root)+10;
    Pohon c[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,21,19,20};
    *iniNode = c[i];

    // Pohon *oldNode = (pData[i]);

    // Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;

    // nodeB = insertLeft('B', root);
    // nodeC = insertRight('C', root);
    // nodeD = insertLeft('D', nodeB);
    // nodeE = insertRight('E', nodeB);
    // nodeF = insertLeft('F', nodeC);
    // nodeG = insertLeft('G', nodeE);
    // nodeH = insertRight('H', nodeE);
    // nodeI = insertLeft('I', nodeG);
    // nodeJ = insertRight('J', nodeG);

    // char data;

    int pilih;
    // char sementara;

    do
    {
        // input karakteristik
        cout << " Input Karakteristik : " << endl;
        cout << " 1. Karakteristik node kiri" << endl;
        cout << " 2. Karakteristik node kanan" << endl;
        cout << " 3. keluar" << endl;
        cout << " Pilih Karakteristik : ";
        cin >> pilih;
        cout << endl;

        // input karakteristik node kiri
        if (pilih == 1)
        {

            cout << "Input data : ";
            cin >> newNode->data;
            cout << " Testing" << endl;

            int i = height(root)+1;
            // iniNode = *pData+1;

            cout << endl << "------------------" << i << endl;

            insertLeft(newNode->data, iniNode);

            cout << endl << iniNode << "----------------  " << newNode->data << "  ------------------" << i << endl;

            cout << " Data berhasil ditambahkan!" << endl;
        }

        // input karakteristik node kanan
        else if (pilih == 2)
        {
            cout << "Input data : ";
            cin >> newNode->data;
            cout << endl;
            // cout << " Input Karakteristik node kanan : ";
            // cin >> newNode->right->data;
            insertRight(newNode->data, newNode->right);

            cout << " Testing" << endl;
        }
        else
        {
            cout << " Input Salah!" << endl;
        }
    } while (pilih != 3);
}

int main()
{
    char data[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    char *pData = data;
    char isi;
    int pil, iniNode, i;
    Pohon *alamat;

    do
    {
        cout << "\n Menu : " << endl;
        cout << " 1. Buat Tree" << endl;
        cout << " 2. Tambah Node" << endl;
        cout << " 3. Tampilkan Tree" << endl;
        cout << " 4. Tampilkan PreOrder" << endl;
        cout << " 5. Tampilkan InOrder" << endl;
        cout << " 6. Tampilkan PostOrder" << endl;
        cout << " 7. Hapus Sub Tree" << endl;
        cout << " 8. Hapus Tree" << endl;
        cout << " 9. Size Tree" << endl;
        cout << " 10. Height Tree" << endl;
        cout << " 11. Karakteristik Tree" << endl;
        cout << " 12. Leaf Tree" << endl;
        cout << " 13. Full Tree" << endl;
        cout << " 14. Keluar" << endl;
        cout << " Pilih : ";
        cin >> pil;
        switch (pil)
        {
        case 1:
            cout << " Masukkan data root: ";
            cin >> isi;
            buatNode(isi);
            break;
        case 2:
            i = height(root)+1;
            iniNode = *(pData + i);
            addNode(root, iniNode);
            break;
        case 3:
            retrieve(root);
            break;
        case 4:
            preOrder(root);
            break;
        case 5:
            inOrder(root);
            break;
        case 6:
            postOrder(root);
            break;
        case 7:
            deleteSub(root);
            break;
        case 8:
            deleteTree(root);
            break;
        case 9:
            cout << " Jumlah node : " << size(root) << endl;
            break;
        case 10:
            cout << " Tinggi tree : " << height(root) << endl;
            break;
        case 11:
            charateristic();
            break;
        case 12:
            cout << " Jumlah leaf : " << leaf(root) << endl;
            break;
        case 13:
            cout << " Jumlah full : " << full(root) << endl;
            break;
        default:
            cout << " Pilihan tidak ada!" << endl;
            break;
        }
    } while (pil != 13);
}