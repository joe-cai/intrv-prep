#Longest Common Prefix
```C++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        int pos = 0;
        for(;;) {
            for (int i = 0; i < strs.size(); i++) {
                if (pos == strs[i].size()) return strs[i];
                if (strs[0][pos] != strs[i][pos]) return strs[0].substr(0, pos);
            }
            pos++;
        }
        return strs[0];
    }
};
```
