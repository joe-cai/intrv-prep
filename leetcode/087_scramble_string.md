#Scramble String
```C++
class Solution {
public:
    const int numascii = 256;
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (!identical(s1, s2)) return false;
        if (s1.size() <= 2) return true;

        for (int i = 1; i < s1.size(); i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && 
                isScramble(s1.substr(i, s1.size() - i), s2.substr(i, s2.size() - i)))
                return true;
            if (isScramble(s1.substr(0, i), s2.substr(s2.size() - i, i)) 
                && isScramble(s1.substr(i, s1.size() - i), s2.substr(0, s2.size() - i)))
                return true;
        }
        return false;
    }

    bool identical(const string& s1, const string& s2) {
        vector<int> count(numascii, 0);
        int numchar = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (count[s1[i]] == 0)
                numchar++;
            count[s1[i]]++;
        }
        for (int i = 0; i < s2.size(); i++) {
            count[s2[i]]--;
            if (count[s2[i]] == 0)
                numchar--;
        }
        return numchar == 0;
    }
};
```
