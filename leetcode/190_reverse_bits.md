#Reverse Bits
```C++
class Solution {
public:
    const int numbit = 32;
    uint32_t reverseBits(uint32_t n) {
        int num = 0;
        for (int i = 0; i < numbit; i++) {
            num = num * 2 + n % 2; // num = (num << 1) | (n & 1)
            n = n / 2; // n = n >> 1
        }
        return num;
    }
};
```