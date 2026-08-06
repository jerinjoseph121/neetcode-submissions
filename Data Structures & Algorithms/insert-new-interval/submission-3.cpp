class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        
        vector<vector<int>> res;

        int newStart = newInterval[0];
        int newEnd = newInterval[1];

        int ptr = n;

        if (!n) {
            res.push_back({newStart, newEnd});
            return res;
        }

        for (int i = 0; i < n; i++) {
            if (newStart < intervals[i][0]) {
                ptr = i;
                break;
            }
        }

        intervals.insert(intervals.begin() + ptr, newInterval);

        n = intervals.size();

        // cout<<ptr<<endl;

        ptr = 0;

        while (ptr < n) {
            int currStart = intervals[ptr][0];
            int currEnd = intervals[ptr][1];
            if (currEnd < newStart || currStart > newEnd) {
                res.push_back(intervals[ptr]);
                ptr++;
            } else {
                while (ptr < n && !(intervals[ptr][1] < newStart || intervals[ptr][0] > newEnd)) {
                    newStart = min(newStart, intervals[ptr][0]);
                    newEnd = max(newEnd, intervals[ptr][1]);
                    ptr++;
                }
                res.push_back({newStart, newEnd});
            }
        } 

        return res;
    }
};
