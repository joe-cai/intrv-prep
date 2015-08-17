#Copy List with Random Pointer
##Linear time with constant space solution
```C++
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        RandomListNode* curr = head;
        while (curr != NULL) {
            RandomListNode* new_node = new RandomListNode(curr->label);
            new_node->next = curr->next;
            new_node->random = curr->random;
            curr->next = new_node;
            curr = new_node->next;
        }

        curr = head;
        while (curr != NULL) {
            if (curr->next->random != NULL)
                curr->next->random = curr->next->random->next;
            curr = curr->next->next;
        }

        RandomListNode* new_head = head->next;
        RandomListNode* new_curr = new_head;
        curr = head;
        while (curr != NULL) {
            curr->next = curr->next->next;
            curr = curr->next;
            if (curr == NULL) break;
            new_curr->next = curr->next;
            new_curr = new_curr->next;
        }
        return new_head;
    }
};
```

##Linear time with linear space solution
```C++
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        
        unordered_map<RandomListNode*, RandomListNode*> map;
        map[head] = copy(head);
        
        queue<RandomListNode*> todo;
        todo.push(map[head]);
        while (!todo.empty()) {
            RandomListNode* curr = todo.front();

            if (curr->next != NULL && map.find(curr->next) == map.end()) {
                map[curr->next] = copy(curr->next);
                todo.push(map[curr->next]);
            }
            curr->next = map[curr->next];

            if (curr->random != NULL && map.find(curr->random) == map.end()) {
                map[curr->random] = copy(curr->random);
                todo.push(map[curr->random]);
            }
            curr->random = map[curr->random];
            
            todo.pop();
        }
        return map[head];
    }
    RandomListNode* copy(RandomListNode* head) {
        RandomListNode* new_head = new RandomListNode(head->label);
        new_head->next = head->next;
        new_head->random = head->random;
        return new_head;
    }
};
```
