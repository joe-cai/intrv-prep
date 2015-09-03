#Longest Substring with At Most Two Distinct Characters
Use the technique of slicing window
```C++
class Solution {
public:
    const int ascii = 256;
    const int k = 2;
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> occur(ascii, 0);
        queue<char> substring;
        int count = 0, ans = 0;
        for (int pos = 0; pos < s.size();) {
            while (pos < s.size()) {
                if (occur[s[pos]] == 0 && count == k) break;
                else if (occur[s[pos]] == 0) count++; // count < k
                occur[s[pos]]++;
                substring.push(s[pos++]);
            }
            ans = max(ans, (int)substring.size());
            char toPop = substring.front();
            substring.pop();
            occur[toPop]--;
            if (occur[toPop] == 0) count--;
        }
        return ans;
    }
};
```
