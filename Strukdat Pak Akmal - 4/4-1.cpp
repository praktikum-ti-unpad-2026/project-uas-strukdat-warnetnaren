#include <iostream>
using std::cout;
using std::cin;
using std::string;

struct barang{
    int kodeBarang;
    string namaBarang;
    int jumlahBarang;
    float hargaBarang;
};

typedef barang data[100];
data brg;

void input(int &n, data& brg){
    cout << "Berapa banyak barang yang mau diinput? ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "\nData barang ke-" << i+1 << "\n";

        cout << "Masukkan kode barang : ";
        cin >> brg[i].kodeBarang;

        cout << "Masukkan nama barang : ";
        cin >> brg[i].namaBarang;

        cout << "Masukkan jumlah barang : ";
        cin >> brg[i].jumlahBarang;

        cout << "Masukkan harga barang : ";
        cin >> brg[i].hargaBarang;
    }
}

void sorting(int n, data& brg){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(brg[i].kodeBarang > brg[j].kodeBarang){
                barang temp = brg[i];
                brg[i] = brg[j];
                brg[j] = temp;
            }
        }
    }
}

void tampil(int n, data& brg){

    cout << "\nDaftar Barang PT Informatika\n";
    cout << "No   Kode   Nama   Harga   Banyak   Jumlah\n";

    for(int i=0;i<n;i++){

        int jumlah = brg[i].hargaBarang * brg[i].jumlahBarang;

        cout << i+1 << "    "
             << brg[i].kodeBarang << "    "
             << brg[i].namaBarang << "    "
             << brg[i].hargaBarang << "    "
             << brg[i].jumlahBarang << "    "
             << jumlah << "\n";
    }
}

void statistik(int n, data& brg){

    float max = brg[0].hargaBarang;
    float min = brg[0].hargaBarang;
    float totalHarga = 0;
    float totalJumlah = 0;

    for(int i=0;i<n;i++){

        if(brg[i].hargaBarang > max)
            max = brg[i].hargaBarang;

        if(brg[i].hargaBarang < min)
            min = brg[i].hargaBarang;

        totalHarga += brg[i].hargaBarang;
        totalJumlah += brg[i].hargaBarang * brg[i].jumlahBarang;
    }

    float rata = totalHarga / n;

    cout << "\nJumlah Total : " << totalJumlah << "\n";
    cout << "Harga Tertinggi : " << max << "\n";
    cout << "Harga Terendah : " << min << "\n";
    cout << "Rata-rata harga : " << rata << "\n";
}

void searching(int n, data& brg){

    int key;
    cout << "\nMasukkan kode barang yang dicari: ";
    cin >> key;

    int i = 0;
    bool ketemu = false;

    while(i < n && !ketemu){

        if(brg[i].kodeBarang == key){
            ketemu = true;
        }
        else{
            i++;
        }
    }

    if(ketemu){
        cout << "\nBarang ditemukan\n";
        cout << "Kode : " << brg[i].kodeBarang << "\n";
        cout << "Nama : " << brg[i].namaBarang << "\n";
        cout << "Harga : " << brg[i].hargaBarang << "\n";
        cout << "Jumlah : " << brg[i].jumlahBarang << "\n";
    }
    else{
        cout << "\nBarang tidak ditemukan\n";
    }
}

void output(int n, data& brg){
    tampil(n, brg);
    statistik(n, brg);
}

int main(){

    int n;

    input(n, brg);
    sorting(n, brg);
    output(n, brg);
    searching(n, brg);

}