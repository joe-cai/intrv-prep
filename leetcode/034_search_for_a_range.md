#Search for a Range
```C++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // find lower bound
        int lstart = 0;
        int lend = nums.size() - 1;
        while (lstart < lend) {
            int mid = (lstart + lend) / 2;
            if (nums[mid] < target) lstart = mid + 1;
            else lend = mid;
        }
        if (nums[lstart] != target) lstart = -1;
        // find upper bound
        int rstart = 0;
        int rend = nums.size() - 1;
        while (rstart < rend) {
            int mid = (rstart + rend + 1) / 2;
            if (nums[mid] > target) rend = mid - 1;
            else rstart = mid;
        }
        if (nums[rstart] != target) rstart = -1;
        
        return vector<int> { lstart, rstart };
    }
};
```
