#include <string>
#include <iostream>

using namespace std;

/*
* Problem: 6. Zigzag Conversion
* Difficulty: Medium
* Time Complexity: O(n)
* Space Complexity: O(n)
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || numRows >= s.length()) return s;

        string result = "";
        int n = s.length();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                result += s[j + i];
                

                int diagonalIdx = j + cycleLen - i;
                if (i != 0 && i != numRows - 1 && diagonalIdx < n) {
                    result += s[diagonalIdx];
                }
            }
        }
        return result;
    }
};


/* Short explanation
* Following the "zigzag" pattern, the original input is constructed to assemble the given word by the zigzag.
*/

// test case

int main () {
    Solution sol;

    string input_text = "PAYPALISHIRING";
    int input_rows = 4;

    string result = sol.convert(input_text, input_rows);

    cout << "Result(output): " << result;

}