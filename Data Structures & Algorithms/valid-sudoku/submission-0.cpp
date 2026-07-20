class Solution {
public:
    bool isValidSquare (int r, int c, vector<vector<char>>& board) {
        vector<int> freq(10, 0);

        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0';
                freq[num]++;
                if (freq[num] > 1)
                    return false;
            }
        }

        return true;
    }

    bool isValidRow (int r, vector<vector<char>>& board) {
        vector<int> freq(10, 0);

        for (int i = 0; i < 9; i++) {
            if (board[r][i] == '.')
                continue;

            int num = board[r][i] - '0';
            freq[num]++;
            if (freq[num] > 1)
                return false;
        }

        return true;
    }

    bool isValidCol (int c, vector<vector<char>>& board) {
        vector<int> freq(10, 0);

        for (int i = 0; i < 9; i++) {
            if (board[i][c] == '.')
                continue;
            
            int num = board[i][c] - '0';
            freq[num]++;
            if (freq[num] > 1)
                return false;
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!isValidSquare(i, j, board))
                    return false;
            }
        }

        for (int i = 0; i < 9; i++) {
            if (!isValidRow(i, board))
                return false;
            if (!isValidCol(i, board))
                return false;
        }

        return true;
    }
};
