class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        unordered_map<string, vector<string>> mpp;

        for (int i = 0; i < n; i++) {
            string str = strs[i];
            vector<int> freq(26, 0);

            for (auto &ch : str) {
                freq[ch - 'a']++;
            }

            string freqStr;

            for (int i = 0; i < 26; i++) {
                freqStr += to_string(freq[i]);
                freqStr += ',';
            }
            mpp[freqStr].push_back(strs[i]);
        }

        vector<vector<string>> res;

        for (auto &mppVal : mpp) {
            res.push_back(mppVal.second);
        }

        return res;
    }
};
