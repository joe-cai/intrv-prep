#Add Binary
```C++
class Solution {
public:
    string addBinary(string a, string b) {
        string sol = "";
        int pos_a = a.size() - 1;
        int pos_b = b.size() - 1;
        int carry = 0;
        while (pos_a >= 0 || pos_b >= 0 || carry > 0) {
            carry += ((pos_a < 0)? 0 : a[pos_a--] - '0');
            carry += ((pos_b < 0)? 0 : b[pos_b--] - '0');
            sol.push_back(carry % 2 + '0');
            carry /= 2;
        }
        reverse(sol.begin(), sol.end());
        return sol;
    }
};
```
