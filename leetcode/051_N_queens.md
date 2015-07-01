#N-Queens
```C++
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sol;
        vector<string> ans(n, string(n, '.'));
        fill(sol, ans, 0);
        return sol;
    }
    void fill(vector<vector<string>>& sol, vector<string>& ans, int row) {
        if (row == ans.size()) { sol.push_back(ans); return; }
        for (int col = 0; col < ans.size(); col++) {
            bool feasible = true;
            for (int i = 0; i < row && feasible; i++)
                if (ans[i][col] == 'Q') feasible = false;
            for (int i = col - 1; i >= 0 && (row >= col - i) && feasible; i--)
                if (ans[row - (col - i)][i] == 'Q') feasible = false;
            for (int i = col + 1; i < ans.size() && (row >= i - col) && feasible; i++)
                if (ans[row - (i - col)][i] == 'Q') feasible = false;
            if (feasible) {
                ans[row][col] = 'Q';
                fill(sol, ans, row + 1);
                ans[row][col] = '.';
            }
        }
    }
};
```
