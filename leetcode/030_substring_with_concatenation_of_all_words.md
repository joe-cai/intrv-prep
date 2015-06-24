#Substring with Concatenation of All Words
##Why I did not make it in the first pass:
The problem is in the less than or equal to comparison in the outer loop (see the following codes). Specifically, it is valid for `i` to reach `s.size() - words.size() * words[0].size()`. 
```C++
for (int i = 0; i <= s.size() - words.size() * words[0].size(); i++) {
    // ...
    for(int j = i; j < i + words.size() * words[0].size(); j += words[0].size())
```
I came up with an inefficient algorithm using `unordered_map`. The following is a O(N) solution to this problem. The essence of the solution is to maintain a window that covers part of the concatenation of the words, and count the occurences of words with a fixed `words[0].size()` gap.

##O(N) average case solution
```C++
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.size() == 0) return vector<int>();
        int wordLength = words[0].size();
        if (words.size() * wordLength > s.size()) return vector<int>();
        unordered_map<string, int> hashmap;
        for (int i = 0; i < words.size(); i++) hashmap[words[i]]++;

        vector<int> sol;
        for (int offset = 0; offset < wordLength; offset++) { /* the key */
            unordered_map<string, int> hash;
            int counter = 0, start = offset, pos = start;
            while (pos <= s.size() - wordLength) {
                string str1 = s.substr(pos, wordLength);
                pos += wordLength;
                if (hashmap.count(str1)) { 
                    hash[str1]++;
                    if (hash[str1] > hashmap[str1]) {
                        string str2;
                        while ((str2 = s.substr(start, wordLength)) != str1) {
                            hash[str2]--;
                            counter--;
                            start += wordLength;
                        }
                        start += wordLength;
                    } else counter++;
                } else { 
                    counter = 0; 
                    hash.clear();
                    start = pos;
                }
                if (counter == words.size()) sol.push_back(start);
            }
        }
        return sol;
    }
};
```
