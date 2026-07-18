class Solution {
public:
    bool isAnag(string a, string b) {
        int n = a.size();
        int m = b.size();

        if (n != m)
            return false;

        vector<int> mpp(26, 0);

        for (int i = 0; i < n; i++) {
            int aVal = a[i] - 'a';
            int bVal = b[i] - 'a';

            mpp[aVal]++;
            mpp[bVal]--;
        }

        for (int i = 0; i < 26; i++) {
            if (mpp[i])
                return false;
        }

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;

        for (int i = 0; i < strs.size(); i++) {
            string firstStr = strs[i];
            bool isAdded = false;

            for (int j = 0; j < res.size(); j++) {
                string secondStr = res[j][0];

                bool isAnagram = isAnag(firstStr, secondStr);

                if (isAnagram) {
                    res[j].push_back(firstStr);
                    isAdded = true;
                    break;
                } 
            }
            if (!isAdded) {
                res.push_back({firstStr});
            }
        }

        return res;
    }
};
