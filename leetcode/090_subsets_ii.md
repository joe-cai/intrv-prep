#Subsets II
##Why I did not make it in the first try:
The key is to push `ans` into the return array `sol` every time. This is different from the permutation problem, where `ans` is pushed into `sol` when `ans` reach a particular size.
```C++
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> ans;
        sol.push_back(ans);

        sort(nums.begin(), nums.end());
        fill(sol, ans, nums, 0);
        return sol;
    }
    void fill(vector<vector<int>>& sol, vector<int>& ans, vector<int>& nums, int start) {
        if (start == nums.size())
            return;

        int prev = -1;
        for (int i = start; i < nums.size(); i++) {
            if (prev == -1 || nums[prev] != nums[i]) {
                prev = i;
                ans.push_back(nums[i]);
                sol.push_back(ans);
                fill(sol, ans, nums, i + 1);
                ans.pop_back();
            }
        }
    }
};
```
