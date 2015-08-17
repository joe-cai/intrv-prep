#Maximum Gap
##Radix sort solution by `missblit`
```C++
class Solution {
public:
    const int maxBit = 32;
    int maximumGap(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        for (int bit = 0; bit < maxBit; bit++)
            stable_partition(nums.begin(), nums.end(), 
            [bit](int num) { return !(num & (1 << bit)); });
        
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) 
            ans = max(ans, nums[i] - nums[i - 1]);
        return ans;
    }
};
```

##Average gap solution
```C++
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        int maxNum = INT_MIN, minNum = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            maxNum = max(maxNum, nums[i]);
            minNum = min(minNum, nums[i]);
        }
        /* the two steps below is particularly critical to corner cases */
        int avgGap = (maxNum - minNum) / (n - 1) + ((maxNum - minNum) % (n - 1) != 0);
        if (avgGap == 0) return 0;
        vector<int> bucketMax(n, INT_MIN);
        vector<int> bucketMin(n, INT_MAX);
        for (int i = 0; i < n; i++) {
            int idx = (nums[i] - minNum) / avgGap;
            bucketMax[idx] = max(bucketMax[idx], nums[i]);
            bucketMin[idx] = min(bucketMin[idx], nums[i]);
        }
        int prev = bucketMax[0], maxGap = avgGap;
        for (int i = 1; i < n; i++) {
            if (bucketMin[i] > bucketMax[i]) continue;
            maxGap = max(maxGap, bucketMin[i] - prev);
            prev = bucketMax[i];
        }
        return maxGap;
    }
};
```
