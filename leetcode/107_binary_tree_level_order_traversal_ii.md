#Binary Tree Level Order Traversal II
```C++
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> sol;
        queue<TreeNode*> level;
        level.push(root);
        level.push(NULL);
        while (level.front() != NULL) {
            vector<int> ans;
            while (level.front() != NULL) {
                TreeNode* curr = level.front();
                level.pop();
                ans.push_back(curr->val);
                if (curr->left != NULL)
                    level.push(curr->left);
                if (curr->right != NULL)
                    level.push(curr->right);
            }
            level.pop();
            level.push(NULL);
            sol.push_back(ans);
        }
	// the only different code with Binary Tree Level Order Traversal I
        reverse(sol.begin(), sol.end());
        return sol;
    }
};
```
