#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_PC = 5;

struct Pelanggan{
    int id;
    string nama;
    string status;
    int prioritas;
};

struct List{
    Pelanggan data;
    List *next;
};

struct Queue{
    Pelanggan data;
    Queue *next;
};

struct Stack{
    Pelanggan data;
    Stack *next;
};

List *head = nullptr;
Queue *frontQ = nullptr;
Stack *topS = nullptr;

Pelanggan pc[MAX_PC];
bool terisi[MAX_PC];

int getPrioritas(string status){
    if(status == "VIP" || status == "vip")
        return 1;
    else if(status == "Member" || status == "member")
        return 2;
    else
        return 3;
}

void initPC(){
    for(int i = 0; i < MAX_PC; i++){
        terisi[i] = false;
    }
}

List* cariPelanggan(int id){
    List *bantu = head;

    while(bantu != nullptr){
        if(bantu->data.id == id)
            return bantu;

        bantu = bantu->next;
    }

    return nullptr;
}

void tambahPelanggan(){
    List *baru = new List;

    cout << "\nID                : ";
    cin >> baru->data.id;
    cin.ignore();

    cout << "Nama              : ";
    getline(cin, baru->data.nama);

    cout << "Status (VIP/Member/Non Member) : ";
    getline(cin, baru->data.status);

    baru->data.prioritas = getPrioritas(baru->data.status);
    baru->next = nullptr;

    if(head == nullptr){
        head = baru;
    }
    else{
        List *bantu = head;

        while(bantu->next != nullptr){
            bantu = bantu->next;
        }

        bantu->next = baru;
    }

    cout << "Data berhasil ditambahkan\n";
}

void enqueuePriority(Pelanggan p){
    Queue *baru = new Queue;
    baru->data = p;
    baru->next = nullptr;

    if(frontQ == nullptr){
        frontQ = baru;
    }
    else if(baru->data.prioritas < frontQ->data.prioritas){
        baru->next = frontQ;
        frontQ = baru;
    }
    else{
        Queue *bantu = frontQ;

        while(bantu->next != nullptr &&
              bantu->next->data.prioritas <= baru->data.prioritas){
            bantu = bantu->next;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

bool dequeuePriority(Pelanggan &p){
    if(frontQ == nullptr)
        return false;

    Queue *hapus = frontQ;

    p = hapus->data;
    frontQ = frontQ->next;

    delete hapus;

    return true;
}

void isiPCKosong(){
    for(int i = 0; i < MAX_PC; i++){
        if(!terisi[i] && frontQ != nullptr){

            Pelanggan p;
            dequeuePriority(p);

            pc[i] = p;
            terisi[i] = true;

            cout << p.nama
                 << " masuk ke PC "
                 << i + 1 << endl;
        }
    }
}

void masukAntrian(){
    int id;

    cout << "\nMasukkan ID pelanggan : ";
    cin >> id;

    List *p = cariPelanggan(id);

    if(p == nullptr){
        cout << "Pelanggan tidak ditemukan\n";
        return;
    }

    enqueuePriority(p->data);

    cout << p->data.nama
         << " masuk antrian\n";

    isiPCKosong();
}

void tampilPelanggan(){
    if(head == nullptr){
        cout << "Belum ada pelanggan\n";
        return;
    }

    List *bantu = head;

    cout << "\n=== DATABASE PELANGGAN ===\n";

    while(bantu != nullptr){

        cout << "ID      : "
             << bantu->data.id << endl;

        cout << "Nama    : "
             << bantu->data.nama << endl;

        cout << "Status  : "
             << bantu->data.status << endl;

        cout << "--------------------------\n";

        bantu = bantu->next;
    }
}

void tampilAntrian(){
    if(frontQ == nullptr){
        cout << "\nAntrian kosong\n";
        return;
    }

    Queue *bantu = frontQ;
    int no = 1;

    cout << "\n=== PRIORITY QUEUE ===\n";

    while(bantu != nullptr){

        cout << no++ << ". "
             << bantu->data.nama
             << " ("
             << bantu->data.status
             << ")\n";

        bantu = bantu->next;
    }
}

void tampilPC(){
    cout << "\n=== KOMPUTER AKTIF ===\n";

    for(int i = 0; i < MAX_PC; i++){

        cout << "PC "
             << i + 1
             << " : ";

        if(terisi[i]){
            cout << pc[i].nama
                 << " ("
                 << pc[i].status
                 << ")";
        }
        else{
            cout << "Kosong";
        }

        cout << endl;
    }
}

void selesaiMain(){
    int nomor;

    cout << "\nPilih PC yang selesai : ";
    cin >> nomor;

    nomor--;

    if(nomor < 0 || nomor >= MAX_PC){
        cout << "Nomor PC tidak valid\n";
        return;
    }

    if(!terisi[nomor]){
        cout << "PC tersebut kosong\n";
        return;
    }

    Stack *baru = new Stack;
    baru->data = pc[nomor];
    baru->next = topS;
    topS = baru;

    cout << pc[nomor].nama
         << " selesai bermain\n";

    terisi[nomor] = false;

    if(frontQ != nullptr){

        Pelanggan p;
        dequeuePriority(p);

        pc[nomor] = p;
        terisi[nomor] = true;

        cout << p.nama
             << " masuk ke PC "
             << nomor + 1 << endl;
    }
}

void tampilRiwayat(){
    if(topS == nullptr){
        cout << "\nBelum ada riwayat\n";
        return;
    }

    Stack *bantu = topS;
    int no = 1;

    cout << "\n=== RIWAYAT SELESAI ===\n";

    while(bantu != nullptr){

        cout << no++ << ". "
             << bantu->data.nama
             << " ("
             << bantu->data.status
             << ")\n";

        bantu = bantu->next;
    }
}

int main(){

    initPC();

    int pilih;

    do{
        cout << "\n========== WARNET ==========\n";
        cout << "1. Tambah Pelanggan\n";
        cout << "2. Masuk Antrian\n";
        cout << "3. Tampilkan Database\n";
        cout << "4. Tampilkan Antrian\n";
        cout << "5. Tampilkan PC Aktif\n";
        cout << "6. Pelanggan Selesai Bermain\n";
        cout << "7. Tampilkan Riwayat\n";
        cout << "8. Keluar\n";
        cout << "Pilihan : ";
        cin >> pilih;

        switch(pilih){

            case 1:
                tambahPelanggan();
                break;

            case 2:
                masukAntrian();
                break;

            case 3:
                tampilPelanggan();
                break;

            case 4:
                tampilAntrian();
                break;

            case 5:
                tampilPC();
                break;

            case 6:
                selesaiMain();
                break;

            case 7:
                tampilRiwayat();
                break;

            case 8:
                cout << "\nProgram selesai\n";
                break;

            default:
                cout << "\nPilihan tidak valid\n";
        }

    }while(pilih != 8);

    return 0;
}