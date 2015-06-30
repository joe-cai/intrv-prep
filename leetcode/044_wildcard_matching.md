#Wildcard Matching
##O(n + m) linear time solution using KMP algorithm
Let `p` be the pattern, `s` be the text we are examining. The basic idea is to trim the pattern `p` into the form `p1*p2*p3`, the asteroids surrounding `p2` are the first and last asteroid in `p` respectively. We first match `p1` and `p3`, which don't have any asteroid within, with their corresponding parts `s1` and `s3` in string `s = s1s2s3`. To match `p2` with `s2`, a key observation is that `p2` can be splited by `*` into a list of strings, each of those string must appear in `s2`. So we can use the KMP algorithm to find those splitted substring of `p2` in order in `s2`, starting from the last position of substring matching. Note that there may be multiple possibilities of substring match in `s2`, but we only match the first appearance of those substring in `s2`, which is guaranteed to be exist if `p2` and `s2` are a match. The following solution also takes into account the case where `s` contains asteroid.
```C++
class Solution {
public:
    const int ascii = 26;
    bool isMatch(string s, string p) {
        // trim the header, so that p[start] == '*' or s[start] == '*'
        int start = 0;
        while (start < min(s.size(), p.size()) && p[start] != '*' && s[start] != '*') {
            if (s[start] != '?' && p[start] != '?' && s[start] != p[start]) return false;
            start++;
        }
        if (start == p.size()) {
            while (start < s.size() && s[start] == '*') { start++; }
            return start == s.size();
        } else if (start == s.size()) {
            while (start < p.size() && p[start] == '*') { start++; }
            return start == p.size();
        }
        
        // trim the trailer, so that p[p_end] == '*' or s[s_end] == '*'
        int s_end = s.size() - 1;
        int p_end = p.size() - 1;
        while (min(s_end, p_end) >= start && p[p_end] != '*' && s[s_end] != '*') {
            if (s[s_end] != '?' && p[p_end] != '?' && s[s_end] != p[p_end]) return false;
            s_end--;
            p_end--;
        }
        if (s_end < start && p[p_end] != '*') return false;
        else if (p_end < start && s[s_end] != '*') return false;
        else if (p_end >= start && p[p_end] == '*' && s[start] == '*' || 
                 s_end >= start && s[s_end] == '*' && p[start] == '*') return true;

        // string s or p has '*' on both sides
        s = string(s.begin() + start, s.begin() + s_end + 1);
        p = string(p.begin() + start, p.begin() + p_end + 1);
        if (s.size() > 0 && s.front() == '*' && s.back() == '*') swap(s, p);

        start = 0;
        int next = 0;
        for(;;) {
            int len = 0;
            while (start < p.size() && p[start] == '*') { start++; }
            if (start == p.size()) return true;
            while (start + len < p.size() && p[start + len] != '*') { len++; }
            next = kmp(p.substr(start, len), s, next) + 1;
            start += len;
            if (next <= 0) return false;
        }
        return true;
    }
    
    int kmp(string needle, string haystack, int start) {
        if (needle.size() == 0) return start;
        else if (start == haystack.size()) return -2;
        
        vector<vector<int>> dfa(ascii, vector<int>(needle.size(), 0));
        if (needle[0] != '?') dfa[needle[0] - 'a'][0] = 1;
        else for (int c = 0; c < ascii; c++) dfa[c][0] = 1;

        int prev_state = 0;
        for (int state = 1; state < needle.size(); state++) {
            if (needle[state] != '?') {
                for (int c = 0; c < ascii; c++)
                    dfa[c][state] = dfa[c][prev_state];
                dfa[needle[state] - 'a'][state] = state + 1;
                prev_state = dfa[needle[state] - 'a'][prev_state];
            } else {
                for (int c = 0; c < ascii; c++)
                    dfa[c][state] = state + 1;
            }
        }
        int state = 0;
        for (int i = start; i < haystack.size(); i++) {
            state = (haystack[i] != '?')? dfa[haystack[i] - 'a'][state] : state + 1;
            if (state == needle.size()) return i;
        }
        return -2;
    }
};
```
