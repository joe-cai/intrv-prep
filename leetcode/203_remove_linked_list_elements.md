#Remove Linked List Elements
##Iterative algorithm with dummy header node
```C++
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;
        while (curr->next != NULL) {
            if (curr->next->val == val)
                curr->next = curr->next->next;
            else curr = curr->next;
        }
        return dummy->next;
    }
};
```

##Concise recursive algorithm by `renzid`
```C++
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return NULL;
        head->next = removeElements(head->next, val);
        return (head->val == val)? head->next : head;
    }
};
```