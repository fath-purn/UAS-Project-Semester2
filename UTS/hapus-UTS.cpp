#include <iostream>

using namespace std;

int main() {

	string daftar[2][7]={{"Nama\t\t","Deva Aprilia\t","Naeli Fitria Rokhmawati","Sadewa Anla Handika", "Safira Anggraeni Irawan","Varrel Bramasta Nugraha", "Yuni Nur Fari'ah"},
                    {"NIM\t","20102082","20102081","20102161","20102162","20102201","20102208"}};
    string *p;

	for (int k=0;k<1;k++){
		for (int b=0;b<2;b++){
			cout<<daftar[b][k]<<"\t\t" << "Alamat\t" << "\t\t";
		}
		cout << endl;
	}

	for (int k=1;k<7;k++){
		for (int b=0;b<2;b++){
            p = &daftar[b][k];
			cout<<daftar[b][k]<<"\t\t" << p <<"\t\t";
		}
		cout << endl;
	}
return 0;

}