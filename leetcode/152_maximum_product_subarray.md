#Maximum Product Subarray
```C++
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int ans = nums[0];
        int minP = nums[0], maxP = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) swap(minP, maxP);
            minP = min(minP * nums[i], nums[i]);
            maxP = max(maxP * nums[i], nums[i]);
            ans = max(ans, maxP);
        }
        return ans;
    }
};
```
