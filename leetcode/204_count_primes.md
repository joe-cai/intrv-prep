#Count Primes
```C++
class Solution {
public:
    int countPrimes(int n) {
        int ans = 0, sqrt_n = sqrt(n);
        vector<bool> isprime(n, true); // c-array : STL-vector = 1 : 4
        for (int i = 2; i < n; i++) {
            if (isprime[i] == true) {
                ans++;
                if (i > sqrt_n) continue;
                int factor = i * i;
                while (factor < n) {
                    if (isprime[factor])
                        isprime[factor] = false;
                    factor += i;
                }
            }
        }
        return ans;
    }
};
```