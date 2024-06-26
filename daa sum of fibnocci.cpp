#include <stdio.h>

int main() {
    int N, a = 0, b = 1, sum = 0, even_sum = 0;

    printf("Enter a number N: ");
    scanf("%d", &N);

    while (a <= N) {
        if (a % 2 == 0) {
            even_sum += a;
        }
        sum += a;
        int temp = a;
        a = b;
        b = temp + b;
    }

    printf("Even sum of Fibonacci series till %d is: %d\n", N, even_sum);

    return 0;
} 