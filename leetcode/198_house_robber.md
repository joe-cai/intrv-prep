#House Robber
```C++
class Solution {
public:
    int rob(vector<int>& nums) {
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
##Note
The space complexity from the `cash` vector can be easily eliminated to obtain an O(1) solution.