class Solution {
public:
    void dfs (int node, unordered_map<int, vector<int>> &graph, vector<int> &visited) {
        if (visited[node])
            return;

        visited[node] = 1;

        for (auto &child : graph[node]) {
            dfs(child, graph, visited);
        }

        return;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1)
            return false;
        
        unordered_map<int, vector<int>> graph;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> visited(n, 0);

        dfs(0, graph, visited);

        for (int i = 0; i < n; i++) {
            if (!visited[i])
                return false;
        }

        return true;
    }
};
