#Word Ladder II
Search the path from `end` to `start`, and build the solution reversely from `start` to `end`. This solution is based on the one given by `Fenghuan`.
```C++
class Solution {
public:
    unordered_map<string, unordered_set<string>> nextString;
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        if (start == end) return vector<vector<string>>(1, vector<string>(1, start));

        queue<string> curr;
        curr.push(end);
        bool found = false;
        while (!curr.empty() && !found) {
            unordered_set<string> used;

            int size = curr.size();
            for (int s = 0; s < size; s++) {
                string word = curr.front();
                for (int i = 0; i < word.size(); i++) {
                    char letter = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (letter == c) continue;
                        word[i] = c;
                        if (word == start) {
                            found = true;
                            nextString[start].insert(curr.front());
                        } else if (dict.count(word) > 0) { 
                            if (used.count(word) == 0) {
                                curr.push(word);
                                used.insert(word);
                            }
                            nextString[word].insert(curr.front());
                        }
                    }
                    word[i] = letter;
                }
                curr.pop();
            }

            for (string usedWord : used) dict.erase(usedWord);
        }
        
        vector<vector<string>> sol;
        vector<string> ans;
        buildSol(sol, ans, start, end);
        return sol;
    }
    
    void buildSol(vector<vector<string>>& sol, vector<string>& ans, string curr, string& end) {
        if (curr == end) { 
            ans.push_back(end); 
            sol.push_back(ans); 
            ans.pop_back(); 
            return;
        }

        ans.push_back(curr);
        for (auto it = nextString[curr].begin(); it != nextString[curr].end(); it++) 
            buildSol(sol, ans, *it, end);
        ans.pop_back();
    }
};
```