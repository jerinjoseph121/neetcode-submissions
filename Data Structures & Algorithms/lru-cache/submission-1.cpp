class LRUCache {
public:
    int capacity;
    queue<int> q;
    unordered_map<int, int> mpp;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    void removeKey(int key) {
        queue<int> temp;
        while(!q.empty()) {
            int currKey = q.front();
            q.pop();
            if (currKey == key)
                continue;
            temp.push(currKey);
        }

        while(!temp.empty()) {
            q.push(temp.front());
            temp.pop();
        }

        return;
    }
    
    int get(int key) {
        if (!mpp.count(key))
            return -1;

        int val = mpp[key];

        if (val != -1) {
            removeKey(key);
            q.push(key);
            if (q.size() > capacity) {
                int remKey = q.front();
                q.pop();
                mpp[remKey] = -1;
            }
        }

        return val;
    }
    
    void put(int key, int value) {
        if (mpp.count(key)) {
            removeKey(key);
        }

        q.push(key);
        if (q.size() > capacity) {
            int remKey = q.front();
            q.pop();
            mpp[remKey] = -1;
        }
        mpp[key] = value;

        return;
    }
};
