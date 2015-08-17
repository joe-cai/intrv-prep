#Minimum Size Subarray Sum
##O(N) solution
```C++
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ans = nums.size() + 1, sum = 0;
        int start = 0, end = 0;
        while (start < nums.size()) {
            while (end < nums.size() && sum < s) { sum += nums[end++]; }
            if (sum >= s) ans = min(ans, end - start);
            sum -= nums[start++];
        }
        if (ans == nums.size() + 1) return 0;
        return ans;
    }
};
```

##O(NlogN) solution
```C++
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> sums(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i++)
            sums[i] = sums[i - 1] + nums[i - 1];
        int minLen = nums.size() + 1;
        for (int start = 1; start <= nums.size(); start++) {
            int end = binarySearch(s + sums[start - 1], start, sums);
            if (sums[end] - sums[start - 1] >= s)
                minLen = min(minLen, end - start + 1);
        }
        return (minLen <= nums.size())? minLen : 0;
    }
    int binarySearch(int s, int pos, vector<int>& sums) {
        int start = pos, end = sums.size() - 1;
        while (start < end) {
            int mid = (start + end) / 2;
            if (sums[mid] >= s) end = mid;
            else start = mid + 1;
        }
        return start;
    }
};
```