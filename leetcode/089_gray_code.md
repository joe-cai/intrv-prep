#Gray Code
```C++
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> codes = {0};
        int base = 1;
        for (int i = 0; i < n; i++) {
            int j = codes.size() - 1;
            for (; j >= 0; j--)
                codes.push_back(codes[j] + base);
            base *= 2;
        }
        return codes;
    }
};
```
