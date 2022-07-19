#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string>

using namespace std;

int maksimal_antrian_barang = 50;//mengurutkan sesuai dg antrian barang  apa sajayg akan dilakukan pengecekan oleh admid dalam 1 minggu kedepan
bool keluar = false;
char ya_tidak;
int pilihan, pilih, pil;
string kode_barang, kode_rak;//dg memasukkan kode barang

int menu,jh, m_idx, cari, dataedite;//jh jumlah data







//prosedur menu login ke aplikasi
void menuLogin (){

    string username;
    int password;
    int i;

    cout << "====================================================================================\n";
    cout << "       SELAMAT DATANG DI APLIKASI MANAJEMEN GUDANG TOKO ANEKA JAYA PURWOKERTO      \n";
    cout << "====================================================================================\n"<<endl;
    string user = "admin";
    int pass = 123123;
    int login=0;
    i = 1;

    do {
        cout << "________________________________"<<endl;
        cout << "\n Username : "; cin >> username;
        cout << "________________________________"<<endl;
        cout << "\n Password : "; cin >> password;
        if (username ==user && password == pass) {
            i=4;
            login=1;
            system ("cls") ;
        }else {
            cout << "\n ___________________________________\n"<<endl;
            cout << "\n|     Maaf ID & PASSWORD Salah!!!   | \n";
            cout << "\n|___________________________________|\n"<<endl;
            i = i +1;
        }
    }while (i <= 3);
    if(login != 1){
        cout<<"Anda Telah 3x Memasukan ID & PASSWORD Yang Salah\n";
        cout << "Mohon Login Kembali Setelah 30, Terima Kasih..";
    }
}

//menu list antrian barang yang akan di lakukan pengecekan dalam 1 minggu kedepan
//dicek berdasarkan antian barang yang dimasukkan terlebih dahulu
//jadi dicek secara berurutan berdasarkan no.antrian barang
struct antrian_pengecekan_barang{
    int depan;
    int belakang;
    string *kodebr = new string[maksimal_antrian_barang];
}urutan_pengecekan;

void nilai_awal(){
    urutan_pengecekan.depan = -1;
    urutan_pengecekan.belakang = -1;
}

bool antrian_barang_penuh(){
    if(urutan_pengecekan.belakang == maksimal_antrian_barang-1){
        return true;
    }else{
        return false;
    }
}

bool antrian_barang_kosong(){
    if(urutan_pengecekan.depan == -1 && urutan_pengecekan.belakang == -1){
        return true;
    }else{
        return false;
    }
}

void masukkan_antrian_pengecekan(string kode_barang){//memasukkan kode barang apa saja yg akan di cek dalam 1 minggu kedepan
    if(antrian_barang_kosong() == true){
        urutan_pengecekan.depan = 0;
        urutan_pengecekan.belakang = 0;
        urutan_pengecekan.kodebr[urutan_pengecekan.belakang] = kode_barang;
        cout<<"Kode Barang Sudah Masuk"<<endl;
    }else if(antrian_barang_penuh() == false){
        urutan_pengecekan.belakang++;
        urutan_pengecekan.kodebr[urutan_pengecekan.belakang] = kode_barang;
        cout<<"Kode Barang Sudah Masuk"<<endl;
    }else{
        cout<<"Antrian Pengecekan Barang Sudah Penuh"<<endl;
    }
}

void hapus_antrian_pengecekan(){//jika pengecekan sudah selesai maka data bisa dihapus
    if(antrian_barang_kosong() == false){
        for(int x = urutan_pengecekan.depan; x <= urutan_pengecekan.belakang; x++){
        urutan_pengecekan.kodebr[x] = urutan_pengecekan.kodebr[x+1];
        }
        urutan_pengecekan.belakang--;
        cout<<"Satu Kode Barang Telah Terhapus "<<endl;
        cout<<endl;
    }else{
        cout<<"Tidak Terdapat Kode Barang Yang akan Di cek "<<endl;
    }
}

