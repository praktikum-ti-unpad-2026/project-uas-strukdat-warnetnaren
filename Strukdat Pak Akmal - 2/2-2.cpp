#include <iostream>
using namespace std;

const int MAX = 10;

void ipMatrix(int A[][MAX], int &r, int &c) {
    cout << "Jumlah baris: "; cin >> r;
    cout << "Jumlah kolom: "; cin >> c;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++) {
            cout << "A["<<i<<"]["<<j<<"] = ";
            cin >> A[i][j];
        }
}

void cetakMatrix(int A[][MAX], int r, int c) {
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}

void cariJmlhBaris(int A[][MAX], int r, int c, int hasil[]) {
    for(int i=0;i<r;i++){
        hasil[i]=0;
        for(int j=0;j<c;j++)
            hasil[i]+=A[i][j];
    }
}

void cariJmlhKolom(int A[][MAX], int r, int c, int hasil[]) {
    for(int j=0;j<c;j++){
        hasil[j]=0;
        for(int i=0;i<r;i++)
            hasil[j]+=A[i][j];
    }
}

void cetakarray(int arr[], int n) {
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int A[MAX][MAX], r, c;
    int jBaris[MAX], jKolom[MAX];

    ipMatrix(A,r,c);
    cetakMatrix(A,r,c);

    cariJmlhBaris(A,r,c,jBaris);
    cariJmlhKolom(A,r,c,jKolom);

    cout << "Jumlah tiap baris: ";
    cetakarray(jBaris,r);

    cout << "Jumlah tiap kolom: ";
    cetakarray(jKolom,c);
}