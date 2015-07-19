#Symmetric Tree
##Recursive solution
```C++
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return sym(root->left, root->right);
    }
    bool sym(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) return true;
        if (left == NULL || right == NULL) return false;
        return left->val == right->val
            && sym(left->left, right->right)
            && sym(left->right, right->left);
    }
};
```

##Iterative soluton
```C++
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        vector<TreeNode*> stack1;
        vector<TreeNode*> stack2;
        stack1.push_back(root);
        stack2.push_back(root);
        while (!stack1.empty() && !stack2.empty()) {
            TreeNode* root1 = stack1.back();
            TreeNode* root2 = stack2.back();
            stack1.pop_back();
            stack2.pop_back();
            if (root1->val != root2->val) return false;
            if (root1->left != NULL && root2->right != NULL) {
                stack1.push_back(root1->left);
                stack2.push_back(root2->right);
            }
            if (root1->right != NULL && root2->left != NULL) {
                stack1.push_back(root1->right);
                stack2.push_back(root2->left);
            }
            if ((root1->left == NULL && root2->right != NULL) ||
                (root1->left != NULL && root2->right == NULL) ||
                (root1->right == NULL && root2->left != NULL) ||
                (root1->right != NULL && root2->left == NULL))
                return false;
        }
        return true;
    }
};
```
