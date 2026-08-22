class Solution {
public:
    vector<vector<string>> res;
    vector<pair<int, int>> queenPos;

    bool validPos (int r, int c) {
        for (auto &pos : queenPos) {
            int rQ = pos.first;
            int cQ = pos.second;

            if (r == rQ || c == cQ || abs(r - rQ) == abs(c - cQ))
                return false;
        }
        return true;
    }
    void placeQueens(int ptr, int &n, vector<string> &board) {
        if (ptr == n) {
            res.push_back(board);
            return;
        }

        string row(n, '.');

        for (int i = 0; i < n; i++) {
            if (validPos(ptr, i)) {
                row[i] = 'Q';
                board.push_back(row);
                queenPos.push_back({ptr, i});

                placeQueens(ptr + 1, n, board);

                board.pop_back();
                queenPos.pop_back();
                row[i] = '.';
            }
        }

        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;

        placeQueens(0, n, board);

        return res;
    }
};
