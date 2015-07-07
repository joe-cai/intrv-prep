#Subsets
The following subset solution is stolen from `thumike`.
```C++
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0) return vector<vector<int>>();
        sort(nums.begin(), nums.end());
        int num_subset = pow(2, nums.size());
        vector<vector<int>> sol(num_subset, vector<int>());
        for (int j = 0; j < num_subset; j++) {
            for (int i = 0; i < nums.size(); i++)
                if ((j >> i) & 1) sol[j].push_back(nums[i]);
        }
        return sol;
    }
};
```
