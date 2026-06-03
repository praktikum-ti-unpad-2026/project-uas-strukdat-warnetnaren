/*
Nama: Kian Islam Susanto
Kelas: B
Tanggal Pengerjaan: 29 April 2026
*/


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_LIMIT = 100;

struct Pegawai {
    string nip;
    string nama;
    int golongan;
};

long getGajiPokok(int gol) {
    if (gol == 1) return 3000000;
    if (gol == 2) return 4000000;
    if (gol == 3) return 5000000;
    return 0;
}

long getTunjangan(int gol) {
    long gapok = getGajiPokok(gol);
    if (gol == 1) return gapok * 1;
    if (gol == 2) return gapok * 1.25;
    if (gol == 3) return gapok * 1.5;
    return 0;
}

void cariIndex(Pegawai data[], int n, string key, int &found, int &pos) {
    found = 0;
    pos = -1;
    int i = 0;
    while (found == 0 && i < n) {
        if (data[i].nip == key) {
            found = 1;
            pos = i;
        } else {
            i++;
        }
    }
}

void entriData(Pegawai data[], int &n) {
    cout << "Jumlah data : "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "\nData ke-" << i + 1 << endl;
        cout << "Masukkan NIP  : "; cin >> data[i].nip;
        cout << "Masukkan Nama : "; cin.ignore(); getline(cin, data[i].nama);
        cout << "Masukkan Gol  : "; cin >> data[i].golongan;
    }
}

void cetakLaporan(Pegawai data[], int n) {
    if (n == 0) {
        cout << "\nData masih kosong!\n";
        return;
    }
    long totGaji = 0, totTunj = 0, totAkhir = 0;

    cout << "\n" << left << setw(5) << "No" << setw(12) << "NIP" << setw(20) << "Nama" 
         << setw(8) << "Gol" << setw(12) << "Gaji" << setw(15) << "Tunjangan" << "Total" << endl;
    cout << string(85, '-') << endl;

    for (int i = 0; i < n; i++) {
        long g = getGajiPokok(data[i].golongan);
        long t = getTunjangan(data[i].golongan);
        long sub = g + t;

        totGaji += g;
        totTunj += t;
        totAkhir += sub;

        cout << left << setw(5) << i + 1 << setw(12) << data[i].nip << setw(20) << data[i].nama 
             << setw(8) << data[i].golongan << setw(12) << g << setw(15) << t << sub << endl;
    }

    cout << string(85, '-') << endl;
    cout << "JUMLAH" << setw(39) << " " << setw(12) << totGaji << setw(15) << totTunj << totAkhir << endl;
    cout << "Rata-rata gaji total : " << (n > 0 ? totAkhir / n : 0) << endl;
}

void sisipData(Pegawai data[], int &n) {
    if (n >= MAX_LIMIT) return;
    string key;
    int ketemu, idx;
    cout << "Masukkan NIP acuan: "; cin >> key;
    cariIndex(data, n, key, ketemu, idx);

    if (ketemu) {
        for (int i = n; i > idx + 1; i--) {
            data[i] = data[i-1];
        }
        cout << "--- Masukkan Data Baru ---\n";
        cout << "NIP  : "; cin >> data[idx+1].nip;
        cout << "Nama : "; cin.ignore(); getline(cin, data[idx+1].nama);
        cout << "Gol  : "; cin >> data[idx+1].golongan;
        n++;
    } else {
        cout << "NIP tidak ditemukan!\n";
    }
}

void hapusElemen(Pegawai data[], int &n) {
    string key;
    int ketemu, idx;
    cout << "Masukkan NIP target hapus: "; cin >> key;
    cariIndex(data, n, key, ketemu, idx);

    if (ketemu) {
        for (int i = idx; i < n - 1; i++) {
            data[i] = data[i+1];
        }
        n--;
        cout << "Data berhasil dihapus.\n";
    } else {
        cout << "NIP tidak ditemukan!\n";
    }
}

int main() {
    Pegawai list[MAX_LIMIT];
    int n = 0, pil;

    do {
        cout << "\n======= MENU PEGAWAI =======";
        cout << "\n1. Input n Data";
        cout << "\n2. Tambah Data (Insert After)";
        cout << "\n3. Hapus Data";
        cout << "\n4. Output Laporan";
        cout << "\n0. Keluar";
        cout << "\nPilihan (0-4): ";
        cin >> pil;

        switch (pil) {
            case 1:
                entriData(list, n);
                break;
            case 2:
                sisipData(list, n);
                break;
            case 3:
                hapusElemen(list, n);
                break;
            case 4:
                cetakLaporan(list, n);
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pil != 0);

    return 0;
}