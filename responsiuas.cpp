#include<iostream>
#include<cstdio>
using namespace std;

const int MAX=100;

struct penerbangan{
	string kode;
	string maskapai;
	string nama;
	string jamkeberangkatan;
	string jamkedatangan;
	string asal;
	string tujuan;
	string tanggal;
	int harga;
};

int main(){
	penerbangan data[MAX];
	int jumlah,pilih;
	
	cout<<"PEMESANAN TIKET PESAWAT\n";
	cout<<"1. Penerbangan berdasarkan rute penerbangan\n";
	cout<<"2. Penerbangan berdasarkan maskapai penerbangan\n";
	cout<<"3. Penerbangan berdasarkan harga termahal hingga termurah\n";
	cout<<"4. Penerbangan berdasarkan harga termurah hingga termahal\n";
	cout<<"5. Pemesanan Tiket\n";
	cout<<"Pilih : ";
	cin>>pilih;
	
	cout<<"\njumlah tiket yang di pesan: ";
	cin>>jumlah;
	cin.ignore();
	for(int i=0; i<jumlah; i++){
		cout<<"\ndata pemesana tiket ke-"<<i+1<<" :\n";
		cout<<"Nama 			:";
		getline(cin,data[i].nama);
		cout<<"Tanggal			: ";
		getline(cin,data[i].tanggal);
		cout<<"Maskapai 		: ";
		getline(cin,data[i].maskapai);
		cout<<"kode pesawat		: ";
		getline(cin,data[i].kode);
		cout<<"Bandara Asal		:";
		getline(cin,data[i].asal);
		cout<<"Bandara Tujuan		: ";
		getline(cin,data[i].tujuan);
		cout<<"Jam Keberangkatan	:";
		getline(cin,data[i].jamkeberangkatan);
		cout<<"Jam Kedatangan		:";
		getline(cin,data[i].jamkedatangan);
		cout<<"Harga Tiket 		:";
		cin>>data[i].harga;
		cin.ignore();
	}
	
	FILE*file=fopen("data_penumpang.txt","w");
	if(file==NULL){
		cout<<"data tidak dapat tersimpan";
		return 1;
	}
	for(int i=0; i<jumlah; i++){
		fprintf(file,"\nNama	: %s\n",data[i].nama.c_str());
		fprintf(file,"Maskapai	: %s\n",data[i].maskapai.c_str());
		fprintf(file,"Rute	: %s-%s\n", data[i].asal.c_str(),data[i].tujuan.c_str());
		fprintf(file,"Tanggal	: %s\n",data[i].tanggal.c_str());
		fprintf(file,"Jam Keberangkatan: %s\n",data[i].jamkeberangkatan.c_str());
	}	
	fclose(file);
		cout<<"data telah tersimpan di file 'data_penumpang.txt'";
		return 0;
	
}
