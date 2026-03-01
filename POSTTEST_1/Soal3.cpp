#include <iostream>
using namespace std;

void reverseArray(int* arr, int n) {
    int* kiri = arr;
    int* kanan = arr + n - 1;

    while (kiri < kanan) {
        int temp = *kiri;
        *kiri = *kanan;
        *kanan = temp;

        kiri++;
        kanan--;
    }
}

int main(){
    int prima[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;
    int *p = prima;

    cout << "Sebelum dibalik: ";
    while (p < prima + n) {
        cout << *p << " ";
        p++;
    }
    cout << endl;

    p = prima;
    cout << "Alamat memori tiap elemen:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "prima[" << i << "] = " << *p << "  ---->  " << p << endl;
        p++;
    }
    cout << endl;

    reverseArray(prima, n);

    cout << "Sesudah dibalik: ";
    p = prima;
    while (p < prima + n) {
        cout << *p << " ";
        p++;
    }
    cout << endl;

    return 0;
}