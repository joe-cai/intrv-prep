#Pascal's Triangle II
```C++
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i - 1; j >= 1; j--)
                row[j] = row[j - 1] + row[j];
        }
        return row;
    }
};
```
