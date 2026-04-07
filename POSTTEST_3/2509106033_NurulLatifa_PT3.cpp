#include <iostream>
#include <string>
using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    string layanan;
    int harga;
};

struct RiwayatTindakan {
    int idHewan;
    string namaHewan;
    string tindakan;
};

const int MAKS = 100;
int jumlah = 0;
Hewan daftar[MAKS];

const int MAX_QUEUE = 50;
Hewan antrianQueue[MAX_QUEUE];
int qFront = -1, qRear = -1;

const int MAX_STACK = 50;
RiwayatTindakan riwayatStack[MAX_STACK];
int stackTop = -1;

void bersihInput(string &s) {
    if (!s.empty() && s[s.length()-1] == '\r')
        s.erase(s.length()-1);
}

bool isQueueFull() { return qRear == MAX_QUEUE - 1; }
bool isQueueEmpty() { return qFront == -1 || qFront > qRear; }
bool isStackFull()  { return stackTop >= MAX_STACK - 1; }
bool isStackEmpty() { return stackTop < 0; }

void enqueue(Hewan* h) {
    if (isQueueFull()) {
        cout << "\n  [!] Antrian penuh! (Queue Overflow)\n";
        return;
    }
    if (qFront == -1) qFront = 0;
    qRear++;
    *(antrianQueue + qRear) = *h;
    cout << "\n  [v] " << h->nama << " (ID: " << h->id << ") berhasil masuk antrian.\n";
}

Hewan dequeue() {
    Hewan kosong = {-1, "", "", "", 0};
    if (isQueueEmpty()) {
        cout << "\n  [!] Antrian kosong! (Queue Underflow)\n";
        return kosong;
    }
    Hewan* p = (antrianQueue + qFront);
    Hewan dipanggil = *p;
    qFront++;
    if (isQueueEmpty()) qFront = qRear = -1;
    return dipanggil;
}

Hewan peekQueue() {
    Hewan kosong = {-1, "", "", "", 0};
    if (isQueueEmpty()) {
        cout << "\n  [!] Antrian kosong.\n";
        return kosong;
    }
    return *(antrianQueue + qFront);
}

void tampilAntrian() {
    if (isQueueEmpty()) {
        cout << "\n  [!] Antrian kosong.\n";
        return;
    }
    cout << "\n  -- Daftar Antrian Pemeriksaan --\n";
    cout << "  +----+------+--------------------+------------+" << endl;
    cout << "  | No | ID   | Nama Hewan         | Jenis      |" << endl;
    cout << "  +----+------+--------------------+------------+" << endl;
    for (int i = qFront; i <= qRear; i++) {
        Hewan* p = (antrianQueue + i);
        int no = i - qFront + 1;
        cout << "  | " << no;
        if (no < 10) cout << " ";
        cout << " | " << p->id << " | ";
        cout << p->nama;
        int pad = 18 - (int)p->nama.length();
        for (int s = 0; s < pad; s++) cout << " ";
        cout << " | ";
        cout << p->jenis;
        pad = 10 - (int)p->jenis.length();
        for (int s = 0; s < pad; s++) cout << " ";
        cout << " |" << endl;
    }
    cout << "  +----+------+--------------------+------------+" << endl;
}

void pushRiwayat(RiwayatTindakan* r) {
    if (isStackFull()) {
        cout << "\n  [!] Riwayat penuh! (Stack Overflow)\n";
        return;
    }
    stackTop++;
    *(riwayatStack + stackTop) = *r;
    cout << "\n  [v] Tindakan \"" << r->tindakan << "\" untuk " << r->namaHewan << " dicatat.\n";
}

RiwayatTindakan popRiwayat() {
    RiwayatTindakan kosong = {-1, "", ""};
    if (isStackEmpty()) {
        cout << "\n  [!] Riwayat kosong! (Stack Underflow)\n";
        return kosong;
    }
    RiwayatTindakan* p = (riwayatStack + stackTop);
    RiwayatTindakan hasil = *p;
    stackTop--;
    return hasil;
}

