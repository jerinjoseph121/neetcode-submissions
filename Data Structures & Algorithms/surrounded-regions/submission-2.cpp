class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, - 1}};

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                        q.push({i, j});
                    } else {
                        board[i][j] = 'T';
                    }
                } 
            }
        }

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m || board[nr][nc] != 'T')
                    continue;

                board[nr][nc] = 'O';

                q.push({nr, nc});
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'T') {
                    board[i][j] = 'X';
                } 
            }
        }

        return;
    }
};
