#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string>

using namespace std;
//mengurutkan sesuai dg antrian barang
//apa sajayg akan dilakukan pengecekan oleh admid dalam 1 minggu kedepan
int maksimal_antrian_barang = 50;
bool keluar = false;
char ya_tidak;
int pilihan, pilih, pil;
string kode_barang, kode_rak;//dg memasukkan kode barang

int menu,jh, m_idx, cari, dataedite;//jh jumlah data

//prosedur menu login ke aplikasi
void menuLogin (){

string username;
int password;
int x=1;
const string user="in";
const int pass=21100;
int login=0;

    do{
        cout<<"=========================================="<<endl;
        cout<<"\tProgram Login Perpustakaan"<<endl;
        cout<<"=========================================="<<endl;
        cout<<"Username : ";
        cin>>username;
        cout<<"Password : ";
        cin>>password;
        cout<<endl;
        if(username==user&&password==pass){
           cout<< "\t===== Anda Berhasil Login ====="<<endl;
           x=4;
           login=1;
        }else{
           cout<<"USERNAME & PASSWORD Salah!\n"<<endl;
           x=x+1;
        }
    }while (x<=3);

    if(login !=1){
        cout<<"Mohon Maaf Akun Anda Telah Terblokir\n";
        cout<<"Anda Telah 3x Memasukan USERNAME & PASSWORD Yang Salah\n";
    }
}

//menu 1 (konsep Queue/antrian)
//menu list antrian barang yang akan di lakukan pengecekan dalam 1 minggu kedepan
//dicek berdasarkan antian barang yang dimasukkan terlebih dahulu
//jadi dicek secara berurutan berdasarkan antrian barang yang telah dimasukann
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

void masukkan_antrian_pengecekan(string kode_barang){//memasukkan kode barang  yg akan di cek dalam 1 minggu kedepan
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
        cout<<"Urutan Pengecekan Barang Untuk Satu Minggu Kedepan Sudah Penuh"<<endl;
    }
}

void hapus_antrian_pengecekan(){//jika barang telah di-cek oleh petugas maka data/kode barang bisa dihapus
    if(antrian_barang_kosong() == false){
        for(int x = urutan_pengecekan.depan; x <= urutan_pengecekan.belakang; x++){
        urutan_pengecekan.kodebr[x] = urutan_pengecekan.kodebr[x+1];
        }
        urutan_pengecekan.belakang--;
        cout<<"Satu Kode Barang Telah Terhapus "<<endl;
        cout<<endl;
    }else{
        cout<<"Tidak Terdapat Kode Barang Yang akan Di-cek "<<endl;
    }
}

void tampil_data_pengecekan(){
    if(antrian_barang_kosong() == false){
        for(int z = urutan_pengecekan.depan; z <= urutan_pengecekan.belakang; z++){
            cout<<urutan_pengecekan.kodebr[z]<<" ";
        }
        cout<<endl;
    }else{
        cout<<"Tidak Terdapat Kode Barang Yang akan Di-cek dalam Satu Minggu Kedepan "<<endl;
    }
}

//menu 2
//membuat tempat pelatakkan barang pada rak barang menggunakan double linkedlist
struct dlinkedlist_rak{
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
        cout<<"Kode Rak Yang Tersedia"<<endl<<endl;
        while(helper != NULL){
            cout<<helper->kode<<" ";
            helper = helper -> next;
        }
    }
}

//menu 3 (dengan Konsep struct)
//data supplier
//deklarasi variabel supplier berjenis array
struct{

    string id_suplier;
    string nama_suplier;
    string alamat;
    string telepon;
    char kode_suplier;

}suplier[4];


