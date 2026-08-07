class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        
        vector<vector<int>> res;

        int newStart = newInterval[0];
        int newEnd = newInterval[1];

        bool isPlaced = false;

        for (int i = 0; i < n; i++) { 
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            if (currEnd < newStart) {
                res.push_back(intervals[i]);
            } else if (currStart > newEnd){
                if (!isPlaced) {
                    res.push_back({newStart, newEnd});
                }
                isPlaced = true;
                res.push_back(intervals[i]);
            } else {
                newStart = min(newStart, currStart);
                newEnd = max(newEnd, currEnd);
            }
        } 

        if (!isPlaced) {
            res.push_back({newStart, newEnd});
        }

        return res;
    }
};
