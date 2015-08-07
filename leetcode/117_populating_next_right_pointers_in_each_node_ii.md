#Populating Next Right Pointers in Each Node II
```C++
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        TreeLinkNode* curr = root;
        while (curr != NULL) {
            TreeLinkNode* start = NULL;
            TreeLinkNode* prev = NULL;
            while (curr != NULL) {
                if (curr->left != NULL) {
                    if (start == NULL) start = curr->left;
                    if (prev != NULL) prev->next = curr->left;
                    prev = curr->left;
                }
                if (curr->right != NULL) {
                    if (start == NULL) start = curr->right;
                    if (prev != NULL) prev->next = curr->right;
                    prev = curr->right;
                }
                curr = curr->next;
            }
            curr = start;
        }
    }
};
```
