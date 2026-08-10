class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();

        vector<int> sortedQueries = queries;

        sort(sortedQueries.begin(), sortedQueries.end());

        int m = sortedQueries.size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        unordered_map<int, int> queryAnsMap;

        int idx = 0;

        for (auto &q : sortedQueries) {
            while (idx < n && q >= intervals[idx][0]) {
                int len = intervals[idx][1] - intervals[idx][0] + 1;
                pq.push({len, intervals[idx][1]});
                idx++;
            }

            while (!pq.empty() && pq.top()[1] < q) {
                pq.pop();
            }

            if (!pq.empty()) {
                queryAnsMap[q] = pq.top()[0];
            } else {
                queryAnsMap[q] = -1;
            }
        }

        vector<int> res;

        for (auto &q: queries) {
            res.push_back(queryAnsMap[q]);
        }

        return res;
    }
};
