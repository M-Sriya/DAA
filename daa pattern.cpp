#include <stdio.h>

int main() {
    int i, j, rows;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    for (i = 1; i <= rows; ++i) {
    	printf("  ");
        // Print leading spaces
        for (j = 1; j <= rows - i; ++j) {
            printf("  ");
        }
        // Print numbers
        for (j = 1; j <= i-1; ++j) {
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}