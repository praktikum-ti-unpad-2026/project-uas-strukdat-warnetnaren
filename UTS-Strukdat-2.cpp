#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Pegawai {
    string nip;
    string nama;
    int gol;
};

struct Node {
    Pegawai data;
    Node *next;
    Node *prev;
};

typedef Node* ptrNode;

void inisialisasi(ptrNode &head) {
    head = nullptr;
}

long hitungGapok(ptrNode p) {
    long gaji = 0;
    if (p->data.gol == 1) gaji = 3000000;
    if (p->data.gol == 2) gaji = 4000000;
    if (p->data.gol == 3) gaji = 5000000;
    return gaji;
}

long hitungTunj(ptrNode p) {
    long tunjangan = 0;
    long g = hitungGapok(p);
    if (p->data.gol == 1) tunjangan = g * 1.0;
    if (p->data.gol == 2) tunjangan =  g * 1.25;
    if (p->data.gol == 3) tunjangan =  g * 1.5;
    return tunjangan;
}

long hitungSubtotal(ptrNode p) {
    return hitungGapok(p) + hitungTunj(p);
}

void cariNode(ptrNode head, string kunci, int &ketemu, ptrNode &lokasi) {
    if (head == nullptr) {
        ketemu = 0;
        return;
    }
    ketemu = 0;
    lokasi = head;
    do {
        if (lokasi->data.nip == kunci) {
            ketemu = 1;
            break;
        }
        lokasi = lokasi->next;
    } while (lokasi != head);
}

void sisipData(ptrNode &head, string kunci) {
    ptrNode baru = new Node;
    cout << "NIP: "; cin >> baru->data.nip;
    cout << "Nama: "; cin.ignore(); getline(cin, baru->data.nama);
    cout << "Gol (1-3): "; cin >> baru->data.gol;

    if (head == nullptr) {
        head = baru;
        baru->next = head;
        baru->prev = head;
    } else {
        int ketemu;
        ptrNode pHelp;
        cariNode(head, kunci, ketemu, pHelp);

        if (ketemu) {
            baru->next = pHelp->next;
            baru->prev = pHelp;
            pHelp->next->prev = baru;
            pHelp->next = baru;
        } else {
            baru->next = head;
            baru->prev = head->prev;
            head->prev->next = baru;
            head->prev = baru;
            head = baru;
        }
    }
}

void hapusBelakang(ptrNode &head) {
    if (head == nullptr) return;
    ptrNode pDel;
    if (head->next == head) {
        pDel = head;
        head = nullptr;
    } else {
        pDel = head->prev;
        pDel->prev->next = head;
        head->prev = pDel->prev;
    }
    delete pDel;
}

void cetakList(ptrNode head) {
    if (head == nullptr) {
        cout << "List Kosong!" << endl;
        return;
    }
    long totG = 0, totT = 0, totS = 0;
    int count = 0;
    ptrNode p = head;

    cout << left << setw(5) << "No" << setw(12) << "NIP" << setw(20) << "Nama" 
         << setw(6) << "Gol" << setw(12) << "Gaji" << setw(15) << "Tunjangan" << "Total" << endl;
    cout << string(85, '-') << endl;

    do {
        long g = hitungGapok(p);
        long t = hitungTunj(p);
        long s = g + t;
        totG += g; totT += t; totS += s; count++;

        cout << left << setw(5) << count << setw(12) << p->data.nip << setw(20) << p->data.nama 
             << setw(6) << p->data.gol << setw(12) << g << setw(15) << t << s << endl;
        p = p->next;
    } while (p != head);

    cout << string(85, '-') << endl;
    cout << "Jumlah Gaji Total: " << totS << endl;
    cout << "Rata-rata Gaji   : " << (totS / count) << endl;
}

int main() {
    ptrNode head;
    inisialisasi(head);
    int pil;
    string key;

    do {
        cout << "\n1. Insert After / First\n2. Delete Last\n3. Traversal\n0. Keluar\nPilih: ";
        cin >> pil;
        switch(pil) {
            case 1:
                cout << "Masukkan NIP acuan: "; cin >> key;
                sisipData(head, key);
                break;
            case 2:
                hapusBelakang(head);
                break;
            case 3:
                cetakList(head);
                break;
        }
    } while (pil != 0);

    return 0;
}