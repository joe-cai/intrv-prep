#Min Stack
```C++
class MinStack {
public:
    vector<int> stack;
    vector<int> mins;
    void push(int x) {
        stack.push_back(x);
        if (mins.empty() || mins.back() > x) mins.push_back(x);
        else mins.push_back(mins.back());
    }

    void pop() {
        stack.pop_back();
        mins.pop_back();
    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return mins.back();
    }
};
```
##Note
The two stacks can be merged into only one stack.
