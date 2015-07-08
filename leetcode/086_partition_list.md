#Partition List
```C++
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *greater = new ListNode(x), *less = new ListNode(x);
        ListNode *greater_head = greater, *less_head = less;
        
        while (head != NULL) {
            if (head->val >= x) {
                greater->next = head;
                greater = greater->next;
            } else {
                less->next = head;
                less = less->next;
            }
            head = head->next;
        }
        less->next = greater_head->next;
        greater->next = NULL;
        return less_head->next;
    }
};
```
