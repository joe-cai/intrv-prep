#Spiral Matrix
```C++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0) return ans;
        int row = 0, col = 0;
        int numRow = matrix.size(), numCol = matrix[0].size();
        while (numRow >= 2 && numCol >= 2) {
            for (int i = 0; i < numCol - 1; i++)
                ans.push_back(matrix[row][col++]);
            for (int i = 0; i < numRow - 1; i++)
                ans.push_back(matrix[row++][col]);
            for (int i = 0; i < numCol - 1; i++)
                ans.push_back(matrix[row][col--]);
            for (int i = 0; i < numRow - 1; i++)
                ans.push_back(matrix[row--][col]);
            row++;
            col++;
            numRow -= 2;
            numCol -= 2;
        }
        if (numRow == 1)
            for (int i = 0; i < numCol; i++)
                ans.push_back(matrix[row][col++]);
        else if (numCol == 1)
            for (int i = 0; i < numRow; i++)
                ans.push_back(matrix[row++][col]);
        return ans;
    }
};
```
