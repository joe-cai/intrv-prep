#Sort List
This solution uses an auxillary pointer to get to the middle node. Counting the number of nodes in the list is unnecessary in order to obtain the middle node.
```C++
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while (p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        p2 = sortList(p1->next);
        p1->next = NULL;
        p1 = sortList(head);
        return merge(p1, p2);
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* sol = new ListNode(0);
        ListNode* ans = sol;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                ans->next = l1;
                l1 = l1->next;
            } else {
                ans->next = l2;
                l2 = l2->next;
            }
            ans = ans->next;
        }
        if (l1 != NULL) ans->next = l1;
        if (l2 != NULL) ans->next = l2;
        return sol->next;
    }
};
```
