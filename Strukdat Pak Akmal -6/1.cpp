/*
Nama : Kian Islam Susanto
Kelas : B
NPM : 140810250079
*/

#include <iostream>
#include <iomanip>
using namespace std;

struct barang{
    string kode;
    string nama;
    int harga;
    int banyak;
}; 

struct Node {
    barang data;
    Node *next;
    Node *prev;
};

typedef Node *ptr;
typedef ptr list;

void createList(list &head){
    head = nullptr;
}

void createData(ptr &pNew){
    pNew = new Node;
    cout << "Masukkan data barang" << endl;
    cout << "Kode : "; cin >> pNew->data.kode;
    cout << "Nama Barang : "; cin >> pNew->data.nama;
    cout << "Harga : "; cin >> pNew->data.harga;
    cout << "Banyak : "; cin >> pNew->data.banyak;
    pNew->next = nullptr;
    pNew->prev = nullptr;
}

void insertFirst(list &head, ptr pNew){
    if(head == nullptr){
        head =  pNew;
    }
    else {
        pNew->next = head;
        head->prev = pNew;
        head = pNew;
    }
}

void insertLast(list &head, ptr pNew){
    if(head == nullptr){
        head = pNew;
    }
    else {
        ptr pHelp = head;
        while(pHelp->next  != nullptr){
            pHelp = pHelp->next;
        }
        pHelp->next = pNew;
        pNew->prev = pHelp;
    }
}

void deleteFirst(list &head, ptr &pDel){
    if(head == nullptr){
        return;
    }
    else if(head->next == nullptr){
        pDel = head;
        head = nullptr;
    }
    else {
        pDel = head;
        head = head->next;
        pDel->next = nullptr;
        head->prev = nullptr;
    }
    delete pDel;
}

void deleteLast(list &head, ptr &pDel){
    if(head == nullptr){
        return;
    }
    else if(head->next == nullptr){
        pDel = head;
        head = nullptr;
    }
    else {
        ptr pHelp = head;
        while(pHelp->next != nullptr){
            pHelp = pHelp->next;
        }
        pDel = pHelp;
        pDel->prev->next = nullptr;
        pDel->prev = nullptr;
    }
    delete pDel;
}

int jumlah(ptr pNew){
    int jumlah = pNew->data.harga * pNew->data.banyak;
    return jumlah;
}

int jumlahTotal(list head){
    int total = 0;
    ptr pHelp = head;
    while(pHelp != nullptr){
        total += jumlah(pHelp);
        pHelp = pHelp->next;
    }
    return total;
}

int hitungNode(list head){
    int count = 0;
    ptr pHelp = head;
    while(pHelp != nullptr){
        count++;
        pHelp = pHelp->next;
    }
    return count;
}

int maks(list head){
    if(head == nullptr){
        return 0;
    }
    else {
        ptr pHelp = head;
        int maks  = pHelp->data.harga;
        do{
            if(pHelp->data.harga > maks){
                maks = pHelp->data.harga;
            }
            pHelp = pHelp->next;
        }
        while(pHelp != nullptr);
        return maks;
    }
}

int min(list head){
    if(head == nullptr){
        return 0;
    }
    else {
        ptr pHelp = head;
        int min = pHelp->data.harga;
        do {
            if(pHelp->data.harga < min){
                min = pHelp->data.harga;
            }
            pHelp = pHelp->next;
        }
        while(pHelp != nullptr);
        return min;
    }
}

float mean(list head){
    if(head == nullptr){
        return 0;
    }
    else {
        ptr pHelp = head;
        int total = 0;
        do {
            total += pHelp->data.harga;
            pHelp = pHelp->next;
        }
        while(pHelp != nullptr);
        int n = hitungNode(head);
        float mean = (float) total/n;
        return mean;
    }
}

void traversalMaju(list head){
    if(head == nullptr){
        cout << "Data kosong" << endl;
    }
    else {
        cout << "Daftar Barang PT Informatika" << endl;
        cout << left
             << setw(5) << "No"
             << setw(10) << "Kode"
             << setw(20) << "Nama Barang"
             << setw(10) << "Harga"  
             << setw(10) << "Banyak"
             << setw(10) << "Jumlah" << endl;

        int no = 1;
        ptr pHelp = head;
        do {
            cout << left
                 << setw(5) << no++
                 << setw(10) << pHelp->data.kode
                 << setw(20) << pHelp->data.nama
                 << setw(10) << pHelp->data.harga
                 << setw(10) << pHelp->data.banyak
                 << setw(10) << jumlah(pHelp) << endl;

            pHelp = pHelp->next;
        }
        while(pHelp != nullptr);
        cout << "\nJumlah total : " << jumlahTotal(head) << endl;

        cout << "\nCatatan : " << endl
             << "\nHarga tertinggi : " << maks(head) << endl
             << "Harga Terendah : " << min(head) << endl
             << "Rata-rata : " << mean(head) << endl;

    }
}

void traversalMundur(list head){
    if(head == nullptr){
        cout << "data kosong" << endl;
    }
    else {
        cout << "Daftar Barang PT Informatika" << endl;
        cout << left
             << setw(5) << "No"
             << setw(10) << "Kode"
             << setw(20) << "Nama Barang"
             << setw(10) << "Harga"  
             << setw(10) << "Banyak"
             << setw(10) << "Jumlah" << endl;

        ptr pHelp = head;
        while(pHelp->next != nullptr){
            pHelp = pHelp->next;
        }
        ptr pLast = pHelp;
        int no = hitungNode(head);
        do {
            cout << left
                 << setw(5) << no--
                 << setw(10) << pLast->data.kode
                 << setw(20) << pLast->data.nama
                 << setw(10) << pLast->data.harga
                 << setw(10) << pLast->data.banyak
                 << setw(10) << jumlah(pLast) << endl;

            pLast = pLast->prev;
        }
        while(pLast != nullptr);
    }
}

void menu(list &head, ptr pNew, ptr &pDel){
    int n;
    do {
        cout << "1.insert first\n" 
             << "2.insert last\n"
             << "3.delete first\n"
             << "4.delete last\n"
             << "5.Traversal maju\n"
             << "6.Traversal mundur\n"
             << "0.keluar\n"
             << "\nPILIH MANA(1-6)\n";
        cin >> n;

        switch(n){
            case 1:
            createData(pNew);
            insertFirst(head, pNew);
            break;

            case 2:
            createData(pNew);
            insertLast(head, pNew);
            break;

            case 3:
            deleteFirst(head, pDel);
            break;

            case 4:
            deleteLast(head, pDel);
            break;

            case 5:
            traversalMaju(head);
            break;

            case 6:
            traversalMundur(head);
            break;
        }
    }
    while(n != 0);
}

int main(){
    list head = nullptr;
    ptr pNew, pDel;

    menu(head, pNew, pDel);
    return 0;
}