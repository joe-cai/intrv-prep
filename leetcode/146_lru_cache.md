#LRU Cache
The key of this problem is to maintain a double linked list, and always ensure that the latest record is at the top of the list, while the oldest record is at the rear of the list. All the operations maintain this property.
```C++
class DListNode {
public:
    int key;
    int val;
    DListNode* prev;
    DListNode* next;
    DListNode(int _key, int _val) { 
        key = _key;
        val = _val; 
        prev = NULL;
        next = NULL;
    }
};

class DList {
public:
    DListNode* head;
    DListNode* rear;
    DList() { 
        head = new DListNode(0, 0);
        rear = new DListNode(-1, 0);
        mov2top(rear);
    }
    void mov2top(DListNode* top) {
        if (top->prev != NULL) top->prev->next = top->next;
        if (top->next != NULL) top->next->prev = top->prev;
        top->next = head->next;
        top->prev = head;
        if (head->next != NULL) head->next->prev = top;
        head->next = top;
    }
};

class LRUCache{
public:
    int capacity;
    DList vals;
    unordered_map<int, DListNode*> key2node;
    
    LRUCache(int _capacity) { capacity = _capacity; }
    
    int get(int key) {
        auto it = key2node.find(key);
        if (it == key2node.end()) return -1;
        vals.mov2top(it->second);
        return it->second->val;
    }
    
    void set(int key, int value) {
        auto it = key2node.find(key);
        if (it != key2node.end()) { 
            it->second->val = value;
            vals.mov2top(it->second);
        } else if (key2node.size() < capacity) {
            key2node[key] = new DListNode(key, value);
            vals.mov2top(key2node[key]);
        } else {
            key2node.erase(vals.rear->prev->key);
            vals.rear->prev->key = key;
            vals.rear->prev->val = value;
            key2node[key] = vals.rear->prev;
            vals.mov2top(vals.rear->prev);
        }
    }
};
```
