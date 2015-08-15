#Implement Trie
##faster version with larger space
```C++
class TrieNode {
public:
    TrieNode* next[26];
    bool exist;
    TrieNode() : exist(false) { memset(next, 0, sizeof(next)); }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->next[word[i] - 'a'] == NULL)
                curr->next[word[i] - 'a'] = new TrieNode();
            curr = curr->next[word[i] - 'a'];
        }
        curr->exist = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size() && curr != NULL; i++)
            curr = curr->next[word[i] - 'a'];
        return curr != NULL && curr->exist;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (int i = 0; i < prefix.size() && curr != NULL; i++)
            curr = curr->next[prefix[i] - 'a'];
        return curr != NULL;
    }
};
```

##slower version with less space
```C++
class TrieNode {
public:
    TrieNode *left, *mid, *right;
    char key;
    bool exist;
    TrieNode() : key('.'), exist(false), left(NULL), mid(NULL), right(NULL) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode** ptr_curr = &root;
        
        int pos = 0;
        while (pos < word.size()) {
            if (*ptr_curr == NULL) {
                *ptr_curr = new TrieNode();
                (*ptr_curr)->key = word[pos];
            } 
            if (word[pos] < (*ptr_curr)->key) ptr_curr = &((*ptr_curr)->left);
            else if (word[pos] > (*ptr_curr)->key) ptr_curr = &((*ptr_curr)->right);
            /* word[pos] == prev->key */
            else if (pos == word.size() - 1) { (*ptr_curr)->exist = true; return; }
            else { ptr_curr = &((*ptr_curr)->mid); pos++; }
        }
    }

    bool search(string word) {
        TrieNode* curr = root;
        int pos = 0;
        while (pos < word.size() && curr != NULL) {
            if (word[pos] < curr->key) curr = curr->left;
            else if (word[pos] > curr->key) curr = curr->right;
            /* word[pos] == curr->key */
            else if (pos == word.size() - 1) return curr->exist;
            else { curr = curr->mid; pos++; }
        }
        return false;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        int pos = 0;
        while (pos < prefix.size() && curr != NULL) {
            if (prefix[pos] < curr->key) curr = curr->left;
            else if (prefix[pos] > curr->key) curr = curr->right;
            else /* prefix[pos] == curr->key */ { curr = curr->mid; pos++; }
        }
        return pos == prefix.size();
    }
};
```