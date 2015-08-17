#Binary Tree Right Side View
##Iterative method using NULL as the sentinel
```C++
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        queue<TreeNode*> level;
        level.push(root);
        level.push(NULL);

        TreeNode* prev = NULL;
        while (!level.empty()) {
            TreeNode* curr = level.front();
            level.pop();
            if (curr != NULL) {
                if (curr->left != NULL) level.push(curr->left);
                if (curr->right != NULL) level.push(curr->right);
            } else { // curr == NULL
                ans.push_back(prev->val);
                if (!level.empty()) level.push(NULL);
            }
            prev = curr;
        }
        return ans;
    }
};
```

##Recursive method using modified preorder traversal
```C++
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> sol;
        preorder(root, 0, sol);
        return sol;
    }
    void preorder(TreeNode* root, int depth, vector<int>& sol) {
        if (root == NULL) return;
        if (depth == sol.size()) sol.push_back(root->val);
        preorder(root->right, depth + 1, sol);
        preorder(root->left, depth + 1, sol);
    }
};
```