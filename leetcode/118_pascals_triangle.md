#Pascal's Triangle
```C++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> sol;
        if (numRows == 0) return sol;
        vector<int> ans = { 1 };
        sol.push_back(ans);
        for (int i = 1; i < numRows; i++) {
            vector<int> row;
            row.push_back(1);
            for (int j = 1; j < ans.size(); j++)
                row.push_back(ans[j - 1] + ans[j]);
            row.push_back(1);
            sol.push_back(row);
            ans = row;
        }
        return sol;
    }
};
```
