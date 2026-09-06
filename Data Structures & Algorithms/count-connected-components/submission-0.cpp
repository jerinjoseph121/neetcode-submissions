class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>> &graph, vector<int> &visited) {
        visited[node] = 1;

        for (auto &child : graph[node]) {
            if (visited[child])
                continue;

            dfs(child, graph, visited);
        }

        return;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> visited(n, 0);

        int res = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;

            dfs(i, graph, visited);
            res++;
        }

        return res;
    }
};
