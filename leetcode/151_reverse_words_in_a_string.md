#Reverse Words in a String
```C++
class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (start != 0) s[start++] = ' ';
                int end = start;
                while (i < s.size() && s[i] != ' ') { s[end++] = s[i++]; }
                reverse(s.begin() + start, s.begin() + end);
                start = end;
            }
        }
        s.erase(s.begin() + start, s.end());
    }
};
```
