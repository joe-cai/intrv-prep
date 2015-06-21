#Palindrome Number
The following concise solution is based on the solution of the Leetcode forum user `gaurav5`:
```C++
class Solution {
public:
    bool isPalindrome(int x) {
        // ensure that we can get the latter half of x
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;
        int rx = 0;
        while (x > rx) {
            rx = rx * 10 + x % 10;
            x /= 10;
        }
        return (x == rx) || (x == (rx / 10));
    }
};
```
