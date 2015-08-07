#Populating Next Right Pointers in Each Node
```C++
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        TreeLinkNode *curr = root;
        while (curr->left != NULL) { // has next level
            TreeLinkNode *level = curr;
            while (level != NULL) {
                level->left->next = level->right;
                if (level->next != NULL) level->right->next = level->next->left;
                level = level->next;
            }
            curr = curr->left;
        }
    }
};
```
