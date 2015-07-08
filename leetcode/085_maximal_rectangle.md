#Maximal Rectangle
##Quadratic solution based on the solution to the previous problem
```C++
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int sol = 0;
        vector<int> height(matrix[0].size(), 0);
        for (int row = 0; row < matrix.size(); row++) {
            for (int col = 0; col < matrix[row].size(); col++) {
                if (matrix[row][col] == '1')
                    height[col]++;
                else height[col] = 0;
            }
            sol = max(sol, largestRectangleArea(height));
        }
        return sol;
    }
    int largestRectangleArea(vector<int>& height) {
        if (height.size() == 0) return 0;
        height.push_back(-1);

        int maxArea = 0;
        vector<int> stack = {-1};
        for (int i = 0; i < height.size(); i++) {
            if (stack.back() != -1 && height[stack.back()] > height[i]) {
                while (stack.back() != -1 && height[stack.back()] > height[i]) {
                    int curr = stack.back();
                    stack.pop_back();
                    maxArea = max(maxArea, (i - stack.back() - 1) * height[curr]);
                }
            }
            stack.push_back(i);
        }
        return maxArea;
    }
};
```
