#House Robber II
Idea by `macobr`. Since the robber can not rob the first house and the last house at the same time, we can create two seperated vectors, one without the first house, while the other without the last one. Apply the algorithm for House Robber I and get their maximum.
```C++
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        else if (nums.size() == 1) return nums[0];
        return max(rob2(vector<int>(nums.begin(), nums.end() - 1)), 
                   rob2(vector<int>(nums.begin() + 1, nums.end())));
    }
    int rob2(vector<int> nums) {
        if (nums.size() == 0) return 0;
        else if (nums.size() == 1) return nums.front();

        vector<int> cash(nums.size(), 0);
        cash[0] = nums[0];
        cash[1] = max(cash[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
            cash[i] = max(cash[i - 1], nums[i] + cash[i - 2]);
        return cash.back();
    }

};
```