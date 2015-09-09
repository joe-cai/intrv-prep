#Ugly Number II
Solution by `syftalent`. I used a heap to maintain the order of the generated ugly numbers, which is much slower. The cirtical part is that we don't actually need to store all the generated ugly numbers except the minimal one among them.
```C++
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n, 0);
        ugly[0] = 1;
	// three generated lists share the same ugly list.
        int index2 = 0, index3 = 0, index5 = 0; // don't store the generated one
        int factor2 = 2, factor3 = 3, factor5 = 5;
        for (int i = 1; i < n; i++) {
            int next = min(factor2, min(factor3, factor5));
            ugly[i] = next;
            if (factor2 == next) factor2 = 2 * ugly[++index2];
            if (factor3 == next) factor3 = 3 * ugly[++index3];
            if (factor5 == next) factor5 = 5 * ugly[++index5];
        }
        if (n == 7)
            for (int i = 0; i < n; i++) cout << ugly[i] << " ";
        
        return ugly[n - 1];
    }
};
```
