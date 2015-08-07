#Path Sum II
```C++
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> sol;
        if (root == NULL) return sol;
        vector<int> ans;
        fill(sol, ans, root, sum);
        return sol;
    }
    void fill(vector<vector<int>>& sol, vector<int>& ans, TreeNode* root, int sum) {
        ans.push_back(root->val);
        if (root->left == NULL && root->right == NULL && sum == root->val) sol.push_back(ans);
        if (root->left != NULL) fill(sol, ans, root->left, sum - root->val);
        if (root->right != NULL) fill(sol, ans, root->right, sum - root->val);
        ans.pop_back();
    }
};
```
