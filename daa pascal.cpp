#include <stdio.h>

void pascalTriangle(int n) {
    int arr[n][n]; 
  

    arr[0][0] = 1;
    printf("%*s%3d\n", n, "", arr[0][0]);

    for (int j = 1; j < n; j++) {
        arr[j][0] = 1; 
        printf("%*s", n-j, "");

        for (int i = 0; i <= j; i++) {
            if (i == 0 || i == j)
                arr[j][i] = 1;
            else 
                arr[j][i] = arr[j-1][i-1] + arr[j-1][i];
            printf("%3d ", arr[j][i]);
        }

        printf("\n");
    }
}

int main() {
    int rows;
    printf("Enter the number of rows: ");
    scanf("%d",&rows);
    pascalTriangle(rows); 
    return 0;
}