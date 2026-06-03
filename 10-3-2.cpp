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

struct Stack{
    pegawai info[MAX];
    int top;
};

void createStack(Stack &S){
    S.top = -1;
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

int jumlahGaji(Stack S){
    int jumlah = 0;

    for(int i = 0; i <= S.top; i++){
        jumlah += gaji(S.info[i]);
    }

    return jumlah;
}

int jumlahTunjangan(Stack S){
    int jumlah = 0;

    for(int i = 0; i <= S.top; i++){
        jumlah += tunjangan(S.info[i]);
    }

    return jumlah;
}

int jumlahTotal(Stack S){
    int jumlah = 0;

    for(int i = 0; i <= S.top; i++){
        jumlah += total(S.info[i]);
    }

    return jumlah;
}

int mean(Stack S){
    if(S.top == -1){
        return 0;
    }

    return jumlahTotal(S) / (S.top + 1);
}

void insertFirst(Stack &S, pegawai pNew){
    if(S.top == MAX - 1){
        cout << "Data penuh\n";
    }
    else{
        S.top++;

        for(int i = S.top; i > 0; i--){
            S.info[i] = S.info[i - 1];
        }

        S.info[0] = pNew;

        cout << "Data berhasil ditambahkan\n\n";
    }
}

void deleteFirst(Stack &S, pegawai &pDel){
    if(S.top == -1){
        cout << "Data kosong\n";
    }
    else{
        pDel = S.info[0];

        for(int i = 0; i < S.top; i++){
            S.info[i] = S.info[i + 1];
        }

        S.top--;

        cout << "Data terhapus : "
             << pDel.nip << " - "
             << pDel.nama << endl << endl;
    }
}

void traversal(Stack S){
    if(S.top == -1){
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

        for(int i = 0; i <= S.top; i++){
            cout << left
                 << setw(5)  << i + 1
                 << setw(10) << S.info[i].nip
                 << setw(20) << S.info[i].nama
                 << setw(5)  << S.info[i].gol
                 << setw(15) << gaji(S.info[i])
                 << setw(15) << tunjangan(S.info[i])
                 << setw(15) << total(S.info[i])
                 << endl;
        }

        cout << endl;

        cout << left
             << setw(40) << "Jumlah : "
             << setw(15) << jumlahGaji(S)
             << setw(15) << jumlahTunjangan(S)
             << setw(15) << jumlahTotal(S)
             << endl;

        cout << "Rata-rata total : "
             << mean(S)
             << endl << endl;
    }
}

void menu(Stack &S){
    int pilih;

    pegawai pNew;
    pegawai pDel;

    do{
        cout << "===== MENU =====\n";
        cout << "1. Insert First\n";
        cout << "2. Delete First\n";
        cout << "3. Traversal\n";
        cout << "0. Keluar\n";
        cout << "Pilih : ";
        cin >> pilih;

        cout << endl;

        switch(pilih){
            case 1:
                createElemen(pNew);
                insertFirst(S, pNew);
                break;

            case 2:
                deleteFirst(S, pDel);
                break;

            case 3:
                traversal(S);
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
    Stack S;

    createStack(S);

    menu(S);

    return 0;
}