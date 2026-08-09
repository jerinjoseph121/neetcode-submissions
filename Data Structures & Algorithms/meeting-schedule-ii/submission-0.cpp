/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
            return a.start < b.start;
        });

        int n = intervals.size();

        if (!n) {
            return 0;
        }

        priority_queue<int, vector<int>, greater<int>> pq; 

        int minRooms = 1;

        pq.push(intervals[0].end);

        for (int i = 1; i < n; i++) {
            if (pq.top() <= intervals[i].start) {
                pq.pop();
            }
            pq.push(intervals[i].end);
        }

        return pq.size();
    }
};
