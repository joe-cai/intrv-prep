#Largest Number
This implementation comes from `issac7`. It directly creates a functional object in the sorting routine without actually naming and defining it.
```C++
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (int i = 0; i < nums.size(); i++) 
            strs.push_back(to_string(nums[i]));
        sort(strs.begin(), strs.end(), 
            [](string& s1, string& s2) { return s1 + s2 > s2 + s1; });
        string ans;
        for (int i = 0; i < strs.size(); i++) ans += strs[i];
        if (ans.size() > 0 && ans[0] == '0') return "0";
        return ans;
    }
};
```