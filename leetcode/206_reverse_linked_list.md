#Reverse Linked List
##Recursive solution
```C++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return reverse(head, NULL);
    }
    ListNode* reverse(ListNode* head, ListNode* tail) {
        if (head == NULL) return tail;
        ListNode* next = head->next;
        head->next = tail;
        return reverse(next, head);
    }
};
```

##Iterative solution
```C++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* tail = NULL;
        while (head != NULL) {
            ListNode* next = head->next;
            head->next = tail;
            tail = head;
            head = next;
        }
        return tail;
    }
};
```