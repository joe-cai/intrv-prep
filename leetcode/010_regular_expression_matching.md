#Regular Expression Matching
##I made it in the first try!
A key observation is that, `x*` can either be an empty string or `x*x`. This serves as the inductive step to evaluate `match[row][col]` from `match[row - 1][col]`. In the following code, only the first conditional branch is needed for this particular problem. The other parts are for the case where string `s` is also a regular expression itself.

##O(N^2) DP solution
```C++
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> match(s.size() + 1, vector<bool>(p.size() + 1, false));
        match[0][0] = true;
        for (int i = 1; i < p.size(); i++)
            if (p[i] == '*')
                match[0][i + 1] = match[0][i - 1];

        for (int row = 1; row <= s.size(); row++) {
            if (s[row - 1] != '.' && s[row - 1] != '*') {
                match[row][0] = false;
                for (int col = 1; col <= p.size(); col++) {
                    if (p[col - 1] != '*')
                        match[row][col] = match[row - 1][col - 1] && (s[row - 1] == p[col - 1] || p[col - 1] == '.');
                    else { // Given a valid p, p[col - 1] == '*', p[col - 2] must exist, i.e. col >= 2.
                        // match at least 1 character
                        match[row][col] = match[row - 1][col] && (s[row - 1] == p[col - 2] || p[col - 2] == '.'); 
                        match[row][col] = match[row][col] || match[row][col - 2]; // empty match
                    }
                }
            } else if (s[row - 1] == '.') {
                match[row][0] = false;
                for (int col = 1; col <= p.size(); col++) {
                    if (p[col - 1] != '*')
                        match[row][col] = match[row][col] || match[row - 1][col - 1];
                    else // p[col - 1] == '*', p[0] != '*', so col >= 2
                        match[row][col] = match[row][col] || match[row - 1][col] || match[row][col - 2];
                }
            } else if (s[row - 1] == '*') { // s[row - 2] must exist
                match[row][0] = match[row - 2][0];
                for (int col = 1; col <= p.size(); col++) {
                    if (p[col - 1] != '*') {
                        match[row][col] = match[row][col - 1] && (s[row - 2] == p[col - 1] || p[col - 1] == '.' );
                    } else // p[col - 1] == '*'
                        match[row][col] = match[row][col - 2];
                    match[row][col] = match[row][col] || match[row - 2][col]; // empty match
                }
            }
        }
        return match[s.size()][p.size()];
    }
};
```
