class Solution {
public:
    bool isWordExist (int r, int c, int ptr, vector<vector<char>>& board, int &n, int &m, string &word) {
        if (ptr == word.size()) {
            return true;
        }

        if (r < 0 || c < 0 || r >= n || c >= m || board[r][c] != word[ptr]) {
            return false;
        }

        board[r][c] = '#';

        bool isValid = false;

        isValid |= isWordExist(r + 1, c, ptr + 1, board, n, m, word);
        isValid |= isWordExist(r, c + 1, ptr + 1, board, n, m, word);
        isValid |= isWordExist(r - 1, c, ptr + 1, board, n, m, word);
        isValid |= isWordExist(r, c - 1, ptr + 1, board, n, m, word);

        board[r][c] = word[ptr];

        return isValid;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (isWordExist(i, j, 0, board, n, m, word))
                        return true;
                }
            }
        }

        return false;
    }
};
