#Insertion Sort List
```C++
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* ans = new ListNode(0);
        ListNode* curr = head;
        ListNode* prev = ans;
        while (curr != NULL) {
            for (;prev->next != NULL && prev->next->val < curr->val;)
	    	prev = prev->next;
            ListNode* temp = prev->next;
            prev->next = curr;
            curr = curr->next;
            prev->next->next = temp;
            prev = ans;
        }
        return ans->next;
    }
};
```