void tampil_data_pengecekan(){
    if(antrian_barang_kosong() == false){
        for(int z = urutan_pengecekan.depan; z <= urutan_pengecekan.belakang; z++){
            cout<<urutan_pengecekan.kodebr[z]<<" ";
        }
        cout<<endl;
    }else{
        cout<<"Tidak Terdapat Kode Barang Yang akan Di cek "<<endl;
    }
}

//prosedur untuk membuat pelatakkan rak barang menggunakan dlinkedlist
struct dlinkedlist_rak{//untuk membuat menu tempat peletakkan barang
    dlinkedlist_rak* prev;
    string kode;
    dlinkedlist_rak* next;
};

dlinkedlist_rak* head;
dlinkedlist_rak* tail;
dlinkedlist_rak* vertex;

void inisialisasi_rak(){
    head = NULL;
    tail = NULL;
}

bool rak_kosong(){
    if(head == NULL && tail == NULL){
        return true;
    }else{
        return false;
    }
}

void tambahDepan(string kode_rak){
    if(rak_kosong() == true){
        vertex = new  dlinkedlist_rak;
        vertex -> kode = kode_rak;
        vertex -> prev = NULL;
        vertex -> next = NULL;
        head = vertex;
        tail = vertex;
    }else{
        vertex = new  dlinkedlist_rak;
        vertex -> kode = kode_rak;
        vertex -> prev = NULL;
        vertex -> next = NULL;
        vertex -> next = head;
        vertex -> prev = vertex;
        head = vertex;
    }
}

void tambahBelakang(string kode_rak){
    if(rak_kosong() == true){
        vertex = new  dlinkedlist_rak;
        vertex -> kode = kode_rak;
        vertex -> prev = NULL;
        vertex -> next = NULL;
        head = vertex;
        tail = vertex;
    }else{
        vertex = new  dlinkedlist_rak;
        vertex -> kode = kode_rak;
        vertex -> prev = NULL;
        vertex -> next = NULL;
        tail -> next = vertex;
        vertex -> prev = tail;
        tail = vertex;
    }
}

void hapusDepan(){
    if(rak_kosong() == true){
        cout<<"Rak Barang Kosong..!!!"<<endl<<endl;
    }else{
        dlinkedlist_rak* helper;
        helper = head;
        if(head == tail){
            head = NULL;
            tail = NULL;
            delete helper;
        }else{
            head = head -> next;
            head -> prev = NULL;
            helper -> next = NULL;
            delete helper;
        }
    }
}

void hapusBelakang(){
    if(rak_kosong() == true){
        cout<<"Rak Barang Kosong..!!!"<<endl<<endl;
    }else{
        if(head == tail){
            dlinkedlist_rak* helper;
            helper = head;
            head = NULL;
            tail = NULL;
            delete helper;
        }else{
            dlinkedlist_rak* helper;
            helper = tail;
            tail = tail ->prev;
            tail -> next = NULL;
            helper -> prev = NULL;
            delete helper;
        }
    }
}

void tampilData(){
    if(rak_kosong() == true){
        cout<<"Rak Barang Kosong..!!!"<<endl<<endl;
    }else{
        dlinkedlist_rak* helper;
        helper = head;
        while(helper != NULL){
            cout<<"Kode Rak Yang Tersedia"<<endl<<endl;
            cout<<helper->kode<<" ";
            helper = helper -> next;
        }
    }
}


//data supplier
struct{

    string kode_suplier,nama_suplier, alamat, kota, provinsi,telepon;

}suplier;

//menu data barang
struct data_barang{
    string nama_barang;
    int kd_barang;
    int no, jumlah_stock, harga_barang;
}data[50];

void data_Brng (data_barang dat){

    cout<< " " <<dat.kd_barang<< " " <<dat.nama_barang<< " " <<dat.jumlah_stock<< " " <<dat.harga_barang<<endl;
}

