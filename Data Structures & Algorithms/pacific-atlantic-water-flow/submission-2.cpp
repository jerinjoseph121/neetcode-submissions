class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    vector<int> isPass (int r, int c, int &n, int &m, vector<vector<int>> &heights, vector<vector<int>> &visited, vector<vector<pair<int, int>>> &dp) {
        if (r < 0 || c < 0) {
            return {1, 0};
        }

        if (r >= n || c >= m) {
            return {0, 1};
        }

        if (dp[r][c].first != -1) {
            return {dp[r][c].first, dp[r][c].second};
        }

        int isPassPac = 0;
        int isPassAtl = 0;

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if (visited[nr][nc]) {
                    continue;
                }

                if (heights[nr][nc] > heights[r][c]) {
                    continue;
                }

                visited[nr][nc] = 1;
            }

            vector<int> isPassRoute = isPass(nr, nc, n, m, heights, visited, dp);

            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                visited[nr][nc] = 0;
            }

            if (isPassRoute[0]) {
                isPassPac = 1;
            }

            if (isPassRoute[1]) {
                isPassAtl = 1;
            }
        }

        dp[r][c].first = isPassPac;
        dp[r][c].second = isPassAtl;

        return {isPassPac, isPassAtl};
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> visited(n, vector<int> (m, 0));

        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>> (m, {-1, -1}));

        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<int> checkPass = isPass(i, j, n, m, heights, visited, dp);
                if (checkPass[0] && checkPass[1]) {
                    res.push_back({i, j});
                }

                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < m; l++) {
                        dp[k][l] = {-1, -1};
                    }
                }
            }
        }

        return res;
    }
};
