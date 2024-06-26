#include <stdio.h>

// Function to generate Pascal's Triangle up to n rows
void generate_pascals_triangle(int n) {
    int triangle[n+1][n+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                triangle[i][j] = 1;
            } else {
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
        }
    }

    // Print Pascal's Triangle
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
        	printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 5;
    generate_pascals_triangle(rows);
    return 0;
}
