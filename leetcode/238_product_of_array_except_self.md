#Product of Array Except Self
```C++
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() <= 1) return vector<int>();
        vector<int> sol(nums.size(), 1);
        sol[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            sol[i] = sol[i - 1] * nums[i];
        int rev = 1;
        for (int i = nums.size() - 1; i >= 1; i--) {
            sol[i] = sol[i - 1] * rev;
            rev *= nums[i];
        }
        sol[0] = rev;
        return sol;
    }
};
```