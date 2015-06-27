#Longest Valid Parentheses
##Why I did not make it in the first try:
Though I finally manage to make the oj accept my solution, it is actually not clear enough, and the code seems ugly. The following ideas are stolen from the Leetcode Forum.

##O(N) solution using stack (by `flyflybird`)
The idea is to keep the top of the stack as index of the end of last invalid sequence, so that the length of subsequent sequence can be offset from it using the index of the right parenthese.
```C++
class Solution {
public:
    int longestValidParentheses(string s) {
        // always storing the index preceding
        // a sequence of valid parentheses
        vector<int> stack;
        stack.push_back(-1);
        
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                stack.push_back(i);
            else {
                // update maximal length
                // whenever ')' is encountered
                stack.pop_back();
                if (stack.empty())
                    // new start, just like -1
                    stack.push_back(i);
                else
                    ans = max(ans, i - stack.back());
            }
        }
        return ans;
    }
};
```

##O(N) solution using dynamic programming (by `jerryrcwong`)
The idea to store the longest valid sequence that ends with string[i] in array[i], which is pretty straight forward. But the update rule needs to be taken care.
```C++
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() <= 1) return 0;
        vector<int> length(s.size(), 0);
        if (s[0] == '(' && s[1] == ')') length[1] = 2;

        int ans = length[1];
        for (int i = 2; i < s.size(); i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') 
                    length[i] = length[i - 2] + 2;
                else if (i > length[i - 1] && s[i - length[i - 1] - 1] == '(') {
                    length[i] = length[i - 1] + 2;
                    if (i >= length[i - 1] + 2) // in cases like ()(())
                        length[i] += length[i - length[i - 1] - 2];
                }
                ans = max(ans, length[i]);
            }
        }
        return ans;
    }
};
```
