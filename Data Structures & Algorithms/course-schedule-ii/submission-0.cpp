class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;

        vector<int> inDeg(numCourses, 0);

        for (auto &pre : prerequisites) {
            int a = pre[0];
            int b = pre[1];

            graph[b].push_back(a);
            inDeg[a]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }

        vector<int> res;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            res.push_back(u);

            for (auto &v : graph[u]) {
                inDeg[v]--;

                if (inDeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (res.size() == numCourses)
            return res;

        return {};
    }
};
