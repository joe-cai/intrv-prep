#Edit Distance
The following solution can be further optimized by getting rid of `curr` array. This is because in the else branch of the inner for loop, we only need to use the preceding element in the same line. We can use a variable to store `prev[col]` and write `curr[col]` directly in `prev`. The stored variable can be used in the next iteration or as the return value.
```C++
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() < word2.size()) swap(word1, word2);
        vector<int> prev(word2.size() + 1, INT_MAX);
        vector<int> curr(word2.size() + 1, INT_MAX);
        for (int col = 0; col <= word2.size(); col++)
            prev[col] = col;
        for (int row = 1; row <= word1.size(); row++) {
            curr[0] = row;
            for (int col = 1; col <= word2.size(); col++) {
                if (word1[row - 1] == word2[col - 1])
                    curr[col] = prev[col - 1];
                else
                    curr[col] = min(prev[col - 1], min(prev[col], curr[col - 1])) + 1;
            }
            prev = curr;
        }
        return prev[word2.size()];
    }
};
```
