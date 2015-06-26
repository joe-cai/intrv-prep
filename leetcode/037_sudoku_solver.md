#Sudoku Solver
```C++
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> box(9, vector<bool>(9, false));
        bool done = false;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    row[i][board[i][j] - '1'] = true;
                    col[j][board[i][j] - '1'] = true;
                    box[i / 3 * 3 + j / 3][board[i][j] - '1'] = true;
                }
            }
        }
        fillBoard(board, 0, done, row, col, box);
    }
    void fillBoard(vector<vector<char>>& board, int next, bool& done,
        vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<bool>>& box) {
        if (next == 9 * 9) { done = true; return; };
        int startRow = next / 9;
        int startCol = next % 9;
        if (board[startRow][startCol] == '.') {
            for (int i = 0; i < 9 && !done; i++) {
                if (!row[startRow][i] && !col[startCol][i] && !box[startRow / 3 * 3 + startCol / 3][i]) {
                    row[startRow][i] = true;
                    col[startCol][i] = true;
                    box[startRow / 3 * 3 + startCol / 3][i] = true;
                    board[startRow][startCol] = '1' + i;
                    fillBoard(board, next + 1, done, row, col, box);
                    if (!done) board[startRow][startCol] = '.';
                    box[startRow / 3 * 3 + startCol / 3][i] = false;
                    col[startCol][i] = false;
                    row[startRow][i] = false;
                }
            }
        } else
            fillBoard(board, next + 1, done, row, col, box);
    }
};
```
