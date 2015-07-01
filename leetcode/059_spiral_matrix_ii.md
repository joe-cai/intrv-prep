#Sprial Matrix II
```C++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> sol(n, vector<int>(n, 0));
        
        int row = 0, col = 0;
        int count = 1;
        while (n >= 2) {
            for (int i = 0; i < n - 1; i++)
                sol[row][col++] = count++;
            for (int i = 0; i < n - 1; i++)
                sol[row++][col] = count++;
            for (int i = 0; i < n - 1; i++)
                sol[row][col--] = count++;
            for (int i = 0; i < n - 1; i++)
                sol[row--][col] = count++;
            n -= 2;
            row++;
            col++;
        }
        if (n == 1) sol[row][col] = count;
        return sol;
    }
};
```