void edit_data_barang(data_barang & edit){

    cout<<"Masukkan Kode Barang  : ";cin>>edit.kd_barang;
    cout<<"Masukkan Nama Barang  : ";cin>>edit.nama_barang;
    cout<<"Masukkan Jumlah Stock : ";cin>>edit.jumlah_stock;
    cout<<"Harga Barang          : Rp. ";cin>>edit.harga_barang;
}

void input_data_barang (data_barang & input){

    cout<<"Masukkan Kode Barang  : ";cin>>input.kd_barang;
    cout<<"Masukkan Nama Barang  : ";cin>>input.nama_barang;
    cout<<"Masukkan Jumlah Stock : ";cin>>input.jumlah_stock;
    cout<<"Harga Barang          : Rp. ";cin>>input.harga_barang;
}

void pembelian_barang(data_barang & pembelian, int& bayar, int& jumlah_beli){

    cout<<"Nama Barang : "<<pembelian.nama_barang;
    cout<<"Jumlah Stok : "<<pembelian.jumlah_stock;
    cout<<"Harga       : "<<pembelian.harga_barang;
    cout<<"Jumlah Yang Dibeli : ";cin>>jumlah_beli;
    bayar = jumlah_beli*pembelian.harga_barang;
    cout<<"Harga Yang Harus Dibayar : "<<jumlah_beli<<" x "<<pembelian.harga_barang<<" = Rp. "<<bayar<<endl;
    cout<<"Jumlah Stock             : "<<pembelian.jumlah_stock<<" - "<<jumlah_beli<< " = "<<pembelian.jumlah_stock - jumlah_beli<<endl;
    pembelian.jumlah_stock = pembelian.jumlah_stock - jumlah_beli;
}




//prosedur pilihan pada menu utama
void menu_utama(){
    cout<<"\t\===============================================\n";
    cout<<"\t\           MENU UTAMA  MANAJEMEN GUDANG    \n";
    cout<<"\t\            TOKO ANEKA JAYA PURWOKERTO    \n";
    cout<<"\t\===============================================\n";
    cout<<"\t\1. Mendata Antrian Barang Yang Akan Di-cek\n";
    cout<<"\t\2. Mendata Persediaan Rak Barang   \n";
    cout<<"\t\3. Mendata Supplier               \n";
    cout<<"\t\4. Input & Update Barang                 \n";
    cout<<"\t\5. petunjuk penggunaan program.     ===========\n";
    cout<<"\t\6. Melihat semua data.              ===========\n";
    cout<<"\t\0. Keluar program.                  ===========\n";
    cout<<"\t\===============================================\n";
    cout<<"\t\===============================================\n";
    cout<<"  Masukkan Pilihan Menu (1-5) : ";
    cin>>pilih;
    cout<<endl<<endl;

}

//menu case 4
void mmenu(){

    cout<<"\n\t\t===============================================\n";
    cout<<"\t\t==========Menu Inpu & Update Barang=============\n";
    cout<<"\t\t===============================================\n";
    cout<<"\t\t1. Memasukan Data Barang.           \n";
    cout<<"\t\t2. Memperbarui data.                \n";
    cout<<"\t\t===============================================\n";
}

void input(){
    cout<<"\t\t===============================================\n";
    cout<<"\t\t==============MASUKAN DATA BARANG==============\n";
    cout<<"\t\t===============================================\n";
    }

void update(){
    cout<<"\t\t============================================= =\n";
    cout<<"\t\t==============Masukan Data pembaruan==========\n";
    cout<<"\t\t==============================================\n";
}


