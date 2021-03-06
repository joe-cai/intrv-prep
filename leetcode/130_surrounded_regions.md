#Surrounded Regions
## BFS solution
```C++
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return;
        for (int row = 0; row < board.size(); row++) {
            if (board[row][0] == 'O')
                color(board, row, 0);
            if (board[row][board[row].size() - 1] == 'O')
                color(board, row, board[row].size() - 1);
        }
        for (int col = 0; col < board[0].size(); col++) {
            if (board[0][col] == 'O')
                color(board, 0, col);
            if (board[board.size() - 1][col] == 'O')
                color(board, board.size() - 1, col);
        }
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[row].size(); col++) {
                if (board[row][col] == 'O')
                    board[row][col] = 'X';
                else if (board[row][col] == 'o')
                    board[row][col] = 'O';
            }
        }
    }
    void color(vector<vector<char>> &board, int row, int col) {
        queue<int> rows;
        rows.push(row);
        queue<int> cols;
        cols.push(col);
        board[row][col] = 'o';
        while (!rows.empty() && !cols.empty()) {
            row = rows.front();
            col = cols.front();
            rows.pop();
            cols.pop();
            if (row > 0 && board[row - 1][col] == 'O') {
                board[row - 1][col] = 'o';
                rows.push(row - 1);
                cols.push(col);
            }
            if (col > 0 && board[row][col - 1] == 'O') {
                board[row][col - 1] = 'o';
                rows.push(row);
                cols.push(col - 1);
            }
            if (row < board.size() - 1 && board[row + 1][col] == 'O') {
                board[row + 1][col] = 'o';
                rows.push(row + 1);
                cols.push(col);
            }
            if (col < board[0].size() - 1 && board[row][col + 1] == 'O') {
                board[row][col + 1] = 'o';
                rows.push(row);
                cols.push(col + 1);
            }
        }
    }
};
```
##Note
There are solutions that are based on Union Find, which is also an efficient implementation.