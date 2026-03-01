#include <iostream>
using namespace std;

void tukarNilai(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;

    cout << "Masukkan nilai x : ";
    cin >> x;
    cout << "Masukkan nilai y : ";
    cin >> y;

    cout << endl;
    cout << "Sebelum ditukar:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    tukarNilai(&x, &y);

    cout << endl;
    cout << "Sesudah ditukar:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}