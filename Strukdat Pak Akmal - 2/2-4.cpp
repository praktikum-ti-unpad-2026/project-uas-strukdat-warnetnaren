#include <iostream>
using namespace std;

struct Mahasiswa {
    string npm;
    string nama;
    float nilai;
};

const int MAX = 100;


void inputData(Mahasiswa m[], int &n) {
    cout << "Jumlah mahasiswa: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i+1 << endl;
        cout << "Nama   : ";
        cin >> m[i].nama;
        cout << "NPM  : ";
        cin >> m[i].npm;
        cout << "Nilai : ";
        cin >> m[i].nilai;
    }
}


void outputData(Mahasiswa m[], int n) {
    cout << "\n=== DATA MAHASISWA ===\n";
    for(int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i+1 << endl;
        cout << "Nama   : " << m[i].nama << endl;
        cout << "NPM  : " << m[i].npm << endl;
        cout << "Nilai : " << m[i].nilai << endl;
    }
}

int main() {
    Mahasiswa mhs[MAX];
    int n;

    inputData(mhs, n);
    outputData(mhs, n);

    return 0;
}