#Remove Duplicates from Sorted List II
```C++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* curr = dummy;
        while (curr->next != NULL && curr->next->next != NULL) {
            if (curr->next->val == curr->next->next->val) {
                int prev = curr->next->val;
                while (curr->next != NULL && prev == curr->next->val) {
                    curr->next = curr->next->next;
                }
            } else curr = curr->next;
        }
        return dummy->next;
    }
};
```
