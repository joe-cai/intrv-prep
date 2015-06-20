#Two Sum
## Why I did not make it in the first pass:
A couple of reasons:
- sorted the array without bookkeeping the original indexes
- scanning through the array for an index without breaking

## O(N) average case solution
```C++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(target - nums[i]) != hash.end()) {
                ans.push_back(hash[target - nums[i]] + 1);
                ans.push_back(i + 1);
                return ans;
            } else if (hash.find(nums[i]) == hash.end())
                hash[nums[i]] = i;
            // insertion into hashmap is put off to allow duplicates
        }
        return ans;
    }
};
```

## O(NlogN) worst case solution
```C++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int start = 0;
        int end = sorted.size() - 1;
        
        int sum;
        while ((sum = sorted[start] + sorted[end]) != target) {
            (sum < target) ? start++ : end--;
        }
        
        int idx1;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == sorted[start]) {
                idx1 = i;
                break;
            }
        int idx2;
        for (int i = nums.size() - 1; i >= 0; i--)
            if (nums[i] == sorted[end]) {
                idx2 = i;
                break;
            }
        vector<int> ans { min(idx1, idx2) + 1, max(idx1, idx2) + 1 };
        return ans;
    }
};
```
