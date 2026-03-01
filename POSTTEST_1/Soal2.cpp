#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    float ipk;
};

int main() {
    Mahasiswa mhs[5];
    int n = 5;

    for (int i = 0; i < n; i++) {
        cout << "Data Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama : ";
        cin >> mhs[i].nama;
        cout << "NIM  : ";
        cin >> mhs[i].nim;
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
        cout << endl;
    }

    Mahasiswa tertinggi = mhs[0];
    for (int i = 1; i < n; i++) {
        if (mhs[i].ipk > tertinggi.ipk) {
            tertinggi = mhs[i];
        }
    }

    cout << ">>> Data Semua Mahasiswa <<<" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nama : " << mhs[i].nama << " | NIM : " << mhs[i].nim << " | IPK : " << mhs[i].ipk << endl;
    }

    cout << endl;
    cout << ">>> Mahasiswa IPK Tertinggi <<<" << endl;
    cout << "Nama : " << tertinggi.nama << endl;
    cout << "NIM  : " << tertinggi.nim << endl;
    cout << "IPK  : " << tertinggi.ipk << endl;

    return 0;
}
