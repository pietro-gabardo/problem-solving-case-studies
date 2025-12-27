#include <iostream>
#include <string>
#include <climits>

using namespace std;

/*
* Problem: 8. String to Integer (atoi)
* Difficulty: Medium
* Time Complexity: O(n)
* Space Complexity: O(1)
*/ 

int myAtoi(string s) {
    int i = 0;
    int sign = 1;
    long result = 0;
    const int n = s.length();

    while (i < n && s[i] == ' ') i++;

    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    while (i < n && s[i] >= '0' && s[i] <= '9') {
        result = result * 10 + (s[i++] - '0');
        
        if (result > INT_MAX) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
    }

    return (int)(result * sign);
}

/* Short explanation
* First scrap the string then each character is transformed into a string, or make the program return
*/

int main() {
    string input = "   -42";
    cout << "Result: " << myAtoi(input) << endl;
    return 0;
}