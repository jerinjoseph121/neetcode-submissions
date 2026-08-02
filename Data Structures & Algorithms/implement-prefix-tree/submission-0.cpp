class PrefixTree {
public:
    struct Trie {
        vector<Trie*> trie;
        bool isWord;
        Trie() {
            trie = vector<Trie*> (26, nullptr);
            isWord = false;
        }
    };

    Trie* head;

    PrefixTree() {
        head = new Trie();
    }
    
    void insert(string word) {
        Trie* ptr = head;
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
        Trie* ptr = head;

        for (auto &ch: word) {
            int chIdx = ch - 'a';
            if (!ptr->trie[chIdx]) {
                return false;
            }
            ptr = ptr->trie[chIdx];
        }
        
        return ptr->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie* ptr = head;

        for (auto &ch: prefix) {
            int chIdx = ch - 'a';
            if (!ptr->trie[chIdx]) {
                return false;
            }
            ptr = ptr->trie[chIdx];
        }
        
        return true;
    }
};
