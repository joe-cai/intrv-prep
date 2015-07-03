#Valid Number
```C++
class Solution {
public:
    bool isNumber(string s) {
        int pos = 0;
        // skip white spaces
        while (pos < s.size() && s[pos] == ' ') { pos++; }
        if (pos == s.size()) return false;
        if (s[pos] == '+' || s[pos] == '-') pos++;
        if (pos == s.size() || s[pos] != '.' && (s[pos] < '0' || s[pos] > '9')) return false;
        
        int numStart = pos;
        while (pos < s.size() && s[pos] >= '0' && s[pos] <= '9') { pos++; }
        // parse floating number part
        if (s[pos] == '.') pos++;
        while (pos < s.size() && s[pos] >= '0' && s[pos] <= '9') { pos++; }
        int numEnd = pos;
        if (numEnd == numStart + 1 && s[numStart] == '.') return false;
        if (pos == s.size()) return true;
        // parse scientific notation part
        if (s[pos] == 'e') { 
            pos++;
            if (pos == s.size()) return false;
            if (s[pos] == '+' || s[pos] == '-') pos++;
            numStart = pos;
            while (pos < s.size() && s[pos] >= '0' && s[pos] <= '9') { pos++; }
            if (pos == numStart) return false;
        }
        // skip white spaces
        while (pos < s.size() && s[pos] == ' ') pos++;
        return pos == s.size();
    }
};
```
