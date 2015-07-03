#Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;
        int numNode = 1;
        ListNode* trav = head;
        while (trav->next != NULL) { 
            trav = trav->next;
            numNode++;
        }
        trav->next = head;
        for (int i = 0; i < numNode - k % numNode; i++)
            trav = trav->next;
        head = trav->next;
        trav->next = NULL;
        return head;
    }
};
```
