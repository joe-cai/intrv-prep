#Candy
Linear time and linear space solution by `1145520074`. There are acutally linear time with constant space solution. But they all have to deal with lots of corner cases, which makes them unnecessarily complicated.
```C++
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        }
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1])
                candies[i] = max(candies[i], candies[i + 1] + 1);
        }
        int ans = 0;
        for (int i = 0; i < candies.size(); i++)
            ans += candies[i];
        return ans;
    }
};
```
