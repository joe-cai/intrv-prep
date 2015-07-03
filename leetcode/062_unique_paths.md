#Unique Paths
```C++
class Solution {
public:
    int uniquePaths(int m, int n) {
        long res = 1;
        // calculating combinorial(m - 1, m + n - 2)
        for (int i = 1; i <= min(n - 1, m - 1); i++)
            res = (m + n - i - 1) * res / i; // possible overflow given 4 bytes!
        return (int)res;
    }
};
```
