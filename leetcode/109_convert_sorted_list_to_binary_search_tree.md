#Convert Sorted List to Binary Search Tree
Linear time solution by `vaputa`. The key is to increment the list node as the inorder traversal proceeds.
```C++
class Solution {
public:
    ListNode* curr;
    TreeNode* sortedListToBST(ListNode* head) {
        curr = head;
        int size = 0;
        while (head != NULL) {
            head = head->next;
            size++;
        }
        return listToBST(size);
    }
    TreeNode* listToBST(int size) {
        if (size <= 0) return NULL;

        TreeNode* left = listToBST(size / 2);
        TreeNode* root = new TreeNode(curr->val);
        curr = curr->next;
        TreeNode* right = listToBST(size - size / 2 - 1);
        root->left = left;
        root->right = right;
        return root;
    }
};
```
