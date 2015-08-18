#Invert Binary Tree
##DFS
```C++
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};
```

##BFS
```C++
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        queue<TreeNode*> to_swap;
        to_swap.push(root);
        while (!to_swap.empty()) {
            TreeNode* curr = to_swap.front();
            to_swap.pop();
            if (curr->left) to_swap.push(curr->left);
            if (curr->right) to_swap.push(curr->right);
            swap(curr->left, curr->right);
        }
        return root;
    }
};
```
