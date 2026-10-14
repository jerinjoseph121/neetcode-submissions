class Solution {
public:
    int getWays(int idx, int &n, string &s, vector<int> &dp) {
        if (idx >= n)
            return 1;

        if (dp[idx] != -1)
            return dp[idx];

        int currDigit = s[idx] - '0';

        if (!currDigit)
            return 0;

        int count = 0;

        count += getWays(idx + 1, n, s, dp);

        if (idx + 1 < n) {
            int nextDigit = s[idx + 1] - '0';

            currDigit = currDigit * 10 + nextDigit;

            if (currDigit <= 26) {
                count += getWays(idx + 2, n, s, dp);
            }
        }

        return dp[idx] = count;
    }
    int numDecodings(string s) {
        int n = s.size();

        vector<int> dp(n, -1);

        return getWays(0, n, s, dp);
    }
};
