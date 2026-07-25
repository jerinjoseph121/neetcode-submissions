class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mpp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp, value});

        return;
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> valueArr = mpp[key];

        int low = 0;

        int high = valueArr.size() - 1;

        string res = "";

        while (low <= high) {
            int mid = (high - low) / 2 + low;

            if (valueArr[mid].first <= timestamp) {
                res = valueArr[mid].second;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return res;
    }
};
