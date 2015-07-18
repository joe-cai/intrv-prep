#Decode Ways
Use 1-D dinamic programming
```C++
class Solution {
public:
    int numDecodings(string s) {
        if (s.size() <= 0) return 0;
        // bug that causes runtime error: vector<int> sol(0, s.size() + 1);
        vector<int> sol(s.size() + 1, 0);
        sol[0] = 1;
        if (s[0] != '0') sol[1] = 1;
        for (int i = 2; i <= s.size(); i++) {
            if (s[i - 1] > '0') sol[i] += sol[i - 1];
            int code = 10 * (s[i - 2] - '0') + s[i - 1] - '0';
            if (s[i - 2] != '0' && code > 0 && code <= 26)
                sol[i] += sol[i - 2];
        }
        return sol[s.size()];
    }
};
```
##Tips
`vector<int> sol(0, s.size())` is one of the apparently buggy code that cannot be recognized in compile time. Take extra care when creating vector array.
