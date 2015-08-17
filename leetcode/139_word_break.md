#Word Break
```C++
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> sol(s.size(), false);
        for (int i = 0; i < s.size(); i++) {
            if (wordDict.find(s.substr(0, i + 1)) != wordDict.end())
                sol[i] = true;
            for (int j = 0; j < i; j++) {
                if (sol[j] && !sol[i] && 
		    wordDict.find(s.substr(j + 1, i - j)) != wordDict.end())
                    sol[i] = true;
            }
        }
        return sol.back();
    }
};
```
