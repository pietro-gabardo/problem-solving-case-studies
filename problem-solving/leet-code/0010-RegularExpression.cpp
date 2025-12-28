#include <string>
#include <vector>
#include <iostream>


using namespace std;

/*
* Problem: 10. Regular Expression Matching
* Difficulty: Hard
* Time Complexity: O(n x m)
* Space Complexity: O(n)
*/


class Solution {
public:
    bool isMatch(string s, string p) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = s.size(), n = p.size();

        vector<bool> dp(n + 1, false);

        dp[0] = true;


        for (int j = 2; j <= n; j++) {
            if (p[j - 1] == '*') dp[j] = dp[j - 2];
        }

        for (int i = 1; i <= m; i++) {
            bool prev_diag = dp[0];
            dp[0] = false; 
            
            for (int j = 1; j <= n; j++) {
                bool temp = dp[j];
                
                if (p[j - 1] == '*') {

                    bool char_match = (p[j - 2] == '.' || p[j - 2] == s[i - 1]);
                    dp[j] = dp[j - 2] || (char_match && dp[j]);
                } else {

                    bool char_match = (p[j - 1] == '.' || p[j - 1] == s[i - 1]);
                    dp[j] = char_match && prev_diag;
                }
                prev_diag = temp;
            }
        }

        return dp[n];
    }
};


/* Short explanation
* The program  build a table for p with the possible combination, then compare each relevant cell with s to return if there they are equivalent or no 
*/

int main() {
    Solution sol;
    string input_1 = "aabb", input_2 = "*.b.";

    bool result = sol.isMatch(input_1, input_2);

    cout << "The test result is: " << result;
}