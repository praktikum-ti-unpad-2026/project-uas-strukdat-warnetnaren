#include <iostream>
using namespace std;

struct Mahasiswa {
 char NPM[8];
 char nama[20];
 int nilai;
};

typedef Mahasiswa* PointerToMhs;
void inputData(PointerToMhs &mhs){
 cout << "Masukkan NPM : ";
 cin >> mhs->NPM;

 cout << "Masukkan Nama : ";
 cin >> mhs->nama;

 cout << "Masukkan Nilai : ";
 cin >> mhs->nilai;

    }
void outputData(PointerToMhs mhs){
 cout << "\nData Mahasiswa\n";
 cout << "NPM : " << mhs->NPM << endl;
 cout << "Nama : " << mhs->nama << endl;
 cout << "Nilai : " << mhs->nilai << endl;

    }
int main()  {
 
    PointerToMhs p, q;
 p = new Mahasiswa;
 q = new Mahasiswa;
 cout << "Input Data Mahasiswa 1\n";
 inputData(p);
 cout << "\nInput Data Mahasiswa 2\n";
 inputData(q);
 cout << "\nOutput Mahasiswa 1";
 outputData(p);
 cout << "\nOutput Mahasiswa 2";
 outputData(q);
 return 0;

}