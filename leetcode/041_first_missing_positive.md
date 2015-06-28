#First Missing Positive
##two pass O(N) Solution
```C++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    	// move numbers to their corresponding positions
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // find the first missing positive
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != i + 1) return i + 1;
        return nums.size() + 1;
    }
};
```
