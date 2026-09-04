class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDeg(numCourses, 0);

        unordered_map<int, vector<int>> graph;

        for (auto &pre : prerequisites) {
            int a = pre[0];
            int b = pre[1];

            graph[a].push_back(b);
            inDeg[b]++;
        }

        queue<int> q;

        int completed = 0;

        for (int i = 0; i < numCourses; i++) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            completed++;

            for (auto &v : graph[u]) {
                inDeg[v]--;

                if (inDeg[v] == 0)
                    q.push(v);
            }
        }

        return completed == numCourses;
    }
};
