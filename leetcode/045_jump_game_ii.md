#Jump Game II
```C++
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int steps = 1;

        int start = 0;
        int end = nums[0];
        while (end < nums.size() - 1) {
            int ans = 0;
            for (int i = start + 1; i <= end; i++)
                ans = max(ans, i + nums[i]);
            start = end;
            end = ans;
            steps++;
        }
        return steps;
    }
};
```
