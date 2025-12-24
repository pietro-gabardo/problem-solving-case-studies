# include <iostream>
# include <vector>
# include <algorithm>
# include <climits>

using namespace std;

/*
* Problem: 4. Median of Two Sorted Arrays
* Difficulty: Hard
* Time Complexity: O(\log(\min(m, n)))
* Space Complexity: O(1)
*/

// Its only work without sort because nums1 and nums2 always will be ordered
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;

        while (left <= right) {
            int posX = (left + right) / 2;
            int posY = (m + n + 1) / 2 - posX;


            int maxleftX = (posX == 0) ? INT_MIN : nums1[posX - 1];
            int minrightX = (posX == m) ? INT_MAX : nums1[posX];

            int maxleftY = (posY == 0) ? INT_MIN : nums2[posY - 1];
            int minrightY = (posY == n) ? INT_MAX : nums2[posY];

            if (maxleftX <= minrightY && maxleftY <= minrightX) {

                if ((m + n) % 2 == 0) {
                    return (max(maxleftX, maxleftY) + min(minrightX, minrightY)) / 2.0;
                } else {
                    return max(maxleftX, maxleftY);
                }
            } else if (maxleftX > minrightY) {

                right = posX - 1;
            } else {

                left = posX + 1;
            }
        }
        return 0.0;
    }
};

/* Short explanation
* This is a classic algorithm for finding the median using binary search.
* In summary, the elements are split into two partitions until the largest of the left is less than or equal to the smallest of the right.
* Once the division is correctly determined, it is checked whether the median is given directly by a single central term or by the average of the two central terms.
*/


// Test case

int main() {
    Solution sol;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2, 3, 7};
    cout << "Test Result: " << sol.findMedianSortedArrays(nums1, nums2) << endl;


    return 0;
}
