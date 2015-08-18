#Lowest Common Ancestor of a Binary Tree
Solution by `StefanPochmann`. Essentially doing an preorder traversal on the binary tree. If the traversal ever found `p` or `q`, this node will be returned to the parent. When neither left subtree nor right subtree is `NULL`, the ancestor is found and returned to the parent.
##Recursive solution
```C++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        else if (left) return left;
        else return right;
    }
};
```

##Iterative solution
```C++

```