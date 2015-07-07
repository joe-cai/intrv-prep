#Combinations
```C++
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> sol;
        vector<int> ans;
        fill(sol, ans, n, k, 1);
        return sol;
    }
    void fill(vector<vector<int>>& sol, vector<int>& ans, int n, int k, int prev) {
        if (k == 0) {
            sol.push_back(ans);
            return;
        }
        for (int i = prev; i <= n; i++) {
            ans.push_back(i);
            fill(sol, ans, n, k - 1, i + 1);
            ans.pop_back();
        }
    }
};
```
