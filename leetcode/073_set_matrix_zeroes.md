#Set Matrix Zeroes
The solution reuses the space in the original matrix, which is kind of hacky...
```C++
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        int numRow = matrix.size();
        int numCol = matrix[0].size();
        // bookkeeping if the first row and col need to be cleared
        bool zero_first_row = false;
        for (int col = 0; col < numCol && !zero_first_row; col++)
            if (matrix[0][col] == 0) zero_first_row = true;
        bool zero_first_col = false;
        for (int row = 0; row < numRow && !zero_first_col; row++)
            if (matrix[row][0] == 0) zero_first_col = true;
        // setting flags in first row and col without contaminating the matrix
        for (int row = 1; row < numRow; row++)
            for (int col = 1; col < numCol; col++)
                if (matrix[row][col] == 0) {
                    matrix[0][col] = 0;
                    matrix[row][0] = 0;
                }
        // clear the matrix guided by first row and col
        for (int row = 1; row < numRow; row++)
            for (int col = 1; col < numCol; col++)
                if (matrix[0][col] == 0 || matrix[row][0] == 0)
                    matrix[row][col] = 0;
        // clear first row and col if nesessary
        for (int col = 0; col < numCol && zero_first_row; col++)
            matrix[0][col] = 0;
        for (int row = 0; row < numRow && zero_first_col; row++)
            matrix[row][0] = 0;
    }
};
```
