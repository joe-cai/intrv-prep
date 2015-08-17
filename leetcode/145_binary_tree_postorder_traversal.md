#Binary Tree Postorder Traversal
This solution is based on the idea by `Deepalaxmi`. In the preorder traversal, the output of the nodes are in `root-left-right` order. We can modify the codes belonging to the preorder traversal to make the output in `root-right-left` order, then reverse the result, and finally get the `left-right-root` postorder traversal.
```C++
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        vector<TreeNode*> stack;
        while (root != NULL) {
            ans.push_back(root->val);
            if (root->left != NULL) stack.push_back(root->left);
            root = root->right;
            if (root == NULL && !stack.empty()) {
                root = stack.back();
                stack.pop_back();
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
