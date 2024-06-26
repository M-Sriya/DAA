#include <stdio.h>

void backtrack(int arr[], int n, int sum, int target, int index, int current_sum) {
    if (current_sum == target) {
        printf("Subset found: ");
        for (int i = 0; i < index; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    if (current_sum > target) {
        return;
    }

    for (int i = index; i < n; i++) {
        arr[index] = arr[i];w
        backtrack(arr, n, sum, target, index + 1, current_sum + arr[i]);
    }
}

void sum_of_subsets(int arr[], int n, int target) {
    backtrack(arr, n, 0, target, 0, 0);
}

int main() {
    int n, target;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    printf("Sum of subsets problem:\n");
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTarget sum: %d\n", target);

    sum_of_subsets(arr, n, target);

    return 0;
}