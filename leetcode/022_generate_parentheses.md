#Generate Parentheses
`left` represents how many more left parentheses are needed. Once the number of left parentheses increases, corresponding need represented by `right` for right parenthese increases. Hence the algorithm will halt once the needs are satisfied (`left` and `right` drop to zero);
```C++
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> sol;
        string ans;
        dfs(n, 0, ans, sol);
        return sol;
    }
    void dfs(int left, int right, string& ans, vector<string>& sol) {
        if (left == 0 && right == 0) sol.push_back(ans);
        if (left > 0) {
            ans.push_back('(');
            dfs(left - 1, right + 1, ans, sol);
            ans.pop_back();
        }
        if (right > 0) {
            ans.push_back(')');
            dfs(left, right - 1, ans, sol);
            ans.pop_back();
        }
    }
};
```
