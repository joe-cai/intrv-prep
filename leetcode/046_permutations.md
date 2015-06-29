#Permutations
A amazingly elegant recursive solution by `xiaohui7` using only constant extra spaces.
```C++
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sol;
        fill(sol, nums, 0);
        return sol;
    }
    void fill(vector<vector<int>>& sol, vector<int>& nums, int start) {
        if (start == nums.size()) {
            sol.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            fill(sol, nums, start + 1);
            swap(nums[i], nums[start]);
        }
    }
};
```
