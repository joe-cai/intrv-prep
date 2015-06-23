#Container with Most Water
##Why I did not make it in the first try:
compile error: always forgot the parenthesis in `vector.end()`
##O(N) worst case solution
```C++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int start = 0;
        int end = height.size() - 1;
        while (start < end) {
            ans = max(ans, (end - start) * min(height[start], height[end]));
            (height[start] <= height[end])? start++ : end--;
        }
        return ans;
    }
};
```
##Tips:
- The essence of this problem is pretty much the same as that of the two sum problem.
- I came up with an suboptimal solution for this problem, which is of time complexity O(NlogN). It is also cumbersome and buggy compared to the O(N) solution given by `franticguy` on the leetcode forum.
