#Single Number II
The bit tricks are not necessary though convenient. The same result can be obtained by counting the number of occurences of 1's in each bit.
```C++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // use two bits to represent the number of 1's in the vector
        // this solution has the following base : 00 -> 01 -> 10 -> 00
        int ones = 0, twos = 0; // ones twos == 0 0
        for (int i = 0; i < nums.size(); i++) {
            twos = (twos ^ nums[i]) & (~ones);
            // if ones == 0, twos is the result of ^ with A[i]
            // otherwise, ones == 1, twos will always be 0
            ones = (ones ^ nums[i]) & (~twos);
            // if twos becomes 0, possible cases are
            // A[i] bit == 0, 00->00, 10->10
            // A[i] bit == 1, 01->10, 10->00 
            // otherwise, twos becomes 1, ones will always be 0
        }
        return twos;
    }
};
```
