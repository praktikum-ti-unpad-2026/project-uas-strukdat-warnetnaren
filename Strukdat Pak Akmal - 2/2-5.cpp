#include <iostream>
using namespace std;

struct Waktu {
    int jam;
    int menit;
    int detik;
};


int keDetik(Waktu w) {
    return (w.jam * 3600) + (w.menit * 60) + w.detik;
}


Waktu selisihWaktu(Waktu w1, Waktu w2) {
    int total1 = keDetik(w1);
    int total2 = keDetik(w2);

    int selisih = abs(total1 - total2);

    Waktu hasil;
    hasil.jam = selisih / 3600;
    selisih %= 3600;

    hasil.menit = selisih / 60;
    hasil.detik = selisih % 60;

    return hasil;
}

int main() {
    Waktu w1, w2, hasil;

    cout << "Waktu 1 (jam menit detik): ";
    cin >> w1.jam >> w1.menit >> w1.detik;

    cout << "Waktu 2 (jam menit detik): ";
    cin >> w2.jam >> w2.menit >> w2.detik;

    hasil = selisihWaktu(w1, w2);

    cout << "\nSelisih waktu: "
         << hasil.jam << " jam "
         << hasil.menit << " menit "
         << hasil.detik << " detik" << endl;

    return 0;
}