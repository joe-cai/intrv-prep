#Largest Rectangle in Histogram
##O(N) solution
The key idea is to compute the area for each bar as the lowest bar in the rectangle. In order to do this, we scan the height array, and keep pushing the bar into the stack. Whenever a bar is lower than the previous bar in the array, it means that the previous bars that are higher than this lower bar can at best extend to this point. So the current index is the rightmost index for those rectangles using those previous bar as the lowest bar. The leftmost index for those rectangels would then be the bar directly precedes them. This is because the bar in the stack would always be in increasing order. So the leftmost point where the particular bar can extend to must be the bar directly preceding it.
```C++
class Solution {
public:
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

##Tips
There is also a divide and conquer algorithm that can run in O(Nlog(N)) time. The idea is simply to divide the bars into two parts, and calculate the maximum area for separate parts respectively. Finally the maximum rectangle passing through the center is also calculated to get the maximum rectangle.
