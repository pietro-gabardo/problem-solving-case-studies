#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <format>

using namespace std;

/*
* Problem: 3. Longest Substring Without Repeating Characters
* Difficulty: Medium
* Time Complexity: O(n)
* Space Complexity: O(1)
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
 
        int lastSeen[128]; // With this optimization, the runtime decreased by 13ms. (By leetcode test)
        for(int i = 0; i < 128; i++) lastSeen[i] = -1; 

        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char current = s[right];


            if (lastSeen[current] >= left) {
                left = lastSeen[current] + 1;
            }
            lastSeen[current] = right;

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

/* Short explanation
* Utilize an array of 128 integers to store the last seen index of each character.
* In the loop, the right pointer moves through the string, and if the current character was already seen within the current window, the left pointer "jumps" to the position after the previous occurrence.
* Update the character's index in the array and calculate the maxLength at each step until the end of the string
*/



// Test case with some utilities functions:


int main(){
    Solution sol;

    string input = "abcabcbb";
    
    cout << "Input: " << input;

    int result = sol.lengthOfLongestSubstring(input);

    cout << "Result(output): " << result;


}
