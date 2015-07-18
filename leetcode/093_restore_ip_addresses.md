#Restore IP Addresses
A recursive solution.
```C++
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> sol;
        if (s.size() > 12) return sol;
        string ans;
        fill(sol, ans, s, 0, 0);
        return sol;
    }
    void fill(vector<string>& sol, string& ans, const string& s, int idx, int pos) {
        if (idx == 4) {
            if (pos == s.size()) sol.push_back(ans); 
            return;
        }
        int end = 3;
        if (s[pos] == '0') end = 1; // if headed with '0', at most 1 digit is allowed
        
        int ip = 0;
        for (int i = pos; i < min((int)s.size(), pos + end); i++) {
            ip = ip * 10 + s[i] - '0';
            if (ip < 256) {
                ans.push_back(s[i]);
                if (idx < 3) ans.push_back('.');
                fill(sol, ans, s, idx + 1, i + 1);
                if (idx < 3) ans.pop_back();
            }
        }
        while (ans.size() > 0 && ans.back() != '.') { ans.pop_back(); }
    }
};
```
