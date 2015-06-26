#Count and Say
```C++
class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        string ans = "1";
        for (int i = 0; i < n - 1; i++) {
            string sol = "";
            int pos = 0, start = pos;
            for(;;) {
                if (pos == ans.size()) break;
                while (pos < ans.size() && ans[pos] == ans[start]) { pos++; }
                sol.push_back(pos - start + '0');
                sol.push_back(ans[start]);
                start = pos;
            }
            ans = sol;
        }
        return ans;
    }
};
```
