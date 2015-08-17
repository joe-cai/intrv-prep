#Compare Version Numbers
```C++
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int pos1 = 0, pos2 = 0;
        while (pos1 < version1.size() || pos2 < version2.size()) {
            int num1 = 0;
            while (pos1 < version1.size() && version1[pos1] != '.') {
                num1 = 10 * num1 + version1[pos1] - '0';
                pos1++;
            }
            pos1++;
            int num2 = 0;
            while (pos2 < version2.size() && version2[pos2] != '.') {
                num2 = 10 * num2 + version2[pos2] - '0';
                pos2++;
            }
            pos2++;
            if (num1 > num2) return 1;
            else if (num1 < num2) return -1;
        }
        return 0;
    }
};
```
