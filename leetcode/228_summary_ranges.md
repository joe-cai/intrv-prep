#Summary Ranges
```C++
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> sol;
        for (int i = 0; i < nums.size();) {
            int start = i, end = i;
            while (end < nums.size() - 1 && nums[end] + 1 == nums[end + 1]) { end++; }
            if (end > start) sol.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            else sol.push_back(to_string(nums[start]));
            i = end + 1;
        }
        return sol;
    }
};
```