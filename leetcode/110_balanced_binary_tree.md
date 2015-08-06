#Balanced Binary Tree
```C++
class Solution {
public:
    bool balanced;
    bool isBalanced(TreeNode* root) {
        balanced = true;
        height(root);
        return balanced;
    }
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        if (left - right < -1 || left - right > 1)
            balanced = false;
        return max(left, right) + 1;
    }
};
```
