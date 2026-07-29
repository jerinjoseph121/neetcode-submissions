class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (m > n) {
            return "";
        }

        unordered_map<char, int> mpp;

        for (int i = 0; i < m; i++) {
            mpp[t[i] - 'A']++;
        }

        int reqMatches = mpp.size();
        int matches = 0;

        string res = "";

        int l = 0, r = 0;

        while (r < n) {
            int chIdx = s[r] - 'A';
            if (mpp.find(chIdx) == mpp.end()) {
                r++;
                continue;
            }

            mpp[chIdx]--;

            if (mpp[chIdx] == 0) {
                matches++;
            }

            if (matches == reqMatches) {
                int candL = l;

                while (matches == reqMatches) {
                    int remChIdx = s[l] - 'A';
                    if (mpp.find(remChIdx) == mpp.end()) {
                        candL = l;
                        l++;
                        continue;
                    }

                    mpp[remChIdx]++;

                    if (mpp[remChIdx] > 0) {
                        matches--;
                    }

                    candL = l;
                    l++;
                }

                string str = s.substr(candL, r - candL + 1);
                if (res == "" || str.size() < res.size()) {
                    res = str;
                }
            }

            r++;
        }

        return res;
    }
};
