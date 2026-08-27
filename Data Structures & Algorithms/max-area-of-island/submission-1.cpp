class Solution {
public:
    int getArea(int r, int c, int &n, int &m, vector<vector<int>> &grid) {
        if (r < 0 || c < 0 || r >= n || c >= m || !grid[r][c]) {
            return 0;
        }

        grid[r][c] = 0;

        int area = 1;

        area += getArea(r + 1, c, n, m, grid);
        area += getArea(r, c + 1, n, m, grid);
        area += getArea(r - 1, c, n, m, grid);
        area += getArea(r, c - 1, n, m, grid);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    maxArea = max(maxArea, getArea(i, j, n, m, grid));
                }
            }
        }

        return maxArea;
    }
};
