#Construct Binary Tree from Inorder and Postorder Traversal
```C++
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode* build(vector<int>& inorder, int in_s, int in_e,
                    vector<int>& postorder, int post_s, int post_e) {
        if (in_s > in_e) return NULL;
        TreeNode* root = new TreeNode(postorder[post_e]);

        int pos = in_s;
        while (inorder[pos] != postorder[post_e]) { pos++; }

        root->left = build(inorder, in_s, pos - 1, 
                           postorder, post_s, post_s + pos - 1 - in_s);
        root->right = build(inorder, pos + 1, in_e, 
                            postorder, post_e - in_e + pos, post_e - 1);
        return root;
    }
};
```
