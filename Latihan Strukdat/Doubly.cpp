#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct barang {
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

void createlist(list &head) {
    head = nullptr;
}

void createdata(ptr &pnew) {
    pnew = new Node;
    cout << "Masukan Data Barang" << endl;
    cout << "Kode: "; cin >> pnew->data.kode;
    cout << "Nama Barang"; cin >> pnew->data.nama;
    cout << "Harga Barang"; cin >> pnew->data.harga;
    cout << "Jumlah Barang"; cin >> pnew->data.banyak;
    pnew->prev = nullptr;
    pnew->next = nullptr;
}


void insertfirst(list &head, ptr pnew){
    if (head = nullptr) {
        head = pnew;
    }
    else {
        pnew->next = head;
        head->prev = pnew;
        head = pnew;
    }

}

void insertlast(list &head, ptr pnew){
    if (head == nullptr) {
        head = pnew;

    }
}

