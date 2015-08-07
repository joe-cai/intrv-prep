#Triangle
Use bottom-up dynamic programming. Add another row under the bottom row and calculate the minimum cost in a bottom-up fashion.
```C++
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;

        vector<int> cost(triangle.size() + 1, 0);
        for (int row = triangle.size() - 1; row >= 0; row--) {
            for (int i = 0; i <= row; i++)
                cost[i] = min(cost[i], cost[i + 1]) + triangle[row][i];
        }
        return cost[0];
    }
};```
