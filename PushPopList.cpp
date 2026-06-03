
#include <iostream>
#include <iomanip>
using namespace std;

struct pegawai {
    string NIP;
    string nama;
    int gol;
};

struct Stack{
    pegawai info;
    Stack *next;
};

typedef Stack *ptr;
typedef ptr list;

void createStack(list &top){
    top = nullptr;
}

void createElemen(ptr &pNew){
    pNew = new Stack;
    cout << "Masukkan NIP : "; cin >> pNew->info.NIP;
    cout << "Masukkan Nama : "; cin >> pNew->info.nama;
    cout << "Masukkan Gol : "; cin >> pNew->info.gol;
    pNew->next = nullptr;
}

int gaji(ptr pNew){
    int gaji;
    if(pNew->info.gol == 1){
        return gaji = 3000000;
    }
    else if(pNew->info.gol == 2){
        return gaji = 4000000;
    }
    else if(pNew->info.gol == 3){
        return gaji = 5000000;
    }
    return 0;
}

int tunjangan(ptr pNew){
    int tunjangan;
    if(pNew->info.gol == 1){
        return tunjangan = gaji(pNew) * 1;
    }
    else if(pNew->info.gol == 2){
        return tunjangan = gaji(pNew) * 1.25;
    }
    else if(pNew->info.gol == 3){
        return tunjangan = gaji(pNew) * 1.5;
    }
    return 0;
}

int total(ptr pNew){
    int total;
    return total = gaji(pNew) + tunjangan(pNew);
}

int jumlahGaji(list top){
    if(top == nullptr){
        return 0;
    }
    else {
        int jumlah = 0;
        ptr pHelp = top;
        do {
            jumlah += gaji(pHelp);
            pHelp = pHelp->next;
        }
        while(pHelp != nullptr);
        return jumlah;
    }
}

int jumlahTunjangan(list top){
    if(top == nullptr){
        return 0;
    }
    else{
        int jumlah = 0;
        ptr pHelp = top;
        do {
            jumlah += tunjangan(pHelp);
            pHelp = pHelp->next;
        }
        while(pHelp != nullptr);
        return jumlah;
    }
}

int jumlahTotal(list top){
    if(top == nullptr){
        return 0;
    }
    else {
        int jumlah = 0;
        ptr pHelp = top;
        do {
            jumlah += total(pHelp);
            pHelp = pHelp->next;
        }
        while(pHelp != nullptr);
        return jumlah;
    }
}

int mean(list top){
    if(top == nullptr){
        return 0;
    }
    else {
        int hitungStack = 0;
        ptr pHelp = top;
        do {
            hitungStack++;
            pHelp = pHelp->next;
        }
        while(pHelp != nullptr);
        int mean = jumlahTotal(top) / hitungStack;
        return mean;
    }
}

void push(list &top, ptr pNew){
    if(top == nullptr){
        top = pNew;
    }
    else {
        pNew->next = top;
        top = pNew;
    }
}

void pop(list &top, ptr pDel){
    if(top == nullptr){
        cout << "Stack kosong" << endl;
    }
    else if(top->next == nullptr){
        pDel = top;
        top = nullptr;
    }
    else {
        pDel = top;
        top = top->next;
        pDel->next = nullptr;
    }
}

void traversal(list &top){
    int no = 1;
    ptr pHelp = top;

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
             << setw(10) << pHelp->info.NIP
             << setw(20) << pHelp->info.nama
             << setw(5) << pHelp->info.gol
             << setw(15) << gaji(pHelp)
             << setw(15) << tunjangan(pHelp)
             << setw(15) << total(pHelp) << endl;
        pHelp = pHelp->next;
    } while(pHelp != nullptr);

    cout << left
         << setw(40) << "Jumlah : "
         << setw(15) << jumlahGaji(top)
         << setw(15) << jumlahTunjangan(top)
         << setw(15) << jumlahTotal(top) << endl;
    cout << "Rata-rata total : " << mean(top) <<endl;
}

void menu(list &top, ptr pNew, ptr pDel){
    int pilih;
    
    do {
        cout << "1.push\n"
             << "2.pop\n"
             << "3.traversal\n"
             << "0.keluar"
             << "\nPILIH(0-3)\n";
        cin >> pilih;

        switch(pilih){
            case 1:
            createElemen(pNew);
            push(top, pNew);
            break;

            case 2:
            pop(top, pDel);
            break;

            case 3:
            traversal(top);
            break;
        }
    }
    while(pilih != 0);
}

int main(){
    ptr pNew, pDel;
    list top;

    createStack(top);

    menu(top, pNew, pDel);
}