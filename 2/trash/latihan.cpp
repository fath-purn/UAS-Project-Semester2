// Nama : Fatkhurrohman Purnomo
// Nim : 21102125

#include <iostream>
using namespace std;

int main(){
    // array 4 dimensi
    char arr[2][3][4][1]=
    {{{{'a'},{'b'},{'c'},{'d'},},{{'e'},{'f'},{'g'},{'h'},},{{'i'},{'j'},{'k'},{'l'},},},
    {{{'m'},{'n'},{'o'},{'p'},},{{'q'},{'r'},{'s'},{'t'},},{{'u'},{'v'},{'w'},{'x'},},}};
    
    // output
    for (int i=0; i<2; i++){
        for (int j=0; j<3; j++){
            for (int k=0; k<4; k++){
                for (int l=0; l<1; l++){
                    cout<<arr[i][j][k][l]<<" ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }

    return 0;
}
