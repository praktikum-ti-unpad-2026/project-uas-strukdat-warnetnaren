/*
Kian Islam Susanto
140810250079
24 Mei 2026
*/

#include <iostream>

using namespace std;

struct elmKaryawan{
    string nip;
    string nama;
    elmKaryawan *next;
};

typedef elmKaryawan* ptrKaryawan;

struct elmDivisi{
    string namaDivisi;
    ptrKaryawan firstKaryawan;
    elmDivisi *next;
};

typedef elmDivisi* ptrDivisi;

struct multiList{
    ptrDivisi firstDivisi;
};

void createList(multiList &L){

    L.firstDivisi = NULL;
}

void createElemenDivisi(ptrDivisi &pDiv){

    pDiv = new elmDivisi;

    cout << "Masukkan Nama Divisi : ";
    cin >> pDiv->namaDivisi;

    pDiv->firstKaryawan = NULL;
    pDiv->next = NULL;
}

void createElemenKaryawan(ptrKaryawan &pKar){

    pKar = new elmKaryawan;

    cout << "Masukkan NIP  : ";
    cin >> pKar->nip;

    cout << "Masukkan Nama : ";
    cin >> pKar->nama;

    pKar->next = NULL;
}

void insertDivisi(multiList &L, ptrDivisi pDiv){

    if(L.firstDivisi == NULL){

        L.firstDivisi = pDiv;
    }
    else{

        ptrDivisi last = L.firstDivisi;

        while(last->next != NULL){

            last = last->next;
        }

        last->next = pDiv;
    }

    cout << "Divisi berhasil ditambahkan\n\n";
}

ptrDivisi cariDivisi(multiList L, string divisi){

    ptrDivisi pDiv = L.firstDivisi;

    while(pDiv != NULL){

        if(pDiv->namaDivisi == divisi){

            return pDiv;
        }

        pDiv = pDiv->next;
    }

    return NULL;
}

void insertKaryawan(ptrDivisi pDiv, ptrKaryawan pKar){

    if(pDiv == NULL){

        cout << "Divisi tidak ditemukan\n\n";
    }
    else{

        if(pDiv->firstKaryawan == NULL){

            pDiv->firstKaryawan = pKar;
        }
        else{

            ptrKaryawan last = pDiv->firstKaryawan;

            while(last->next != NULL){

                last = last->next;
            }

            last->next = pKar;
        }

        cout << "Karyawan berhasil ditambahkan\n\n";
    }
}

void deleteKaryawan(ptrDivisi pDiv, string nip){

    if(pDiv == NULL){

        cout << "Divisi tidak ditemukan\n\n";
    }
    else{

        ptrKaryawan hapus;
        ptrKaryawan prev = NULL;

        hapus = pDiv->firstKaryawan;

        while(hapus != NULL && hapus->nip != nip){

            prev = hapus;
            hapus = hapus->next;
        }

        if(hapus == NULL){

            cout << "Karyawan tidak ditemukan\n\n";
        }
        else{

            if(prev == NULL){

                pDiv->firstKaryawan = hapus->next;
            }
            else{

                prev->next = hapus->next;
            }

            delete hapus;

            cout << "Karyawan berhasil dihapus\n\n";
        }
    }
}

void deleteDivisi(multiList &L, string namaDiv){

    ptrDivisi hapus = L.firstDivisi;
    ptrDivisi prev = NULL;

    while(hapus != NULL && hapus->namaDivisi != namaDiv){

        prev = hapus;
        hapus = hapus->next;
    }

    if(hapus == NULL){

        cout << "Divisi tidak ditemukan\n\n";
    }
    else{

        ptrKaryawan pKar;

        while(hapus->firstKaryawan != NULL){

            pKar = hapus->firstKaryawan;

            hapus->firstKaryawan = pKar->next;

            delete pKar;
        }

        if(prev == NULL){

            L.firstDivisi = hapus->next;
        }
        else{

            prev->next = hapus->next;
        }

        delete hapus;

        cout << "Divisi berhasil dihapus\n\n";
    }
}

void traversal(multiList L){

    if(L.firstDivisi == NULL){

        cout << "Data kosong\n\n";
    }
    else{

        cout << "=====================================\n";
        cout << "Daftar Divisi dan Karyawan\n";
        cout << "=====================================\n\n";

        ptrDivisi pDiv = L.firstDivisi;

        int no = 1;

        while(pDiv != NULL){

            cout << no++ << ". Divisi : "
                 << pDiv->namaDivisi
                 << endl;

            ptrKaryawan pKar = pDiv->firstKaryawan;

            if(pKar == NULL){

                cout << "   Tidak ada karyawan\n";
            }
            else{

                while(pKar != NULL){

                    cout << "   "
                         << pKar->nip
                         << " - "
                         << pKar->nama
                         << endl;

                    pKar = pKar->next;
                }
            }

            cout << endl;

            pDiv = pDiv->next;
        }
    }
}

void menu(multiList &L){

    int pilih;

    ptrDivisi pDiv;
    ptrKaryawan pKar;

    string namaDiv;
    string nip;

    do{

        cout << "===== MENU MULTI LIST =====\n";
        cout << "1. Tambah Divisi\n";
        cout << "2. Tambah Karyawan\n";
        cout << "3. Hapus Karyawan\n";
        cout << "4. Hapus Divisi\n";
        cout << "5. Traversal\n";
        cout << "0. Keluar\n";
        cout << "Pilih : ";
        cin >> pilih;

        cout << endl;

        switch(pilih){

            case 1:

                createElemenDivisi(pDiv);
                insertDivisi(L, pDiv);

                break;

            case 2:

                cout << "Masukkan Nama Divisi : ";
                cin >> namaDiv;

                pDiv = cariDivisi(L, namaDiv);

                createElemenKaryawan(pKar);

                insertKaryawan(pDiv, pKar);

                break;

            case 3:

                cout << "Masukkan Nama Divisi : ";
                cin >> namaDiv;

                pDiv = cariDivisi(L, namaDiv);

                cout << "Masukkan NIP Karyawan : ";
                cin >> nip;

                deleteKaryawan(pDiv, nip);

                break;

            case 4:

                cout << "Masukkan Nama Divisi : ";
                cin >> namaDiv;

                deleteDivisi(L, namaDiv);

                break;

            case 5:

                traversal(L);

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

    multiList L;

    createList(L);

    menu(L);

    return 0;
}