#include <iostream>

using namespace std;

/*
* Problem: 7. Reverse Integer
* Difficulty: Medium
* Time Complexity: O(log_{10}(n))
* Space Complexity: O(1)
*/


class Solution {
public:
    int reverse(int x) {
        int result = 0;

        while (x != 0) {
            int pop = x % 10;
            x /= 10;


            if (result > INT_MAX/10 || (result == INT_MAX/10 && pop > 7)) return 0;
            if (result < INT_MIN/10 || (result == INT_MIN/10 && pop < -8)) return 0;

            result = result * 10 + pop;
        }

        return result;
    }
};

/* Short explanation
* The final number(reverse) is constructed by the units from the number x, which loses the unit that gave to the result.
*/

int main () { 
    Solution sol;

    int input = -120;

    int result = sol.reverse(input);

    cout <<  "Result(output): " << result;
}