#Merge Two Sorted Lists
```C++
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* l3 = head;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) { l3->next = l1; l1 = l1->next; }
            else { l3->next = l2; l2 = l2->next; }
            l3 = l3->next;
        }
        l3->next = l1? l1 : l2; /* convenient! */
        return head->next;
    }
};
```
