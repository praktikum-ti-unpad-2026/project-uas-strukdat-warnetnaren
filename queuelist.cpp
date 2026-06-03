/*
Kian Islam Susanto
140810250079
17 Mei 2026
*/


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct pegawai{
    string nip;
    string nama;
    int gol;
};

const int MAX = 100;

struct Queue{
    pegawai info[MAX];
    int front;
    int rear;
};

string rupiah(int angka){

    string hasil = to_string(angka);

    int posisi = hasil.length() - 3;

    while(posisi > 0){
        hasil.insert(posisi, ".");
        posisi -= 3;
    }

    return hasil;
}

string terbilang(int angka){

    string bilangan[] = {
        "", "SATU", "DUA", "TIGA", "EMPAT",
        "LIMA", "ENAM", "TUJUH", "DELAPAN",
        "SEMBILAN", "SEPULUH", "SEBELAS"
    };

    if(angka < 12){
        return bilangan[angka];
    }
    else if(angka < 20){
        return terbilang(angka - 10) + " BELAS";
    }
    else if(angka < 100){
        return terbilang(angka / 10) + " PULUH " +
               terbilang(angka % 10);
    }
    else if(angka < 200){
        return "SERATUS " + terbilang(angka - 100);
    }
    else if(angka < 1000){
        return terbilang(angka / 100) + " RATUS " +
               terbilang(angka % 100);
    }
    else if(angka < 2000){
        return "SERIBU " + terbilang(angka - 1000);
    }
    else if(angka < 1000000){
        return terbilang(angka / 1000) + " RIBU " +
               terbilang(angka % 1000);
    }
    else if(angka < 1000000000){
        return terbilang(angka / 1000000) + " JUTA " +
               terbilang(angka % 1000000);
    }

    return "";
}

void createQueue(Queue &Q){
    Q.front = -1;
    Q.rear = -1;
}

void createElemen(pegawai &pNew){

    cout << "Masukkan NIP  : ";
    cin >> pNew.nip;

    cout << "Masukkan Nama : ";
    cin >> pNew.nama;

    cout << "Masukkan Gol  : ";
    cin >> pNew.gol;
}

int gaji(pegawai p){

    int gaji = 0;

    if(p.gol == 1){
        gaji = 3000000;
    }
    else if(p.gol == 2){
        gaji = 4000000;
    }
    else if(p.gol == 3){
        gaji = 5000000;
    }

    return gaji;
}

int tunjangan(pegawai p){

    int tunjangan = 0;

    if(p.gol == 1){
        tunjangan = gaji(p);
    }
    else if(p.gol == 2){
        tunjangan = gaji(p) * 125 / 100;
    }
    else if(p.gol == 3){
        tunjangan = gaji(p) * 150 / 100;
    }

    return tunjangan;
}

int total(pegawai p){
    return gaji(p) + tunjangan(p);
}

int jumlahGaji(Queue Q){

    int jumlah = 0;

    for(int i = Q.front; i <= Q.rear; i++){
        jumlah += gaji(Q.info[i]);
    }

    return jumlah;
}

int jumlahTunjangan(Queue Q){

    int jumlah = 0;

    for(int i = Q.front; i <= Q.rear; i++){
        jumlah += tunjangan(Q.info[i]);
    }

    return jumlah;
}

int jumlahTotal(Queue Q){

    int jumlah = 0;

    for(int i = Q.front; i <= Q.rear; i++){
        jumlah += total(Q.info[i]);
    }

    return jumlah;
}

int mean(Queue Q){

    if(Q.front == -1){
        return 0;
    }

    return jumlahTotal(Q) / (Q.rear + 1);
}

void masukAntrian(Queue &Q, pegawai pNew){

    if(Q.rear == MAX - 1){
        cout << "Data penuh\n";
    }
    else{

        if(Q.front == -1){
            Q.front = 0;
        }

        Q.rear++;

        Q.info[Q.rear] = pNew;

        cout << "Data berhasil ditambahkan\n\n";
    }
}

void keluarAntrian(Queue &Q, pegawai &pDel){

    if(Q.front == -1){
        cout << "Data kosong\n";
    }
    else{

        pDel = Q.info[Q.front];

        for(int i = Q.front; i < Q.rear; i++){
            Q.info[i] = Q.info[i + 1];
        }

        Q.rear--;

        if(Q.rear < 0){
            Q.front = -1;
        }

        cout << "Data keluar : "
             << pDel.nip << " - "
             << pDel.nama << endl << endl;
    }
}

void traversal(Queue Q){

    if(Q.front == -1){
        cout << "Data kosong\n\n";
    }
    else{

        cout << left
             << setw(5)  << "No"
             << setw(10) << "NIP"
             << setw(20) << "Nama"
             << setw(5)  << "Gol"
             << setw(15) << "Gaji"
             << setw(15) << "Tunjangan"
             << setw(15) << "Total"
             << endl;

        for(int i = Q.front; i <= Q.rear; i++){

            cout << left
                 << setw(5)  << i + 1
                 << setw(10) << Q.info[i].nip
                 << setw(20) << Q.info[i].nama
                 << setw(5)  << Q.info[i].gol
                 << setw(15) << rupiah(gaji(Q.info[i]))
                 << setw(15) << rupiah(tunjangan(Q.info[i]))
                 << setw(15) << rupiah(total(Q.info[i]))
                 << endl;

            cout << "     TERBILANG : "
                 << terbilang(total(Q.info[i]))
                 << " RUPIAH"
                 << endl << endl;
        }

        cout << left
             << setw(40) << "Jumlah : "
             << setw(15) << rupiah(jumlahGaji(Q))
             << setw(15) << rupiah(jumlahTunjangan(Q))
             << setw(15) << rupiah(jumlahTotal(Q))
             << endl << endl;

        cout << "Rata-rata total : "
             << rupiah(mean(Q))
             << endl << endl;

        cout << "Terbilang Jumlah Total : "
             << terbilang(jumlahTotal(Q))
             << " RUPIAH"
             << endl;

        cout << "Terbilang Rata-rata : "
             << terbilang(mean(Q))
             << " RUPIAH"
             << endl << endl;
    }
}

void menu(Queue &Q){

    int pilih;

    pegawai pNew;
    pegawai pDel;

    do{

        cout << "===== MENU QUEUE =====\n";
        cout << "1. Masuk Antrian\n";
        cout << "2. Keluar Antrian\n";
        cout << "3. Traversal\n";
        cout << "0. Keluar\n";
        cout << "Pilih : ";
        cin >> pilih;

        cout << endl;

        switch(pilih){

            case 1:
                createElemen(pNew);
                masukAntrian(Q, pNew);
                break;

            case 2:
                keluarAntrian(Q, pDel);
                break;

            case 3:
                traversal(Q);
                break;

            case 0:
                cout << "Program selesai\n";
                break;

            default:
                cout << "Pilihan tidak tersedia\n\n";
        }

    } while(pilih != 0);
}

int main(){

    Queue Q;

    createQueue(Q);

    menu(Q);

    return 0;
}