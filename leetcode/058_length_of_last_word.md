#Length of Last Word
```C++
class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastWord = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                lastWord = 0; 
                while (i < s.size() && s[i] != ' ') { lastWord++; i++; }
                // don't write sloppy self increase in a while loop
                // the following is incorrect!! result in one extra increment
                // while (i < s.size() && s[i++] != ' ') { lastSize++; }
            }
        }
        return lastWord;
    }
};
```
