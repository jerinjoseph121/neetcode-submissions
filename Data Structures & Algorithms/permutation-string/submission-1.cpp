class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freqS1(26, 0);
        vector<int> freqS2(26, 0);
        int n = s1.size();

        for (auto &ch: s1) {
            freqS1[ch - 'a']++;
        }

        int l = 0, r = 0;
        int count = 0;

        while (r < s2.size()) {
            if (!freqS1[s2[r] - 'a']) {
                count = 0;
                r++;
                l = r;
                freqS2.assign(26, {});
                continue;
            }

            freqS2[s2[r] - 'a']++;
            count++;

            while (freqS2[s2[r] - 'a'] > freqS1[s2[r] - 'a']) {
                freqS2[s2[l] - 'a']--;
                count--;
                l++;
            }

            if (count == n) {
                return true;
            }

            r++;
        }

        return false;
    }
};
