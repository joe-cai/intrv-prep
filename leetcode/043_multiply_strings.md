#Multiply Strings
```C++
class Solution {
public:
    string multiply(string num1, string num2) {
        string ans(num1.size() + num2.size(), '0');
        for (int i = num1.size() - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = num2.size() - 1; j >= 0; j--) {
                carry = ans[i + j + 1] - '0' + (num1[i] - '0') * (num2[j] - '0') + carry;
                ans[i + j + 1] = carry % 10 + '0';
                carry /= 10;
            }
            ans[i] = carry + '0';
        }
        for (int i = 0; i < ans.size(); i++) if (ans[i] != '0') return ans.substr(i, ans.size() - i);
        return "0";
    }
};
```
