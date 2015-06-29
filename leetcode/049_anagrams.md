#Anagrams
##O(N(mlogm)) average time and O(Nm) space solution
Including the time to hash a string.
```C++
class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> sol;
        unordered_map<string, vector<int>> hash;
        for (int i = 0; i < strs.size(); i++) {
            string str_copy = strs[i];
            sort(str_copy.begin(), str_copy.end());
            hash[str_copy].push_back(i);
        }
        for (auto it = hash.begin(); it != hash.end(); it++) {
            if ((it->second).size() > 1) {
                for (int i = 0; i < (it->second).size(); i++)
                    sol.push_back(strs[(it->second)[i]]);
            }
        }
        return sol;
    }
}
```