//prosedur pilihan pada menu utama
void menu_utama(){
    cout<<"\t\===============================================\n";
    cout<<"\t\|                                             |"<<endl;
    cout<<"\t\           MENU UTAMA  MANAJEMEN GUDANG    \n";
    cout<<"\t\|                                             |"<<endl;
    cout<<"\t\            TOKO ANEKA JAYA PURWOKERTO    \n";
    cout<<"\t\|                                             |"<<endl;
    cout<<"\t\===============================================\n";
    cout<<"\t\|                                             |"<<endl;
    cout<<"\t\  1. Mendata Urutan Barang Yang Akan Di-cek "    <<endl;
    cout<<"\t\|                                             |"<<endl;
    cout<<"\t\  2. Mendata Penempatan Barang Pada Rak Gudang "<<endl;
    cout<<"\t\|                                             |"<<endl;
    cout<<"\t\  3. Data Supplier                             "<<endl;
    cout<<"\t\|                                             |"<<endl;
    cout<<"\t\  4. Jarak Antar Gudang "<<endl;
    cout<<"\t\|                                             |"<<endl;
    cout<<"\t\  5. Logout  "<<endl;
    cout<<"\t\|                                             |"<<endl;
    cout<<"\t\===============================================\n";
    cout<<"\t\ Masukkan Pilihan Menu (1-4) : ";
    cin>>pilih;
    cout<<endl<<endl;

}

//menu 4 (konsep graph) jarak antar gudang
//deklarasikan variabel global
//deklarasikan variabel global
int jumlahSimpul = 5;
string *dataSimpul;//digunakan untuk membuat array dinamis
int **dataBusur;//digunakan untuk membuat array dinamis dua dimensi
bool cekMatrik = false;
int indeksPosisi, simpulSaatIni, simpulAsal, simpulTujuan, jarakSaatIni, jarakLama, jarakBaru;
int dikunjungi = 1;
int belumDikunjungi = 0;
int *jarakDiketahui;
int *kunjungan;

//buat matriks
void buatMatriks(){
    dataSimpul = new string[jumlahSimpul];
    dataBusur = new int*[jumlahSimpul];
    dataBusur[0] = new int[jumlahSimpul * jumlahSimpul];//inisiaisasi ukuran elemen array
    for(int i = 1; i < jumlahSimpul; i++){
            //ukuran matriks sesuai masukkan user
        dataBusur[i] = dataBusur[i-1] + jumlahSimpul;
    }
    //proses input nama simpul
    cout<<"Silahkan Masukkan Nama Gudang"<<endl;
    for(int i = 0; i < jumlahSimpul; i++){
        cout<<"Gudang "<<i+1<<" : ";
        cin>>dataSimpul[i];
    }//memberi nama simpul sesuai inputan user
    cout<<endl<<endl;
    //proses pemberian nilai busur (bobot)
    cout<<"Silahkan masukkan Jarak Antar Gudang"<<endl;
    for(int baris = 0; baris < jumlahSimpul; baris++){
        for(int kolom = 0; kolom < jumlahSimpul; kolom++){
            cout<<dataSimpul[baris]<<" --> "<<dataSimpul[kolom]<<" : ";//pemberian bobot sebagao baris dan kolom
            cin>> dataBusur[baris][kolom];
        }
    }
    cekMatrik = true;
    cout<<endl<<endl;
}

//menhitung jarak terdekat/lintasan terpendek
void hitungJarakTerdekat(){
    if(cekMatrik){
        jarakDiketahui = new int[jumlahSimpul];//mengecek apakah matriks sudah terisi
        kunjungan = new int[jumlahSimpul];
        for(int i = 0; i < jumlahSimpul; i++){
            jarakDiketahui[i] = 999; //Nilai 999 dianggap sebagai infinity atau tak hingga
            kunjungan[i] = belumDikunjungi;
         }
         kunjungan[simpulAsal] = dikunjungi;
         jarakDiketahui[simpulAsal] = 0;
         simpulSaatIni = simpulAsal;
         while(simpulSaatIni != simpulTujuan){
            jarakLama = 999;
            jarakSaatIni = jarakDiketahui[simpulSaatIni];
            for(int i = 0; i < jumlahSimpul; i++){
                if(kunjungan[i] == belumDikunjungi){
                    jarakBaru = jarakSaatIni + dataBusur[simpulSaatIni][i];
                    if(jarakBaru < jarakDiketahui[i]){
                        jarakDiketahui[i] = jarakBaru;
                    }
                    if(jarakDiketahui[i] < jarakLama){
                        jarakLama = jarakDiketahui[i];
                        indeksPosisi = i;
                    }
                }
            }
            simpulSaatIni = indeksPosisi;
            kunjungan[simpulSaatIni] = dikunjungi;
        }
        cout<<endl;
         cout<<"Jarak Derdekat Dari Gudang "<<simpulAsal<<" ke Gudang "<<simpulTujuan<<" Adalah "<<jarakDiketahui[simpulTujuan]<<endl;
         delete jarakDiketahui;
         delete kunjungan;
    }
}

