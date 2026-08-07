class Solution {
public:
    // static bool cmp (vector<int> a, vector<int> b) {
    //     if (a[0] < b[0]) {
    //         return true;
    //     } else if (a[0] > b[0]) {
    //         return false;
    //     } else {
    //         if (a[1] < b[1]) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();

        vector<vector<int>> res;

        int ptr = 0;

        while (ptr < n) {
            int newStart = intervals[ptr][0];
            int newEnd = intervals[ptr][1];

            ptr++;

            while (ptr < n && !(intervals[ptr][1] < newStart || intervals[ptr][0] > newEnd)) {
                newStart = min(newStart, intervals[ptr][0]);
                newEnd = max(newEnd, intervals[ptr][1]);
                ptr++;
            }

            res.push_back({newStart, newEnd});
        }

        return res;
    }
};
