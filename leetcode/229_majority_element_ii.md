#Majority Element II
```C++
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count1 == 0) { candidate1 = nums[i]; count1++; }
            else if (candidate1 == nums[i]) count1++;
            else if (count2 == 0) { candidate2 = nums[i]; count2++; }
            else if (candidate2 == nums[i]) count2++;
            else { count1--; count2--; }
        }
        count1 = 0; count2 = 0;
        for (int i = 0; i < nums.size(); i++)
            if (candidate1 == nums[i]) count1++;
            else if (candidate2 == nums[i]) count2++;
        vector<int> ans;
        if (count1 > nums.size() / 3) ans.push_back(candidate1);
        if (count2 > nums.size() / 3) ans.push_back(candidate2);
        return ans;
    }
};
```
##Note
This algorithm can be easily extend to the case of k majorities.