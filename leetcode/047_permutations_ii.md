#Permutations II
One solution shares similar idea with the solution to the Permutation problem, but may have high space overhead. (Can this overhead be eliminated?)
```C++
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sol;
        fill(sol, nums, 0);
        return sol;
    }
    void fill(vector<vector<int>>& sol, vector<int> nums, int start) {
        if (start == nums.size() - 1) {
            sol.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            if (i == start || nums[start] != nums[i]) {
                swap(nums[start], nums[i]);
                fill(sol, nums, start + 1);
            }
        }
    }
};```

Another solution is based on the idea of the Next Permutation problem, which is elegant and pretty straight forward.
```C++
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sol;
        sol.push_back(nums);
        for(;;) {
            int pos = nums.size() - 1;
            for (; pos >= 1 && nums[pos - 1] >= nums[pos]; pos--);
            if (pos == 0) break;
            int swapIdx = pos;
            while (swapIdx < nums.size() && nums[swapIdx++] > nums[pos - 1]) {}
            swap(nums[swapIdx - 1], nums[pos - 1]);
            reverse(nums.begin() + pos, nums.end());
            sol.push_back(nums);
        }
        return sol;
    }
};
```
