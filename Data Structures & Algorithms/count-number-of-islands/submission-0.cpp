class Solution {
public:
    void markIsland(int r, int c, int &n, int &m, vector<vector<char>>&grid, vector<vector<int>>&visited) {
        if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == '0' || visited[r][c])
            return;

        visited[r][c] = 1;

        markIsland(r + 1, c, n, m, grid, visited);
        markIsland(r, c + 1, n, m, grid, visited);
        markIsland(r - 1, c, n, m, grid, visited);
        markIsland(r, c - 1, n, m, grid, visited);

        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int> (m, 0));

        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j])
                    continue;
                if (grid[i][j] == '1') {
                    markIsland(i, j, n, m, grid, visited);
                    res++;
                }
            }
        }

        return res;
    }
};
