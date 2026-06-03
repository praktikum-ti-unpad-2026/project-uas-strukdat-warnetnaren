#include <iostream>
#include <iomanip>
using namespace std;

struct pegawai {
    string nip;
    string nama;
    int gol;
};

const int MAX = 100;

struct stack {
    pegawai info[MAX];
    int top;
};

void createStack(stack &S){
    S.top = -1;
}

void createElemen(pegawai &pNew){
    cout << "Masukkan NIP : "; cin >> pNew.nip;
    cout << "Masukkan Nama : "; cin >> pNew.nama;
    cout << "Masukkan Gol : "; cin >> pNew.gol;
}

int gaji(pegawai pNew){ // gol bukan pegawai
    int gaji = 0;
    if(pNew.gol == 1){
        gaji = 3000000;
    }
    else if(pNew.gol == 2){
        gaji = 4000000;
    }
    else if(pNew.gol == 3){
        gaji = 5000000;
    }
    return gaji;
}

int tunjangan(pegawai pNew){ // gol bukan tunjangan
    int tunjangan = 0;
    if(pNew.gol == 1){
        tunjangan = gaji(pNew) * 1;
    }
    else if(pNew.gol == 2){
        tunjangan = gaji(pNew) * 1.25;
    }
    else if(pNew.gol == 3){
        tunjangan = gaji(pNew) * 1.5;
    }
    return tunjangan;
}

int total(pegawai pNew){
    int total;
    return total = gaji(pNew) + tunjangan(pNew);
}

int jumlahGaji(stack S){
    if(S.top < 0){
        return 0;
    }
    else {
        int jumlah = 0;

        for(int i=0;i<S.top + 1;i++){
            jumlah += gaji(S.info[i]);
        }
        return jumlah;
    }
}

int jumlahTunjangan(stack S){
    if(S.top < 0){
        return 0;
    }
    else{
        int jumlah = 0;
        for(int i=0;i<S.top + 1;i++){
            jumlah += tunjangan(S.info[i]);
        }
        return jumlah;
    }
}

int jumlahTotal(stack S){
    if(S.top < 0){
        return 0;
    }
    else {
    int jumlah = 0;
    for(int i=0;i<S.top + 1;i++){
            jumlah += total(S.info[i]);
        }
        return jumlah;
    }
}

int mean(stack S){
    if(S.top < 0){
        return 0;
    }
    else {
        int mean = jumlahTotal(S) / (S.top + 1);
        return mean;
    }
}

void push(stack &S, pegawai pNew){
    if(S.top == MAX - 1){
        cout << "Stack penuh" << endl;
    }
    else {
        S.top++;
        S.info[S.top] = pNew;
    }
}

void pop(stack &S, pegawai pDel){
    if(S.top < 0){
        cout << "Stack kosong" << endl;
    }
    else {
        pDel = S.info[S.top];
        S.top--;
    }
}

void traversal(stack S){
    if(S.top < 0){
        cout << "Data kosong" << endl;
    }
    else {
        int no = 1;
        int i = 0;

        cout << left
             << setw(5) << "No"
             << setw(10) << "NIP"
             << setw(20) << "Nama"
             << setw(5) << "Gol"
             << setw(15) << "Gaji"
             << setw(15) << "Tunjangan"
             << setw(15) << "Total" << endl;
        do {
            cout << left
                << setw(5) << no++
                << setw(10) << S.info[i].nip
                 << setw(20) << S.info[i].nama
                 << setw(5) << S.info[i].gol
                 << setw(15) << gaji(S.info[i]) // S.info[i].gol
                 << setw(15) << tunjangan(S.info[i])
                 << setw(15) << total(S.info[i]) << endl;
            i++;
        } while(i < S.top + 1);

        cout << left
             << setw(40) << "Jumlah : "
             << setw(15) << jumlahGaji(S)
             << setw(15) << jumlahTunjangan(S)
             << setw(15) << jumlahTotal(S) << endl;
        cout << "Rata-rata total : " << mean(S) << endl;
    }
}

void menu(stack &S, pegawai pNew, pegawai pDel){
    int pilih;
    
    do {
        cout << "Menu (1-3)\n"
             <<"1.push\n"
             << "2.pop\n"
             << "3.traversal\n"
             << "0.keluar"
             << "\nPILIH(0-3)\n";
        cin >> pilih;

        switch(pilih){
            case 1:
            createElemen(pNew);
            push(S, pNew);
            break;

            case 2:
            pop(S, pDel);
            break;

            case 3:
            traversal(S);
            break;
        }
    }
    while(pilih != 0);
}

int main(){
    pegawai pNew, pDel;
    stack mytumpukan;

    createStack(mytumpukan);

    menu(mytumpukan, pNew, pDel);
}