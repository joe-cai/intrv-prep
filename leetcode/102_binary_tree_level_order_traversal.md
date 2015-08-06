#Binary Tree Level Order Traversal
##Iterative version using queue
```C++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> sol;
        queue<TreeNode*> level;
        level.push(root);
        level.push(NULL);
        while (level.front() != NULL) {
            vector<int> ans;
            while (level.front() != NULL) {
                TreeNode* curr = level.front();
                ans.push_back(curr->val);
                level.pop();
                if (curr->left != NULL)
                    level.push(curr->left);
                if (curr->right != NULL)
                    level.push(curr->right);
            }
            level.pop();
            level.push(NULL);
            sol.push_back(ans);
        }
        return sol;
    }
};
```
Here `NULL` is used as a sentinel. There are other solutions which count the number of nodes in the current level without using a sentinel.

##Recursive version using preorder traversal
```C++
class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> sol;
	fill(sol, root, 0);
	return sol;
    }
    void fill(vector<vector<int>>& sol, TreeNode* root, int depth) {
    	if (root == NULL) return;
	if (sol.size() == depth) sol.push_back(vector<int>());
	
	sol[depth].push_back(root->val);
	fill(sol, root->left, depth + 1);
	fill(sol, root->right, depth + 1);
    }
};
```
