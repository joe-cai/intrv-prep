#Trapping Rain Water
The essence of solution is pretty much the same as that of the Two Sum problem. Specifically, setting two pointers on the left end and right end respectively. If the left bar is shorter than the right one, increase the left end cuz left bar dominates the maximal area we can get so far, and vice versa.

##O(N) Solution 1
This solution (by `mcrystal`) fills in the trap bar by bar, namely, if left bar is shorter, fill in this bar and increase the left pointer. If right bar is shorter, fill in the right bar and decrease the right pointer. It also keep track of the highest bar on both left and right respectively.
```C++
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] > maxLeft) maxLeft = height[left];
                else ans += maxLeft - height[left];
                left++;
            } else {
                if (height[right] > maxRight) maxRight = height[right];
                else ans += maxRight - height[right];
                right--;
            }
        }
        return ans;
    }
};
```

##O(N) Solution 2
This solution (by `dragonmigo`) keeps track of the water level. And update the water level in similar way as in solution 2. `areaRec` is the area of the rectangle form by the left bar and right bar. In each iteration, we update the `areaRec` as needed. We subtract the cumutative area formed by the bars in the end.
```C++
class Solution {
public:
    int trap(vector<int>& height) {
        int areaRec = 0;
        int left = 0, right = height.size() - 1;
        int level = 0, block = 0;
        while (left <= right) {
            if (min(height[left], height[right]) > level) {
                areaRec += (right - left + 1) * (min(height[left], height[right]) - level);
                level = min(height[left], height[right]);
            }
            if (height[left] < height[right]) block += height[left++];
            else block += height[right--];
        }
        return areaRec - block;
    }
};
```
