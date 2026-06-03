#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct pegawai{
    string NIP;
    string namaPegawai;
    int golongan;
};

struct node{
    pegawai info;
    node *next;
};

typedef node* alamat;

struct Stack{
    alamat top;
};

void createStack(Stack &S){
    S.top = NULL;
}

alamat createElement(pegawai x){
    alamat p = new node;

    p->info = x;
    p->next = NULL;

    return p;
}

void createPegawai(pegawai &x){
    cout << "Masukkan NIP  : ";
    cin >> x.NIP;

    cin.ignore();

    cout << "Masukkan Nama : ";
    getline(cin, x.namaPegawai);

    cout << "Masukkan Gol  : ";
    cin >> x.golongan;
}

int gaji(pegawai x){

    int gaji = 0;

    if(x.golongan == 1){
        gaji = 3000000;
    }
    else if(x.golongan == 2){
        gaji = 4000000;
    }
    else if(x.golongan == 3){
        gaji = 5000000;
    }

    return gaji;
}

int tunjangan(pegawai x){

    int tunjangan = 0;

    if(x.golongan == 1){
        tunjangan = gaji(x);
    }
    else if(x.golongan == 2){
        tunjangan = gaji(x) * 125 / 100;
    }
    else if(x.golongan == 3){
        tunjangan = gaji(x) * 150 / 100;
    }

    return tunjangan;
}

int total(pegawai x){
    return gaji(x) + tunjangan(x);
}

int jumlahGaji(Stack S){
    if(S.top == NULL){
        return 0;
    }

    int jumlah = 0;
    alamat p = S.top;

    do{
        jumlah += gaji(p->info);
        p = p->next;

    } while(p != S.top);

    return jumlah;
}

int jumlahTunjangan(Stack S){
    if(S.top == NULL){
        return 0;
    }

    int jumlah = 0;
    alamat p = S.top;

    do{
        jumlah += tunjangan(p->info);
        p = p->next;

    } while(p != S.top);

    return jumlah;
}

int jumlahTotal(Stack S){
    if(S.top == NULL){
        return 0;
    }

    int jumlah = 0;
    alamat p = S.top;

    do{
        jumlah += total(p->info);
        p = p->next;

    } while(p != S.top);

    return jumlah;
}

int jumlahData(Stack S){
    if(S.top == NULL){
        return 0;
    }

    int jumlah = 0;
    alamat p = S.top;

    do{
        jumlah++;
        p = p->next;

    } while(p != S.top);

    return jumlah;
}

int mean(Stack S){
    if(S.top == NULL){
        return 0;
    }

    return jumlahTotal(S) / jumlahData(S);
}

void push(Stack &S, pegawai x){
    alamat p = createElement(x);

    if(S.top == NULL){
        S.top = p;
        p->next = S.top;
    }
    else{
        alamat q = S.top;

        while(q->next != S.top){
            q = q->next;
        }

        q->next = p;
        p->next = S.top;
    }

    cout << "Data berhasil ditambahkan\n\n";
}

void pop(Stack &S){
    if(S.top == NULL){
        cout << "Data kosong\n\n";
    }
    else if(S.top->next == S.top){
        cout << "Data terhapus : "
             << S.top->info.NIP << " - "
             << S.top->info.namaPegawai << endl << endl;

        delete S.top;
        S.top = NULL;
    }
    else{
        alamat last = S.top;
        
        while(last->next->next != S.top){
            last = last->next;
        }

        alamat hapus = last->next;

        cout << "Data terhapus : "
             << hapus->info.NIP << " - "
             << hapus->info.namaPegawai << endl << endl;

        last->next = S.top;

        delete hapus;
    }
}

void traversal(Stack S){
    if(S.top == NULL){
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

        alamat p = S.top;
        int no = 1;

        do{
            cout << left
                 << setw(5)  << no++
                 << setw(10) << p->info.NIP
                 << setw(20) << p->info.namaPegawai
                 << setw(5)  << p->info.golongan
                 << setw(15) << gaji(p->info)
                 << setw(15) << tunjangan(p->info)
                 << setw(15) << total(p->info)
                 << endl;

            p = p->next;

        } while(p != S.top);

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
    pegawai x;

    do{
        cout << "===== MENU =====\n";
        cout << "1. Insert Last (Push)\n";
        cout << "2. Delete Last (Pop)\n";
        cout << "3. Traversal\n";
        cout << "0. Keluar\n";
        cout << "Pilih : ";
        cin >> pilih;

        cout << endl;

        switch(pilih){
            case 1:
                createPegawai(x);
                push(S, x);
                break;

            case 2:
                pop(S);
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