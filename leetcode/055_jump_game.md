#Jump Game
```C++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) return true;
        int pos = 0;
        int reach = pos + nums[pos];
        while (pos < nums.size() - 1 && pos <= reach) {
            reach = max(reach, pos + nums[pos]);
            pos++;
        }
        return reach >= nums.size() - 1;
    }
};
```
