#include <stdio.h>

// Function to add two 2x2 matrices
void add_matrices(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two 2x2 matrices
void subtract_matrices(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to perform Strassen's matrix multiplication
void strassen_matrix_multiply(int A[2][2], int B[2][2], int C[2][2]) {
    int M1, M2, M3, M4, M5, M6, M7;

    // Calculate intermediate matrices
    int P1[2][2], P2[2][2], P3[2][2], P4[2][2], P5[2][2], P6[2][2], P7[2][2];

    // M1 = (A11 + A22) * (B11 + B22)
    int A_sum[2][2] = {{A[0][0] + A[1][1], 0}, {0, A[0][0] + A[1][1]}};
    int B_sum[2][2] = {{B[0][0] + B[1][1], 0}, {0, B[0][0] + B[1][1]}};
    add_matrices(A_sum, B_sum, P1);

    // M2 = (A21 + A22) * B11
    int A21_A22[2][2] = {{A[1][0] + A[1][1], 0}, {0, A[1][0] + A[1][1]}};
    add_matrices(A21_A22, B, P2);

    // M3 = A11 * (B12 - B22)
    int B12_B22[2][2] = {{B[0][1] - B[1][1], 0}, {0, B[0][1] - B[1][1]}};
    subtract_matrices(B, B12_B22, P3);
    int A11[2][2] = {{A[0][0], 0}, {0, A[0][0]}};
    add_matrices(A11, P3, P3);

    // M4 = A22 * (B21 - B11)
    int B21_B11[2][2] = {{B[1][0] - B[0][0], 0}, {0, B[1][0] - B[0][0]}};
    subtract_matrices(B, B21_B11, P4);
    int A22[2][2] = {{A[1][1], 0}, {0, A[1][1]}};
    add_matrices(A22, P4, P4);

    // M5 = (A11 + A12) * (B22)
    int A11_A12[2][2] = {{A[0][0] + A[0][1], 0}, {0, A[0][0] + A[0][1]}};
    add_matrices(A11_A12, B, P5);

    // M6 = (A21 - A11) * (B11 + B12)
    int A21_A11[2][2] = {{A[1][0] - A[0][0], 0}, {0, A[1][0] - A[0][0]}};
    int B11_B12[2][2] = {{B[0][0] + B[0][1], 0}, {0, B[0][0] + B[0][1]}};
    subtract_matrices(A, A21_A11, P6);
    add_matrices(B, B11_B12, P6);

    // M7 = (A12 - A22) * (B21 + B22)
    int A12_A22[2][2] = {{A[0][1] - A[1][1], 0}, {0, A[0][1] - A