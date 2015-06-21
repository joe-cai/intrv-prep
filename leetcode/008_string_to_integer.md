#String to Integer (atoi)
```C++
class Solution {
public:
    int myAtoi(string str) {
        int pos = 0;
        while (str[pos] == ' ') { pos++; }
        
        int sign = 1;
        if (str[pos] == '-') {
            sign = -1;
            pos++;
        } else if (str[pos] == '+')
            pos++;
        
        int ans = 0;
        if (sign == 1) {
            while (pos < str.size() && str[pos] >= '0' && str[pos] <= '9') {
                if (ans > INT_MAX / 10 || ans * 10 > INT_MAX - (str[pos] - '0'))
                    return INT_MAX;
                ans = ans * 10 + (str[pos] - '0');
                pos++;
            }
        } else {
            while (pos < str.size() && str[pos] >= '0' && str[pos] <= '9') {
                if (ans < INT_MIN / 10 || ans * 10 < INT_MIN + (str[pos] - '0'))
                    return INT_MIN;
                ans = ans * 10 - (str[pos] - '0');
                pos++;
            }
        }
        return ans;
    }
};
```
