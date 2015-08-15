#Contains Duplicate
##O(NlogN) solution using sorting
```C++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() == 0) return false;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] == nums[i + 1]) return true;
        return false;
    }
};
```

##O(N) solution using hashmap
```C++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> occur;
        for (int i = 0; i < nums.size(); i++) {
            if (occur.find(nums[i]) == occur.end())
                occur.insert(nums[i]);
            else return true;
        }
        return false;
    }
};
```