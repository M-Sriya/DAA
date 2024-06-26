#include <stdio.h>

// Function to perform binary search
int binarySearch(int nums[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (nums[mid] == target)
            return mid;

        // If target greater, ignore left half
        if (nums[mid] < target)
            left = mid + 1;
        // If target is smaller, ignore right half
        else
            right = mid - 1;
    }
    
    // If target is not found
    return -1;
}

// Function to search for target in sorted array
int search(int nums[], int numsSize, int target) {
    // Perform binary search
    return binarySearch(nums, 0, numsSize - 1, target);
}

int main() {
    int nums[] = { -1, 0, 3, 5, 9, 12 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 9;
    
    int result = search(nums, numsSize, target);
    if (result != -1)
        printf("Target %d found at index %d\n", target, result);
    else
        printf("Target %d not found in the array\n", target);
    
    return 0;
}
