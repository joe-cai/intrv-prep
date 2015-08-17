#Linked List Cycle
```C++
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        
        ListNode* fast = head->next->next;
        ListNode* slow = head->next;

        while (fast && fast->next && slow && fast != slow) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return fast == slow;
    }
};
```
