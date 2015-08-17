#Linked List Cycle II
```C++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        
        ListNode* fast = head->next->next;
        ListNode* slow = head->next;
        while (fast && fast->next && slow && fast != slow) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast != slow || fast == NULL) return NULL;

        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
```
