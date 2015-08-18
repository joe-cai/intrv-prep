#Basic Calculator II
```C++
class Solution {
public:
    int calculate(string s) {
        trim(s);
        
        vector<int> stack;
        int pos = 0, num = 0;
        char sign = '+';
        while (pos < s.size()) {
            if (s[pos] >= '0' && s[pos] <= '9') num = 10 * num + s[pos] - '0';
            if (s[pos] < '0' || s[pos] > '9' || pos == s.size() - 1) {
                if (sign == '+') stack.push_back(num);
                else if (sign == '-') stack.push_back(-num);
                else if (sign == '*') stack[stack.size() - 1] *= num;
                else if (sign == '/') stack[stack.size() - 1] /= num;
                sign = s[pos];
                num = 0;
            }
            pos++;
        }
        int res = 0;
        for (int i = 0; i < stack.size(); i++) res += stack[i];
        return res;
    }
    void trim(string &s) {
        int pos = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] != ' ') s[pos++] = s[i];
        while (s.size() > pos) { s.pop_back(); }
    }
};
```
