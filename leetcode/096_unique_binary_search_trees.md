#Unique Binary Search Trees
Dynamic programming solution
```C++
class Solution {
public:
    int numTrees(int n) {
        vector<int> sol(n + 1, 0);
        sol[0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i; j++)
                sol[i] += sol[j - 1] * sol[i - j];
        return sol[n];
    }
};
```
