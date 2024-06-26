#include <stdio.h>

// Function to return the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 0) {
        return -1;  // Error case for invalid input
    } else if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n, i;
    
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Input should be a positive integer.\n");
        return 1;  // Exit the program with an error code
    }
    
    printf("Fibonacci series of %d terms:\n", n);
    for (i = 1; i <= n; i++) {
        printf("%d ", fibonacci(i));
    }
    
    return 0;
}