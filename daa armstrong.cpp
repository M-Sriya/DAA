#include <stdio.h>
#include <math.h>

int main() {
    int n, sum = 0, temp, digit;

    printf("Enter a number: ");
    scanf("%d", &n);

    temp = n;

    // Calculate the sum of the cubes of each digit
    while (temp > 0) {
        digit = temp % 10;
        sum += pow(digit, 3);
        temp /= 10;
    }

    // Check if the sum is equal to the original number
    if (sum == n) {
        printf("%d is an Armstrong number.\n", n);
    } else {
        printf("%d is not an Armstrong number.\n", n);
    }

    return 0;
}