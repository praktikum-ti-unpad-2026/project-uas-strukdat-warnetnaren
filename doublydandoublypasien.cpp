/*
Kian Islam Susanto
24 Mei 2026
1408102500791
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct pasien{
    string nik;
    string nama;
    int prioritas;
};

const int MAX = 100;

struct PriorityQueue{
    pasien info[MAX];
    int front;
    int rear;
};

void createQueue(PriorityQueue &Q){
    Q.front = -1;
    Q.rear = -1;
}

int hitungElemen(PriorityQueue Q){
    if(Q.front == -1){
        return 0;
    }

    if(Q.rear >= Q.front){
        return Q.rear - Q.front + 1;
    }
    else{
        return (MAX - Q.front) + (Q.rear + 1);
    }
}

void createElemen(pasien &pNew){

    cout << "Masukkan NIK        : ";
    cin >> pNew.nik;

    cout << "Masukkan Nama       : ";
    cin >> pNew.nama;

    cout << "Masukkan Prioritas  : ";
    cin >> pNew.prioritas;

    cout << endl;
}

string kategori(int prioritas){

    if(prioritas == 1){
        return "KRITIS";
    }
    else if(prioritas == 2){
        return "DARURAT";
    }
    else if(prioritas == 3){
        return "BIASA";
    }

    return "-";
}

void masukAntrian(PriorityQueue &Q, pasien pNew){

    if((Q.front == 0 && Q.rear == MAX - 1) ||
       (Q.rear + 1 == Q.front)){

        cout << "Antrian penuh\n\n";
    }

    else{

        if(Q.front == -1){

            Q.front = 0;
            Q.rear = 0;

            Q.info[Q.rear] = pNew;
        }
        else{

            int i;

            if(Q.rear == MAX - 1){
                Q.rear = 0;
            }
            else{
                Q.rear++;
            }

            i = Q.rear;

            while(i != Q.front &&
                  Q.info[(i - 1 + MAX) % MAX].prioritas > pNew.prioritas){

                Q.info[i] = Q.info[(i - 1 + MAX) % MAX];

                i = (i - 1 + MAX) % MAX;
            }

            Q.info[i] = pNew;
        }

        cout << "Pasien berhasil masuk antrian\n\n";
    }
}

void keluarAntrian(PriorityQueue &Q, pasien &pDel){

    if(Q.front == -1){

        cout << "Antrian kosong\n\n";
    }
    else{

        pDel = Q.info[Q.front];

        cout << "Pasien dipanggil : "
             << pDel.nama
             << " (" << kategori(pDel.prioritas) << ")"
             << endl << endl;

        if(Q.front == Q.rear){

            Q.front = -1;
            Q.rear = -1;
        }
        else if(Q.front == MAX - 1){

            Q.front = 0;
        }
        else{

            Q.front++;
        }
    }
}

void traversal(PriorityQueue Q){

    if(Q.front == -1){

        cout << "Antrian kosong\n\n";
    }
    else{

        cout << left
             << setw(5)  << "No"
             << setw(15) << "NIK"
             << setw(20) << "Nama"
             << setw(10) << "Prioritas"
             << setw(15) << "Kategori"
             << endl;

        int i = Q.front;
        int no = 1;

        while(true){

            cout << left
                 << setw(5)  << no++
                 << setw(15) << Q.info[i].nik
                 << setw(20) << Q.info[i].nama
                 << setw(10) << Q.info[i].prioritas
                 << setw(15) << kategori(Q.info[i].prioritas)
                 << endl;

            if(i == Q.rear){
                break;
            }

            i = (i + 1) % MAX;
        }

        cout << endl;
    }
}

void menu(PriorityQueue &Q){

    int pilih;

    pasien pNew;
    pasien pDel;

    do{

        cout << "===== PRIORITY QUEUE IGD =====\n";
        cout << "1. Masuk Antrian\n";
        cout << "2. Panggil Pasien\n";
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

    }while(pilih != 0);
}

int main(){

    PriorityQueue Q;

    createQueue(Q);

    menu(Q);

    return 0;
}