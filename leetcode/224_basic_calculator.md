#Basic Calculator
Solution by `mingjun`. The idea is essentially decoupling the input formula from
7 - ( 6 - 5 - ( 4 - 3 ) - 2 ) - ( 1 )
to
+ 7 - 6 + 5 + 4 - 3 + 2 - 1
using the vector `signs`. `southpenguin` presented a more intuitive solution using Java.

```C++
class Solution {
public:
    int calculate(string s) {
        vector<int> signs(1, 1);
        int sum = 0, num = 0, sign = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') num = num * 10 + s[i] - '0';
            else if (s[i] == '(') signs.push_back(sign);
            else if (s[i] == ')') signs.pop_back();
            else if (s[i] == '+' || s[i] == '-') {
                sum += sign * num;
                num = 0;
                sign = ((s[i] == '+')? 1 : -1) * signs.back();
            }
        }
        sum += sign * num;
        return sum;
    }
};
```