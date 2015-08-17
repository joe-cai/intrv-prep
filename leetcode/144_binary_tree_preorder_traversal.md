#Binary Tree Preorder Traversal
##Iterative solution
```C++
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        vector<TreeNode*> stack;
        while (root != NULL) {
            ans.push_back(root->val);
            if (root->right != NULL) stack.push_back(root->right);
            root = root->left;
            if (root == NULL && !stack.empty()) {
                root = stack.back();
                stack.pop_back();
            }
        }
        return ans;
    }
```
