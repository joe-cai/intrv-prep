#N-Queens II
```C++
class Solution {
public:
    int totalNQueens(int n) {
        int sol = 0;
        vector<int> ans;
        count(ans, sol, n);
        return sol;
    }
    void count(vector<int>& ans, int& sol, int n) {
        if (ans.size() == n) {
            sol++;
            return;
        }
        int row = ans.size();
        for (int col = 0; col < n; col++) {
            bool feasible = true;
            for (int j = 0; j < row && feasible; j++)
                if (ans[j] == col || row - j == abs(col - ans[j]))
                    feasible = false;
            if (feasible) {
                ans.push_back(col);
                count(ans, sol, n);
                ans.pop_back();
            }
        }
    }
};
```