RiwayatTindakan peekStack() {
    RiwayatTindakan kosong = {-1, "", ""};
    if (isStackEmpty()) {
        cout << "\n  [!] Riwayat kosong.\n";
        return kosong;
    }
    return *(riwayatStack + stackTop);
}

void tampilRiwayat() {
    if (isStackEmpty()) {
        cout << "\n  [!] Riwayat kosong.\n";
        return;
    }
    cout << "\n  -- Riwayat Tindakan Medis (Terbaru ke Terlama) --\n";
    cout << "  +----+------+--------------------+--------------------+" << endl;
    cout << "  | No | ID   | Nama Hewan         | Tindakan           |" << endl;
    cout << "  +----+------+--------------------+--------------------+" << endl;
    int no = 1;
    for (int i = stackTop; i >= 0; i--) {
        RiwayatTindakan* r = (riwayatStack + i);
        cout << "  | " << no;
        if (no < 10) cout << " ";
        cout << " | " << r->idHewan;
        int tmp = r->idHewan, digits = 0;
        while (tmp > 0) { digits++; tmp /= 10; }
        if (digits == 0) digits = 1;
        int pad = 4 - digits;
        for (int s = 0; s < pad; s++) cout << " ";
        cout << " | ";
        cout << r->namaHewan;
        pad = 18 - (int)r->namaHewan.length();
        for (int s = 0; s < pad; s++) cout << " ";
        cout << " | ";
        cout << r->tindakan;
        pad = 18 - (int)r->tindakan.length();
        for (int s = 0; s < pad; s++) cout << " ";
        cout << " |" << endl;
        no++;
    }
    cout << "  +----+------+--------------------+--------------------+" << endl;
}

void cetakKolom(string teks, int lebar) {
    cout << teks;
    int sisa = lebar - (int)teks.length();
    for (int s = 0; s < sisa; s++) cout << " ";
}

void cetakAngka(int angka, int lebar) {
    string s = "";
    int tmp = angka;
    if (tmp == 0) { s = "0"; }
    else { while (tmp > 0) { s = (char)('0' + tmp % 10) + s; tmp /= 10; } }
    cout << s;
    int sisa = lebar - (int)s.length();
    for (int i = 0; i < sisa; i++) cout << " ";
}

void tampilHeader() {
    cout << "\n";
    cout << "  +===========================================+" << endl;
    cout << "  |        PAWCARE PETSHOP & KLINIK          |" << endl;
    cout << "  |       Jl.Konoha KW 01, Kab.Solo          |" << endl;
    cout << "  +===========================================+" << endl;
}

void tampilGaris() {
    cout << "  +------+--------------------+------------+--------------------+----------+" << endl;
}

void tampilSemuaData(Hewan* arr, int n) {
    if (n == 0) {
        cout << "\n  [!] Belum ada data hewan.\n";
        return;
    }
    cout << "\n";
    tampilGaris();
    cout << "  | "; cetakKolom("ID",   4);
    cout << " | "; cetakKolom("Nama Hewan", 18);
    cout << " | "; cetakKolom("Jenis", 10);
    cout << " | "; cetakKolom("Layanan", 18);
    cout << " | "; cetakKolom("Harga", 8);
    cout << " |" << endl;
    tampilGaris();
    for (int i = 0; i < n; i++) {
        Hewan* p = (arr + i);
        cout << "  | "; cetakAngka(p->id,    4);
        cout << " | "; cetakKolom(p->nama,   18);
        cout << " | "; cetakKolom(p->jenis,  10);
        cout << " | "; cetakKolom(p->layanan,18);
        cout << " | "; cetakAngka(p->harga,  8);
        cout << " |" << endl;
    }
    tampilGaris();
}

