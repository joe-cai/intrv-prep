#Reorder List
```C++
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;
        ListNode *p1 = head, *p2 = head->next; // (#nodes - 1) / 2 steps
        while (p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        ListNode* head2 = p1->next;
        p1->next = NULL; // split two lists, the latter has at least 1 node
        
        p2 = head2->next;
        head2->next = NULL;
        while (p2 != NULL) {
            ListNode* temp = p2->next;
            p2->next = head2;
            head2 = p2;
            p2 = temp;
        } // reverse the second list
        
        p1 = head, p2 = head2;
        while (p1) {
            ListNode* temp = p1->next;
            p1->next = p2;
            p1 = p2;
            p2 = temp;
        } // merge the two lists
    }
};
```
