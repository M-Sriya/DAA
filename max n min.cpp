#include <stdio.h>

// Function to find minimum and maximum in an array
void find_min_max(int arr[], int start, int end, int *min_val, int *max_val) {
    int mid, min1, max1, min2, max2;

    // Base case: if there is only one element
    if (start == end) {
        *min_val = arr[start];
        *max_val = arr[start];
        return;
    }

    // Base case: if there are two elements
    if (end == start + 1) {
        if (arr[start] > arr[end]) {
            *max_val = arr[start];
            *min_val = arr[end];
        } else {
            *max_val = arr[end];
            *min_val = arr[start];
        }
        return;
    }

    // Divide the array into two halves
    mid = (start + end) / 2;
    find_min_max(arr, start, mid, &min1, &max1);
    find_min_max(arr, mid + 1, end, &min2, &max2);

    // Combine results from two halves
    *min_val = (min1 < min2) ? min1 : min2;
    *max_val = (max1 > max2) ? max1 : max2;
}

int main() {
    int arr[] = {23, 45, 6, 8, -9, 44, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min_val, max_val;

    find_min_max(arr, 0, n - 1, &min_val, &max_val);

    printf("Minimum value: %d\n", min_val);
    printf("Maximum value: %d\n", max_val);

    return 0;
}
