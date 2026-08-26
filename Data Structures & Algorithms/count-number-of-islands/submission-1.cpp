class Solution {
public:
    void markIsland(int r, int c, int &n, int &m, vector<vector<char>>&grid) {
        if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == '0')
            return;

        grid[r][c] = '0';

        markIsland(r + 1, c, n, m, grid);
        markIsland(r, c + 1, n, m, grid);
        markIsland(r - 1, c, n, m, grid);
        markIsland(r, c - 1, n, m, grid);

        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    markIsland(i, j, n, m, grid);
                    res++;
                }
            }
        }

        return res;
    }
};
