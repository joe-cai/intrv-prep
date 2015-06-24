#Implement strStr
##Why I did not make it in the first try:
Again, we need to pay attention to the type `container::size_type`, which is probably a `typedef` of `unsigned long`. If in the following implementation, the type cast `(int)` is omitted, `haystack.size() - needle.size()` will be an extremely huge numbers if string `haystack` is shorted that `needle`, due to the unsigned nature. This is where I fail at the first try.
```C++
class Solution {
public:
    int strStr(string haystack, string needle) {
         // the type cast is of extremely critical in this case
        for (int i = 0; i <= (int)(haystack.size() - needle.size()); i++) {
            bool found = true;
            for (int j = 0; j < needle.size(); j++)
                if (haystack[i + j] != needle[j]) { found = false; break; }
            if (found) return i;
        }
        return -1;
    }
};
```
