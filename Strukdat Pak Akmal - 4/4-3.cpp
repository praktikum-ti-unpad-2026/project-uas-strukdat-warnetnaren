#include <iostream>
using std::cout;
using std::cin;
using std::string;

struct Barang{
    string kode;
    string nama;
    int harga;
    int banyak;
};

struct Node{
    Barang info;
    Node *next;
};

typedef Node* address;

address first = NULL;

address createNode(Barang x){
    address p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

void insertFirst(address &first, Barang x){

    address p = createNode(x);

    if(first == NULL){
        first = p;
    }
    else{
        p->next = first;
        first = p;
    }
}

void deleteFirst(address &first){

    if(first == NULL){
        cout<<"List kosong\n";
        return;
    }

    address p = first;
    first = first->next;

    delete p;

    cout<<"Data pertama berhasil dihapus\n";
}

void traversal(address first){

    address p = first;
    int no = 1;

    cout<<"\nDaftar Barang PT Informatika\n";
    cout<<"No Kode Nama Harga Banyak Jumlah\n";

    while(p != NULL){

        int jumlah = p->info.harga * p->info.banyak;

        cout<<no<<" "
            <<p->info.kode<<" "
            <<p->info.nama<<" "
            <<p->info.harga<<" "
            <<p->info.banyak<<" "
            <<jumlah<<"\n";

        p = p->next;
        no++;
    }
}

void statistik(address first){

    if(first == NULL){
        cout<<"Data kosong\n";
        return;
    }

    address p = first;

    int max = p->info.harga;
    int min = p->info.harga;
    int totalHarga = 0;
    int totalJumlah = 0;
    int n = 0;

    while(p != NULL){

        if(p->info.harga > max)
        max = p->info.harga;

        if(p->info.harga < min)
        min = p->info.harga;

        totalHarga += p->info.harga;
        totalJumlah += p->info.harga * p->info.banyak;

        n++;

        p = p->next;
    }

    float rata = (float)totalHarga / n;

    cout<<"\nJumlah Total : "<<totalJumlah<<"\n";
    cout<<"Harga Tertinggi : "<<max<<"\n";
    cout<<"Harga Terendah : "<<min<<"\n";
    cout<<"Rata-rata harga : "<<rata<<"\n";
}

void output(address first){

    traversal(first);
    statistik(first);

}

void inputBarang(){

    Barang x;

    cout<<"Kode Barang : ";
    cin>>x.kode;

    cout<<"Nama Barang : ";
    cin>>x.nama;

    cout<<"Harga : ";
    cin>>x.harga;

    cout<<"Banyak : ";
    cin>>x.banyak;

    insertFirst(first,x);
}

void menu(){

    cout<<"\nMENU\n";
    cout<<"1. Insert First\n";
    cout<<"2. Delete First\n";
    cout<<"3. Tampilkan Data\n";
    cout<<"4. Keluar\n";

}

int main(){

    int pilih;

    do{

        menu();

        cout<<"Pilih : ";
        cin>>pilih;

        switch(pilih){

            case 1:
            inputBarang();
            break;

            case 2:
            deleteFirst(first);
            break;

            case 3:
            output(first);
            break;

        }

    }while(pilih != 4);

}