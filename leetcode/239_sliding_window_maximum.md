#Sliding Window Maximum
```C++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> window; // indexes
        for (int i = 0; i < nums.size(); i++) {
            while (!window.empty() && nums[i] >= nums[window.back()]) { window.pop_back(); }
            if (!window.empty() && i - window.front() >= k) { window.pop_front(); }
            window.push_back(i);
            if (i >= k - 1) ans.push_back(nums[window.front()]);
        }
        return ans;
    }
};
```