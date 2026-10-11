class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int> (n, 0));

        int res = 0;

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            res++;

            if (i + 1 < n && s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                res++;
            }
        }

        for (int len = 3; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                if (dp[l + 1][r - 1] && s[l] == s[r]) {
                    dp[l][r] = 1;
                    res++;
                }        
            }
        }

        return res;
    }
};
