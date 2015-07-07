#Word Search
```C++
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) return false;
        for (int row = 0; row < board.size(); row++)
            for (int col = 0; col < board[row].size(); col++)
                if (helper(board, word, row, col, 0))
                    return true;
        return false;
    }
    bool helper(vector<vector<char>>& board, string& word, int row, int col, int pos) {
        if (pos == word.size()) return true;
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return false;
        if (board[row][col] != word[pos] || board[row][col] == '#') return false;
        char backup = board[row][col];
        board[row][col] = '#';
        if (helper(board, word, row - 1, col, pos + 1) || helper(board, word, row + 1, col, pos + 1) ||
            helper(board, word, row, col - 1, pos + 1) || helper(board, word, row, col + 1, pos + 1))
            return true;
        board[row][col] = backup;
        return false;
    }
};
```
