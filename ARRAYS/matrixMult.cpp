#include <iostream>
using namespace std;

int main() {
    int r1, c1, r2, c2;

    cout << "Enter rows and columns of Matrix A: ";
    cin >> r1 >> c1;

    cout << "Enter rows and columns of Matrix B: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Matrix multiplication not possible!";
        return 0;
    }

    int A[10][10], B[10][10], C[10][10] = {0};

    cout << "Enter Matrix A:\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> A[i][j];

    cout << "Enter Matrix B:\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> B[i][j];

    // Matrix multiplication
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Resultant Matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
## Strassen’s Algorithm?
- It’s a faster matrix multiplication algorithm that reduces the number of multiplications.
1. 🧮 Normal method
- 8 multiplications for 2×2 matrices
- Time: O(n³)

2. ⚡ Strassen’s method
- 7 multiplications
- Time: O(n^log₂7) ≈ O(n²·⁸¹)

M1 = (a + d)(e + h)
M2 = (c + d)e
M3 = a(f − h)
M4 = d(g − e)
M5 = (a + b)h
M6 = (c − a)(e + f)
M7 = (b − d)(g + h)

*/