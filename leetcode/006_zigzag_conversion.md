#ZigZag Conversion
##Why I did not make it in the first pass:
See the comments of the codes.
```C++
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 0 || numRows == 1) return s;
        vector<string> ans(numRows, "");

        int row = 0;
        int step = +1;
        for (int i = 0; i < s.size(); i++) {
            ans[row].push_back(s[i]);
	    // RE submission: if (... || row == 0); note the nuances
            if (row == numRows - 1 || (i > 0 && row == 0)) step = -step;
            row += step;
        }
        
        string sol = "";
        for (int i = 0; i < numRows; i++) sol.append(ans[i]);
        return sol;
    }
};
```

##Tips
The problem statement would be better if it was put in this way:
Converst string `PAYPALISHIRING` to the following format
```
P   A   H   N
 A P L S I I G
  Y   I   R
```
