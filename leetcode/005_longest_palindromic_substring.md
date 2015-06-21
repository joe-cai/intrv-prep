##Longest Palindromic Substring
#Why I did not make it in the first try
- The minimum length of the longest palindrome in a non-empty string should be 1.
- This problem can be done in constant space, without using DP (table). My previous solution is of time complexity O(N^2) and space complexity O(N^2). In fact, there exists a complicated algorithm **Manacher's Algorithm** which runs in linear time and linear space.

```C++
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0) return "";
        if (s.size() == 1) return s;
        
        int leftmost = 0;
        int rightmost = 0;
        for (int i = 0; i < s.size(); i++) {
            int start = i, end = i;
            while (end + 1 < s.size() && s[end] == s[end + 1]) { end++; }
            while (end + 1 < s.size() && start > 0 && s[start - 1] == s[end + 1]) { start--; end++; }
            if (rightmost - leftmost < end - start) { leftmost = start; rightmost = end;}
        }
        return s.substr(leftmost, rightmost - leftmost + 1);
    }
};
```
