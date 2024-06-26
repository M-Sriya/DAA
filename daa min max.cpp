#include <stdio.h>

void find_nth_max_min(int arr[], int n, int nth_max, int nth_min) {
    int max[n], min[n];
    for (int i = 0; i < n; i++) {
        max[i] = arr[i];
        min[i] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (max[i] < arr[j]) {
                max[i] = arr[j];
            }
            if (min[i] > arr[j]) {
                min[i] = arr[j];
            }
        }
    }

    int nth_max_num = max[nth_max - 1];
    int nth_min_num = min[nth_min - 1];

    printf("Nth maximum number is: %d\n", nth_max_num);
    printf("Nth minimum number is: %d\n", nth_min_num);

    int sum = nth_max_num + nth_min_num;
    int difference = nth_max_num - nth_min_num;

    printf("Sum of nth maximum and nth minimum numbers is: %d\n", sum);
    printf("Difference of nth maximum and nth minimum numbers is: %d\n", difference);
}

int main() {
    int n, nth_max, nth_min;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements in the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of nth maximum: ");
    scanf("%d", &nth_max);

    printf("Enter the value of nth minimum: ");
    scanf("%d", &nth_min);

    find_nth_max_min(arr, n, nth_max, nth_min);

    return 0;
}