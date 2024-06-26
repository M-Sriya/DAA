#include <stdio.h>

void print_subset(int arr[], int n, int subset[], int index) {
    if (index == n) {
        printf("{ ");
        for (int i = 0; i < n; i++) {
            if (subset[i] == 1)
                printf("%d ", arr[i]);
        }
        printf("}\n");
        return;
    }
    subset[index] = 0;
    print_subset(arr, n, subset, index + 1);
    subset[index] = 1;
    print_subset(arr, n, subset, index + 1);
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int subset[n];
    for (int i = 0; i < n; i++)
        subset[i] = 0;
    print_subset(arr, n, subset, 0);
    return 0;
}