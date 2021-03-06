#Longest Consecutive Sequence
Linear solution by `dchen0215`. The idea is to keep the boundary point accurate in the hashmap. At any point, those known to be in the middle of the sequence may not be accurate. But those in the boundary are accurate. The hashmap stores the length of the sequence the boundary point is in.
```C++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> length;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (length.count(nums[i]) > 0) continue;
            int left = (length.count(nums[i] - 1) > 0)? length[nums[i] - 1] : 0;
            int right = (length.count(nums[i] + 1) > 0)? length[nums[i] + 1] : 0;
            int total = left + right + 1;
            length[nums[i] - left] = total;
            length[nums[i] + right] = total;
            length[nums[i]] = total;
            ans = max(ans, total);
        }
        return ans;
    }
};
```