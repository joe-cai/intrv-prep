#Construct Binary Tree from Preorder and Inorder Traversal
##Recursive version
```C++
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* build(vector<int>& preorder, int pre_s, int pre_e, 
                    vector<int>& inorder, int in_s, int in_e) {
        if (pre_s > pre_e) return NULL;
        TreeNode* root = new TreeNode(preorder[pre_s]);

        int pos = in_s; // find the position of the root node in inorder array
        while (inorder[pos] != preorder[pre_s]) { pos++; }

        root->left = build(preorder, pre_s + 1, pre_s + pos - in_s,
                           inorder, in_s, pos - 1);
        root->right = build(preorder, pre_s + pos - in_s + 1, pre_e,
                            inorder, pos + 1, in_e);
        return root;
    }
};
```
##Note
There is an iterative solution to this problem which I can not yet understand.
