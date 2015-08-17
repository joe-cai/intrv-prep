#Maximal Square
```C++
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int ans = 0;
        
        vector<int> square(matrix[0].size(), 0); // as bottom right
        vector<int> upper(matrix[0].size(), 0); // as bottom
        vector<int> lefter(matrix[0].size(), 0); // as right
        for (int col = 0; col < matrix[0].size(); col++) {
            square[col] = matrix[0][col] - '0';
            upper[col] = matrix[0][col] - '0';
            lefter[col] = (matrix[0][col] - '0') * ((col == 0)? 1 : (lefter[col - 1] + 1));
            ans = max(square[col], ans);
        }
        
        for (int row = 1; row < matrix.size(); row++) {
            vector<int> pre_square = square;
            square[0] = matrix[row][0] - '0';
            upper[0] = (matrix[row][0] - '0') * (upper[0] + 1);
            lefter[0] = matrix[row][0] - '0';
            ans = max(square[0], ans);
            for (int col = 1; col < matrix[row].size(); col++) {
                square[col] = (matrix[row][col] - '0') * (min(pre_square[col - 1], min(upper[col], lefter[col - 1])) + 1);
                upper[col] = (upper[col] + 1) * (matrix[row][col] - '0');
                lefter[col] = (lefter[col - 1] + 1) * (matrix[row][col] - '0');
                ans = max(square[col], ans);
            }
        }
        return ans * ans;
    }
};
```