#Unique Paths II
##O(m + n) space solution
```C++
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0) return 0;
        vector<int> upper(obstacleGrid[0].size(), 0);
        upper[0] = 1;

        vector<int> curr(obstacleGrid[0].size(), 0);
        for (int row = 0; row < obstacleGrid.size(); row++) {
            curr[0] = (obstacleGrid[row][0] != 1)? upper[0] : 0;
            for (int col = 1; col < obstacleGrid[row].size(); col++)
                curr[col] = (obstacleGrid[row][col] != 1)? upper[col] + curr[col - 1] : 0;
            upper = curr;
        }
        return curr.back();
    }
};
```
