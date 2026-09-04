class Solution {
public:
    bool isCycle (int node, unordered_map<int, vector<int>> &graph, vector<int> &visited) {
        if (visited[node])
            return true;

        visited[node] = true;

        bool cycleExist = false;

        for (auto &child : graph[node]) {
            cycleExist |= isCycle (child, graph, visited);
        }

        visited[node] = false;

        graph[node].clear();

        return cycleExist;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;

        for (auto &prerequisite : prerequisites) {
            int a = prerequisite[0];
            int b = prerequisite[1];

            graph[a].push_back(b);
        }

        queue<int> q;

        vector<int> visited(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (isCycle(i, graph, visited)) {
                return false;
            }
        }

        return true;
    }
};
