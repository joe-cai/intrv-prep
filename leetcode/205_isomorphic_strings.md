#Isomorphic Strings
```C++
class Solution {
public:
    const int num_ascii = 256;
    bool isIsomorphic(string s, string t) {
        vector<char> map1(num_ascii, 0), map2(num_ascii, 0);
        for (int i = 0; i < s.size(); i++) {
            if (map1[s[i]] != map2[t[i]]) return false;
            map1[s[i]] = i + 1; // record the index in string t
            map2[t[i]] = i + 1; // record the index in string s
        }
        return true;
    }
};
```