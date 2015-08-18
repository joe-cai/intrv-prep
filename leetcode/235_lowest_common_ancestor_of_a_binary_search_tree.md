#Lowest Common Ancestor of a Binary Search Tree
##Recursive algorithm
```C++
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) return NULL;
    else if (p == NULL) return q;
    else if (q == NULL) return p;

    if (root->val > p->val && root->val > q->val)
    return lowestCommonAncestor(root->left, p, q);
    else if (root->val < p->val && root->val < q->val)
    return lowestCommonAncestor(root->right, p, q);
    else return root;
}
```

##Iterative algorithm
```C++
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root != NULL) {
	if (root->val > p->val && root->val > q->val) root = root->left;
        else if (root->val < p->val && root->val < q->val) root = root->right;
        else return root;
    }
    return NULL;
}
```