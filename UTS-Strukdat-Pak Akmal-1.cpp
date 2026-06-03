#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 100;

struct pegawai {
    string NIP;
    string nama;
    int gol;
};

typedef pegawai* ptr;

void data(int &n){
    cout << "Berapa data : "; cin >> n;
}

void inputData(ptr a, int &n){
    data(n);
    for(int i=0;i<n;i++){
        cout << "Data ke-" << i+1 << endl;
        cout << "Masukkan NIP : "; cin >> (a+i)->NIP;
        cout << "Masukkan Nama : "; cin >> (a+i)->nama;
        cout << "Masukkan Gol : "; cin >> (a+i)->gol;
    }
}

int gaji(ptr a){
    int gaji = 0;
    if(a->gol == 1){
        gaji = 3000000;
    }
    else if(a->gol == 2){
        gaji = 4000000;
    }
    else if(a->gol == 3){
        gaji = 5000000;
    }
    return gaji;
}

int tunjangan(ptr a){
    int tunjangan = 0;
    if(a->gol == 1){
        tunjangan = gaji(a) * 1;
    }
    else if(a->gol == 2){
        tunjangan = gaji(a) * 1.25;
    }
    else if(a->gol == 3){
        tunjangan = gaji(a) * 1.5;
    }
    return tunjangan;
}

int total(ptr a){
    int total;
    return total = gaji(a) + tunjangan(a);
}

int jumlahGaji(ptr a, int n){
    int total = 0;
    for(int i=0;i<n;i++){
        total += gaji((a+i));
    }
    return total;
}

int jumlahTunjangan(ptr a, int n){
    int total = 0;
    for(int i=0;i<n;i++){
        total += tunjangan((a+i));
    }
    return total;
}

int jumlahTotal(ptr a, int n){
    int jumlah = 0;
    for(int i=0;i<n;i++){
        jumlah += total((a+i));
    }
    return jumlah;
}

int mean(ptr a, int n){
    if(n == 0){
        return 0;
    }
    int total = jumlahTotal(a,n);
    int mean = total/n;
    return mean;
}

void output(ptr a, int n){
    cout << left
         << setw(5) << "No"
         << setw(10) << "NIP"
         << setw(20) << "Nama"
         << setw(5) << "Gol"
         << setw(15) << "Gaji"
         << setw(15) << "Tunjangan"
         << setw(15) << "Total" << endl;

    int no = 1;
    for(int i=0;i<n;i++){
        cout << left
             << setw(5) << no++
             << setw(10) << (a+i)->NIP
             << setw(20) << (a+i)->nama
             << setw(5) << (a+i)->gol
             << setw(15) << gaji((a+i))
             << setw(15) << tunjangan((a+i))
             << setw(15) << total((a+i)) << endl;
    }

    cout << left
         << setw(10) << "Jumlah : "
         << setw(30) << " "
         << setw(15) << jumlahGaji(a,n) 
         << setw(15) << jumlahTunjangan(a,n)
         << setw(15) << jumlahTotal(a,n)
         << endl;
    cout << "Rata-rata gaji total : " << mean(a,n) << endl;
}

void search(ptr a, int n, int &found, int &index, string key){
    index = -1;
    found = 0;
    int i = 0;
    while(found == 0 && i < n){
        if((a+i)->NIP == key){
            found = 1;
            index = i;
        }
        else {
            i++;
        }
    }
}

void tambahData(ptr a, int &n, string key){
    if(n >= MAX){
        cout << "Array penuh" << endl;
        return;
    }
    int found;
    int index;
    search(a, n, found, index, key);
    if(found){
        for(int i = n; i > index + 1; i--){
            *(a+i) = *(a+i-1);
        }

        cout << "Masukkan data baru" << endl;
        cout << "Masukkan NIP : "; cin >> (a+index+1)->NIP;
        cout << "Masukkan Nama : "; cin >> (a+index+1)->nama;
        cout << "Masukkan gol : "; cin >> (a+index+1)->gol;

        n++;
    }
    else {
        cout << "Data tidak ditemukan" << endl;
    }
}

void hapusData(ptr a, int &n, string key){
    int found;
    int index;
    search(a, n, found, index, key);
    if(found){
        for(int i=index; i<n-1;i++){
            *(a+i) = *(a+i+1);
        }
        n--;
    }
    else {
        cout << "Data tidak ditemukan" << endl;
    }
}

void menu(ptr a, int &n, string key){
    int pilih;
    do {
        cout << "1. Input data sebanyak n buah\n"
             << "2. Input data setelah data\n"
             << "3. Hapus data setelah data\n"
             << "4. Output\n"
             << "0. Keluar\n"
             << "\nPilih(0-4)\n";
    
        cin >> pilih;

        switch(pilih){
            case 1:
            inputData(a,n);
            break;

            case 2:
            cout << "Masukkan kunci : "; cin >> key;
            tambahData(a,n,key);
            break;

            case 3:
            cout << "Masukkan kunci : "; cin >> key;
            hapusData(a, n, key);
            break;

            case 4:
            output(a,n);
            break;
        }
    }
    while(pilih != 0);
}

int main(){
    pegawai arr[MAX];
    ptr a = arr;
    int n;
    string key;

    menu(a,n,key);

}