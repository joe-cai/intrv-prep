#Minimum Window Substring
See the comments in the code. The "window" method is very comment in many linear algorithm.
```C++
class Solution {
public:
    const int numascii = 256;
    string minWindow(string s, string t) {
        vector<int> count(numascii, 0); // accumulates chars in string t
        for (int i = 0; i < t.size(); i++) count[t[i]]++;
        vector<int> window(numascii, 0); // accumulates chars in string s

        int ans = INT_MAX;
        string sol = "";

        int start = 0;
        int pos = start; // s[start, pos] is the current string
        while (start < s.size() && count[s[start]] == 0) { start++; }
        int match = 0; // match records the number of char match between s and t
        while (start < s.size()) {
            while (pos < s.size() && match < t.size()) {
	        // the character does not yet exceed the requirement
                if (window[s[pos]] < count[s[pos]]) match++;
                window[s[pos++]]++;
            }
            if (match == t.size() && ans > pos - start) {
                sol = s.substr(start, pos - start);
                ans = pos - start;
            }
            if (window[s[start]] == count[s[start]]) match--;
            window[s[start++]]--;
            
            // count[s[start]] == 0 means character s[start] is not required
            // window[s[start]] > count[s[start]] means s[start] is redundant
            while (start < s.size() && 
	    (count[s[start]] == 0 || window[s[start]] > count[s[start]])) {
                if (window[s[start]] > count[s[start]]) window[s[start]]--;
                start++; 
            }
        }
        return sol;
    }
};
```
