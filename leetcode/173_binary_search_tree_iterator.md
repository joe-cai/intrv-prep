#Binary Search Tree Iterator
```C++
class BSTIterator {
public:
    BSTIterator(TreeNode *root) { push(root); }

    /** @return whether we have a next smallest number */
    bool hasNext() { return !path.empty(); }

    /** @return the next smallest number */
    int next() {
        TreeNode* curr = path.back();
        path.pop_back();
        push(curr->right);
        return curr->val;
    }
private:
    vector<TreeNode*> path;
    void push(TreeNode* curr) {
        while (curr != NULL) {
            path.push_back(curr);
            curr = curr->left;
        }
    }
};
```
