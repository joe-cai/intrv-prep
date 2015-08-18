#Kth Smallest Element in a BST
This problem is essentially a matter of BST inorder search. The followup problem is interesting. Modify the tree structure as followed
```C++
struct TreeNode {
    int val;
    int count; // counts the number of nodes in this BST
    // updating also takes O(height of BST)
    TreeNode* left;
    TreeNode* right;
    // count is initialized to 1
};
```
The corresponding algorithm for finding the kth smallest element
```C++
while (k != 0) {
    if (root->left == NULL) {
        if (k == 1) return root->Val;
       	else root = root->right;
    }
    else if (root->left->count >= k) root = root->left;
    else if (root->left->count == k - 1) return root->val;
    else { root = root->right; k = k - root->left->count - 1; }
```

Updating the BST (insert `val`, similar for delete operation)
```C++
bool duplicate = false;
while (root) {
    if (root->val > val) {
       if (root->left != NULL) root = root->left;
       else root->left = new TreeNode(val);
    } else if (root->val < val) {
       if (root->right != NULL) root = root->right;
       else root->right = new TreeNode(val);
    } else /* root->val == val */ { duplicate = true; return; }
}
if (!duplicate) {
    while (root->val != val) {
        root->count++;
	if (root->val > val) root = root->left;
	else if (root->val < val) root = root->right;
    }
}
```