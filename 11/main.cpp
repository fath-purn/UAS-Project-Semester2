#include <iostream>
using namespace std;

struct pohon{
    pohon* kanan;
    char data;
    pohon* kiri;
};
pohon* simpul;
pohon* root;
pohon* saatIni;
pohon* helperA;
pohon* helperB;
pohon* alamat[256];

void insialisasi(){
    root = NULL;
}
void simpulBaru(char dataMasukkan){
    simpul = new pohon;
    simpul->data = dataMasukkan;
    simpul->kanan = NULL;
    simpul->kiri = NULL;
}
void simpulAkar(){
    if(root == NULL){
        char dataAnda;
        cout<<"Silahkan masukkan data : ";
        cin>>dataAnda;
        simpulBaru(dataAnda);
        root = simpul;
        cout<<"Root terbentuk..."<<endl;
    }else{
        cout<<"Root sudah ada..."<<endl;
    }
}
void tambahSimpul_kiri(){
    if(root != NULL){
        int i, j, penanda;
        char dataUser;
        i = 1; j = 1; penanda = 0;
        alamat[i] = root;
        while(penanda == 0 && j < 256){
            cout<<"Masukkan data kiri : ";
            cin>>dataUser;
            if(dataUser != '0'){
                simpulBaru(dataUser);
                saatIni = alamat[i];
                saatIni->kiri = simpul;
                j++;
                alamat[j] = simpul;
            }else{
                penanda = 1;
                j++;
                alamat[j] = NULL;
            }
            i++;
        }
    }
}
void tambahSimpul_kanan(){
    if(root != NULL){
        int i, j, penanda;
        char dataUser;
        i = 1; j = 1; penanda = 0;
        alamat[i] = root;
        while(penanda == 0 && j < 256){
            cout<<"Masukkan data kanan : ";
            cin>>dataUser;
            if(dataUser != '0'){
                simpulBaru(dataUser);
                saatIni = alamat[i];
                saatIni->kanan = simpul;
                j++;
                alamat[j] = simpul;
            }else{
                penanda = 1;
                j++;
                alamat[j] = NULL;
            }
        }
        i++;
    }
}
void bacaPohon(){
    if(root != NULL){
        int i, n, pencacah;
        i = 1;
        n = 1;
        pencacah = 0;
        cout<<endl;
        while(alamat[i] != NULL){
            saatIni = alamat[i];
            cout<<saatIni->data<<" ";
            pencacah++;
            if(pencacah == n){
                cout<<endl;
                pencacah = 0;
                n = n*2;
            }
            i++;
        }
    }
}
int main(){
    char ya_tidak;
    bool keluar = false;
    int pilih;
    do{
        cout<<"============================="<<endl;
        cout<<"\t     TREE "<<endl;
        cout<<"============================="<<endl;
        cout<<"1. Silahkan Masukan Data Root"<<endl;
        cout<<"2. Sisip Data Kanan"<<endl;
        cout<<"3. Sisip Data Kiri"<<endl;
        cout<<"4. Tampil Data"<<endl;
        cout<<"5. Keluar"<<endl;
        cout<<"Pilihan anda: ";
        cin>>pilih;
        switch(pilih){
        case 1 :
            simpulAkar();
            cout<<"Keluar (y/t) ? ";
            cin>>ya_tidak;
            if(ya_tidak == 'y' || ya_tidak == 'Y'){
                cout<<"Jumpa kembali "<<endl;
                keluar = true;
            }else{
                system("cls");
            }
        break;
        case 2 :
            tambahSimpul_kanan();
            cout<<"Keluar (y/t) ? ";
            cin>>ya_tidak;
            if(ya_tidak == 'y' || ya_tidak == 'Y'){
                cout<<"Jumpa kembali "<<endl;
                keluar = true;
            }else{
                system("cls");
            }
        break;
        case 3 :
            tambahSimpul_kiri();
            cout<<"Keluar (y/t) ? ";
            cin>>ya_tidak;
            if(ya_tidak == 'y' || ya_tidak == 'Y'){
                cout<<"Jumpa kembali "<<endl;
                keluar = true;
            }else{
                system("cls");
            }
        break;
        case 4 :
            bacaPohon();
            cout<<endl;
            cout<<"Keluar (y/t) ? ";
            cin>>ya_tidak;
            if(ya_tidak == 'y' || ya_tidak == 'Y'){
                cout<<"Jumpa kembali "<<endl;
                keluar = true;
            }else{
                system("cls");
            }
        break;
        default :
            cout<<"Yakin ingin keluar???"<<endl;
            cout<<"Keluar (y/t) ? ";
            cin>>ya_tidak;
            if(ya_tidak == 'y' || ya_tidak == 'Y'){
                cout<<"Terima kasih"<<endl;
                keluar = true;
            }else{
                system("cls");
            }
        }
    }while (keluar == false);
    return 0;
}






