#Insert Interval
The following is an in-place solution. The code can be further simplified if extra space is allowed.
```C++
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int pos = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval.end < intervals[i].start) {
                swap(intervals[pos], newInterval);
                if (pos != i) swap(newInterval, intervals[i]);
                pos++; // deal with corner case where pos == i
            } else if (newInterval.start <= intervals[i].end) {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            } else
                intervals[pos++] = intervals[i];
        }
        if (pos == intervals.size()) 
            intervals.push_back(newInterval);
        else { 
            intervals[pos++] = newInterval;
            intervals.erase(intervals.begin() + pos, intervals.end()); 
        }
        return intervals;
    }
};
```
