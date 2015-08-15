#Contains Duplicate II
##Solution using hashmap
This solution works because the index stored in the hashmap is always the one with the minimal distance from the current index.
```C++
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> index;
        for (int i = 0; i < nums.size(); i++) {
            if (index.find(nums[i]) != index.end() && i - index[nums[i]] <= k)
                return true;
            index[nums[i]] = i;
        }
        return false;
    }
};
```

##Solution using set
The idea is to delete the number that appears k index earlier away from the current index.
```C++
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) set.erase(nums[i - k - 1]);
            if (set.find(nums[i]) != set.end()) return true;
            else set.insert(nums[i]);
        }
        return false;
    }
};
```