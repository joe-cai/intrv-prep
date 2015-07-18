#Binary Tree Inorder Traversal
Trivial recursive solution
```C++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> sol;
        helper(sol, root);
        return sol;
    }
    void helper(vector<int>& sol, TreeNode* root) {
        if (root == NULL)
            return;
        helper(sol, root->left);
        sol.push_back(root->val);
        helper(sol, root->right);
    }
};
```

Iterative version using stack
```C++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> sol;
        
        vector<TreeNode*> stack;
        while (root != NULL) {
            stack.push_back(root);
            root = root->left;
        }
        while (!stack.empty()) {
            TreeNode* curr = stack.back();
            sol.push_back(curr->val);
            stack.pop_back();

            TreeNode* next = curr->right;
            while (next != NULL) {
                stack.push_back(next);
                next = next->left;
            }
        }
        
        return sol;
    }
};
```

An more unified solution by `KaiChen`
```C++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> sol;
        
        vector<TreeNode*> stack;
        while (!stack.empty() || root != NULL) {
            if (root != NULL) {
                stack.push_back(root);
                root = root->left;
            } else {
                TreeNode* curr = stack.back();
                sol.push_back(curr->val);
                stack.pop_back();
                root = curr->right;
            }
        }
        
        return sol;
    }
};
```
