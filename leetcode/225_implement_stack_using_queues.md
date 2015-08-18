#Implement Stack using Queues
```C++
class Stack {
public:
    queue<int> stack;
    void push(int x) {
        int n = stack.size();
        stack.push(x);
        for (int i = 0; i < n; i++) {
            stack.push(stack.front());
            stack.pop();
        }
    }

    void pop() {
        stack.pop();
    }

    int top() {
        return stack.front();
    }

    bool empty() {
        return stack.empty();
    }
};
```
