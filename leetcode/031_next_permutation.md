#Next Permutation
##Why I did not make it in the first try:
Used `sort`, which is in fact unnecessary. A simple inplace `reverse` is enough.

```C++
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 0) return;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                int minIdx = i + 1;
                for (int j = i + 1; j < nums.size(); j++)
                    if (nums[j] > nums[i] && nums[j] <= nums[minIdx]) minIdx = j;
		swap(nums[minIdx], nums[i]);
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
        return;
    }
};
```
