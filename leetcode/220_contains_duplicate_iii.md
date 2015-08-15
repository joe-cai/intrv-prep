#Contains Duplicate III
##O(NlogK) solution using `set` as a k-element window
```C++
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> window;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) window.erase(nums[i - k - 1]);
            auto it = window.lower_bound(nums[i] - t);
            if (it != window.end() && *it - t <= nums[i]) return true;
            window.insert(nums[i]);
        }
        return false;
    }
};
```
##Note
It seems like bucket can be used to find the minimum gap. But I do not yet know how to do it.