#Valid Anagram
```C++
class Solution {
public:
    const int sizealpha = 26;
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> stats(sizealpha, 0);
        for (int i = 0; i < s.size(); i++) {
            stats[s[i] - 'a']++;
            stats[t[i] - 'a']--;
        }
        for (int i = 0; i < sizealpha; i++)
            if (stats[i] != 0) return false;
        return true;
    }
};
```