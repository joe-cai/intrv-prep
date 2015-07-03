#Sqrt(x)
```C++
class Solution {
public:
    int mySqrt(int x) {
        long long start = 0;
        long long end = x;
        while (start < end) {
            long long mid = (start + end) / 2;
            if (mid * mid < x) start = mid + 1;
            else end = mid;
        }
        return (start * start == x)? start : start - 1;
    }
};
```
##Tips
Watch out for overflow during squaring `mid * mid`.
