#Rectangle Area
```C++
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    	// clever way to compute the area without deciding if overlap or not
        int left = max(A, E), right = max(min(C, G), left);
        int bottom = max(B, F), top = max(min(D, H), bottom);
        // do the minus first to avoid overflow
        return (C - A) * (D - B) - (right - left) * (top - bottom) + (G - E) * (H - F);
    }
};
```