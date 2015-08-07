#Path Sum
```C++
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        if (root->left == NULL && root->right == NULL) return sum == root->val;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};
```
##Note
There are always iterative solutions to this kind of problems. But I don't think they are worth the effort since those solutions are usually not very intuitive.
