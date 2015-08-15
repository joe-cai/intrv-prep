#Number of One Bits
##Output sensitive solution using `n & n - 1` by `makuiyu`
```C++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n > 0) {
            n = n & (n - 1);
            ans++;
        }
        return ans;
    }
};
```
##Tip
`n & n - 1` essentially deletes the rightmost 1 in the binary representation of n.