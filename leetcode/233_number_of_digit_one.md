#Number of Digit One
Solution by `StefanPochmann`. The idea is to go through each digit of the number, and count the number of times 1 appears at that position. This quantity can be computed via the product of `prefix` and `subfix` of this number.
```C++
class Solution {
public:
    int countDigitOne(int n) {
        int ans = 0;
        for (long long m = 1; m <= n; m *= 10) {
            int prefix = n / m, subfix = n % m;
            if (prefix % 10 > 1) ans += (prefix / 10 + 1) * m;
            else if (prefix % 10 == 1) ans += (prefix / 10) * m + subfix + 1;
            else if (prefix % 10 == 0) ans += (prefix / 10) * m;
        }
        return ans;
    }
};
```