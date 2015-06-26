#Merge k Sorted Lists
The following solution is based on the Java solution by `wksora` without using a heap, which is pretty straight forward. My solution uses a heap, and the code is a little verboser.

```C++
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int numLists = lists.size();
        if (numLists == 0) return NULL;
        while (numLists > 1) {
            for (int i = 0; i < numLists / 2; i++)
                lists[i] = mergeLists(lists[2 * i], lists[2 * i + 1]);
            if (numLists % 2 == 0) 
                numLists /= 2;
            else { 
                lists[numLists / 2] = lists[numLists - 1]; 
                numLists = numLists / 2 + 1; 
            }
        }
        return lists[0];
    }
    ListNode* mergeLists(ListNode* a, ListNode* b) {
        ListNode* c = new ListNode(0);
        ListNode* head = c;
        while (a && b) {
            if (a->val < b->val) {
                c->next = a;
                a = a->next;
            } else {
                c->next = b;
                b = b->next;
            }
            c = c->next;
        }
        c->next = (a)? a : b;
        return head->next; // omit delete head
    }
};
```
