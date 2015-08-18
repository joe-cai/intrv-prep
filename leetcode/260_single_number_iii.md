#Single Number III
Code simplified by `zhiqing_xiao` and `StefanPochmann`.
```C++
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        int diff_at_last = diff & ~(diff - 1);

        vector<int> sol(2, 0);
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] & diff_at_last) sol[0] ^= nums[i];
            else sol[1] ^= nums[i];
        return sol;
    }
};
```