// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
//
// You may assume that the intervals were initially sorted according to their start times.
//
// Example 1:
//
//
// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]
//
//
// Example 2:
//
//
// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
//


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
        auto iti = lower_bound(intervals.begin(), intervals.end(), newInterval, [](Interval a, Interval b){return a.end < b.start;}) ;
        auto itj = upper_bound(iti, intervals.end(), newInterval, [](Interval a, Interval b) {return a.end < b.start;});
        if(iti == itj){
            intervals.insert(iti, newInterval);
        }else{
            iti->start = min(iti->start, newInterval.start);
            iti->end = max((itj - 1)->end, newInterval.end);
            intervals.erase(iti + 1, itj);
        }
        return intervals;
    }
};