void menu4(){
    cetak:
    int menu,jh, m_idx, cari, dataedite;//jh jumlah data
    jh = 50;
    string nbarang[jh], jenis[jh];
    int kodebarang[jh], harga[jh], jumlah[jh], expired[jh];

    mmenu();
    cout<<"Silahkan Masukkan Pilihan Anda [1/2] : ";
    cin>>pilih;
    cout<<endl<<endl;
    switch(pilih){
        case 1:
            cout<<"\t\tMasukan Jumlah data Barang yang ingin diinput : \n";
            cin>>jh;
            cout<<"\t\t-----------------------------------------------\n";
            for(int d = 0; d < jh; d++){

                cout<<"Masukan Nama Barang : ";
                cin>>nbarang[d];

                cout<<"\t\t  Masukan Kode Barang : ";
                cin>>kodebarang[d];

                cout<<"\t\t  Masukan jenis Barang : ";
                cin>>jenis[d];

                cout<<"\t\t  Masukan harga Barang : ";
                cin>>harga[d];

                cout<<"\t\t  Masukan Jumlah Barang : ";
                cin>>jumlah[d];

                cout<<"\t\t  Masukan expired Barang : ";
                cin>>expired[d];
                cout<<endl<<endl;
            }
            break;
        case 2:
            string namaupdate;
            int kodeupdate, jenisupdate,hargaupdate, hargapdate,jumlahupdate,expiredupdate, index;
            update();
            cout<<"\t\tMasukan Kode Barang untuk mengubah data : ";
            cout<<"\t\t";cin>>dataedite;

            cin.ignore();
            cout<<"\t\tMasukan Nama Barang yang baru : ";
            getline(cin, namaupdate);

            cout<<"\t\tMasukan Kode Barang yang baru : ";
            cout<<"\t";cin>>kodeupdate;

            cout<<"\t\tMasukan jenis Barang yang baru : ";
            cout<<"\t";cin>>jenisupdate;

            cout<<"\t\tMasukan harga Barang yang baru : ";
            cout<<"\t";cin>>hargaupdate;

            cout<<"\t\tMasukan Jumlah Barang yang baru : ";
            cout<<"\t";cin>>jumlahupdate;

            cout<<"\t\tMasukan expired Barang yang baru : ";
            cout<<"\t";cin>>expiredupdate;

            for(int u = 0; u < jh; u++){
                cout<<u+1;
                if(dataedite == kodebarang[u]){
                    index = u;
                    nbarang[index]      =   namaupdate;
                    kodebarang[index]   =   kodeupdate;
                    jenis[index]        =   jenisupdate;
                    harga[index]        =   hargaupdate;
                    jumlah[index]       =   jumlahupdate;
                    expired[index]      =   expiredupdate;
                }
            }
            break;
    }
}






