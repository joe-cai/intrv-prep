#3Sum Closest
```C++
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sol = nums[0] + nums[1] + nums[2]; // assuming no less than 3 eles
        for (int i = nums.size() - 1; i >= 2; i--) {
            int start = 0, end = i - 1;
            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if (abs(sol - target) > abs(sum - target)) sol = sum;
		(sum > target)? end-- : start++;
            }
        }
        return sol;
    }
};
```
