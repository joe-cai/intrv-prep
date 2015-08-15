#Add and Search Word
##Solution using `unordered_map`
```C++
class Word {
public:
    unordered_map<int, Word*> next;
    bool exist;
    Word() : exist(false) {}
};

class WordDictionary {
private:
    Word* root;
    bool find(string word, int start, Word* root) {
        if (start == word.size()) return root->exist;
        if (word[start] != '.') {
            if (root->next.count(word[start] - 'a') == 0) return false;
            else return find(word, start + 1, root->next[word[start] - 'a']);
        } // word[start] == '.'
        for (auto it = root->next.begin(); it != root->next.end(); it++)
            if (find(word, start + 1, it->second)) return true;
        return false;
    }
public:
    WordDictionary() { root = new Word(); }
    void addWord(string word) {
        Word* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->next.count(word[i] - 'a') == 0)
                curr->next[word[i] - 'a'] = new Word();
            curr = curr->next[word[i] - 'a'];
        }
        curr->exist = true;
    }

    bool search(string word) {
        return find(word, 0, root);
    }
};
```