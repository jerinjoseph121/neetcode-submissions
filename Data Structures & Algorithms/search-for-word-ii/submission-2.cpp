class Solution {
public:
    struct Trie {
        vector<Trie*> children;
        int idx;
        int count;

        Trie() {
            children = vector<Trie*> (26, nullptr);
            idx = -1;
            count = 0;
        }
    };
    void addWord(Trie* root, string &word, int wordIdx) {
        Trie* curr = root;
        int ptr = 0;

        while (ptr < word.size()) {
            curr->count++;

            int chIdx = word[ptr] - 'a';

            if (!curr->children[chIdx]) {
                curr->children[chIdx] = new Trie();
            }

            curr = curr->children[chIdx];
            ptr++;
        }

        curr->count++;
        curr->idx = wordIdx;

        return;
    }

    int locateWords (int r, int c, Trie* root, vector<vector<char>>& board, vector<string>& words, vector<string> &res) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] == '*')
            return 0;

        if (!root->children[board[r][c] - 'a'])
            return 0;

        int wordsFound = 0;

        Trie* prev = root;
        root = root->children[board[r][c] - 'a'];

        if (root->idx != -1) {
            res.push_back(words[root->idx]);
            root->idx = -1;
            wordsFound++;
        }

        char tempCh = board[r][c];
        board[r][c] = '*';

        wordsFound += locateWords(r + 1, c, root, board, words, res);
        wordsFound += locateWords(r, c + 1, root, board, words, res);
        wordsFound += locateWords(r - 1, c, root, board, words, res);
        wordsFound += locateWords(r, c - 1, root, board, words, res);

        board[r][c] = tempCh;

        root->count -= wordsFound;

        if (!root->count) {
            root = prev;
            root->children[board[r][c] - 'a'] = nullptr;
        }

        return wordsFound;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();

        for (int i = 0; i < words.size(); i++) {
            addWord(root, words[i], i);
        }

        int n = board.size();
        int m = board[0].size();

        vector<string> res;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                root->count -= locateWords(i, j, root, board, words, res);
            }
        }

        return res;
    }
};
