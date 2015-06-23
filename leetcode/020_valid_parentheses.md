#Valid Parentheses
My solution runs in 0ms with the test cases on Leetcode OJ ...
```C++
class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') stack.push_back(s[i]);
            else if (s[i] == ')') {
                if (stack.empty() || stack.back() != '(') return false;
                stack.pop_back();
            } else if (s[i] == '}') {
                if (stack.empty() || stack.back() != '{') return false;
                stack.pop_back();
            } else if (s[i] == ']') {
                if (stack.empty() || stack.back() != '[') return false;
                stack.pop_back();
            }
        }
        return stack.empty();
    }
};
```
