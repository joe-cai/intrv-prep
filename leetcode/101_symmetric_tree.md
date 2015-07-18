#Symmetric Tree
Recursive solution.
```C++
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return sym(root->left, root->right);
    }
    bool sym(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) return true;
        if (left == NULL || right == NULL) return false;
        return left->val == right->val
            && sym(left->left, right->right)
            && sym(left->right, right->left);
    }
};
```
