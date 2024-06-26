#include <stdio.h>

int search(int nums[], int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid; 
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int numsSize;
    printf("Enter the size of the array: ");
    scanf("%d", &numsSize);

    int nums[numsSize];
    printf("Enter the elements of the array in ascending order:\n");
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }

    int target;
    printf("Enter the target value: ");
    scanf("%d", &target);

    int result = search(nums, numsSize, target);
    if (result != -1) {
        printf("Target found at index %d\n", result);
    } else {
        printf("-1");
    }
    return 0;
}