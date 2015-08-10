#Palindrome Partitioning
```C++
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> palin(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); i++) { palin[i][i] = true; }
        for (int i = 0; i < s.size() - 1; i++) { palin[i][i + 1] = (s[i] == s[i + 1]); }
        for (int l = 2; l < s.size(); l++) {
            for (int i = 0; i < s.size() - l; i++)
                palin[i][i + l] = (s[i] == s[i + l]) && palin[i + 1][i + l - 1];
        }
        vector<vector<string>> sol;
        vector<string> ans;
        fill(sol, ans, palin, s, 0);
        return sol;
    }
    void fill(vector<vector<string>>& sol, vector<string>& ans, vector<vector<bool>>& palin, string& s, int start) {
        if (start == s.size()) {
            sol.push_back(ans);
            return;
        }
        for (int pos = start; pos < s.size(); pos++) {
            if (palin[start][pos]) {
                ans.push_back(s.substr(start, pos - start + 1));
                fill(sol, ans, palin, s, pos + 1);
                ans.pop_back();
            }
        }
    }
};
```