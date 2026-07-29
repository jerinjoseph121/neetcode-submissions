class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        vector<int> freq(26, 0);

        int l = 0;
        int r = 0;

        int res = 0;
        int diffCount = 0;

        int diffIdx = l;

        while (r < n) {
            int chIdx = s[r] - 'A';
            freq[chIdx]++;

            while (true) {
                int maxCh = 0;

                for (int i = 0; i < 26; i++) {
                    maxCh = max(maxCh, freq[i]);
                }

                if (r - l + 1 - maxCh <= k) {
                    res = max(res, r - l + 1);
                    break;
                }

                freq[s[l] - 'A']--;
                l++;
            }

            r++;
        }

        return res;
    }
};
