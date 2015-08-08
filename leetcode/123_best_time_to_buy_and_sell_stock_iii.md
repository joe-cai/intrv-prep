#Best Time to Buy and Sell Stock III
##Linear time and linear space solution
```C++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        
        vector<int> one_trans(prices.size(), 0);
        int min_price = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < min_price) min_price = prices[i];
            one_trans[i] = max(one_trans[i - 1], prices[i] - min_price);
        }
        
        int profit = 0, max_res = one_trans[0] - prices[0];
        for (int i = 1; i < prices.size(); i++) {
            profit = max(profit, max_res + prices[i]);
            max_res = max(max_res, one_trans[i] - prices[i]);
        }
        return profit;
    }
};
```

##Linear time and constant space solution by `weijiac`
```C++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1 = INT_MIN, hold2 = INT_MIN;
        int sold1 = 0, sold2 = 0;
        for (int i = 0; i < prices.size(); i++) {
            sold2 = max(sold2, hold2 + prices[i]); // max when 2nd stock is sold
            hold2 = max(hold2, sold1 - prices[i]); // max when 2nd stock is hold
            sold1 = max(sold1, hold1 + prices[i]); // max when 1st stock is sold
            hold1 = max(hold1, -prices[i]);        // max when 1st stock is hold
        }
        return sold2;
    }
};
```