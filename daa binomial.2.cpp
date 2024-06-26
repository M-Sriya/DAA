#include <stdio.h>

#define MAX_N 100

int binomial_coefficient[MAX_N][MAX_N];

int compute_binomial_coefficient(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    } else if (binomial_coefficient[n][k]!= 0) {
        return binomial_coefficient[n][k];
    } else {
        binomial_coefficient[n][k] = compute_binomial_coefficient(n-1, k-1) + compute_binomial_coefficient(n-1, k);
        return binomial_coefficient[n][k];
    }
}

int main() {
    int n = 8, k = 8;
    printf("Binomial Coefficient (%d, %d) = %d\n", n, k, compute_binomial_coefficient(n, k));
    return 0;
}