/*#include <iostream>
using namespace std;
struct pohon{
    pohon* kanan;
    char data;
    pohon* kiri;
};

pohon* simpul;
pohon* root;
pohon* saatIni;
pohon* helperA;
pohon* helperB;
pohon* alamat[10];

void inisialisasi(){
    root = NULL;
}

void simpulBaru(char dataMasukkan){
    simpul = new pohon;
    simpul->data = dataMasukkan;
    simpul->kanan = NULL;
    simpul->kiri = NULL;
}

void simpulAkar(){
    if(root == NULL){
        char dataAnda;
        cout<<"Silahkan masukkan data : ";
        cin>>dataAnda;
        simpulBaru(dataAnda);
        root = simpul;
        cout<<"Root terbentuk..."<<endl;
    }else{
        cout<<"Root sudah ada..."<<endl;
    }
}

int i, j, penanda;
char dataUser;

void tambahKiri(){
    if(root != NULL){
        int i, j, penanda;
        char dataUser;
        i = 1; j = 1; penanda = 0;
        alamat[i] = root;
        while(penanda == 0 && j < 10){
            cout<<"Masukkan data kiri : ";
            cin>>dataUser;
            if(dataUser != '0'){
                simpulBaru(dataUser);
                saatIni = alamat[i];
                saatIni->kiri = simpul;
                j++;
                alamat[j] = simpul;
            }else{
                penanda = 1;
                j++;
                alamat[j] = NULL;
            } i++;
        }
    }
}
void tambahKanan(){
    if(root != NULL){
        int i, j, penanda;
        char dataUser;
        i = 1; j = 1; penanda = 0;
        alamat[i] = root;
        while(penanda == 0 && j < 10){
            cout<<"Masukkan data kanan : ";
            cin>>dataUser;
            if(dataUser != '0'){
                simpulBaru(dataUser);
                saatIni = alamat[i];
                saatIni->kanan = simpul;
                j++;
                alamat[j] = simpul;
            }else{
                penanda = 1;
                j++;
                alamat[j] = NULL;
            }
        } i++;
    }
}

void bacaPohon(){
    if(root != NULL){
        int i, n, pencacah;
        i = 1;
        n = 1;
        pencacah = 0;
        cout<<endl;
        while(alamat[i] != NULL){
            saatIni = alamat[i];
            cout<<saatIni->data<<" ";
            pencacah++;
            if(pencacah == n){
                cout<<endl;
                pencacah = 0;
                n = n*2;
            } i++;
        }
    }
}

void masukData(){
    int masuk;
    do{
        cout<<"1.Data kanan"<<endl;
        cout<<"2.Data kiri"<<endl;
        cout<<"masukkan pilihan 1-2 : ";cin>>masuk;
        switch (masuk){
        case 1 :
            tambahKiri();
        break;
        case 2 :
            tambahKanan();
        break;
        default:
            cout<<"kosong";
        }
        bacaPohon();
    }while(masuk!=0);
}

int main(){
    inisialisasi();
    simpulAkar();
    masukData();
    cout<<endl<<endl<<endl;
    bacaPohon();
    simpulAkar();
    bacaPohon();

    return 0;
}
   inisialisasi();
    simpulAkar();
    int pilihan;
    bool keluar=false;
    char ya_tidak;
    do{
        cout<<"1. Masukkan data kanan"<<endl;
        cout<<"2. Masukkan data kiri"<<endl;
        cout<<"Masukkan pilihan (1-2): ";cin>>pilihan;
        switch(pilihan){
        case 1:
            tambahSimpul();
            bacaPohon();
            cout<<"Keluar (y/t) ? ";
            cin>>ya_tidak;
            if(ya_tidak == 'y' || ya_tidak == 'Y'){
                cout<<" Jumpa kembali "<<endl;
                keluar = true;
            }else{
                system("cls");
            }
        break;
        default :
            cout<<"Pilihan tidak tersedia..."<<endl;
            cout<<"Keluar (y/t) ? ";
            cin>>ya_tidak;
            if(ya_tidak == 'y' || ya_tidak == 'Y'){
                cout<<" Terima kasih"<<endl;
                keluar = true;
            }else{
                system("cls");
            }
        }
    }while(keluar==false);

    tambahSimpul();
    bacaPohon();

*/
