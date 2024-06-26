#include <stdio.h>

int is_palindrome(int x) {
    int reversed = 0;
    int original = x;

    while (x != 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10;
    }

    return original == reversed;
}

int main() {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (is_palindrome(x)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}