#Longest Substring without Repeating Characters
##Why I did not make it in the first try:
compile error

##O(N) DP solution
```C++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);
        /* s[i, ..., j - 1] denotes the longest 
        valid sequence ending with s[j - 1] */
        int ans = 0;
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
	    // take s[j] into consideration
            i = max(i, hash[s[j]] + 1);
            hash[s[j]] = j;
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
```

##Tips:
`container.size()` return a value of type `container::size_type`. Using `size_type` is better than using `int` or `size_t` in that, `INT_MAX` is generally less than `max_size` of a particular container, `size_t` is always library dependent (e.g QT), while `size_type` is container dependent, which is the most portable.
