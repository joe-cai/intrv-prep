#Pow(x, n)
```C++
class Solution {
public:
    double myPow(double x, int n) {
    	// deal with negative numbers
        if (n == INT_MIN) return (1.0 / myPow(x, INT_MAX)) / x;
        if (n < 0) return 1.0 / myPow(x, -n);
	// base cases
        if (n == 0) return 1;
        if (n == 1) return x;
	// divide and conquer
        double sqroot = myPow(x, n / 2);
        if (n % 2 == 0) return sqroot * sqroot;
        else return sqroot * sqroot * x;
    }
};
```
