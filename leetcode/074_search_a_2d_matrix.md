#Search a 2D Matrix
Flatten the matrix into a 1D array by subscript transformation.
```C++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int numRow = matrix.size(), numCol = matrix[0].size();

        int start = 0, end = numRow * numCol - 1;
        while (start < end) {
            int mid = (start + end) / 2;
            int mid_row = mid / numCol, mid_col = mid % numCol;
            if (matrix[mid_row][mid_col] < target) start = mid + 1;
            else end = mid;
        }
        return matrix[start / numCol][start % numCol] == target;
    }
};
```
