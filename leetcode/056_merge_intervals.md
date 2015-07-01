#Merge Intervals
There are two methods to define a customized method in `sort()`. The following solution uses one of them which defines a comparator function *outside* the class definition. The other method is to define a comparator structure *inside* the class definition. Note that the following solution is also in-place.
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
bool cmp (struct Interval a, struct Interval b) { return a.start < b.start; }
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() == 0) return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        struct Interval prev = intervals[0];
        int pos = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (prev.end >= intervals[i].start) prev.end = max(prev.end, intervals[i].end);
            else { intervals[pos++] = prev; prev = intervals[i]; }
        }
        intervals[pos++] = prev;
        intervals.erase(intervals.begin() + pos, intervals.end());
        return intervals;
    }
};
```
