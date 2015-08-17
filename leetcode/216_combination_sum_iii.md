#Combination Sum III
```C++
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> sol;
        vector<int> ans;
        fill(sol, ans, 1, k, n);
        return sol;
    }
    void fill(vector<vector<int>>& sol, vector<int>& ans, int start, int k, int n) {
        if (k == 0 && n == 0) {
            sol.push_back(ans);
            return;
        } else if (k == 0 || n == 0 || start > n || start > 9)
            return;
        
        for (int i = start; i <= min(9, n / k); i++) {
            ans.push_back(i);
            fill(sol, ans, i + 1, k - 1, n - i);
            ans.pop_back();
        }
    }
};
```