#Binary Tree Zigzag Level Order Traversal
##Iterative verison using queue
```C++
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> sol;
        if (root == NULL) return sol; 
        queue<TreeNode*> level;
        level.push(root);
        int numnodes = 1;
        bool reversed = false;
        while (!level.empty()) {
            vector<int> ans;
            for (int i = 0; i < numnodes; i++) {
                TreeNode* curr = level.front();
                level.pop();
                if (curr->left != NULL) level.push(curr->left);
                if (curr->right != NULL) level.push(curr->right);
                ans.push_back(curr->val);
            }
            numnodes = level.size();
            if (reversed) reverse(ans.begin(), ans.end());
            reversed = !reversed;
            sol.push_back(ans);
        }
        return sol;
    }
};
```

##Recursive version using preorder traversal
```C++
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> sol;
        fill(sol, root, 0);
        for (int i = 1; i < sol.size(); i += 2)
            reverse(sol[i].begin(), sol[i].end());
        return sol;
    }
    void fill(vector<vector<int>>& sol, TreeNode* root, int depth) {
        if (root == NULL) return;
        if (depth == sol.size()) sol.push_back(vector<int>());
        
        sol[depth].push_back(root->val);
        fill(sol, root->left, depth + 1);
        fill(sol, root->right, depth + 1);
    }
};
```
