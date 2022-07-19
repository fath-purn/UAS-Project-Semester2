#include <iostream>
using namespace std;

// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon
{
    string data_21102125;
    Pohon *left_21102125, *right_21102125, *parent_21102125;
};
Pohon *root_21102125, *baru_21102125;

// Inisialisasi
void init()
{
    root_21102125 = NULL;
}

// Cek Node
int isEmpty()
{
    if (root_21102125 == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node baru_21102125
void buatNode(string data_21102125)
{
    if (isEmpty() == 1)
    {
        root_21102125 = new Pohon();
        root_21102125->data_21102125 = data_21102125;
        root_21102125->left_21102125 = NULL;
        root_21102125->right_21102125 = NULL;
        root_21102125->parent_21102125 = NULL;
        cout << "\n Node " << data_21102125 << " berhasil dibuat menjadi root_21102125." << endl;
    }
    else
    {
        cout << "\n Pohon sudah dibuat" << endl;
    }
}

// Tambah Kiri
Pohon *insertleft_21102125(string data_21102125, Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat root_21102125 terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        // cek apakah child kiri ada atau tidak
        if (node->left_21102125 != NULL)
        {
            // kalau ada
            cout << "\n Node " << node->data_21102125 << " sudah ada child kiri!" << endl;
            return NULL;
        }
        else
        {
            // kalau tidak ada
            baru_21102125 = new Pohon();
            baru_21102125->data_21102125 = data_21102125;
            baru_21102125->left_21102125 = NULL;
            baru_21102125->right_21102125 = NULL;
            baru_21102125->parent_21102125 = node;
            node->left_21102125 = baru_21102125;
            cout << "\n Node " << data_21102125 << " berhasil ditambahkan ke child kiri " << baru_21102125->parent_21102125->data_21102125 << endl;
            return baru_21102125;
        }
    }
}

// Tambah Kanan
Pohon *insertright_21102125(string data_21102125, Pohon *node)
{
    if (root_21102125 == NULL)
    {
        cout << "\n Buat root_21102125 terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        // cek apakah child kanan ada atau tidak
        if (node->right_21102125 != NULL)
        {
            // kalau ada
            cout << "\n Node " << node->data_21102125 << " sudah ada child kanan!" << endl;
            return NULL;
        }
        else
        {
            // kalau tidak ada
            baru_21102125 = new Pohon();
            baru_21102125->data_21102125 = data_21102125;
            baru_21102125->left_21102125 = NULL;
            baru_21102125->right_21102125 = NULL;
            baru_21102125->parent_21102125 = node;
            node->right_21102125 = baru_21102125;
            cout << "\n Node " << data_21102125 << " berhasil ditambahkan ke child kanan " << baru_21102125->parent_21102125->data_21102125 << endl;
            return baru_21102125;
        }
    }
}

// Ubah data_21102125 Tree
void update(string data_21102125, Pohon *node)
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
            string temp = node->data_21102125;
            node->data_21102125 = data_21102125;
            cout << "\n Node " << temp << " berhasil diubah menjadi " << data_21102125 << endl;
        }
    }
}

// Lihat Isi data_21102125 Tree
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
            cout << "\n data_21102125 node : " << node->data_21102125 << endl;
        }
    }
}

// Cari data_21102125 Tree
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
            cout << "\n data_21102125 Node : " << node->data_21102125 << endl;
            cout << " root_21102125 : " << root_21102125->data_21102125 << endl;

            if (!node->parent_21102125)
                cout << " parent_21102125 : (tidak punya parent_21102125)" << endl;
            else
                cout << " parent_21102125 : " << node->parent_21102125->data_21102125 << endl;

            if (node->parent_21102125 != NULL && node->parent_21102125->left_21102125 != node && node->parent_21102125->right_21102125 == node)
                cout << " Sibling : " << node->parent_21102125->left_21102125->data_21102125 << endl;
            else if (node->parent_21102125 != NULL && node->parent_21102125->right_21102125 != node &&
                     node->parent_21102125->left_21102125 == node)
                cout << " Sibling : " << node->parent_21102125->right_21102125->data_21102125 << endl;
            else
                cout << " Sibling : (tidak punya sibling)" << endl;

            if (!node->left_21102125)
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left_21102125->data_21102125 << endl;
            if (!node->right_21102125)
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan : " << node->right_21102125->data_21102125 << endl;
        }
    }
}

