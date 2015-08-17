#Intersection of Two Linked Lists
This solution comes from CC150. I don't think it is a good itea to implement such a tricky algorithm though. In fact, the problem can be solved by first counting the number of nodes in the linked lists, and then comparing corresponding nodes in the two lists.
```C++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        ListNode *p1 = headA, *p2 = headB;
        while (p1 && p2 && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
            if (p1 == p2) return p1;
            if (p1 == NULL) p1 = headB;
            if (p2 == NULL) p2 = headA;
        }
        return p1;
    }
};
```
