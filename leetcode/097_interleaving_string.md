#Interleaving String
Dynamic programming solution: match the last letter of s3 and that of either s1 or s2
```C++
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        for (int col = 0; col <= s2.size(); col++)
            dp[0][col] = (s2.substr(0, col) == s3.substr(0, col));
        for (int row = 1; row <= s1.size(); row++) {
            dp[row][0] = (s1.substr(0, row) == s3.substr(0, row));
            for (int col = 1; col <= s2.size(); col++)
                dp[row][col] = ((s1[row - 1] == s3[row + col - 1]) ? dp[row - 1][col] : false) ||
                               ((s2[col - 1] == s3[row + col - 1]) ? dp[row][col - 1] : false);
        }
        return dp[s1.size()][s2.size()];
    }
};
```
