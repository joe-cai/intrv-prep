#Evaluate Reverse Polish Notation
Ignore "Each operand may be an integer or another expression" in the problem statement, since no test cases actually contains an expression in the tokens.
```C++
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 0) return 0;
        vector<int> stack;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" ||
                tokens[i] == "*" || tokens[i] == "/") {
                int num2 = stack.back();
                stack.pop_back();
                int num1 = stack.back();
                stack.pop_back();
                switch(tokens[i][0]) {
                case '+': stack.push_back(num1 + num2); break;
                case '-': stack.push_back(num1 - num2); break;
                case '*': stack.push_back(num1 * num2); break;
                case '/': stack.push_back(num1 / num2); break;
                }
            } else
                stack.push_back(parse(tokens[i]));
        }
        return stack.back();
    }
    int parse(string& token) {
        int num = 0, sign = 1;
        if (token.size() == 0) return 0;
        int pos = 0;
        if (token[pos] == '+' || token[pos] == '-') 
	    sign = (token[pos++] == '-')? -1 : 1;
        for (int i = pos; i < token.size(); i++) 
	    num = 10 * num + token[i] - '0';
        return num * sign;
    }
};
```
