class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];

            int sqDist = x * x + y * y;

            pq.push({sqDist, i});

            if (pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> res;

        while (!pq.empty()) {
            int idx = pq.top().second;
            res.push_back(points[idx]);
            pq.pop();
        }

        return res;
    }
};
