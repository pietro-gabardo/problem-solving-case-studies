#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
* Problem: 1. Two Sum
* Difficulty: Easy
* Time Complexity: O(n)
* Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> numMap;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement)) {
                return {numMap[complement], i}; // Soluction found case
            }
            numMap[nums[i]] = i;
        }

        return {}; // There is no soluction
    }
};

/* Short explanation
* The program run the list (hash map) once, searching for the presence of the complement (n - target = complement). If the complement is found, the solution has been obtained and the code returns the indices.
*/

// test case:
int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> result = sol.twoSum(nums, target);
    
    if (!result.empty()) {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "Solluction not found" << endl;
    }
    return 0;   
}