void tambahData(Hewan* arr, int &n) {
    if (n >= MAKS) {
        cout << "\n  [!] Data penuh.\n";
        return;
    }
    Hewan* p = (arr + n);
    cout << "\n  -- Tambah Data Hewan Baru --\n";
    cout << "  ID Hewan    : ";
    cin >> p->id;
    cin.ignore(1000, '\n');
    cout << "  Nama Hewan  : ";
    getline(cin, p->nama);
    bersihInput(p->nama);
    cout << "  Jenis Hewan : ";
    getline(cin, p->jenis);
    bersihInput(p->jenis);
    cout << "  Layanan     : ";
    getline(cin, p->layanan);
    bersihInput(p->layanan);
    cout << "  Harga (Rp)  : ";
    cin >> p->harga;
    cin.ignore(1000, '\n');
    n++;
    cout << "\n  [v] Data berhasil ditambahkan.\n";
}

void linearSearch(Hewan* arr, int n, string target) {
    cout << "\n  -- Hasil Linear Search: \"" << target << "\" --\n";
    bool ketemu = false;
    for (int i = 0; i < n; i++) {
        if ((arr + i)->nama == target) {
            cout << "\n  Ditemukan di indeks ke-" << i << ":\n";
            tampilGaris();
            cout << "  | "; cetakKolom("ID",   4);
            cout << " | "; cetakKolom("Nama Hewan", 18);
            cout << " | "; cetakKolom("Jenis", 10);
            cout << " | "; cetakKolom("Layanan", 18);
            cout << " | "; cetakKolom("Harga", 8);
            cout << " |" << endl;
            tampilGaris();
            Hewan* p = (arr + i);
            cout << "  | "; cetakAngka(p->id,    4);
            cout << " | "; cetakKolom(p->nama,   18);
            cout << " | "; cetakKolom(p->jenis,  10);
            cout << " | "; cetakKolom(p->layanan,18);
            cout << " | "; cetakAngka(p->harga,  8);
            cout << " |" << endl;
            tampilGaris();
            ketemu = true;
        }
    }
    if (!ketemu)
        cout << "  [!] Nama hewan tidak ditemukan.\n";
}

int fibonacciSearch(Hewan* arr, int n, int target) {
    int fib2 = 0, fib1 = 1, fib = 1;
    while (fib < n) { fib2 = fib1; fib1 = fib; fib = fib1 + fib2; }
    int offset = -1, langkah = 1;
    cout << "\n  -- Proses Fibonacci Search (ID: " << target << ") --\n";
    while (fib > 1) {
        // Iterasi: tentukan indeks yang diperiksa = offset + fib2
        int i = offset + fib2;
        if (i >= n) i = n - 1;
        cout << "  Langkah " << langkah++ << " -> cek indeks " << i
             << " (ID: " << (arr + i)->id << ") ";
        if ((arr + i)->id == target) {
            // Iterasi selesai: elemen ditemukan
            cout << "=> COCOK\n"; return i;
        } else if ((arr + i)->id < target) {
            // Iterasi: elemen terlalu kecil, eliminasi bagian kiri, geser offset ke kanan
            cout << "=> terlalu kecil, cari kanan\n";
            fib = fib1; fib1 = fib2; fib2 = fib - fib1; offset = i;
        } else {
            // Iterasi: elemen terlalu besar, eliminasi bagian kanan, perkecil range
            cout << "=> terlalu besar, cari kiri\n";
            fib = fib2; fib1 = fib1 - fib2; fib2 = fib - fib1;
        }
    }
    if (fib1 == 1 && (arr + offset + 1)->id == target) {
        cout << "  Langkah " << langkah << " -> cek indeks " << (offset + 1)
             << " (ID: " << (arr + offset + 1)->id << ") => COCOK\n";
        return offset + 1;
    }
    return -1;
}

void swapHewan(Hewan* a, Hewan* b) {
    Hewan temp = *a; *a = *b; *b = temp;
}

void bubbleSort(Hewan* arr, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if ((arr + j)->nama > (arr + j + 1)->nama)
                swapHewan((arr + j), (arr + j + 1));
}

void selectionSort(Hewan* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if ((arr + j)->harga < (arr + minIdx)->harga) minIdx = j;
        if (minIdx != i) swapHewan((arr + i), (arr + minIdx));
    }
}