// Penelurusan (Traversal)
// preOrder
void preOrder(Pohon *node = root_21102125)
{
    if (isEmpty() == 1)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data_21102125 << ", ";
            preOrder(node->left_21102125);
            preOrder(node->right_21102125);
        }
    }
}

// inOrder
void inOrder(Pohon *node = root_21102125)
{
    if (isEmpty() == 1)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            inOrder(node->left_21102125);
            cout << " " << node->data_21102125 << ", ";
            inOrder(node->right_21102125);
        }
    }
}

// postOrder
void postOrder(Pohon *node = root_21102125)
{
    if (isEmpty() == 1)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            postOrder(node->left_21102125);
            postOrder(node->right_21102125);
            cout << " " << node->data_21102125 << ", ";
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
            if (node != root_21102125)
            {
                node->parent_21102125->left_21102125 = NULL;
                node->parent_21102125->right_21102125 = NULL;
            }
            deleteTree(node->left_21102125);
            deleteTree(node->right_21102125);
            if (node == root_21102125)
            {
                delete root_21102125;
                root_21102125 = NULL;
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
        deleteTree(node->left_21102125);
        deleteTree(node->right_21102125);
        cout << "\n Node subtree " << node->data_21102125 << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear()
{
    if (isEmpty() == 1)
        cout << "\n Buat tree terlebih dahulu!!" << endl;
    else
    {
        deleteTree(root_21102125);
        cout << "\n Pohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node = root_21102125)
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
            return 1 + size(node->left_21102125) + size(node->right_21102125);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node = root_21102125)
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
            int heightKiri = height(node->left_21102125);
            int heightKanan = height(node->right_21102125);
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

int main()
{
    buatNode("Winner");
    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ, *nodeK, *nodeL, *nodeM, *nodeN;



    nodeD = insertleft_21102125("Grand Finalis 1", root_21102125);
    nodeF = insertleft_21102125("Semi Finalis 1", nodeD);
    nodeE = insertright_21102125("Semi Finalis 2", nodeD);
    nodeG = insertleft_21102125("Defending Champion", nodeF);
    nodeI = insertleft_21102125("Group Winner 1", nodeE);
    nodeH = insertright_21102125("Group Winner 2", nodeE);



    nodeC = insertright_21102125("Grand Finalis 2", root_21102125);
    nodeB = insertleft_21102125("Semi Finalis 3", nodeC);
    nodeJ = insertright_21102125("Semi Finalis 4", nodeC);
    nodeK = insertleft_21102125("Group Winner 3", nodeB);
    nodeL = insertright_21102125("Group Winner 4", nodeB);
    nodeM = insertleft_21102125("Group Winner 5", nodeJ);
    nodeN = insertright_21102125("Group Winner 6", nodeJ);

    deleteSub(nodeN);

    cout << "\n PreOrder :" << endl;
    preOrder(root_21102125);
    cout << "\n" << endl;

    cout << " InOrder :" << endl;
    inOrder(root_21102125);
    cout << "\n" << endl;

    cout << " PostOrder :" << endl;
    postOrder(root_21102125);
    cout << "\n" << endl;

    cout << " Semi Finalis 2" << endl;
    preOrder(nodeE);

    cout << "\n\n Grand Finalis 2" << endl;
    postOrder(nodeC);

    cout << "\n\n Karakteristik: ";
    charateristic();


    return 0;
}