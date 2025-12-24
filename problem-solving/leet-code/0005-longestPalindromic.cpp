#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

/*
* Problem: 5. Longest Palindromic Substring
* Difficulty: Medium
* Time Complexity: O(n^2)
* Space Complexity: O(1)
*/

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;

        int start = 0, maxLen = 1;

        for (int i = 0; i < s.length(); i++) {
            expand(s, i, i, start, maxLen);

            expand(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

private:
    void expand(const string& s, int left, int right, int& start, int& maxLen) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            int currentLen = right - left + 1;
            if (currentLen > maxLen) {
                start = left;
                maxLen = currentLen;
            }
            left--;
            right++;
        }
    }
};

/* Short explanation
* The program tests even and odd palindromes while recording length records in maxLen.
* The search for palindromes is done by expanding from a term i until the ends stop being the same. (for even palindromes, the term i is two characters)
*/


// test case

int main() {
    Solution sol;
    string input = "adadaad";
    
    string result = sol.longestPalindrome(input);

    cout << "Test result: " << result << endl;

};