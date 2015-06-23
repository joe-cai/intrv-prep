#Letter Combinations of a Phone Number
```C++
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> sol;
        if (digits.size() == 0) return sol;
        string codes = "";
        decipher(digits, codes, 0, sol);
        return sol;
    }
    void decipher(string& digits, string& codes, int pos, vector<string>& sol) {
        static vector<string> codebook = { "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (pos == digits.size()) {
            sol.push_back(codes);
            return; // remember to return !!!
        }
        for (int i = 0; i < codebook[digits[pos] - '1'].size(); i++) {
            codes.push_back(codebook[digits[pos] - '1'][i]);
            decipher(digits, codes, pos + 1, sol);
            codes.pop_back();
        }
    }
};
```
