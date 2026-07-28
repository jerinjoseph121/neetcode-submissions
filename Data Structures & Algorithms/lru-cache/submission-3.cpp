class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
};

class LRUCache {
public:
    int capacity;
    unordered_map<int, Node*> mpp;
    Node* left;
    Node* right;

    LRUCache(int capacity) {
        this->capacity = capacity;
        mpp.clear();
        left = new Node(-1, -1);
        right = new Node(-1, -1);

        left->next = right;
        right->prev = left;
    }

    void insertNode(Node* node) {
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;

        return;
    }

    void removeNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    
        return;
    }
    
    int get(int key) {
        if (mpp.find(key) != mpp.end()) {
            removeNode(mpp[key]);
            insertNode(mpp[key]);

            return mpp[key]->val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            removeNode(mpp[key]);
        }

        Node* newNode = new Node(key, value);
        insertNode(newNode);

        mpp[key] = newNode;

        if (mpp.size() > capacity) {
            Node* delNode = left->next;
            mpp.erase(delNode->key);
            removeNode(delNode);

            delete delNode;
        }

        return;
    }
};
