class Solution {
public:
    int totalWays(int currPos, int &n, vector<int> &dp) {
        if (currPos > n)
            return 0;

        if (currPos == n)
            return 1;

        if (dp[currPos] != -1)
            return dp[currPos];
    
        int ways = 0;

        ways += totalWays(currPos + 1, n, dp);
        ways += totalWays(currPos + 2, n, dp);

        return dp[currPos] = ways;
    }
    
    int climbStairs(int n) {
        vector<int> dp(n, -1);
        return totalWays(0, n, dp);
    }
};
