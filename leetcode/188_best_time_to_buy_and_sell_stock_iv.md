#Best Time to Buy and Sell Stock IV
##O(kN) time with O(N) space DP solution
Write down the state tranform equation:
dp[k][i] = max(dp[k][i - 1], max(dp[k-1][j] + prices[i] - prices[j]))
         = max(dp[k][i - 1], prices[i] + max(dp[k-1][j] - prices[j]))
dp[k][i] is the maximal profit trading the first i stocks in k transactions. 
0 <= j < i is the key to obtain the maximum in linear time in the inner loop.
```C++
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0) return 0;
        if (k >= prices.size() / 2) { // which means any number of transactions
            int ans = 0;
            for (int i = 0; i < prices.size() - 1; i++) {
                if (prices[i + 1] > prices[i])
                    ans += prices[i + 1] - prices[i];
            }
            return ans;
        }
        
        vector<int> profit(prices.size(), 0);
        for (int j = 0; j < k; j++) {
            profit[0] = 0;
            int maxCapital = profit[0] - prices[0];
            for (int i = 1; i < prices.size(); i++) {
                int bestDeal = maxCapital;
                maxCapital = max(maxCapital, profit[i] - prices[i]);
                profit[i] = max(profit[i - 1], prices[i] + bestDeal);
            }
        }
        return profit.back();
    }
};
```

##Note
This problem can also be solved as in Best Time to Buy and Sell Stock II using hold and release. In that case, the space complexity can be reduced to O(k).