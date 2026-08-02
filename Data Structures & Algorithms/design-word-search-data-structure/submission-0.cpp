class WordDictionary {
public:
    struct Trie {
        vector<Trie*> trie;
        bool isWord;

        Trie() {
            trie = vector<Trie*> (26, nullptr);
            isWord = false;
        }
    };

    Trie* root;

    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* ptr = root;

        for (auto &ch: word) {
            int chIdx = ch - 'a';
            if (!ptr->trie[chIdx]) {
                ptr->trie[chIdx] = new Trie();
            }

            ptr = ptr->trie[chIdx];
        }

        ptr->isWord = true;
    }
    
    bool search(string word) {
        return findWord(0, word, root);
    }

    bool findWord (int idx, string &word, Trie* root) {
        if (!root)
            return false;

        if (idx == word.size()) {
            return root->isWord;
        }

        while (idx < word.size()) {
            char ch = word[idx];
            if (ch == '.') {
                for (auto &child : root->trie) {
                    if (!child)
                        continue;
                    
                    if (findWord(idx + 1, word, child))
                        return true;
                }
                return false;

            } else {
                if (!root->trie[ch - 'a'])
                    return false;
                
                root = root->trie[ch - 'a'];
                idx++;
            }
        } 

        return root->isWord;
    }
};
