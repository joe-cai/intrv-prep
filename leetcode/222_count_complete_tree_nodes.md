#Count Complete Tree Nodes
```C++
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;

        int left_h = 0, right_h = 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        while (left != NULL) { left_h++; left = left->left;}
        while (right != NULL) { right_h++; right = right->right; }
        if (left_h == right_h) return pow2(left_h + 1) - 1; // full and complete

	// else left_h == right_h + 1
        left_h = 0;
        left = root->left;
        while (left != NULL) { left_h++; left = left->right; }
        if (left_h == right_h) return pow2(right_h) + countNodes(root->left);
        else return pow2(left_h) + countNodes(root->right);
    }
    int pow2(int h) {
        if (h == 0) return 1;
        else if (h == 1) return 2;
        int ans = pow2(h / 2);
        if (h % 2 == 0) return ans * ans;
        else return ans * ans * 2;
    }
};
```