#Repeated DNA Sequences
Based on the fact that A/T/C/G & 0x7 is different, use the last three bits of the ascii representations of A, T, C, G to encode the four letters.
```C++
class Solution {
public:
    const int size = 10;
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<int, int> occur;
        int encode = 0, pos = 0;
        for (int i = 0; i < s.size(); i++) {
            encode = (encode << 3 | s[i] & 7) & 0x3FFFFFFF;
            if (occur[encode]++ == 1) 
	        ans.push_back(s.substr(i - size + 1, size));
        }
        return ans;
    }
};
```