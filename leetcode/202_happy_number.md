#Happy Number
##Solution using hash-alike technique
```C++
class Solution {
public:
    const int maxnum = 9 * 9 * 10 + 1;
    bool isHappy(int n) {
        vector<bool> appear(maxnum, false);
        appear[1] = true;
        n = translate(n);
        while (!appear[n]) {
            appear[n] = true;
            n = translate(n);
        }
        return n == 1;
    }
    int translate(int n) {
        int ans = 0;
        while (n > 0) {
            ans += (n % 10) * (n % 10);
            n /= 10;
        }
        return ans;
    }
};
```

##Solution using Floyd cycle detection algorithm (cycle in linked-list)
```C++
class Solution {
public:
    bool isHappy(int n) {
        int fast = n, slow = n;
        while (fast != 1 && slow != 1) {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
            if (fast == slow) break;
        }
        return (fast == 1) || (slow == 1);
    }
    int digitSquareSum(int n) {
        int ans = 0;
        while (n > 0) {
            int digit = n % 10;
            ans += digit * digit;
            n /= 10;
        }
        return ans;
    }
};
```