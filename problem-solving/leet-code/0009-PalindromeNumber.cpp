#include <iostream>

using namespace std;

/*
* Problem: 9. Palindrome Number
* Difficulty: Medium
* Time Complexity: O(log(n))
* Space Complexity: O(1)
*/

class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reverse = 0;
        while (x > reverse) {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }

        return x == reverse || x == reverse / 10;
    }
};

/* Short explanation
* To make the code faster, instead of inverting all the values ​​of x, only half of them are inverted. Then, the inverted half and n are compared to check if the input is a palindrome or not.
*/

int main() {
    int input = 12321;
    Solution sol;

    bool result = sol.isPalindrome(input);

    cout << "The result is: " << result; 
}