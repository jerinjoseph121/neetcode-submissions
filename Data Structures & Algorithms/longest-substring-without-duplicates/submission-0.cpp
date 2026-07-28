class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        vector<int> freq(256, 0);

        int l = 0;
        int r = 0;

        int res = 0;

        while (r < n) {
            int ascVal = static_cast<int>(s[r]);
            freq[ascVal]++;

            if (freq[ascVal] > 1) {
                while (freq[ascVal] > 1) {
                    int remAscVal = static_cast<int>(s[l]);
                    freq[remAscVal]--;
                    l++;
                }
            }
            res = max(res, r - l + 1);
            r++;
        }

        return res;
    }
};
