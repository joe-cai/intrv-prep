#Unique Binary Search Trees II
Recursive solution - every solution need to be a deep copy, so I don't think it is necessary to solve this problem using dynamic programming.
```C++
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> sol;
        if (start > end) {
            sol.push_back(NULL);
            return sol;
        } else if (start == end) {
            sol.push_back(new TreeNode(start));
            return sol;
        }
        
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = generate(start, i - 1);
            vector<TreeNode*> right = generate(i + 1, end);
            for (int j = 0; j < (int)(left.size()); j++)
                for (int k = 0; k < (int)(right.size()); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    sol.push_back(root);
                }
        }
        return sol;
    }
};
```
