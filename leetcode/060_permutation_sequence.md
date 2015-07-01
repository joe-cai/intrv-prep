#Permutation Sequence
```C++
class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        // initialization
        vector<int> nums(n, 0);
        vector<int> fact(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            nums[i - 1] = i;
            fact[i] = fact[i - 1] * i;
        }
        // locating permutation
        n--;
        k--;
        while (n > 0) {
            ans.push_back(nums[k / fact[n]] + '0');
            nums.erase(nums.begin() + k / fact[n]);
            k = k % fact[n];
            n--;
        }
        ans.push_back(nums[0] + '0');
        return ans;
    }
};
```
