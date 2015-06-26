#Valid Sudoku
For code simplicity, the following solution is of space complexity O(N^2). Note that O(N) space complexity is achievable, but the codes will be somewhat longer.
```C++
class Solution {
public: // using magic number since the problem is very specific
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> box(9, vector<bool>(9, false));
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (row[i][board[i][j] - '1']) return false;
                else row[i][board[i][j] - '1'] = true;
                if (col[j][board[i][j] - '1']) return false;
                else col[j][board[i][j] - '1'] = true;
                if (box[i / 3 * 3 + j / 3][board[i][j] - '1']) return false;
                else box[i / 3 * 3 + j / 3][board[i][j] - '1'] = true;
            }
        }
        return true;
    }
};
```
