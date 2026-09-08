class Solution {
public:
    int findParent(int node, vector<int> &parent) {
        int x = node;

        while (x != parent[x]) {
            x = parent[x];
        }

        int root = x;

        x = node;

        while (x != parent[x]) {
            int temp = parent[x];

            parent[x] = root;

            x = temp;
        }

        return root;
    }

    bool unionFind(int a, int b, vector<int> &parent, vector<int> &rank) {
        if (a == b)
            return false;

        int rootA = findParent(a, parent);
        int rootB = findParent(b, parent);

        if (rootA == rootB)
            return false;

        if (rank[rootA] >= rank[rootB]) {
            parent[rootB] = rootA;
            rank[rootA] += rank[rootB];
        } else {
            parent[rootA] = rootB;
            rank[rootB] += rank[rootA];
        }

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> parent(n + 1, 0);
        vector<int> rank(n + 1, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (!unionFind(u, v, parent, rank)) {
                return {u, v};
            }
        }

        return {};
    }
};
