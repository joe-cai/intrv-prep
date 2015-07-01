#Maximum Subarrays
##O(N) linear solution
```C++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int sol = nums[0];
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += nums[i];
            sol = max(sol, ans);
            if (ans < 0) ans = 0;
        }
        return sol;
    }
};
```

##O(NlogN) divide and conquer solution
```C++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        return dc(nums, 0, nums.size() - 1);
    }
    int dc(vector<int>& nums, int start, int end) {
        if (start == end) return nums[start];
        
        int mid = (start + end) / 2;
        int leftMax = nums[mid], leftSum = 0;
        for (int i = mid; i >= start; i--) {
            leftSum += nums[i];
            leftMax = max(leftSum, leftMax);
        }
        int rightMax = nums[mid + 1], rightSum = 0;
        for (int i = mid + 1; i <= end; i++) {
            rightSum += nums[i];
            rightMax = max(rightSum, rightMax);
        }
            
        return max(leftMax + rightMax, 
        max(dc(nums, start, mid), dc(nums, mid + 1, end)));
    }
};
```
