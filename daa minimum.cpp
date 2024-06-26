#include <stdio.h>

int main() {
    int n, i, min1, min2;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    if(arr[0] < arr[1]) {
        min1 = arr[0];
        min2 = arr[1];
    }
    else {
        min1 = arr[1];
        min2 = arr[0];
    }
    for(i=2; i<n; i++) {
        if(arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        }
        else if(arr[i] < min2 && arr[i] != min1) {
            min2 = arr[i];
        }
    }
    printf("\nThe first two minimum values are %d and %d\n", min1, min2);
    return 0;
}