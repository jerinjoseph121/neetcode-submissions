class Solution {
public:
    static bool cmp (pair<int, int> a, pair<int, int> b) {
        if (a.first > b.first)
            return true;
        else if (a.first < b.first)
            return false;
        else {
            if (a.second < b.second)
                return true;
        }

        return false;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }

        vector<pair<int, int>> sortedArr;

        vector<int> res;

        for (auto &val : mpp) {
            sortedArr.push_back({val.second, val.first});
        }

        sort(sortedArr.begin(), sortedArr.end(), cmp);

        for (auto &val : sortedArr) {
            res.push_back(val.second);

            if (res.size() >= k)
                break;
        }

        return res;
    }
};
