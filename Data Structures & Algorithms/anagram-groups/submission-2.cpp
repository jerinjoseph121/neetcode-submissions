class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        unordered_map<string, vector<string>> mpp;

        for (int i = 0; i < n; i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            mpp[str].push_back(strs[i]);
        }

        vector<vector<string>> res;

        for (auto &mppVal : mpp) {
            res.push_back(mppVal.second);
        }

        return res;
    }
};
