#include <stdio.h>

void merge(int* nums1, int m, int* nums2, int n, int* result) {
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (nums1[i] >= nums2[j]) {
            result[k++] = nums1[i++];
        } else {
            result[k++] = nums2[j++];
        }
    }

    while (i < m) {
        result[k++] = nums1[i++];
    }

    while (j < n) {
        result[k++] = nums2[j++];
    }
}

int main() {
    int m, n;

    printf("Enter the number of elements in the first array: ");
    scanf("%d", &m);

    int nums1[m];

    printf("Enter the elements of  the first array: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n);

    int nums2[n];

    printf("Enter the elements of the second array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    int result[m + n];

    merge(nums1, m, nums2, n, result);

    printf("The merged array is: ");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}