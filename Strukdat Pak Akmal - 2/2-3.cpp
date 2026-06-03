#include <iostream>
using namespace std;

const int MAX = 10;


void inputMatriks(int A[][MAX], int r, int c) {
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++) {
            cout << "Elemen [" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
}


void cetakMatriks(int A[][MAX], int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}


void tambahMatriks(int A[][MAX], int B[][MAX], int C[][MAX], int r, int c) {
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            C[i][j] = A[i][j] + B[i][j];
}


void kaliMatriks(int A[][MAX], int B[][MAX], int C[][MAX], int r1, int c1, int c2) {
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for(int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int r1, c1, r2, c2;

    cout << "Masukkan baris dan kolom Matriks A: ";
    cin >> r1 >> c1;

    cout << "Masukkan baris dan kolom Matriks B: ";
    cin >> r2 >> c2;

    cout << "\nInput Matriks A:\n";
    inputMatriks(A, r1, c1);

    cout << "\nInput Matriks B:\n";
    inputMatriks(B, r2, c2);

    
    if(r1 == r2 && c1 == c2) {
        tambahMatriks(A, B, C, r1, c1);
        cout << "\nHasil Penjumlahan:\n";
        cetakMatriks(C, r1, c1);
    } else {
        cout << "\nMatriks tidak bisa dijumlahkan (ukuran berbeda)\n";
    }

   
    if(c1 == r2) {
        kaliMatriks(A, B, C, r1, c1, c2);
        cout << "\nHasil Perkalian:\n";
        cetakMatriks(C, r1, c2);
    } else {
        cout << "\nMatriks tidak bisa dikalikan (kolom A != baris B)\n";
    }

    return 0;
}