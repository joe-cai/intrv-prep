#Reverse Integer
##Why I did not make it in the first try:
There is imbalance between INT_MAX and INT_MIN. And thus it is inappropriate to use -INT_MIN.

```C++
class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN)
            return 0;
        if (x < 0)
            return -reverse(-x);
        
        int rx = 0;
        while (x != 0) {
            if (rx > INT_MAX / 10 || 10 * rx > INT_MAX - x % 10)
                return 0;
            rx = rx * 10 + x % 10;
            x = x / 10;
        }
        return rx;
    }
};
```
