#include <stdio.h>

void find_min_max(int arr[], int low, int high, int* min, int* max) {
    if (low == high) {
        *min = arr[low];
        *max = arr[low];
    } else if (low + 1 == high) {
        if (arr[low] < arr[high]) {
            *min = arr[low];
            *max = arr[high];
        } else {
            *min = arr[high];
            *max = arr[low];
        }
    } else {
        int mid = (low + high) / 2;
        int min1, max1, min2, max2;

        find_min_max(arr, low, mid, &min1, &max1);
        find_min_max(arr, mid + 1, high, &min2, &max2);

        *min = (min1 < min2)? min1 : min2;
        *max = (max1 > max2)? max1 : max2;
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min, max;
    find_min_max(arr, 0, n - 1, &min, &max);

    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    return 0;
}