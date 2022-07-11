#include <iostream>
#define MAX (10)
using namespace std;

// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon
{
    char data;
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

int isFull()
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
            cout << "\n Node " << node->data << " sudah ada child kiri!" << endl;
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
            node->left = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
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

// Ubah Data Tree
void update(char data, Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\n Node yang ingin diganti tidak ada!!" << endl;
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\n Node " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

// Lihat Isi Data Tree
void retrieve(Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\n Data node : " << node->data << endl;
        }
    }
}

// Cari Data Tree
void find(Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\n Data Node : " << node->data << endl;
            cout << " Root : " << root->data << endl;
            if (!node->parent)
                cout << " Parent : (tidak punya parent)" << endl;
            else
                cout << " Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << " Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node &&
                     node->parent->left == node)
                cout << " Sibling : " << node->parent->right->data << endl;
            else
                cout << " Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left->data << endl;
            if (!node->right)
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
    if (isEmpty() == 1)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node = root)
{
    if (isEmpty() == 1)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node = root)
{
    if (isEmpty() == 1)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (isEmpty() == 1)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (isEmpty() == 1)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\n Node subtree " << node->data << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear()
{
    if (isEmpty() == 1)
        cout << "\n Buat tree terlebih dahulu!!" << endl;
    else
    {
        deleteTree(root);
        cout << "\n Pohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node = root)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node = root)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
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

int isExist(Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + isExist(node->left) + isExist(node->right);
        }
    }
}

int findNode(Pohon *node, char data)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            if (node->data == data)
            {
                return 1;
            }
            else
            {
                return findNode(node->left, data) + findNode(node->right, data);
            }
        }
    }
}

void tambahNode()
{
    // deklarasi variabel
    char data;
    int pil;
    Pohon *node;
    Pohon *parent;
    Pohon *sibling;
    Pohon *child;

    // menu input kanan input kiri
    cout << "\n Input data node : ";
    cin >> data;

    // cek apakah data sudah ada atau belum
    if (findNode(root, data) == 1)
    {
        cout << "\n Data sudah ada!" << endl;
    }
    else
    {
        // menu input parent
        cout << "\n Input data parent : ";
        cin >> data;
        parent = findNode(root, data);
        if (parent == NULL)
        {
            cout << "\n Data parent tidak ditemukan!" << endl;
        }
        else
        {
            // menu input kanan atau kiri
            cout << "\n Input kanan atau kiri (1. kanan, 2. kiri) : ";
            cin >> pil;
            if (pil == 1)
            {
                // menu input kanan
                cout << "\n Input data kanan : ";
                cin >> data;
                sibling = findNode(root, data);
                if (sibling == NULL)
                {
                    cout << "\n Data kanan tidak ditemukan!" << endl;
                }
                else
                {
                    // menu input child
                    cout << "\n Input data child : ";
                    cin >> data;
                    child = findNode(root, data);
                    if (child == NULL)
                    {
                        cout << "\n Data child tidak ditemukan!" << endl;
                    }
                    else
                    {
                        // tambah node
                        node = new Pohon;
                        node->data = data;
                        node->parent = parent;
                        node->left = child;
                        node->right = sibling;
                        child->parent = node;
                        sibling->parent = node;
                        cout << "\n Node berhasil ditambahkan." << endl;
                    }
                }
            }
            else if (pil == 2)
            {
                // menu input kiri
                cout << "\n Input data kiri : ";
                cin >> data;
                sibling = findNode(root, data);
                if (sibling == NULL)
                {
                    cout << "\n Data kiri tidak ditemukan!" << endl;
                }
                else
                {
                    // menu input child
                    cout << "\n Input data child : ";
                    cin >> data;
                    child = findNode(root, data);
                    if (child == NULL)
                    {
                        cout << "\n Data child tidak ditemukan!" << endl;
                    }
                    else
                    {
                        // tambah node
                        node = new Pohon;
                        node->data = data;
                        node->parent = parent;
                        node->left = sibling;
                        node->right = child;
                        sibling->parent = node;
                        child->parent = node;
                        cout << "\n Node berhasil ditambahkan." << endl;
                    }
                }
            }
        }
    }

}

int main()
{
    int menu;
    char isi;

    // menu
    do
    {
        cout << "\n\n\n";
        cout << " ============================================================" << endl;
        cout << " |                                                          |" << endl;
        cout << " |                         Tree                             |" << endl;
        cout << " |                                                          |" << endl;
        cout << " ============================================================" << endl;
        cout << " Pilih menu:" << endl;
        cout << " 1. Buat Tree" << endl;
        cout << " 2. Tambah Node" << endl;
        cout << " 3. Tampilkan Tree" << endl;
        cout << " 4. Penelurusan (PreOrder)" << endl;
        cout << " 5. Penelurusan (InOrder)" << endl;
        cout << " 6. Penelurusan (PostOrder)" << endl;
        cout << " 7. Hapus Node" << endl;
        cout << " 8. Hapus SubTree" << endl;
        cout << " 9. Hapus Tree" << endl;
        cout << " 10. Cek Size Tree" << endl;
        cout << " 11. Cek Height Level Tree" << endl;
        cout << " 12. Karakteristik Tree" << endl;
        cout << " 13. Keluar" << endl;
        cout << " Pilih menu: ";
        cin >> menu;

        // switch case
        switch (menu)
        {
        case 1:
            cout << " Masukkan data root: ";
            cin >> isi;
            buatNode(isi);
            break;
        case 2:
            tambahNode();
            break;
        case 3:
            charateristic();
            break;
        case 4:
            preOrder();
            break;
        case 5:
            inOrder();
            break;
        case 6:
            postOrder();
            break;
        case 7:
            clear();
            break;
        case 8:
            // deleteSubTree();
            break;
        case 9:
            clear();
            break;
        case 10:
            cout << "\n Size Tree : " << size() << endl;
            break;
        case 11:
            cout << "\n Height Tree : " << height() << endl;
            break;
        case 12:
            charateristic();
            break;
        case 13:
            cout << "\n Terima kasih telah menggunakan program ini." << endl;
            break;
        default:
            cout << "\n Pilihan tidak ada!" << endl;
            break;
        }
    } while (menu != 13);

    return 0;

}