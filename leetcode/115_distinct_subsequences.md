#Distinct Subsequences
This version of solution using O(N) space is optimized due to the observation that dynamic programming only needs the previous row to update the current row.
```C++
class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() <= t.size()) return s == t;

        vector<int> sol(t.size() + 1, 0);
        sol[0] = 1;
        for (int pos_s = 1; pos_s <= s.size(); pos_s++) {
            for (int pos_t = t.size(); pos_t >= 1; pos_t--)
                sol[pos_t] += (s[pos_s - 1] == t[pos_t - 1]) * sol[pos_t - 1];
        }
        return sol[t.size()];
    }
};
```
