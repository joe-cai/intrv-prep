#Different Ways to Add Parentheses
##Naive recursive solution
```C++
```

##Postfix recursive solution
We count the number of different arrangements in the corresponding postfix exp. For example,
(2*(3-(4*5))) <=> 2 3 4 5 * - *
((2*3)-(4*5)) <=> 2 3 * 4 5 * -
We can count the number of ways to add parentheses by counting how many different postfix there are, which is not hard. As we can see, the relative order of the numbers are fixed, while the operations have to be the same with the first operand. So the only divergence is to add an operation or a number. The following recursive algorithm solve this without redundant repeatition.
```C++
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;
        vector<char> ops; // nums.size() == ops.size() + 1
        int pos = 0;
        while (pos < input.size()) {
            int num = 0;
            while (pos < input.size() && input[pos] >= '0' && input[pos] <= '9') {
                num = num * 10 + input[pos] - '0';
                pos++;
            }
            nums.push_back(num);
            if (pos == input.size()) break;
            ops.push_back(input[pos++]);
        }
        
        vector<int> sol;
        if (nums.size() == 0) return vector<int>();
        vector<pair<int, int>> stack;
        stack.push_back(pair<int, int>(nums.front(), 0));
        parse(stack, sol, 1, nums, ops);
        return sol;
    }
    // parse all possible postfix expressions
    void parse(vector<pair<int, int>> stack, vector<int>& sol, int pos_num, 
               const vector<int>& nums, const vector<char>& ops) {
        if (stack.size() == 1 && pos_num == nums.size()) { // get result
            sol.push_back(stack.front().first);
            return;
        } else if (stack.size() == 1) { // pos_num < nums.size(), only one option
            stack.push_back(pair<int, int>(nums[pos_num], pos_num));
            parse(stack, sol, pos_num + 1, nums, ops);
        } else { // stack.size() > 1, may have two options
            if (pos_num < nums.size()) {
                // choose a num
                stack.push_back(pair<int, int>(nums[pos_num], pos_num));
                parse(stack, sol, pos_num + 1, nums, ops);
                stack.pop_back();
            }
            // choose an op
            pair<int, int> num2 = stack.back();
            stack.pop_back();
            pair<int, int> num1 = stack.back();
            stack.pop_back();
            switch(ops[num2.second - 1]) {
            case '+': stack.push_back(pair<int, int>(num1.first + num2.first, num1.second)); break;
            case '-': stack.push_back(pair<int, int>(num1.first - num2.first, num1.second)); break;
            case '*': stack.push_back(pair<int, int>(num1.first * num2.first, num1.second)); break;
            }
            parse(stack, sol, pos_num, nums, ops);
        }
    }
};
```

##Dynamic Programming
```C++
```