#Divide Two Integers
My solution does not extend bit length by using `long` or `long long`.
```C++
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == INT_MIN && dividend == INT_MIN) return 1;
        else if (divisor == INT_MIN) return 0;
        else if (divisor == -1 && dividend == INT_MIN) return INT_MAX; // overflow
        else if (dividend == 0) return 0;
        else if (divisor == 0) return INT_MAX;
        
        if (divisor < 0) return -divide(dividend, -divisor);
        
        int ans = 0;
        if (dividend > 0) {
            while (dividend >= divisor) {
                int shift = 0;
                while (dividend - (divisor << shift) >= (divisor << shift)) { shift++; }
                dividend -= (divisor << shift);
                if (INT_MAX - (1 << shift) <= ans) return INT_MAX;
                ans += (1 << shift);
            }
        } else {
            while (dividend <= -divisor) {
                int shift = 0;
                while (dividend + (divisor << shift) <= -(divisor << shift)) { shift++; }
                dividend += (divisor << shift);
                if (INT_MIN + (1 << shift) >= ans) return INT_MIN;
                ans -= (1 << shift);
            }
        }
        return ans;
    }
};
```
