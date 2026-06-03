#include <iostream>
using namespace std;

struct Tanggal {
    int hari;
    int bulan;
    int tahun;
};


int keHari(Tanggal t) {
    return (t.tahun * 365) + (t.bulan * 30) + t.hari;
}


int selisihTanggal(Tanggal t1, Tanggal t2) {
    int total1 = keHari(t1);
    int total2 = keHari(t2);

    if(total1 > total2)
        return total1 - total2;
    else
        return total2 - total1;
}

int main() {
    Tanggal t1, t2;

    cout << "Tanggal 1 (hari bulan tahun): ";
    cin >> t1.hari >> t1.bulan >> t1.tahun;

    cout << "Tanggal 2 (hari bulan tahun): ";
    cin >> t2.hari >> t2.bulan >> t2.tahun;

    int hasil = selisihTanggal(t1, t2);

    cout << "\nSelisih hari: " << hasil << " hari" << endl;

    return 0;
}