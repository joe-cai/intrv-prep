#Rotate Image
##Why I did not make it in the first try:
See the comments in the codes.

##A brute-force coordinate transform solution
```C++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        /* The following codes are incorrect cuz it rotates 
        the rows in the center when n is odd twice!!
        for (int j = 0; j < (n + 1) / 2; j++) {
            for (int i = 0; i < (n + 1) / 2; i++) {
        */
        for (int j = 0; j < n / 2; j++) {
            for (int i = 0; i < (n + 1) / 2; i++) {
                int swap = matrix[j][i];
                matrix[j][i] = matrix[n - 1 - i][j];
                matrix[n - 1 - i][j] = matrix[n - 1 - j][n - 1 - i];
                matrix[n - 1 - j][n - 1 - i] = matrix[i][n - 1 - j];
                matrix[i][n - 1 - j] = swap;
            }
        }
    }
};
```

##A smart two-step solution by first flip the matrix, and then make it upside down.
By `ethan3`.
```C++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); i++)
            for (int j = i + 1; j < matrix[i].size(); j++)
                swap(matrix[i][j], matrix[j][i]);
    }
};
```
