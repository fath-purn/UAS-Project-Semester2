#include <iostream>
using namespace std;
// node
struct Node
{
    string label;
    Node *left, *right, *parent;
};
// variabel pointer global
Node *root, *newNode;
// create New Tree
void createNewTree(string label)
{
    if (root != NULL)
        cout << "\nTree sudah dibuat" << endl;
    else
    {
        root = new Node();
        root->label = label;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\nNode " << label << " berhasil dibuat menjadi root." << endl;
    }
}
// insert Left
Node *insertLeft(string label, Node *node)
{
    if (root == NULL)
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return NULL;
    }
    else
    {
        // cek apakah anak kiri ada atau tidak
        if (node->left != NULL)
        {
            // kalau ada
            cout << "\nNode " << node->label << " sudah ada anak kiri!!" << endl;
            return NULL;
        }
        else
        {
            // kalau tidak ada
            newNode = new Node();
            newNode->label = label;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->parent = node;
            node->left = newNode;
            cout << "\nNode " << label << " berhasil ditambahkan ke anak kiri " << newNode->parent->label << endl;
            return newNode;
        }
    }
}
// insert right
Node *insertRight(string label, Node *node)
{
    if (root == NULL)
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return NULL;
    }
    else
    {
        // cek apakah anak kiri ada atau tidak
        if (node->right != NULL)
        {
            // kalau ada
            cout << "\nNode " << node->label << " sudah ada anak kanan!!" << endl;
            return NULL;
        }
        else
        {
            // kalau tidak ada
            newNode = new Node();
            newNode->label = label;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->parent = node;
            node->right = newNode;
            cout << "\nNode" << label << " berhasil ditambahkan ke anak kanan " << newNode->parent->label << endl;
            return newNode;
        }
    }
}
// Empty
bool empty()
{
    if (root == NULL)
        return true;
    else
        return false;
}
// update
void update(string label, Node *node)
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else
        {
            string temp = node->label;
            node->label = label;
            cout << "\nLabel node " << temp << " berhasil diubah menjadi " << label << endl;
        }
    }
}
// retrieve
void retrieve(Node *node)
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!!" << endl;
        else
        {
            cout << "\nLabel node : " << node->label << endl;
        }
    }
}
// Find
void find(Node *node)
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!!" << endl;
        else
        {
            cout << "\nLabel Node : " << node->label << endl;
            cout << "Root Node : " << root->label << endl;
            if (!node->parent)
                cout << "Parent Node : (tidak punya orang tua)" << endl;
            else
                cout << "Parent Node : " << node->parent->label << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Saudara : " << node->parent->left->label << endl;
            else if (node->parent != NULL && node->parent->right != node &&
                     node->parent->left == node)
                cout << "Saudara : " << node->parent->right->label << endl;
            else
                cout << "Saudara : (tidak punya saudara)" << endl;
            if (!node->left)
                cout << "Anak Kiri Node : (tidak punya anak kiri)" << endl;
            else
                cout << "Anak Kiri Node : " << node->left->label << endl;
            if (!node->right)
                cout << "Anak Kanan Node : (tidak punya anak kanan)" << endl;
            else
                cout << "Anak Kanan Node : " << node->right->label << endl;
        }
    }
}
// Tranversal
// preOrder
void preOrder(Node *node = root)
{
    if (!root)
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {
        if (node != NULL)
        {
            cout << node->label << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}
// inOrder
void inOrder(Node *node = root)
{
    if (!root)
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << node->label << ", ";
            inOrder(node->right);
        }
    }
}
// postOrder
void postOrder(Node *node = root)
{
    if (!root)
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->label << ", ";
        }
    }
}
// deleteTree
void deleteTree(Node *node)
{
    if (!root)
        cout << "\nBuat tree terlebih dahulu!!" << endl;
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
// delete Sub
void deleteSub(Node *node)
{
    if (!root)
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nSubtree node " << node->label << " berhasil dihapus." << endl;
    }
}
// clear
void clear()
{
    if (!root)
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {
        deleteTree(root);
        cout << "\nTree berhasil dihapus." << endl;
    }
}
// size
float size(Node *node = root)
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
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
// height
float height(Node *node = root)
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
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
            float heightKiri = height(node->left);
            float heightKanan = height(node->right);
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
// characteristic
void charateristic()
{
    cout << "\nSize Tree : " << size() << endl;
    cout << "Height Tree : " << height() << endl;
    cout << "Average Node of Tree : " << size() / height() << endl;
}
int main()
{
    createNewTree("JAWA");
    Node *node2, *node3, *node4, *node5, *node6, *node7, *node8, *node9, *node10;
    node2 = insertLeft("KALIMANTAN", root);
    node3 = insertRight("SULAWESI", root);
    node4 = insertLeft("PAPUA", node2);
    node5 = insertRight("MALUKU", node2);
    node6 = insertLeft("FLORES", node3);
    node7 = insertLeft("TIMOR", node5);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n"
         << endl;
    cout << "InOrder :" << endl;
    inOrder(root);
    cout << "\n"
         << endl;
    charateristic();
    cout << "\nPreOrder SULAWESI :" << endl;
    preOrder(node3);
    cout << "\n"
         << endl;
    cout << "InOrder TIMOR :" << endl;
    inOrder(node7);
    cout << "\n"
         << endl;
    charateristic();
}