//prosedur menampilakan metriks
void tampilMatriks(){
    if(cekMatrik){
        for(int i = 0; i < jumlahSimpul; i++){
            cout<<dataSimpul[i]<<" ";
         }
         cout<<endl;
         for(int baris = 0; baris < jumlahSimpul; baris++){
            for(int kolom = 0; kolom < jumlahSimpul; kolom++){
            cout<<dataBusur[baris][kolom]<<" ";
            }
            cout<<endl;
         }
     }else{
        cout<<"Tidak ada matriks"<<endl;
     }
}

int main(){

    int n = 0, nomor_barang = 1, kode_Barang;
    char kembali;
    menuLogin();
    stok:
    menu_utama();
    system ("cls") ;
    suplier[0].kode_suplier = 'A';
    suplier[0].id_suplier= "Sup01";
    suplier[0].nama_suplier = "Gunung Agung";
    suplier[0].alamat = "Jl.Merdeka Selatan,Semarang,Jawa Tengah";
    suplier[0].telepon = "082377541208";

    suplier[1].kode_suplier = 'B';
    suplier[1].id_suplier = "Sup02";
    suplier[1].nama_suplier = "Sumber Jaya";
    suplier[1].alamat = "Jl.Perjuangan,Subang,Jawa Barat";
    suplier[1].telepon = "082399900012";

    suplier[2].kode_suplier = 'C';
    suplier[2].id_suplier = "Sup03";
    suplier[2].nama_suplier = "Doa Ibu";
    suplier[2].alamat = "Jl.Mangga,Muara Bulian,Jambi";
    suplier[2].telepon = "0823456789120";

    suplier[3].kode_suplier = 'D';
    suplier[3].id_suplier = "Sup04";
    suplier[3].nama_suplier = "Tiga Saudara";
    suplier[3].alamat = "Jl.Pramuka,Bukittinggi,Sumatra Barat";
    suplier[3].telepon = "085346789000";

    suplier[4].kode_suplier = 'E';
    suplier[4].id_suplier = "Sup05";
    suplier[4].nama_suplier = "Maju Terus";
    suplier[4].alamat = "Jl.Semangat,Purwokerto,Jawa Tengah";
    suplier[4].telepon = "085377891200";

    switch(pilih){
        case 1:
            do{
                cout<<"========================================================="<<endl;
                cout<<"|                                                      |"<<endl;
                cout<<"\t"<<"Urutan Pengecekan Barang Dalam 1 Minggu"<<endl;
                cout<<"|                                                      |"<<endl;
                cout<<"\t"<<"       Toko Aneka Jaya Purwokerto       "<<endl;
                cout<<"========================================================="<<endl;
                cout<<"|                                                      |"<<endl;
                cout<<"| 1. Masukkan Jumlah Barang Yang Akan Di-cek           |"<<endl;
                cout<<"|                                                      |"<<endl;
                cout<<"_________________________________________________________"<<endl;
                cout<<"| 2. Masukkan Kode Barang Yang Akan Di-cek             |"<<endl;
                cout<<"|                                                      |"<<endl;
                cout<<"|                                                      |"<<endl;
                cout<<"_________________________________________________________"<<endl;
                cout<<"| 3. Hapus Kode Barang [Jika Telah Di-cek]             |"<<endl;
                cout<<"|                                                      |"<<endl;
                cout<<"|                                                      |"<<endl;
                cout<<"_________________________________________________________"<<endl;
                cout<<"|                                                      |"<<endl;
                cout<<"| 4. Tampilkan Urutan Kode Barang Yang Akan Di-cek     |"<<endl;
                cout<<"|                                                      |"<<endl;
                cout<<"__________________________________________________________"<<endl;
                cout<<"|                                                      |"<<endl;
                cout<<"| 5. Kembali Kemenu Utama                              |"<<endl;
                cout<<"|                                                      |"<<endl;
                cout<<"__________________________________________________________"<<endl;
                cout<<"Masukkan Pilihan Menu (1-5) : ";
                cin>>pilihan;
                cout<<endl<<endl;
                switch(pilihan){

                case 1 :
                    cout<<"Masukkan Jumlah  Barang Yang Akan Di-Cek  : ";
                    cin>>maksimal_antrian_barang;
                    cout<<endl<<endl;
                    cout<<"__________________________________________________________________________________"<<endl;
                    cout<<"\t\Pengaturan Jumlah Pengecekan Barang Untuk 1 Minggu Kedepan Selesai"<<endl;
                    cout<<"__________________________________________________________________________________"<<endl<<endl;

                    cout<<"\t\              Apakah Anda Ingin Logout (y/t) ? ";
                    cin>>ya_tidak;
                    if(ya_tidak == 'y' || ya_tidak == 'Y'){
                        cout<<"__________________________________________________________________________________"<<endl;
                        cout<<"\t\              ANDA TELAH LOGOUT ! ! ! "<<endl;
                        cout<<"__________________________________________________________________________________"<<endl;
                        keluar = true;
                    }else{
                        system("cls");
                    }
                    break;

                case 2 :
                    cout<<"Silahkan Masukkan Kode Barang  : ";
                    cin>>kode_barang;
                    cout<<"__________________________________________________________"<<endl;
                    masukkan_antrian_pengecekan(kode_barang);
                    cout<<endl;
                    cout<<"Apakah Anda Ingin Logout (y/t) ? ";
                    cin>>ya_tidak;
                    cout<<endl<<endl;
                    if(ya_tidak == 'y' || ya_tidak == 'Y'){
                        cout<<"______________________________________________________"<<endl;
                        cout<<"\t\   ANDA TELAH LOGOUT ! ! ! "<<endl;
                        cout<<"_______________________________________________________"<<endl;
                        keluar = true;
                    }else{
                        system("cls");
                    }
                    break;

                case 3 :
                    hapus_antrian_pengecekan();
                    cout<<"___________________________________________"<<endl<<endl;
                    cout<<"Apakah Anda Ingin Logout (y/t) ? ";
                    cin>>ya_tidak;
                    if(ya_tidak == 'y' || ya_tidak == 'Y'){
                        cout<<"\t\   ANDA TELAH LOGOUT ! ! ! "<<endl;
                        keluar = true;
                    }else{
                        system("cls");
                    }
                    break;

                case 4 :
                    cout<<"Berikut Urutan Kode Barang Yang Akan Dilakukan Pengecekan  "<<endl<<endl;
                    tampil_data_pengecekan();
                    cout<<"___________________________________________________________"<<endl<<endl;
                    cout<<"Apakah Anda Ingin Logout (y/t) ? ";
                    cin>>ya_tidak;
                    if(ya_tidak == 'y' || ya_tidak == 'Y'){
                        cout<<"___________________________________________"<<endl;
                        cout<<"\t\   ANDA TELAH LOGOUT ! ! ! "<<endl;
                        cout<<"___________________________________________"<<endl;
                        keluar = true;
                    }else{
                        system("cls");
                    }
                    break;

                case 5 :
                    cout<<"Apakah Anda Ingin Kemenu Utama (y/t) ? ";
                    cin>>ya_tidak;
                    if(ya_tidak =='y'||ya_tidak=='Y'){
                        system("cls");
                        goto stok;
                    }else{
                        system("cls");
                        cout<<"___________________________________________"<<endl;
                        cout<<"\t\   ANDA TELAH lOGOUT ! ! ! "<<endl;
                        cout<<"___________________________________________"<<endl;
                        keluar=true;
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
                    cout<<"|                                            |"<<endl;
                    cout<<"\t"<<"Pendataan Persediaan Rak Barang"<<endl;
                    cout<<"|                                            |"<<endl;
                    cout<<"=============================================="<<endl;
                    cout<<" 1. Tambahkan Barang di Rak Depan"<<endl;
                    cout<<"|                                            |"<<endl;
                    cout<<" 2. Tambahkan Barang di Rak Belakang"<<endl;
                    cout<<"|                                            |"<<endl;
                    cout<<" 3. Kosongkan Rak Barang Dari Depan"<<endl;
                    cout<<"|                                            |"<<endl;
                    cout<<" 4. Kosongkan Rak Barang Dari Belakang"<<endl;
                    cout<<"|                                            |"<<endl;
                    cout<<" 5. Tampilkan Rak Barang Yang Tersedia"<<endl;
                    cout<<"|                                            |"<<endl;
                    cout<<" 6. Kembali Kemenu Utama"<<endl;
                    cout<<"|                                            |"<<endl;
                    cout<<"=============================================="<<endl;
                    cout<<"Silahkan Masukkan Pilihan Anda [1-6] : ";
                    cin>>pilihan;
                    cout<<endl<<endl;

                    switch(pilihan){
                    case 1:
                        cout<<"Silahkan Masukkan Kode Rak Dari Depan : ";
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
                        cout<<"Silahkan Masukkan Kode Rak Dari Belakang  : ";
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
                        cout<<"Apakah Anda Ingin Kemenu Utama (y/t) ? ";
                        cin>>ya_tidak;
                        if(ya_tidak =='y'||ya_tidak=='Y'){
                            system("cls");
                            goto stok;
                        }else{
                            system("cls");
                            cout<<"___________________________________________"<<endl;
                            cout<<"\t\   ANDA TELAH lOGOUT ! ! ! "<<endl;
                            cout<<"___________________________________________"<<endl;
                            keluar=true;
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
                do{
                    cout<<"========================================================"<<endl;
                    cout<<"|                                                       |"<<endl;
                    cout<<"\t\t"<<                   " Data Supplier "                 <<endl;
                    cout<<"|                                                       |"<<endl;
                    cout<<"========================================================"<<endl;
                    cout<<"|                                                       |"<<endl;
                    cout<<" 1. Gunung Agung  "<<endl;
                    cout<<"|                                                       |"<<endl;
                    cout<<" 2. Sumber Jaya   "<<endl;
                    cout<<"|                                                       |"<<endl;
                    cout<<" 3. Doa Ibu       "<<endl;
                    cout<<"|                                                       |"<<endl;
                    cout<<" 4. Tiga Saudara  "<<endl;
                    cout<<"|                                                       |"<<endl;
                    cout<<" 5. Maju Terus    "<<endl;
                    cout<<"|                                                       |"<<endl;
                    cout<<" 6. Kembali Kemenu Utama        "<<endl;
                    cout<<"|                                                       |"<<endl;
                    cout<<"========================================================"<<endl;
                    cout<<" Silahkan Masukkan Pilihan Anda [1-6] : ";
                    cin>>pilihan;
                    cout<<endl<<endl;

                    if(pilihan == 1){
                        cout<<"_________________________________________________________"<<endl<<endl;
                        cout<<"kode Suplier : "<<suplier[0].kode_suplier<<endl;
                        cout<<"Id Suplier   : "<<suplier[0].id_suplier<<endl;
                        cout<<"Nama Suplier : "<<suplier[0].nama_suplier<<endl;
                        cout<<"Alamat       : "<<suplier[0].alamat<<endl;
                        cout<<"Telepon      : "<<suplier[0].telepon<<endl;
                        cout<<"_________________________________________________________"<<endl<<endl;
                        cout<<endl<<endl<<endl;
                    }
                    else if (pilihan == 2){
                        cout<<"_________________________________________________________"<<endl<<endl;
                        cout<<"kode Suplier : "<<suplier[1].kode_suplier<<endl;
                        cout<<"Id Suplier   : "<<suplier[1].id_suplier<<endl;
                        cout<<"Nama Suplier : "<<suplier[1].nama_suplier<<endl;
                        cout<<"Alamat       : "<<suplier[1].alamat<<endl;
                        cout<<"Telepon      : "<<suplier[1].telepon<<endl;
                        cout<<"_________________________________________________________"<<endl<<endl;
                        cout<<endl<<endl<<endl;
                    }
                    else if (pilihan == 3){
                        cout<<"_________________________________________________________"<<endl<<endl;
                        cout<<"kode Suplier : "<<suplier[2].kode_suplier<<endl;
                        cout<<"Id Suplier   : "<<suplier[2].id_suplier<<endl;
                        cout<<"Nama Suplier : "<<suplier[2].nama_suplier<<endl;
                        cout<<"Alamat       : "<<suplier[2].alamat<<endl;
                        cout<<"Telepon      : "<<suplier[2].telepon<<endl;
                        cout<<"_________________________________________________________"<<endl<<endl;
                        cout<<endl<<endl<<endl;
                    }
                    else if (pilihan == 4){
                        cout<<"_________________________________________________________"<<endl<<endl;
                        cout<<"kode Suplier : "<<suplier[3].kode_suplier<<endl;
                        cout<<"Id Suplier   : "<<suplier[3].id_suplier<<endl;
                        cout<<"Nama Suplier : "<<suplier[3].nama_suplier<<endl;
                        cout<<"Alamat       : "<<suplier[3].alamat<<endl;
                        cout<<"Telepon      : "<<suplier[3].telepon<<endl;
                        cout<<"_________________________________________________________"<<endl<<endl;
                        cout<<endl<<endl<<endl;
                    }
                    else if (pilihan == 5){
                        cout<<"_________________________________________________________"<<endl<<endl;
                        cout<<"kode Suplier : "<<suplier[4].kode_suplier<<endl;
                        cout<<"Id Suplier   : "<<suplier[4].id_suplier<<endl;
                        cout<<"Nama Suplier : "<<suplier[4].nama_suplier<<endl;
                        cout<<"Alamat       : "<<suplier[4].alamat<<endl;
                        cout<<"Telepon      : "<<suplier[4].telepon<<endl;
                        cout<<"_________________________________________________________"<<endl<<endl;
                        cout<<endl<<endl<<endl;
                    }
                   else if (pilihan == 6){
                        cout<<"Apakah Anda Ingin Kemenu Utama (y/t) ? ";
                        cin>>ya_tidak;
                        if(ya_tidak =='y'||ya_tidak=='Y'){
                            system("cls");
                            goto stok;
                        }else{
                            system("cls");
                            cout<<"___________________________________________"<<endl;
                            cout<<"\t\   ANDA TELAH lOGOUT ! ! ! "<<endl;
                            cout<<"___________________________________________"<<endl;
                            keluar=true;
                        }
                   }
                    else{
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
            case 4:
                char keluar;
                cout<<"Silahkan Masukkan Jumlah Gudang  : ";
                cin>>jumlahSimpul;
                cout<<endl<<endl;
                //memanggil prosedur buat metriks
                buatMatriks();
                //memanggil prosedur tampil matriks
                tampilMatriks();
                cout<<endl<<endl;
                cout<<"Silahkan Masukkan Gudang Asal (0 - "<<jumlahSimpul-1<<") : ";
                cin>>simpulAsal;
                cout<<"Silahkan Masukkan Gudang Tujuan (0 - "<<jumlahSimpul-1<<") : ";
                cin>>simpulTujuan;
                cout<<endl;
                cout<<"===================================================================="<<endl;
                //memanggil prosedur hitung jarak terdekat
                hitungJarakTerdekat();
                cout<<endl<<endl;
                cout<<"Apakah Anda Ingin Kemenu Utama (y/t) ? ";
                cin>>ya_tidak;
                if(ya_tidak =='y'||ya_tidak=='Y'){
                    system("cls");
                    goto stok;
                }else{
                    cout<<"___________________________________________"<<endl;
                    cout<<"\t\   ANDA TELAH lOGOUT ! ! ! "<<endl;
                    cout<<"___________________________________________"<<endl;
                    keluar=true;
                }
                break;
            case 5:
                cout<<"Apakah Anda Ingin Logout (y/t) ? ";
                cin>>ya_tidak;
                if(ya_tidak =='y'||ya_tidak=='Y'){
                     cout<<"___________________________________________"<<endl;
                    cout<<"\t\   ANDA TELAH lOGOUT ! ! ! "<<endl;
                    cout<<"___________________________________________"<<endl;
                    keluar=true;
                }else{
                    system("cls");
                    goto stok;
                }
                break;
        default:
            cout<<"\t\ Pilihan Menu Tidak Tersedia !!!"<<endl;
            cout<<"_____________________________________________________"<<endl;
            cout<<"Apakah Anda Ingin Kemenu Utama (y/t) ? ";
            cin>>ya_tidak;
            if(ya_tidak =='y'||ya_tidak=='Y'){
                system("cls");
                goto stok;
            }else{
                system("cls");
                cout<<"___________________________________________"<<endl;
                cout<<"\t\   ANDA TELAH lOGOUT ! ! ! "<<endl;
                cout<<"___________________________________________"<<endl;
                keluar=true;
            }
        break;
        }


    return 0;
}






