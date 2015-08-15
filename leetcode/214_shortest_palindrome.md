#Shortest Palindrome
The following solution uses the prefix of the input string as pattern to create a deterministic finite automata. Then this dfa is fed with the reversed input string to see how many letters got matched. When the number of letters matched collide with the last position of the matched pattern, the longest prefix palindrome is found.
```C++
class Solution {
public:
    const int ascii = 26;
    string shortestPalindrome(string s) {
        if (s.size() <= 1) return s;

        vector<vector<int>> dfa(ascii, vector<int>(s.size() / 2, 0));
        dfa[s[0] - 'a'][0] = 1;
        int prev = 0;
        for (int i = 1; i < s.size() / 2; i++) {
            for (char c = 'a'; c <= 'z'; c++) { dfa[c - 'a'][i] = dfa[c - 'a'][prev]; }
            dfa[s[i] - 'a'][i] = i + 1;
            prev = dfa[s[i] - 'a'][prev];
        }

        int curr = 0; // the number of letter matched        
        int pos = s.size() - 1; // the last position of the number of letter matched
        while (pos >= 0) { 
        	curr = dfa[s[pos] - 'a'][curr]; 
        	if (pos == curr || pos - 1 == curr) break;
        	pos--;
        }
        
        string rs = s.substr(pos + curr, s.size() - pos - curr);
        reverse(rs.begin(), rs.end());
        return rs + s;
    }
};
```
##Note:
There are other solutions based on prefix function in KMP algorithm. But I have not yet tried to understand.