#Minimum Path Sum
```C++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        vector<int> prev(grid[0].size(), INT_MAX);
        prev[0] = 0;
        for (int row = 0; row < grid.size(); row++) {
            prev[0] = grid[row][0] + prev[0];
            for (int col = 1; col < grid[row].size(); col++)
                prev[col] = grid[row][col] + min(prev[col - 1], prev[col]);
        }
        return prev.back();
    }
};
```
##Tips
The codes were optimized, so that O(n) space was spared. In the original codes, the update rule is `curr[col] = grid[row][col] + min(curr[col - 1], prev[col])`. However, only the current value in index `col - 1`, and the previous value in index `col`, which resides in the `curr` array are used. So we can merge them by using one bookkeeping vector.
