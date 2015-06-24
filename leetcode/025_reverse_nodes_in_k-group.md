#Remove Nodes in k-group
```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        while (curr) {
            ListNode* checkpoint = prev;
            ListNode* next = curr->next;
            for (int i = 1; i < k; i++) {
                if (!next) { // less than k nodes, recover them
                    prev = checkpoint;
                    curr = prev->next;
                    next = curr->next;
                    for (int j = 1; j < i; j++) {
                        curr->next = next->next;
                        next->next = prev->next;
                        prev->next = next;
                        next = curr->next;
                    }
                    ListNode* ans = dummy->next;
                    delete dummy;
                    return ans;
                }
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev = curr;
            curr = curr->next;
        }
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
```
