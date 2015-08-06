#Minimum Depth of Binary Tree
##Breath First Search on the binary tree
```C++
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        queue<TreeNode*> level;
        level.push(root);
        int numnode = 1, size = 1;
        while (!level.empty()) {
            for (int i = 0; i < numnode; i++) {
                TreeNode* curr = level.front();
                if (curr->left == NULL && curr->right == NULL) return size;
                if (curr->left != NULL) level.push(curr->left);
                if (curr->right != NULL) level.push(curr->right);
                level.pop();
            }
            numnode = level.size();
            size++;
        }
        return size;
    }
};
```
