#include <stdio.h>

int binomialCoeff(int n, int k) {
    int C[n + 1][k + 1];
    int i, j;

    // Initialize the first row and column to 1
    for (i = 0; i <= n; i++) {
        C[i][0] = 1;
    }
    for (j = 0; j <= k; j++) {
        C[0][j] = 0;
        C[j][j] = 1;
    }

    // Compute the binomial coefficients using dynamic programming
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= k; j++) {
            if (j > i) {
                C[i][j] = 0;
            } else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }

    return C[n][k];
}

int main() {
    int n=8;
    int k=5;

    int result = binomialCoeff(n, k);
    printf("Binomial coefficient %dC%d is %d\n", n, k, result);

    return 0;
}