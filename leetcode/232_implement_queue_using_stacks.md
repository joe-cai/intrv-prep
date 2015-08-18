#Implement Queue using Stacks
```C++
class Queue {
public:
    vector<int> pushstack;
    vector<int> popstack;
    // Push element x to the back of queue.
    void push(int x) {
        pushstack.push_back(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        peek();
        popstack.pop_back();
    }

    // Get the front element.
    int peek(void) {
        if (popstack.empty()) {
            while (!pushstack.empty()) {
                popstack.push_back(pushstack.back());
                pushstack.pop_back();
            }
        }
        return popstack.back();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return pushstack.empty() && popstack.empty();
    }
};
```