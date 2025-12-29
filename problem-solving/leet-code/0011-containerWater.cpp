#include <vector>
#include <iostream>
#include <algorithm>

/*
* Problem: 11. Container With Most Water
* Difficulty: Medium
* Time Complexity: O(n)
* Space Complexity: O(1)
*/

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {


        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {

            int h = min(height[left], height[right]);
            

            int currentArea = h * (right - left);
            if (currentArea > maxArea) maxArea = currentArea;

            if (height[left] == h) {

                while (left < right && height[left] <= h) {
                    left++;
                }
            } 

            else {
                while (left < right && height[right] <= h) {
                    right--;
                }
            }
        }

        return maxArea;
    }
};


/*  Short explanation
*   Two vectors represent the leftmost and rightmost heights in the input. Then, the volume is calculated given the smaller of these vectors. This process is repeated until all relevant height combinations are made and compared to determine which combination will result in the largest area (this is not volume, as we do not have the depth).
*/

int main(){
    Solution sol;

    vector<int> input = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int result = sol.maxArea(input);

    cout << "The test result is: " << result;
}