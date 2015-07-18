#Validate Binary Search Tree
```C++
class Solution {
public:
    TreeNode* prev;
    bool isValidBST(TreeNode* root) {
        prev = NULL;
        return helper(root);
    }
    bool helper(TreeNode* root) {
        // go through inorder traversal and collect the nodes
        if (root == NULL) return true;
        if (!helper(root->left)) return false;
        if (prev != NULL && prev->val >= root->val)
            return false;
        prev = root;
        if (!helper(root->right)) return false;
        return true;
    }
};
```
