#include <iostream>
using namespace std;

int main() {

    // unsigned int a;
    // a = -1;
    // cout << a << endl;


    // int a[]={12, 3, 13, 8, 22};
    // int *p;
    // p = &a[1];
    // *(--p) *= 3;
    // cout << *a << endl;

    int a[]={12, 3, 13, 8, 22};
    int *p, *q, n;
    p = &a[1];
    q = &a[4];
    *(--p) *= 3;
    n = q - p;
    cout << n << endl;
     

    return 0;
}