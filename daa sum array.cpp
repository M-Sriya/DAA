#include <stdio.h>
int sumOfDigits(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int maximumSum(int* nums, int numsSize) {
    int maxSum = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            int sumI = sumOfDigits(nums[i]);
            int sumJ = sumOfDigits(nums[j]);
            if (sumI == sumJ) {
                int sum = nums[i] + nums[j];
                if (sum > maxSum) {
                    maxSum = sum;
                }
            }
        }
    }
    return maxSum;
}

int main() {
    int nums[] = {18, 43, 36, 13, 58};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = maximumSum(nums, numsSize);
    printf("Maximum sum: %d\n", result);
    return 0;
}