int main(){

    int n = 0, nomor_barang = 1, kode_Barang;
    char kembali;
    menuLogin();
    menu_utama();
    system ("cls") ;
    do{
        switch(pilih){
        case 1:
            do{
                cout<<"========================================================="<<endl;
                cout<<"|                                                      |"<<endl;
                cout<<"\t"<<"Antrian Pengecekan Barang Dalam 1 Minggu"<<endl;
                cout<<"|                                                      |"<<endl;
                cout<<"\t"<<"       Toko Aneka Jaya Purwokerto       "<<endl;
                cout<<"========================================================="<<endl;
                cout<<"| 1. Masukkan Jumlah Maksimal Barang Yang Akan Di-cek  |"<<endl;
                cout<<"_________________________________________________________"<<endl;
                cout<<"| 2. Masukkan Kode Barang Yang Akan Di-cek             |"<<endl;
                cout<<"_________________________________________________________"<<endl;
                cout<<"| 3. Hapus Kode Barang [Jika Telah Di-cek]             |"<<endl;
                cout<<"_________________________________________________________"<<endl;
                cout<<"| 4. Tampilkan Kode Barang Yang Akan Di-cek            |"<<endl;
                cout<<"__________________________________________________________"<<endl;
                cout<<"| 5. Keluar                            |"<<endl;
                cout<<"__________________________________________________________"<<endl;
                cout<<"Masukkan Pilihan Menu (1-5) : ";
                cin>>pilihan;
                cout<<endl<<endl;
                switch(pilihan){

                case 1 :
                    cout<<"Masukkan Jumlah Maksimal Barang Yang Akan Di-Cek [Bilangan Bulat] : ";
                    cin>>maksimal_antrian_barang;
                    cout<<endl<<endl;
                    cout<<"__________________________________________________________________________________"<<endl;
                    cout<<"\t\Pengaturan Pengecekan Barang Untuk 1 Minggu Kedepan Selesai"<<endl;
                    cout<<"__________________________________________________________________________________"<<endl<<endl;

                    cout<<"\t\              Apakah Anda Ingin Keluar (y/t) ? ";
                    cin>>ya_tidak;
                    if(ya_tidak == 'y' || ya_tidak == 'Y'){
                        cout<<"__________________________________________________________________________________"<<endl;
                        cout<<"\t\              ANDA TELAH KELUAR ! ! ! "<<endl;
                        cout<<"__________________________________________________________________________________"<<endl;
                        keluar = true;
                    }else{
                        system("cls");
                    }
                    break;

                case 2 :
                    cout<<" Silahkan Masukkan Kode Barang  : ";
                    cin>>kode_barang;
                    cout<<"__________________________________________________________"<<endl;
                    masukkan_antrian_pengecekan(kode_barang);
                    cout<<"Apakah Anda Ingin Keluar (y/t) ? ";
                    cin>>ya_tidak;
                    cout<<endl<<endl;
                    if(ya_tidak == 'y' || ya_tidak == 'Y'){
                        cout<<"______________________________________________________"<<endl;
                        cout<<"\t\   ANDA TELAH KELUAR ! ! ! "<<endl;
                        cout<<"_______________________________________________________"<<endl;
                        keluar = true;
                    }else{
                        system("cls");
                    }
                    break;

                case 3 :
                    hapus_antrian_pengecekan();
                    cout<<"___________________________________________"<<endl;
                    cout<<"Apakah Anda Ingin Keluar (y/t) ? ";
                    cin>>ya_tidak;
                    if(ya_tidak == 'y' || ya_tidak == 'Y'){
                        cout<<"\t\   ANDA TELAH KELUAR ! ! ! "<<endl;
                        keluar = true;
                    }else{
                        system("cls");
                    }
                    break;

                case 4 :
                    cout<<"Berikut Kode Barang Yang Akan Di-cek  "<<endl<<endl;
                    tampil_data_pengecekan();
                    cout<<"___________________________________________"<<endl<<endl;
                    cout<<"Apakah Anda Ingin Keluar (y/t) ? ";
                    cin>>ya_tidak;
                    if(ya_tidak == 'y' || ya_tidak == 'Y'){
                        cout<<"___________________________________________"<<endl;
                        cout<<"\t\   ANDA TELAH KELUAR ! ! ! "<<endl;
                        cout<<"___________________________________________"<<endl;
                        keluar = true;
                    }else{
                        system("cls");
                    }
                    break;

                case 5 :
                    cout<<"Apakah Anda Ingin Keluar (y/t) ? ";
                    cin>>ya_tidak;
                    if(ya_tidak =='y'||ya_tidak=='Y'){
                        cout<<"___________________________________________"<<endl;
                        cout<<"\t\   ANDA TELAH lOGOUT ! ! ! "<<endl;
                        cout<<"___________________________________________"<<endl;
                        keluar=true;
                    }else{
                        system("cls");
                    }
                    break;
                default:
                    cout<<"\t\ Pilihan Menu Tidak Tersedia !!!"<<endl;
                    cout<<"_____________________________________________________"<<endl;
                    cout<<"\t\ Apakah Anda Ingin Keluar (y/t) ? ";
                    cin>>ya_tidak;
                    cout<<endl<<endl;
                    if(ya_tidak =='y'||ya_tidak=='Y'){
                        cout<<"\t\========== Terima Kasih ==========="<<endl;
                        keluar=true;
                    }else{
                        system("cls");
                    }
                }
            }while(keluar==false);
            break;

            case 2:
                inisialisasi_rak();
                do{//masukkan kode rak
                    cout<<"=============================================="<<endl;
                    cout<<"\t"<<"Pendataan Persediaan Rak Barang"<<endl;
                    cout<<"=============================================="<<endl;
                    cout<<"1. Tambahkan Rak Barang Di Depan"<<endl;
                    cout<<"2. Tambahkan Rak Barang Di Belakang"<<endl;
                    cout<<"3. Kosongkan Rak Barang Di Depan"<<endl;
                    cout<<"4. Kosongkan Rak Barang Dari Belakang"<<endl;
                    cout<<"5. Tampilkan Rak Barang Yang Tersedia"<<endl;
                    cout<<"6. Kembali Ke Menu Utama"<<endl;
                    cout<<"=============================================="<<endl;
                    cout<<"Silahkan Masukkan Pilihan Anda [1-6] : ";
                    cin>>pil;
                    cout<<endl<<endl;

                    switch(pil){
                    case 1:
                        cout<<"Silahkan Masukkan Kode Rak : ";
                        cin>>kode_rak;
                        tambahDepan(kode_rak);
                        cout<<endl<<endl;
                        cout<<"Apakah Anda Ingin Keluar (y/t) ? ";
                        cin>>ya_tidak;
                        if(ya_tidak =='y'||ya_tidak=='Y'){
                            cout<<"___________________________________________"<<endl;
                            cout<<"\t\   ANDA TELAH KELUAR ! ! ! "<<endl;
                            cout<<"___________________________________________"<<endl;
                            keluar=true;
                        }else{
                            system("cls");
                        }
                        break;
                    case 2:
                        cout<<"Silahkan Masukkan Kode Rak : ";
                        cin>>kode_rak;
                        cout<<endl<<endl;
                        tambahBelakang(kode_rak);
                        cout<<"Apakah Anda Ingin Keluar (y/t) ? ";
                        cin>>ya_tidak;
                        if(ya_tidak =='y'||ya_tidak=='Y'){
                            cout<<"___________________________________________"<<endl;
                            cout<<"\t\   ANDA TELAH KELUAR ! ! ! "<<endl;
                            cout<<"___________________________________________"<<endl;
                            keluar=true;
                        }else{
                            system("cls");
                        }
                        break;
                    case 3:
                        hapusDepan();
                        cout<<"Apakah Anda Ingin Keluar (y/t) ? ";
                        cin>>ya_tidak;
                        cout<<endl<<endl;
                        if(ya_tidak =='y'||ya_tidak=='Y'){
                            cout<<"___________________________________________"<<endl;
                            cout<<"\t\   ANDA TELAH KELUAR ! ! ! "<<endl;
                            cout<<"___________________________________________"<<endl;
                            keluar=true;
                        }else{
                            system("cls");
                        }
                        break;
                    case 4:
                        hapusBelakang();
                        cout<<"Apakah Anda Ingin Keluar (y/t) ? ";
                        cin>>ya_tidak;
                        cout<<endl<<endl;
                        if(ya_tidak =='y'||ya_tidak=='Y'){
                            cout<<"___________________________________________"<<endl;
                            cout<<"\t\   ANDA TELAH KELUAR ! ! ! "<<endl;
                            cout<<"___________________________________________"<<endl;
                            keluar=true;
                        }else{
                            system("cls");
                        }
                        break;
                    case 5:
                        tampilData();
                        cout<<endl<<endl;
                        cout<<"Apakah Anda Ingin Keluar (y/t) ? ";
                        cin>>ya_tidak;
                        if(ya_tidak =='y'||ya_tidak=='Y'){
                            cout<<"___________________________________________"<<endl;
                            cout<<"\t\   ANDA TELAH KELUAR ! ! ! "<<endl;
                            cout<<"___________________________________________"<<endl;
                            keluar=true;
                        }else{
                            system("cls");
                        }
                        break;
                    case 6:
                        cout<<"Apakah Anda Ingin Keluar (y/t) ? ";
                        cin>>ya_tidak;
                        if(ya_tidak =='y'||ya_tidak=='Y'){
                            cout<<"___________________________________________"<<endl;
                            cout<<"\t\   ANDA TELAH LOGOUT ! ! ! "<<endl;
                            cout<<"___________________________________________"<<endl;
                            keluar=true;
                        }else{
                            system("cls");
                        }
                        break;
                    default:
                        cout<<"\t\ Pilihan Menu Tidak Tersedia !!!"<<endl;
                        cout<<"_____________________________________________________"<<endl;
                        cout<<"\t\ Apakah Anda Ingin Keluar (y/t) ? ";
                        cin>>ya_tidak;
                        cout<<endl<<endl;
                        if(ya_tidak =='y'||ya_tidak=='Y'){
                            cout<<"\t\========== Terima Kasih ==========="<<endl;
                            keluar=true;
                        }else{
                            system("cls");
                        }
                    }
                }while(keluar==false);
                break;
            case 3:
                suplier.kode_suplier;
                suplier.nama_suplier;
                suplier.alamat;
                suplier.kota;
                suplier.provinsi;
                suplier.telepon;
                nilai_awal();

                cout<<"__________________________________________________"<<endl;
                cout<<"\t\t"<<      " Input Data Supplier "                 <<endl;
                cout<<"__________________________________________________"<<endl<<endl;
                cout<<"Silahkan Masukkan Kode Suplier   : ";cin>>suplier.kode_suplier;
                cout<<"Silahkan Masukkan Nama Suplier   : ";cin>>suplier.nama_suplier;
                cout<<"Silahkan Masukkan Alamat         : ";cin>>suplier.alamat;
                cout<<"Silahkan Masukkan Kota           : ";cin>>suplier.kota;
                cout<<"Silahkan Masukkan Provinsi       : ";cin>>suplier.provinsi;
                cout<<"Silahkan Masukkan NO. Telepon    : ";cin>>suplier.telepon;
                cout<<"__________________________________________________"<<endl;
                cout<<endl<<endl;
                system("cls");
                cout<<"__________________________________________________"<<endl;
                cout<<"                 Data Suplier                "<<endl;
                cout<<"__________________________________________________"<<endl<<endl;
                cout<<"Kode         : "<<suplier.kode_suplier<<endl;
                cout<<"Nama         : "<<suplier.nama_suplier<<endl;
                cout<<"Alamat       : "<<suplier.alamat<<endl;
                cout<<"Kota         : "<<suplier.kota<<endl;
                cout<<"Provinsi     : "<<suplier.provinsi<<endl;
                cout<<"No.Telpon    : "<<suplier.telepon<<endl;
                cout<<"___________________________________________________"<<endl<<endl<<endl;

                cout<<"Apakah Anda Ingin Keluar (y/t) ? ";
                cin>>ya_tidak;
                if(ya_tidak =='y'||ya_tidak=='Y'){
                    cout<<"___________________________________________"<<endl;
                    cout<<"\t\   ANDA TELAH LOGOUT ! ! ! "<<endl;
                    cout<<"___________________________________________"<<endl;
                    keluar=true;
                }else{
                    system("cls");
                }
                break;
            case 4:
                menu4();
                break;


            case 5:
                break;
        default:
            cout<<"\t\ Pilihan Menu Tidak Tersedia !!!"<<endl;
            cout<<"_____________________________________________________"<<endl;
            cout<<"\t\ Apakah Anda Ingin Keluar (y/t) ? ";
            cin>>ya_tidak;
            cout<<endl<<endl;
            if(ya_tidak =='y'||ya_tidak=='Y'){
                cout<<"\t\========== Terima Kasih ==========="<<endl;
                keluar=true;
            }else{
                system("cls");
                menu_utama();
                }
            }
        }while(keluar==false);

    return 0;

}






