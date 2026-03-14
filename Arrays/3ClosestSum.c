#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    
    qsort(nums, numsSize, sizeof(int), compare);

    
    long closestSum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            long currentSum = (long)nums[i] + nums[left] + nums[right];

            
            if (currentSum == target) {
                return (int)currentSum;
            }

            
            if (abs(currentSum - target) < abs(closestSum - target)) {
                closestSum = currentSum;
            }

            
            if (currentSum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    return (int)closestSum;
}
