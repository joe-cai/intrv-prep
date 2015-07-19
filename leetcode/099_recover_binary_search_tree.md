#Recover Binary Search Tree
Implement an in-order traversal similar to the previous problem.
```C++
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        
        TreeNode* prev = new TreeNode(INT_MIN);
        inorder(root, first, second, prev);
        swap(first->val, second->val);
    }
    void inorder(TreeNode* root, TreeNode*& first, TreeNode*& second, TreeNode*& prev) {
        if (root == NULL) return;
        inorder(root->left, first, second, prev);
        if (first == NULL && prev->val > root->val)
            first = prev;
        // else if (first != NULL && prev->val > root->val); buggy
            // second = prev; buggy
        if (first != NULL && prev->val > root->val)
            second = root;
        prev = root;
        inorder(root->right, first, second, prev);
    }
};
```
