#Remove Duplicates from Sorted Array II
`dup` counts the number of times the current number has appeared. If it reach the specified quota (2 in this case), `nums[i]` will be prevented from pushing into the array. Otherwise, `dup` will be cleared.
```C++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int dup = 0, pos = 1;
        int prev = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (prev == nums[i]) dup++;
            else dup = 0;
            if (dup <= 1) nums[pos++] = nums[i];
            prev = nums[i];
        }
        return pos;
    }
};
```
