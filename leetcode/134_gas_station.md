#Gas Station
A key observation by `daxianji007` is that, if the total amount of gas is not less than the total amount of cost, a circuit must exist. Vice virsa.
```C++
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int net = 0, total = 0;
        for (int i = 0; i < gas.size(); i++) {
            net += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (total < 0) { start = i + 1; total = 0; }
        }
        return (net >= 0)? start : -1;
    }
};
```