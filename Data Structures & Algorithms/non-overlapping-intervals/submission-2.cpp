class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();

        int res = 0;

        int ptr = 0;

        int currStart = intervals[0][1];
        int currEnd = intervals[0][1];

        ptr++;

        while (ptr < n) {
            if (intervals[ptr][0] >= currEnd) {
                currStart = intervals[ptr][0];
                currEnd = intervals[ptr][1];
            } else {
                if (intervals[ptr][1] < currEnd) {
                    currStart = intervals[ptr][0];
                    currEnd = intervals[ptr][1];
                }
                res++;
            }
            ptr++;
        }

        return res;
    }
};
