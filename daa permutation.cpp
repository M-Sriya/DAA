#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void permute(int arr[], int l, int r) {
    if (l == r)
        printf("%d", arr[l]);
    else {
        for (int i = l; i <= r; i++) {
            swap((arr+l), (arr+i));
            permute(arr, l+1, r);
            swap((arr+l), (arr+i)); // backtrack
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    printf("\nPermutations are:\n");
    permute(arr, 0, n-1);
    return 0;
}