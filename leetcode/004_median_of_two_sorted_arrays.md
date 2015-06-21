#Median of Two Sorted Arrays
##Why I did not make it in the first try:
The code I wrote is over too complicated, which make it difficult to reason about the base cases. The result is that bugs exist and are hard to find. The following solution is stolen from Leetcode Discuss forum by `vaputa`. The code shares the same basic idea with mine, but is much shorter and cleaner.


##O(log(m + n)) worst case solution
```C++
class Solution {
public:
    double getkth(vector<int>& nums1, int s1, int l1, vector<int>& nums2, int s2, int l2, int k) {
        if (l1 > l2) // maintain l1 <= l2
            return getkth(nums2, s2, l2, nums1, s1, l1, k);
        if (l1 == 0) // previous WA submission: nums2[k - 1]
            return nums2[s2 + k - 1];
        if (k == 1) // previous WA submission: min(nums1[0], nums2[0])
            return min(nums1[s1], nums2[s2]);
            
        int m1 = min(l1, k / 2);
        int m2 = min(l2, k / 2);
        if (nums1[s1 + m1 - 1] > nums2[s2 + m2 - 1])
            return getkth(nums1, s1, l1, nums2, s2 + m2, l2 - m2, k - m2);
        else // if somehow m1 == l1 and this branch is activated, then the size of nums1 becomes 0
            return getkth(nums1, s1 + m1, l1 - m1, nums2, s2, l2, k - m1);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // k starts from 1. l1 is the size of the vector; same thing for l2.
        int total = nums1.size() + nums2.size();
        int num1 = getkth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), (total + 1) / 2);
        int num2 = getkth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), (total + 2) / 2);
        return (num1 + num2) / 2.0;
    }
};
```

##Tips
- Thing get a bit trickier when the start index may NOT be zero. See the comments in the codes for wrong answer submission. Be careful during the interview.
- k is decreased at least by half at each iteration. See the comments for the sketch of proof.
