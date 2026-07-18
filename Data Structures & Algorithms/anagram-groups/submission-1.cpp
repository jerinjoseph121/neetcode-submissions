class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        unordered_map<string, vector<int>> mpp;

        for (int i = 0; i < n; i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            mpp[str].push_back(i);
        }

        vector<vector<string>> res;

        for (auto &mppVal : mpp) {
            vector<string> currAnags;

            for (auto &idx : mppVal.second) {
                currAnags.push_back(strs[idx]);
            }

            if (currAnags.size()) {
                res.push_back(currAnags);
            }
        }

        return res;
    }
};
