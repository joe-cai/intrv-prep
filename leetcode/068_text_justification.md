#Text Justification
##Why I did not make it in the first try:
Tricked by the corner case ...
```C++
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        if (maxWidth == 0 || words.size() == 0) return words;
        
        vector<string> sol;
        vector<int> ans = {0};
        int size = words[0].size();
        for (int i = 1; i < words.size(); i++) {
            if (size + 1 + words[i].size() <= maxWidth)
                size = size + 1 + words[i].size();
            else {
                justify(words, ans, sol, size, maxWidth);
                size = words[i].size();
                ans.clear();
            }
            ans.push_back(i);
        }
        
        string curr;
        curr += words[ans[0]];
        for (int i = 1; i < ans.size(); i++) curr += " " + words[ans[i]];
        sol.push_back(curr + string(maxWidth - size, ' '));
        return sol;
    }

    void justify(vector<string>& words, vector<int>& ans, vector<string>& sol, int size, int width) {
        if (ans.size() == 1) { // corner case
            sol.push_back(words[ans[0]] + string(width - words[ans[0]].size(), ' '));
            return; 
        }
        int numSpace = (width - size) / (ans.size() - 1) + 1;
        int extraSpace = (width - size) % (ans.size() - 1);
        string line, pad(numSpace, ' '), extrapad(numSpace + 1, ' ');
        for (int i = 0; i < ans.size() - 1; i++) {
            line += words[ans[i]];
            line += (extraSpace-- > 0)? extrapad : pad;
        }
        line += words[ans.back()];
        sol.push_back(line);
    }
};
```
