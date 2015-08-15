#Dungeon Game
```C++
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if (m == 0) return 1;
        int n = dungeon[0].size();
        
        vector<int> curr(n, INT_MAX);
	// base case: initial value obtained from last row
        curr[n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);
        for (int col = n - 2; col >= 0; col--)
            curr[col] = max(1, curr[col + 1] - dungeon[m - 1][col]);
        // inductive cases
        for (int row = m - 2; row >= 0; row--) {
            curr[n - 1] = max(1, curr[n - 1] - dungeon[row][n - 1]);
            for (int col = n - 2; col >= 0; col--)
                curr[col] = min(max(1, curr[col + 1] - dungeon[row][col]), 
                                max(1, curr[col] - dungeon[row][col]));
        }

        return curr[0];
    }
};
```