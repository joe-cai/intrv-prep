#Excel Sheet Column Number
A - Z   |   AA  -  AZ     |   BA  -  BZ     |   ...   |   ZA  -  ZZ      |   AAA  -  AAZ
--------|-----------------|-----------------|---------|------------------|---------------------
A   1   |   AA    26+ 1   |   BA  2×26+ 1   |   ...   |   ZA  26×26+ 1   |   AAA  1×26²+1×26+ 1
B   2   |   AB    26+ 2   |   BB  2×26+ 2   |   ...   |   ZB  26×26+ 2   |   AAB  1×26²+1×26+ 2
.   .   |   ..    .....   |   ..  .......   |   ...   |   ..  ........   |   ...  .............   
.   .   |   ..    .....   |   ..  .......   |   ...   |   ..  ........   |   ...  .............
.   .   |   ..    .....   |   ..  .......   |   ...   |   ..  ........   |   ...  .............
Z  26   |   AZ    26+26   |   BZ  2×26+26   |   ...   |   ZZ  26×26+26   |   AAZ  1×26²+1×26+26

```C++
class Solution {
public:
    const int numletter = 26;
    string convertToTitle(int n) {
        string str;
        while (n > 0) {
            str.push_back((n - 1) % numletter + 'A');
            n = (n - 1) / numletter;
        }
        return string(str.rbegin(), str.rend());
    }
};
```
