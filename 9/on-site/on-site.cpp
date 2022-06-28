// Nama : Fatkhurrohman Purnomo
// NIM : 21102125

#include <iostream>
#include <iomanip>


using namespace std;

///PROGRAM REPRESENTASI GRAPH DENGAN MATRIKS BERDASARKAN INPUT USER

//Deklarasi Global
int jumlahSimpul = 5;
string *dataSimpul; //digunakan untuk membuat array dinamis
int **dataBusur;    //digunakan untuk membuat array dinamis dua dimensi
bool cekMatriks = false;

//Buat Matriks Graph
void buatMatriks()
{
	dataSimpul = new string[jumlahSimpul];  //membuat array string dinamis

	//Membuat simpul dengan jumlah yang dimasukkan user
	dataBusur = new int*[jumlahSimpul]; //membuat pointer array integer dinamis
	dataBusur[0] = new int[jumlahSimpul * jumlahSimpul]; //inisialisasi ukuran elemen matriks

	for (int i = 1; i < jumlahSimpul; i++){
		dataBusur[i] = dataBusur[i-1] + jumlahSimpul;
	}
	cout << endl;

	//Membuat matriks 2 dimensi dengan ukuran sesuai masukan user
	//Proses input nama simpul
	cout << " Silahkan masukkan nama simpul " <<endl;    //input nama simpul sebanyak jumlah simpul

	for (int i = 0; i < jumlahSimpul; i++){
		cout << " Simpul " <<i+1<< setw(5) << " \t: ";
		cin >> dataSimpul[i];
	}
	cout << endl;

	//Proses input nilai busur (bobot)
	cout << " Silahkan masukkan bobot antar simpul" << endl;    //input bobot busur antar simpul

	for (int baris = 0; baris < jumlahSimpul; baris++){
		for (int kolom = 0; kolom < jumlahSimpul; kolom++){
			cout << " " <<  setw(5) << dataSimpul[baris] << setw(5) << "\t--> " << dataSimpul[kolom] << setw(5) <<"\t : ";  //input bobot sebagai baris dan kolom
			cin >> dataBusur[baris][kolom];
		}
	}
	cout << endl;
    cout << endl;


	//Inisialisasi Pengecekan Matriks
	cekMatriks = true;  //atur keberadaan matriks menjadi ada/true
}

//Tampil Matriks Graph
void tampilMatriks()
{
	if (cekMatriks){    //jika matriks ada (true)
	    cout << setw(14) << "DARI/KE" << setw(19);
		for (int i = 0; i < jumlahSimpul; i++){ //membuat kolom nama simpul
			cout  << dataSimpul[i] << setw(14);
		}
		cout << endl;
		cout << setw(14) << "==================================================================="<<endl;
		for (int baris = 0; baris < jumlahSimpul; baris++){ //membuat kolom bobot
		    cout << setw(14) << dataSimpul[baris] << setw(14);    //membuat baris nama simpul
			for (int kolom = 0; kolom < jumlahSimpul; kolom++){ //membuat baris bobot
				cout << dataBusur[baris][kolom] << setw(14);
			}
			cout << endl;
        cout << setw(14) << "==================================================================="<<endl;

		}
	}
	else{   //jika matriks belum ada (false)
	cout << " Tidak ada matriks" << endl;
	}
}

int main()
{
	cout << " Silahkan masukkan jumlah simpul : ";   //input jumlah simpul
	cin >> jumlahSimpul;

	buatMatriks();
	tampilMatriks();

	return 0;
}