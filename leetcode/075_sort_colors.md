#Sort Colors
The idea is to keep `start` and `end` point to 1's. `[0 ... start - 1]` will be a bunch of 0's, while `[end + 1, nums.size() - 1]` will be bunch of 2's. `pos` scan the array. Once `pos` found a 1, it swap it with `start` and increase the pointer since `start` will always point to an 1. Once `pos` found a 2, it swap it with `end` but does not increase `pos` since `end` might not points to 1. Note the difference in the code.
```C++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0; // pointing to 1's
        int end = nums.size() - 1;

        int pos = 0;
        while (pos <= end) {
            if (nums[pos] == 0) {
                swap(nums[pos++], nums[start++]);
            } else if (nums[pos] == 2) {
                swap(nums[pos], nums[end--]);
            } else pos++;
        }
    }
};
```
