#Search in Rotated Sorted Array
Note that *no duplicates* is an important assumption for this algorithm to be correct.
```C++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) return mid;
            // decide which side is in order
            if (nums[mid] >= nums[start]) { // left is in order, search the right one
                if (target > nums[mid] || target < nums[start]) { start = mid + 1; }
                else { end = mid - 1; }
            } else if (nums[mid] < nums[start]) { // right is in order, search left
                if (target < nums[mid] || target > nums[end]) { end = mid - 1; }
                else { start = mid + 1; }
            }
        }
        return -1;
    }
};
```
