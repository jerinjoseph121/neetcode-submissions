class Solution {
public:
    int findChangeCount(int amount, vector<int> &coins, vector<int> &dp) {
        if (amount < 0)
            return INT_MAX;

        if (amount == 0) {
            return 0;
        }

        if (dp[amount] != -1)
            return dp[amount];

        int changeCount = INT_MAX;

        for (auto &coinVal : coins) {
            int currChangeCount = findChangeCount(amount - coinVal, coins, dp);
            if (currChangeCount == INT_MAX)
                continue;

            currChangeCount++;

            changeCount = min(changeCount, currChangeCount);
        }

        return dp[amount] = changeCount;
    } 

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);

        int res = findChangeCount(amount, coins, dp);

        return res == INT_MAX ? -1 : res;
    }
};
