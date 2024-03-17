/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105

*/


//------------------------------------------------------------------------------------------SOLUTION---------------------------------------------------

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0;
        vector<vector<int>> res;
         int n = intervals.size();
        while(i<n) {
           if(intervals[i][1] < newInterval[0]) { // case 1 if end_i in intervals is smaller than start of new interval
              res.push_back(intervals[i]);
           }else if(intervals[i][0] > newInterval[1]) { // case 2 check if start_i in intervals is greater than the end of newinterval
            break;
           }else {
            // if found to be overlapping merge and create a new interval 
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
           }
           i++;
        }
           res.push_back(newInterval); // push the new interval found to vector 
           // at last push all the left intervals in res;
           while(i<n) {
            res.push_back(intervals[i]);
            i++;
           }
           return res;
    }
};