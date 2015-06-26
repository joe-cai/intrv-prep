#Combination Sum II
```C++
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> sol;
        vector<int> ans;
        sort(candidates.begin(), candidates.end());
        fill(sol, ans, 0, candidates, target);
        return sol;
    }
    void fill(vector<vector<int>> &sol, vector<int> &ans, int next, vector<int> candidates, int target) {
        if (target == 0) { sol.push_back(ans); return; }
        for (int i = next; i < candidates.size() && candidates[i] <= target; i++) {
            if (i > next && candidates[i] == candidates[i - 1]) continue;
            ans.push_back(candidates[i]);
            fill(sol, ans, i + 1, candidates, target - candidates[i]);
            ans.pop_back();
        }
    }
};
```
