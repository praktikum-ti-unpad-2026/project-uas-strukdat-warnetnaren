#include <iostream>
#include <cmath>
using namespace std;


void input(int &panjang, int &lebar) {
    cout << "Masukan panjang: ";
    cin >> panjang;

    cout << "Masukan lebar: ";
    cin >> lebar;
}


int hitungluas(int p, int l) {
    return p * l;
}


int hitungkeliling(int p, int l) {
    return 2 * (p + l);
}


void hitungdiagonal(int p, int l) {
    double d = sqrt(p*p + l*l);
    cout << "Diagonal = " << d << endl;
}

int main() {
    int panjang, lebar;

    input(panjang, lebar);

    cout << "Luas = " << hitungluas(panjang, lebar) << endl;
    cout << "Keliling = " << hitungkeliling(panjang, lebar) << endl;

    hitungdiagonal(panjang, lebar);

    return 0;
}