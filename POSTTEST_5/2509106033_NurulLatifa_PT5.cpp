#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk Circular Linked List Perpustakaan
struct BukuNode {
    string judulBuku;
    BukuNode* next;

    // Constructor
    BukuNode(string judul) {
        judulBuku = judul;
        next = nullptr;
    }
};

// Fungsi insert di akhir Circular Linked List untuk membangun data
BukuNode* tambahBuku(BukuNode* head, string judul) {
    BukuNode* newNode = new BukuNode(judul);
    if (head == nullptr) {
        newNode->next = newNode;
        return newNode;
    }
    
    BukuNode* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

bool cariBuku(BukuNode* head, string judulDicari) {
    // Jika list kosong, langsung kembalikan false karena tidak ada yang bisa ditelusuri
    if (head == nullptr) return false;

    // Mulai penelusuran dari node pertama (head)
    BukuNode* temp = head;

    // Gunakan do-while agar node head ikut dicek sebelum kondisi berhenti dievaluasi
    do {
        // Cek apakah judul node saat ini cocok dengan judul yang dicari
        if (temp->judulBuku == judulDicari) return true; // Buku ditemukan, kembalikan true

        // Pindah ke node berikutnya
        temp = temp->next;

    } while (temp != head); // Berhenti ketika sudah kembali ke head (satu putaran penuh)

    // Seluruh list sudah ditelusuri dan tidak ditemukan, kembalikan false
    return false;
}

int main() {
    BukuNode* head = nullptr;
    
    head = tambahBuku(head, "Struktur Data dengan C++");
    head = tambahBuku(head, "Pengantar Algoritma");
    head = tambahBuku(head, "Pemrograman Berorientasi Objek");
    head = tambahBuku(head, "Sistem Basis Data");

    string buku1 = "Pengantar Algoritma";
    string buku2 = "Kalkulus Lanjut";

    cout << "Mencari buku '" << buku1 << "': " 
         << (cariBuku(head, buku1) ? "Ditemukan" : "Tidak Ditemukan") << endl; 
         // Harusnya output: Ditemukan

    cout << "Mencari buku '" << buku2 << "': " 
         << (cariBuku(head, buku2) ? "Ditemukan" : "Tidak Ditemukan") << endl; 
         // Harusnya output: Tidak Ditemukan

    return 0;
}