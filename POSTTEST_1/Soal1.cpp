#include <iostream>
using namespace std;

int main() {
    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;
    int min = A[0];
    int posisi = 0;

    for (int i = 1; i < n; i++) {
        if (A[i] < min) {
            min = A[i];
            posisi = i;
        }
    }

    cout << "Array Fibonacci: ";
    for (int i = 0; i < n; i++) {
        cout << A[i];
        if (i < n - 1) cout << ", ";
    }
    cout << endl;

    cout << "Nilai minimum : " << min << endl;
    cout << "Posisi/Indeks : " << posisi << endl;

    return 0;
}

/*
 * Pseudocode              | Cost | Tmin | Tmax
 * ----------------------- |------|------|------
 * procedure FindMin       | C1   | 1    | 1
 * min <- A[0]             | C2   | 1    | 1
 * for i <- 1 to n-1       | C3   | n    | n
 * if A[i] < min           | C4   | n-1  | n-1
 * min <- A[i]             | C5   | 0    | n-1
 * end if                  | C6   | n-1  | n-1
 * end for                 | C7   | n    | n
 * return min              | C8   | 1    | 1
 * end procedure           | C9   | 1    | 1
 * Total waktu (Tn)        |      | O(n) | O(n)
 *
 * Best case: C5 = 0 (kondisi selalu salah, min tidak pernah diupdate)
 * Tn = C1+C2 + C3*n + C4*(n-1) + 0 + C6*(n-1) + C7*n + C8+C9
 *    = (C3+C4+C6+C7)n + (C1+C2+C8+C9-C4-C6)
 *    = (1+1+1+1)n + (1+1+1+1-1-1)
 *    = 4n+4 => Big-O Best Case : O(n)
 *
 * Worst case: C5 = n-1 (kondisi selalu benar, min selalu diupdate)
 * Tn = C1+C2 + C3*n + C4*(n-1) + C5*(n-1) + C6*(n-1) + C7*n + C8+C9
 *    = (C3+C4+C5+C6+C7)n + (C1+C2+C8+C9-C4-C5-C6)
 *    = (1+1+1+1+1)n + (1+1+1+1-1-1-1)
 *    = 5n+3 => Big-O Worst Case : O(n)
 */