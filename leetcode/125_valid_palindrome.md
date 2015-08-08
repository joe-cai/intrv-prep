#Valid Palindrome
```C++
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < s.size() && !isAlphaNumeric(s[left])) { left++; }
            while (right < s.size() && !isAlphaNumeric(s[right])) { right--; }
            if (max(left, right) < s.size() && s[left++] != s[right--]) return false;
        }
        return true;
    }
    bool isAlphaNumeric(char& c) {
        if (c >= 'a' && c <= 'z') return true;
        if (c >= 'A' && c <= 'Z') { c = 'a' + c - 'A'; return true;}
        if (c >= '0' && c <= '9') return true;
        return false;
    }
};
```