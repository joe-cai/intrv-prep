#Reverse Linked List II
Let `prev` denote the node preceding the m-th node (index starts from 1), `curr` denote node starting from the m-th node. The following algorithm works by repeatly inserting node `curr` in the position directly after `prev`.
```C++
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        // points to node preceding the m-th node (index starts from 1)
        for (int i = 1; i < m; i++) prev = prev->next;
        ListNode* curr = prev->next;
        for (int i = m; i < n; i++) {
            ListNode* temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;
        }
        return dummy->next;
    }
};
```
