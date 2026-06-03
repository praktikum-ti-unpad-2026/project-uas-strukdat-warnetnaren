#include <iostream>
using namespace std;


void input(int &n, int &r) {
    cout << "Masukkan n: ";
    cin >> n;
    cout << "Masukkan r: ";
    cin >> r;
}


long faktorialWhile(int n) {
    long hasil = 1;
    int i = 1;
    while (i <= n) {
        hasil *= i;
        i++;
    }
    return hasil;
}


long faktorialFor(int n) {
    long hasil = 1;
    for (int i = 1; i <= n; i++) {
        hasil *= i;
    }
    return hasil;
}


long permutasi(int n, int r) {
    return faktorialFor(n) / faktorialFor(n - r);
}


long kombinasi(int n, int r) {
    return faktorialFor(n) / (faktorialFor(n - r) * faktorialFor(r));
}


void output(long hasil) {
    cout << "Hasil = " << hasil << endl;
}


int main() {
    int pilih, n, r;

    do {
    cout << "=== MENU ===" << endl;
    cout << "1. Faktorial (While)" << endl;
    cout << "2. Faktorial (For)" << endl;
    cout << "3. Permutasi" << endl;
    cout << "4. Kombinasi" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih: ";
    cin >> pilih;

    switch (pilih) {
        case 1:
            cout << "Masukkan n: ";
            cin >> n;
            output(faktorialWhile(n));
            break;

        case 2:
            cout << "Masukkan n: ";
            cin >> n;
            output(faktorialFor(n));
            break;

        case 3:
            input(n, r);
            output(permutasi(n, r));
            break;

        case 4:
            input(n, r);
            output(kombinasi(n, r));
            break;

        case 5:
            cout << "Program Selesai" << endl;
            break;

        default:
            cout << "Pilihan tidak ada." << endl;

          }

    } while (pilih != 5);

    return 0;
}