int main() {
    int pilihan;

    daftar[0] = {1001, "Naruto",  "Anjing", "Grooming",     150000};
    daftar[1] = {1002, "Sasuke",  "Kucing", "Vaksinasi",    200000};
    daftar[2] = {1003, "Hime",    "Burung", "Perawatan",     80000};
    daftar[3] = {1004, "Sakura",  "Kucing", "Grooming",     130000};
    daftar[4] = {1005, "Maruko",  "Anjing", "Pemeriksaan",  175000};
    jumlah = 5;

    do {
        tampilHeader();
        cout << "\n  === MANAJEMEN DATA ===" << endl;
        cout << "  [1] Tampilkan Semua Data Hewan" << endl;
        cout << "  [2] Tambah Data Hewan Baru" << endl;
        cout << "  [3] Cari Nama Hewan (Linear Search)" << endl;
        cout << "  [4] Cari ID Hewan (Fibonacci Search)" << endl;
        cout << "  [5] Urutkan Nama A-Z (Bubble Sort)" << endl;
        cout << "  [6] Urutkan Harga Murah-Mahal (Selection Sort)" << endl;
        cout << "\n  === ANTRIAN & RIWAYAT ===" << endl;
        cout << "  [7]  Daftarkan Hewan ke Antrian (Enqueue)" << endl;
        cout << "  [8]  Panggil Pasien Terdepan (Dequeue)" << endl;
        cout << "  [9]  Catat Tindakan Medis ke Riwayat (Push)" << endl;
        cout << "  [10] Batalkan Tindakan Terakhir (Pop)" << endl;
        cout << "  [11] Intip Antrian & Riwayat (Peek)" << endl;
        cout << "  [12] Tampilkan Semua Antrian" << endl;
        cout << "  [13] Tampilkan Semua Riwayat" << endl;
        cout << "\n  [0] Keluar" << endl;
        cout << "\n  Pilih menu: ";
        cin >> pilihan;
        cin.ignore(1000, '\n');

        if (pilihan == 1) {
            tampilSemuaData(daftar, jumlah);

        } else if (pilihan == 2) {
            tambahData(daftar, jumlah);

        } else if (pilihan == 3) {
            string cariNama;
            cout << "\n  Masukkan nama hewan: ";
            getline(cin, cariNama);
            bersihInput(cariNama);
            linearSearch(daftar, jumlah, cariNama);

        } else if (pilihan == 4) {
            int cariId;
            cout << "\n  Masukkan ID hewan: ";
            cin >> cariId;
            cin.ignore(1000, '\n');
            for (int si = 0; si < jumlah - 1; si++) {
                int minI = si;
                for (int sj = si + 1; sj < jumlah; sj++)
                    if ((daftar + sj)->id < (daftar + minI)->id) minI = sj;
                if (minI != si) swapHewan((daftar + si), (daftar + minI));
            }
            int hasil = fibonacciSearch(daftar, jumlah, cariId);
            if (hasil != -1) {
                Hewan* p = (daftar + hasil);
                cout << "\n  Ditemukan di indeks " << hasil << ":\n";
                tampilGaris();
                cout << "  | "; cetakKolom("ID",4); cout << " | "; cetakKolom("Nama Hewan",18);
                cout << " | "; cetakKolom("Jenis",10); cout << " | "; cetakKolom("Layanan",18);
                cout << " | "; cetakKolom("Harga",8); cout << " |" << endl;
                tampilGaris();
                cout << "  | "; cetakAngka(p->id,4); cout << " | "; cetakKolom(p->nama,18);
                cout << " | "; cetakKolom(p->jenis,10); cout << " | "; cetakKolom(p->layanan,18);
                cout << " | "; cetakAngka(p->harga,8); cout << " |" << endl;
                tampilGaris();
            } else {
                cout << "\n  [!] ID tidak ditemukan.\n";
            }

        } else if (pilihan == 5) {
            bubbleSort(daftar, jumlah);
            cout << "\n  [v] Data diurutkan berdasarkan Nama (A-Z):\n";
            tampilSemuaData(daftar, jumlah);

        } else if (pilihan == 6) {
            selectionSort(daftar, jumlah);
            cout << "\n  [v] Data diurutkan berdasarkan Harga (Termurah):\n";
            tampilSemuaData(daftar, jumlah);

        } else if (pilihan == 7) {
            if (jumlah == 0) {
                cout << "\n  [!] Belum ada data hewan.\n";
            } else {
                int idMasuk;
                cout << "\n  -- Daftarkan Hewan ke Antrian Pemeriksaan --\n";
                tampilSemuaData(daftar, jumlah);
                cout << "\n  Masukkan ID hewan yang akan didaftarkan: ";
                cin >> idMasuk;
                cin.ignore(1000, '\n');
                bool found = false;
                for (int i = 0; i < jumlah; i++) {
                    if ((daftar + i)->id == idMasuk) {
                        enqueue(daftar + i);
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "\n  [!] ID hewan tidak ditemukan.\n";
            }

        } else if (pilihan == 8) {
            cout << "\n  -- Memanggil Pasien Terdepan --\n";
            Hewan dipanggil = dequeue();
            if (dipanggil.id != -1) {
                cout << "\n  Pasien dipanggil:\n";
                cout << "  Nama  : " << dipanggil.nama << endl;
                cout << "  ID    : " << dipanggil.id << endl;
                cout << "  Jenis : " << dipanggil.jenis << endl;
                cout << "\n  [v] Silakan menuju ruang pemeriksaan!\n";
            }

        } else if (pilihan == 9) {
            cout << "\n  -- Catat Tindakan Medis --\n";
            RiwayatTindakan r;
            cout << "  ID Hewan    : ";
            cin >> r.idHewan;
            cin.ignore(1000, '\n');
            cout << "  Nama Hewan  : ";
            getline(cin, r.namaHewan);
            bersihInput(r.namaHewan);
            cout << "  Tindakan    : ";
            getline(cin, r.tindakan);
            bersihInput(r.tindakan);
            pushRiwayat(&r);

        } else if (pilihan == 10) {
            cout << "\n  -- Membatalkan Tindakan Terakhir --\n";
            RiwayatTindakan dihapus = popRiwayat();
            if (dihapus.idHewan != -1) {
                cout << "\n  Tindakan dibatalkan:\n";
                cout << "  Hewan    : " << dihapus.namaHewan << " (ID: " << dihapus.idHewan << ")\n";
                cout << "  Tindakan : " << dihapus.tindakan << "\n";
                cout << "\n  [v] Tindakan berhasil dihapus dari riwayat.\n";
            }

        } else if (pilihan == 11) {
            cout << "\n  -- PEEK: Antrian & Riwayat --\n";
            cout << "\n  [Antrian] Pasien terdepan saat ini:\n";
            Hewan pq = peekQueue();
            if (pq.id != -1) {
                cout << "  -> " << pq.nama << " (ID: " << pq.id << ", " << pq.jenis << ")\n";
            }
            cout << "\n  [Riwayat] Tindakan terakhir dicatat:\n";
            RiwayatTindakan pr = peekStack();
            if (pr.idHewan != -1) {
                cout << "  -> " << pr.tindakan << " untuk " << pr.namaHewan
                     << " (ID: " << pr.idHewan << ")\n";
            }

        } else if (pilihan == 12) {
            tampilAntrian();

        } else if (pilihan == 13) {
            tampilRiwayat();

        } else if (pilihan != 0) {
            cout << "\n  [!] Pilihan tidak valid.\n";
        }

        cout << endl;

    } while (pilihan != 0);

    cout << "\n  Terima kasih telah Berkunjung Ke Pawcare Petshop!";
    cout << "\n  Semoga Peliharaan Kalian Sehat Selalu Yaa~ :3 \n\n";
    return 0;
}