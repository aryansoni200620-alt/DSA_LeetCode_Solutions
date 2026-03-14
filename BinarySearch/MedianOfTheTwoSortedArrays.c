#include <limits.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // 1. MUST swap so nums1 is smaller (m <= n)
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int m = nums1Size;
    int n = nums2Size;
    int low = 0, high = m;

    while (low <= high) {
        int partitionX = low + (high - low) / 2; // Prevents overflow
        int partitionY = (m + n + 1) / 2 - partitionX;

        // Correctly handling boundaries using INT_MIN/MAX
        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            // Found the partition!
            if ((m + n) % 2 == 0) {
                return (double)(fmax(maxLeftX, maxLeftY) + fmin(minRightX, minRightY)) / 2.0;
            } else {
                return (double)fmax(maxLeftX, maxLeftY);
            }
        } else if (maxLeftX > minRightY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }
    return 0.0;
}
