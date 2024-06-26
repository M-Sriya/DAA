  #include <stdio.h>

int reverseNumber(int num) {
    int rev = 0;
    while (num!= 0) {
        int digit = num % 10;
        rev = rev * 10 + digit;
        num /= 10;
    }
    return rev;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int rev = reverseNumber(num);
    printf("Reverse of %d is %d\n", num, rev);

    return 0;
}