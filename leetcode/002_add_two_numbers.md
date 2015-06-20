#Add Two Numbers
##Why I did not make it in the first pass:
forgot the corner case where a dangling carry exists

```C++
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *l3 = &dummy;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry > 0) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            l3->next = new ListNode(sum % 10);
            l3 = l3->next;
            l1 = (l1 ? l1->next : NULL);
            l2 = (l2 ? l2->next : NULL);
        }
        return dummy.next;
    }
};
```
