#include <iostream>
using namespace std;

void opdata(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int nilaitertinggi(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > max) max = arr[i];
    return max;
}

int nilaiterendah(int arr[], int n) {
    int min = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] < min) min = arr[i];
    return min;
}

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-1-i; j++)
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

int linearsearch(int arr[], int n, int cari) {
    for(int i = 0; i < n; i++)
        if(arr[i] == cari)
            return i;
    return -1;
}

int main() {
    int arr[] = {12, 7, 25, 10, 3, 18, 5, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Data awal: ";
    opdata(arr, n);

    cout << "Nilai tertinggi: " << nilaitertinggi(arr, n) << endl;
    cout << "Nilai terendah : " << nilaiterendah(arr, n) << endl;

    bubbleSort(arr, n);

    cout << "Setelah sorting: ";
    opdata(arr, n);

    int cari = 25;
    int hasil = linearsearch(arr, n, cari);

    if(hasil != -1)
        cout << "Ditemukan di index ke-" << hasil << endl;
    else
        cout << "Tidak ditemukan\n";

    return 0;
}