#Word Search
2-D vector costs large amount of time. Try to avoid using it.
```C++
class Word {
public:
    Word* next[26];
    bool exist;
    Word() : exist(false) { memset(next, 0, sizeof(next)); }
};

class WordDictionary {
public:
    Word* root;
    WordDictionary() { root = new Word(); }
    void addWord(string word) {
        Word* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->next[word[i] - 'a'] == NULL)
                curr->next[word[i] - 'a'] = new Word();
            curr = curr->next[word[i] - 'a'];
        }
        curr->exist = true;
    }
};


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> sol;
        if (board.size() == 0) return sol;
        
        WordDictionary wordBook;
        for (int i = 0; i < words.size(); i++) { wordBook.addWord(words[i]); }

        string ans;
        for (int row = 0; row < board.size(); row++)
            for (int col = 0; col < board[row].size(); col++)
                fill(board, sol, wordBook, ans, row, col, wordBook.root);

        return sol;
    }
    void fill(vector<vector<char>>& board, vector<string>& sol, 
              WordDictionary& wordBook, string& ans, int row, int col, Word* root) {
        char backup = board[row][col];
        ans.push_back(backup);
        board[row][col] = '-';

        Word* next = root->next[backup - 'a'];
        if (next && next->exist) { sol.push_back(ans); next->exist = false; }
        if (row > 0 && board[row - 1][col] != '-' && next) fill(board, sol, wordBook, ans, row - 1, col, next);
        if (row < board.size() - 1 && board[row + 1][col] != '-' && next) fill(board, sol, wordBook, ans, row + 1, col, next);
        if (col > 0 && board[row][col - 1] != '-' && next) fill(board, sol, wordBook, ans, row, col - 1, next);
        if (col < board[0].size() - 1 && board[row][col + 1] != '-' && next) fill(board, sol, wordBook, ans, row, col + 1, next);

        board[row][col] = backup;
        ans.pop_back();
    }
};
```