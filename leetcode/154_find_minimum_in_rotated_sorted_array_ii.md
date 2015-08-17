#Find Minimum in Rotated Sorted Array II
It is probably impossible to find the minimum with O(logN) time in this case. But so far no rigorous proof is given.
```C++
class Solution {
public:
    int findMin(vector<int>& nums) {
        int min_ele = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
            min_ele = min(nums[i], min_ele);
        return min_ele;
    }
};
```
