#include <stdio.h>
#include <limits.h>

/**
 * Problem: 4. Median of Two Sorted Arrays
 * Time Complexity: O(log(min(m, n)))
 * Space Complexity: O(1)
 */

// Additional functions (necessary)
double fmax_val(double a, double b) { return (a > b) ? a : b; }
double fmin_val(double a, double b) { return (a < b) ? a : b; }

// Its only work without sort because nums1 and nums2 always will be ordered and the sizes are in the input
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int m = nums1Size;
    int n = nums2Size;
    int left = 0, right = m;

    while (left <= right) {
        int posX = (left + right) / 2;
        int posY = (m + n + 1) / 2 - posX;

        int maxLeftX = (posX == 0) ? INT_MIN : nums1[posX - 1];
        int minRightX = (posX == m) ? INT_MAX : nums1[posX];

        int maxLeftY = (posY == 0) ? INT_MIN : nums2[posY - 1];
        int minRightY = (posY == n) ? INT_MAX : nums2[posY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if ((m + n) % 2 == 0) {
                return (fmax_val(maxLeftX, maxLeftY) + fmin_val(minRightX, minRightY)) / 2.0;
            } else {
                return (double)fmax_val(maxLeftX, maxLeftY);
            }
        } else if (maxLeftX > minRightY) {
            right = posX - 1;
        } else {
            left = posX + 1;
        }
    }

    return 0.0;
}

int main() {
    int nums1[] = {1, 3};
    int nums2[] = {2, 3, 7};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int size2 = sizeof(nums2) / sizeof(nums2[0]);

    double result = findMedianSortedArrays(nums1, size1, nums2, size2);
    
    printf("Test Result: %.5f\n", result);

    return 0;
}