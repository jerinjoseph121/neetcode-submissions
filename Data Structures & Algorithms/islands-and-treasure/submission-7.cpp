class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<vector<int>> q;

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                    count++;
                }
            }
        }

        int dist = 1;

        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (!q.empty()) {
            int tempCount = 0;

            while (count) {
                int r = q.front()[0];
                int c = q.front()[1];
                q.pop();
                
                for (int i = 0; i < 4; i++) {
                    int newR = r + dir[i][0];
                    int newC = c + dir[i][1];

                    if (newR < 0 || newC < 0 || newR >= n || newC >= m || grid[newR][newC] == -1)
                        continue;

                    if (dist < grid[newR][newC]) {
                        grid[newR][newC] = dist;
                        q.push({newR, newC});
                        tempCount++;
                    }
                }

                count--;
            }

            dist++;
            count = tempCount;
        }

        return;
    }
};
