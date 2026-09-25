class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        // vector<vector<int>> dp(n, vector<int> (n, 0));

        // for (int i = 0; i < n; i++) {
        //     dp[i][i] = 1;
        //     if (i < n - 1 && dp[i] == dp[i + 1]) {
        //         dp[i][i + 1] = 1;
        //     }
        // }
        
        int maxL = 0;
        int maxR = 0;

        for (int mid = 0; mid < n; mid++) {
            int currL = mid;
            int currR = mid;


            while (currL >= 0 && currR < n && s[currL] == s[currR]) {
                if (currR - currL + 1 > maxR - maxL + 1) {
                    maxL = currL;
                    maxR = currR;
                }
                currL--;
                currR++;
            }

            currL = mid;
            currR = mid + 1;

            while (currL >= 0 && currR < n && s[currL] == s[currR]) {
                if (currR - currL + 1 > maxR - maxL + 1) {
                    maxL = currL;
                    maxR = currR;
                }
                currL--;
                currR++;
            }
        }

        return s.substr(maxL, maxR - maxL + 1);
    }
};
