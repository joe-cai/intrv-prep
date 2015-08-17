#Palindrome Partitioning II
Solution by `tqlong`. A table recording if s[i,j] is palindrome is not required.
```C++
class Solution {
public:
    int minCut(string s) {
        // ans[k] is the min # of cuts needed for the first k characters
        vector<int> ans(s.size() + 1, s.size() - 1);
        ans[0] = -1;
        for (int i = 0; i < s.size(); i++) {
            // start from the last character: odd palindrome
            for (int j = 0; j <= i && j < s.size() - i && s[i - j] == s[i + j]; j++)
                ans[i + j + 1] = min(ans[i + j + 1], ans[i - j] + 1);
            // start from the last two characters: even palindrome
            for (int j = 1; j <= i && j <= s.size() - i && s[i - j] == s[i + j - 1]; j++)
                ans[i + j] = min(ans[i + j], ans[i - j] + 1);
        }
        return ans.back();
    }
};
```