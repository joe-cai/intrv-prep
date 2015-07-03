#Climbing Stairs
```C++
class Solution {
public:
    int climbStairs(int n) {
        int prev = 1, curr = 1;
        for (int i = 1; i < n; i++) {
            prev = prev + curr;
            swap(prev, curr);
        }
        return curr;
    }
};
```
