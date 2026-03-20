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

int jumlah = 0;
const int MAKS = 100;
Hewan daftar[MAKS];

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
    cin.ignore();
    cout << "  Nama Hewan  : ";
    getline(cin, p->nama);
    cout << "  Jenis Hewan : ";
    getline(cin, p->jenis);
    cout << "  Layanan     : ";
    getline(cin, p->layanan);
    cout << "  Harga (Rp)  : ";
    cin >> p->harga;
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
    int fib2 = 0;
    int fib1 = 1;
    int fib  = 1;

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib  = fib1 + fib2;
    }

    int offset  = -1;
    int langkah =  1;

    cout << "\n  -- Proses Fibonacci Search (ID: " << target << ") --\n";

    while (fib > 1) {
        // Iterasi: tentukan indeks yang diperiksa = offset + fib2
        int i = offset + fib2;
        if (i >= n) i = n - 1;

        cout << "  Langkah " << langkah++ << " -> cek indeks " << i
             << " (ID: " << (arr + i)->id << ") ";

        if ((arr + i)->id == target) {
            // Iterasi selesai: elemen ditemukan
            cout << "=> COCOK\n";
            return i;
        } else if ((arr + i)->id < target) {
            // Iterasi: elemen terlalu kecil, eliminasi bagian kiri, geser offset ke kanan
            cout << "=> terlalu kecil, cari kanan\n";
            fib  = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else {
            // Iterasi: elemen terlalu besar, eliminasi bagian kanan, perkecil range
            cout << "=> terlalu besar, cari kiri\n";
            fib  = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
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
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Hewan* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((arr + j)->nama > (arr + j + 1)->nama) {
                swapHewan((arr + j), (arr + j + 1));
            }
        }
    }
}

void selectionSort(Hewan* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga < (arr + minIdx)->harga) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swapHewan((arr + i), (arr + minIdx));
        }
    }
}

int main() {
    int pilihan;

    daftar[0] = {1001, "Naruto",  "Anjing",  "Grooming",     150000};
    daftar[1] = {1002, "Sasuke",  "Kucing",  "Vaksinasi",    200000};
    daftar[2] = {1003, "Hime",    "Burung",  "Perawatan",     80000};
    daftar[3] = {1004, "Sakura",  "Kucing",  "Grooming",     130000};
    daftar[4] = {1005, "Maruko",  "Anjing",  "Pemeriksaan",  175000};
    jumlah = 5;

    do {
        tampilHeader();
        cout << "\n  [1] Menampilkan Semua Data Hewan" << endl;
        cout << "  [2] Tambah Data Hewan Baru" << endl;
        cout << "  [3] Mencari Nama Hewan (Linear Search)" << endl;
        cout << "  [4] Mencari ID Hewan (Fibonacci Search)" << endl;
        cout << "  [5] Mengurutkan Nama Hewan A-Z (Bubble Sort)" << endl;
        cout << "  [6] Mengurutkan Harga Murah-Mahal (Selection Sort)" << endl;
        cout << "  [0] Keluar" << endl;
        cout << "\n  Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            tampilSemuaData(daftar, jumlah);

        } else if (pilihan == 2) {
            tambahData(daftar, jumlah);

        } else if (pilihan == 3) {
            string cariNama;
            cout << "\n  Masukkan nama hewan: ";
            getline(cin, cariNama);
            linearSearch(daftar, jumlah, cariNama);

        } else if (pilihan == 4) {
            int cariId;
            cout << "\n  Masukkan ID hewan: ";
            cin >> cariId;
            for (int si = 0; si < jumlah - 1; si++) {
                int minI = si;
                for (int sj = si + 1; sj < jumlah; sj++) {
                    if ((daftar + sj)->id < (daftar + minI)->id)
                        minI = sj;
                }
                if (minI != si) swapHewan((daftar + si), (daftar + minI));
            }
            int hasil = fibonacciSearch(daftar, jumlah, cariId);
            if (hasil != -1) {
                Hewan* p = (daftar + hasil);
                cout << "\n  Ditemukan di indeks " << hasil << ":\n";
                tampilGaris();
                cout << "  | "; cetakKolom("ID",   4);
                cout << " | "; cetakKolom("Nama Hewan", 18);
                cout << " | "; cetakKolom("Jenis", 10);
                cout << " | "; cetakKolom("Layanan", 18);
                cout << " | "; cetakKolom("Harga", 8);
                cout << " |" << endl;
                tampilGaris();
                cout << "  | "; cetakAngka(p->id,    4);
                cout << " | "; cetakKolom(p->nama,   18);
                cout << " | "; cetakKolom(p->jenis,  10);
                cout << " | "; cetakKolom(p->layanan,18);
                cout << " | "; cetakAngka(p->harga,  8);
                cout << " |" << endl;
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

        } else if (pilihan != 0) {
            cout << "\n  [!] Pilihan tidak valid.\n";
        }

        cout << endl;

    } while (pilihan != 0);

    cout << "\n  Terima kasih telah Berkunjung Ke Pawcare Petshop!";
    cout << "\n  Semoga Peliharaan Kalian Sehat Selalu Yaa~ :3 \n\n";
    return 0;
}