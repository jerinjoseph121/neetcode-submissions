class Solution {
public:
    bool isWordExist (int r, int c, int ptr, vector<vector<char>>& board, int &n, int &m, string &word, vector<vector<int>> &visited) {
        if (ptr == word.size()) {
            return true;
        }

        if (r < 0 || c < 0 || r >= n || c >= m) {
            return false;
        }

        if (visited[r][c])
            return false;

        if (board[r][c] != word[ptr])
            return false;

        visited[r][c] = 1;

        bool isValid = false;

        isValid |= isWordExist(r + 1, c, ptr + 1, board, n, m, word, visited);
        isValid |= isWordExist(r, c + 1, ptr + 1, board, n, m, word, visited);
        isValid |= isWordExist(r - 1, c, ptr + 1, board, n, m, word, visited);
        isValid |= isWordExist(r, c - 1, ptr + 1, board, n, m, word, visited);

        visited[r][c] = 0;

        return isValid;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (isWordExist(i, j, 0, board, n, m, word, visited))
                        return true;
                }
            }
        }

        return false;
    }
};
