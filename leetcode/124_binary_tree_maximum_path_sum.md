#Binary Tree Maximum Path Sum
```C++
class Solution {
public:
    int ans;
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        maxFromRoot(root);
        return ans;
    }
    int maxFromRoot(TreeNode* root) {
        if (root == NULL) return 0;
        int leftMax = maxFromRoot(root->left);
        int rightMax = maxFromRoot(root->right);
        ans = max(ans, max(0, leftMax) + max(0, rightMax) + root->val);
        return root->val + max(0, max(leftMax, rightMax));
    }
};
```