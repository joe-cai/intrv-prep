#Number of Islands
```C++
class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int numIslands(vector<vector<char>>& grid) {
        int counter = 0;
        for (int row = 0; row < grid.size(); row++)
            for (int col = 0; col < grid[row].size(); col++)
                if (grid[row][col] == '1') {
                    color(grid, row, col);
                    counter++;
                }
        // recover here
        return counter;
    }
    void color(vector<vector<char>>& grid, int row, int col) {
        grid[row][col] = 'x';
        for (int i = 0; i < 4; i++) {
            int nextRow = row + dx[i], nextCol = col + dy[i];
            if (nextRow >= 0 && nextRow < grid.size() && nextCol >= 0 && 
                nextCol < grid[nextRow].size() && grid[nextRow][nextCol] == '1')
                color(grid, nextRow, nextCol);
        }
    }
};
```