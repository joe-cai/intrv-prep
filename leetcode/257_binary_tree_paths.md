#Binary Tree Paths
##Recursive solution
```C++
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> sol;
	string ans;
        if (root != NULL) fill(sol, ans, root);
        return sol;
    }
    void fill(vector<string>& sol, string& ans, TreeNode* root) {
        int prev_size = ans.size();
        if (prev_size != 0) ans = ans + "->";
        ans += to_string(root->val);
        if (root->left == NULL && root->right == NULL) sol.push_back(ans);
        else {
            if (root->left) fill(sol, ans, root->left);
            if (root->right) fill(sol, ans, root->right);
        }
        while (ans.size() > prev_size) { ans.pop_back(); }
    }
};
```

##Iterative solution
```C++

```