#Word Break II
The efficient solution to this problem is pretty much the same as the one of problem `Word Ladder II`. That is, scan from rear to head, store the valid next start indices for the current indices, and finally build solution from head to rear. In this way, every solution built is a valid solution that start from head and end with rear.
```C++
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<vector<int>> sol(s.size(), vector<int>());
        for (int i = s.size() - 1; i >= 0; i--) {
            if (wordDict.find(s.substr(i, s.size() - i)) != wordDict.end())
                sol[i].push_back(s.size());
            for (int j = i + 1; j < s.size(); j++) {
                if (!sol[j].empty() && 
		    wordDict.find(s.substr(i, j - i)) != wordDict.end())
                    sol[i].push_back(j);
            }
        }
        vector<string> ans;
        if (s.size() == 0) return ans;
        for (int i = 0; i < sol[0].size(); i++)
            fill(ans, s.substr(0, sol[0][i]), sol, sol[0][i], s);
        return ans;
    }
    void fill(vector<string>& ans, string str, vector<vector<int>>& sol, int pos, string& s) {
        if (pos == s.size()) {
            ans.push_back(str);
            return;
        }
        for (int i = 0; i < sol[pos].size(); i++)
            fill(ans, str + " " + s.substr(pos, sol[pos][i] - pos), 
	         sol, sol[pos][i], s);
    }
};
```
