#Combination Sum
```C++
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> sol;
        vector<int> ans;
        sort(candidates.begin(), candidates.end());
        fill(sol, ans, candidates, 0, target);
        return sol;
    }
    void fill(vector<vector<int>>& sol, vector<int>& ans, vector<int>& candidates, int prev, int target) {
        if (target == 0) { sol.push_back(ans); return; }
        for (int i = prev; i < candidates.size() && candidates[i] <= target; i++) {
            ans.push_back(candidates[i]);
            fill(sol, ans, candidates, i, target - candidates[i]);
            ans.pop_back();
        }
    }
};
```
