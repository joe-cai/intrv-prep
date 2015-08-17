#Majority Element
The problem will be more reasonable if it asks about the index of the major element in the array (in case the input is an empty array).
```C++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = -1, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                major = nums[i];
                count = 1;
            } else if (major == nums[i])
                count++;
            else // major != nums[i]
                count--;
        }
        return major;
    }
};
```
