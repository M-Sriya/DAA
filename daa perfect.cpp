#include <stdio.h>

int isPerfect(int num) {
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return (sum == num);
}

int main() {
    int n;
    printf("Enter the number of perfect numbers to print: ");
    scanf("%d", &n);

    int count = 0;
    int num = 1;

    while (count < n) {
        if (isPerfect(num)) {
            printf("%d ", num);
            count++;
        }
        num++;
    }
    printf("\n");

    return 0;
}