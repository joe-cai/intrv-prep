#Flatten Binary Tree to Linked List
An in-place linear iterative solution by `zjulyx`. Every node in the binary tree will be visited by `curr` exactly once, and by `prev` at most once.
```C++
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != NULL) {
            TreeNode* prev = curr->left; // the first node that connects curr->right
            if (prev != NULL) {
                while (prev->right != NULL) { prev = prev->right; }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};
```
